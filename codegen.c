#include "codegen.h"

int current_instruction = 0;

void generate(ast_node* root)
{
	generate_bootstrap_code();
	generate_code(root);
}

void generate_bootstrap_code()
{
	generate_comment("Initialize pointers");
	instruction("loadI 0 => rfp\n");
	instruction("loadI 1000 => rsp\n");
	instruction("loadI 0 => rbss\n");
	instruction("jumpI => Lmain\n");
}

void generate_code(ast_node* node)
{
	if (node == NULL)
	{
		return;
	}
    switch (node->type)
    {
        case NODE_PROGRAM:

            generate_code(node->child[0]);
            generate_code(node->child[1]);
      	break;

		case NODE_COMMAND_BLOCK:
			generate_code(node->child[0]);
			generate_code(node->child[1]);
		break;

		case NODE_BRACKET_EXPR:
			node->child[0]->true_label = node->true_label;
			node->child[0]->false_label = node->false_label;
			node->register_name = node->child[0]->register_name;
			generate_code(node->child[0]);
		break;

		case NODE_FUNCTION_CALL:
			generate_function_call(node);
		break;

      	case NODE_FUNCTION_DEFINITION:
		  	generate_function_definition(node);
      	break;

		case NODE_FUNCTION_BODY:
			// Generate the function body directly
			generate_code(node->child[0]); // Instructions
		break;

		case NODE_ASSIGNMENT:
			generate_assignment_code(node);
		break;

      	case NODE_LOCAL_VAR:
            generate_local_var_code(node);
      	break;

      	case NODE_BOOL_LITERAL:
            generate_boolean_literal_code(node);
      	break;

      	case NODE_COMMAND_LIST:
            generate_code(node->child[0]);
            generate_code(node->child[1]);
      	break;

      	case NODE_VAR_ACCESS:
            generate_var_access(node);
      	break;

      	case NODE_IF:
		  	generate_if_code(node);
      	break;

		case NODE_ELSE:
			generate_code(node->child[0]);
		break;

      	case NODE_WHILE:
            generate_while_code(node);
      	break;

      	case NODE_DO_WHILE:
            generate_do_while_code(node);
      	break;

      	case NODE_LESS:
      		generate_relational_op(node, "cmp_LT");
      	break;

		case NODE_LE:
			generate_relational_op(node, "cmp_LE");
		break;

		case NODE_GREATER:
			generate_relational_op(node, "cmp_GT");
		break;

		case NODE_GE:
			generate_relational_op(node, "cmp_GE");
		break;

		case NODE_EQ:
			generate_relational_op(node, "cmp_EQ");
		break;

		case NODE_NE:
			generate_relational_op(node, "cmp_NE");
		break;

		case NODE_AND:
			generate_and_code(node);
		break;

		case NODE_OR:
			generate_or_code(node);
		break;

        case NODE_ADD:
        	generate_binary_op(node, "add");
        break;

        case NODE_SUB:
        	generate_binary_op(node, "sub");
        break;

        case NODE_DIV:
            generate_binary_op(node, "div");
       	break;

        case NODE_MUL:
            generate_binary_op(node, "mult");
       	break;

      	case NODE_INT_LITERAL:
         	node->register_name = next_register();
            instruction("loadI %d => %s\n", node->int_literal, node->register_name);
       	break;

				case NODE_RETURN:
					generate_return_op(node);
				break;
    }
}

void instruction(const char *format, ...)
{
	// Count instructions
	current_instruction++;

	// Forward to printf
	va_list arglist;
	va_start(arglist, format);
	vprintf(format, arglist);
	va_end(arglist);
}
void generate_return_op(ast_node* node){
	generate_comment("rhs of the return");
	generate_code(node->child[0]); // rhs
	char* ret_addr = next_register();
	char* ret_val = next_register();

	// Pop stack, increment old Program Counter by two to skip jump, increment stack pointer, jump to caller (PC)
	instruction("load rsp => %s\n", ret_addr);
	instruction("addI rsp, 4 => rsp\n");
	instruction("addI %s, 2 => %s\n",ret_addr,ret_addr);
	instruction("jump -> %s\n", ret_addr);

}

void generate_function_call(ast_node* node)
{
    char* function_identifier = node->child[0]->string_literal;
	printf("// Calling function %s\n", function_identifier);

	ast_node* argument_node = node->child[1];
	while(argument_node->type == NODE_ARGUMENT_LIST)
	{
		char* register_name = next_register();
		generate_code(argument_node->child[0]);
		char* var = argument_node->child[0]->register_name;
		instruction("subI rsp, 4 => rsp\n");
		instruction("store %s => rsp\n", var);
		// Next argument
		argument_node = argument_node->child[1];
	}
	node->register_name = next_register();

	//Push Program Counter (PC) into stack pointer addr, subtract stack pointer, jump to function
	instruction("subI rsp, 4 => rsp\n");
	instruction("store rpc => rsp\n");
	instruction("jumpI -> L%s\n", function_identifier);
}

void generate_function_definition(ast_node* node)
{
	generate_comment("Start functon definition");
	node->register_name = next_register();
	instruction("L%s:\n", node->child[0]->child[2]->string_literal);
	generate_code(node->child[1]); // Body
	generate_comment("End functon definition");
}

char* generate_variable_load_code(char* variable_identifier)
{
	char* register_name = next_register();
	char* variable_address_register_name = next_register();
	t_entrada_simbolo* out;
	scope_stack_get(&scope_stack, &out, variable_identifier);

	if (out->variavel.is_global_var)
	{
    	// Endereço de variáveis globais são um deslocamento em relação ao registrador especial rbss
		instruction("addI rbss, %d => %s\n", out->variavel.offset_in_bytes, variable_address_register_name);
	}
	else
	{
		// Endereço de variáveis locais são um deslocamento em relação ao registrador especial rfp
		instruction("addI rfp, %d => %s\n", out->variavel.offset_in_bytes, variable_address_register_name);
	}
	instruction("load %s => %s\n", variable_address_register_name, register_name);

	return register_name;
}

void generate_local_var_code(ast_node* node)
{
	t_entrada_simbolo* lhs_out;
	scope_stack_get(&scope_stack, &lhs_out, node->child[0]->string_literal);

	ast_node* optional_value_definition = node->child[4]; // Declaracao de valor opcional
	if (optional_value_definition->type == NODE_INT_LITERAL)
	{
		generate_comment("Initializing local variable with int literal");
		char* temp_register = next_register();
		char* temp_register_2 = next_register();
		instruction("addI rfp, %d => %s\n", lhs_out->variavel.offset_in_bytes, temp_register);
		instruction("loadI %d => %s\n", optional_value_definition->int_literal, temp_register_2);
		instruction("store %s => %s\n", temp_register_2, temp_register);
	}
	else if (optional_value_definition->type == NODE_IDENTIFIER)
	{
		generate_comment("Initializing local variable with another variable");
		char* rhs_value_register_name = generate_variable_load_code(optional_value_definition->string_literal);
		char* lhs_memory_address_register = next_register();
		instruction("addI rfp, %d => %s\n", lhs_out->variavel.offset_in_bytes, lhs_memory_address_register);
		instruction("store %s => %s\n", lhs_memory_address_register, rhs_value_register_name);
	}
}

void generate_assignment_code(ast_node* node)
{
	generate_comment("rhs of the assignment");
	generate_code(node->child[3]); // rhs

	t_entrada_simbolo* out;
	scope_stack_get(&scope_stack, &out, node->child[1]->string_literal);

	char* temp_register = next_register();
	generate_comment("Storing the rhs into the variable");
	if (out->variavel.is_global_var)
	{
    	// Endereço de variáveis globais são um deslocamento em relação ao registrador especial rbss
		instruction("addI rbss, %d => %s\n", out->variavel.offset_in_bytes, temp_register);
	}
	else
	{
		// Endereço de variáveis locais são um deslocamento em relação ao registrador especial rfp
		instruction("addI rfp, %d => %s\n", out->variavel.offset_in_bytes, temp_register);
	}
	if(node->child[3]->type == NODE_FUNCTION_CALL){
		char* temp_register2 = next_register();
		instruction("load %s => %s\n", node->child[3]->register_name, temp_register2);
		instruction("store %s => %s\n", temp_register2, temp_register);
	}
	else instruction("store %s => %s\n", node->child[3]->register_name, temp_register);
}

void generate_and_code(ast_node* node)
{
	ast_node* lhs = node->child[0];
	ast_node* rhs = node->child[1];
	// Implement short-circut
	lhs->false_label = node->false_label;
	lhs->true_label = next_label();

	rhs->false_label = node->false_label;
	rhs->true_label = node->true_label;

	generate_comment("'and' begin");
	generate_comment("lhs:");
	generate_code(lhs);

	instruction("%s:\n", lhs->true_label);
	generate_comment("rhs:");
	generate_code(rhs);
	generate_comment("'and' end");
}

void generate_or_code(ast_node* node)
{
	ast_node* lhs = node->child[0];
	ast_node* rhs = node->child[1];

	// Implement short-circuit
	lhs->true_label = node->true_label;
	lhs->false_label = next_label();

	rhs->true_label = node->true_label;
	rhs->false_label = node->false_label;

	generate_comment("'or' begin");
	generate_code(lhs);
	instruction("%s:\n", lhs->false_label);
	generate_code(rhs);
	generate_comment("'or' end");

}

void generate_boolean_literal_code(ast_node* node)
{
	if (node->bool_literal)
	{
		instruction("jumpI -> %s\n", node->true_label);
	}
	else
	{
		instruction("jumpI -> %s\n", node->false_label);
	}
}

void generate_comment(char* comment)
{
	printf("// %s \n", comment);
}

void generate_if_code(ast_node* node)
{
	char* true_label = next_label();
	char* false_label = next_label();
	char* done_label = next_label();
	node->child[0]->true_label = true_label;
	node->child[0]->false_label = false_label;

	generate_comment("'if' begin");
	generate_code(node->child[0]); // Expression
	instruction("%s:\n", true_label);

	generate_comment("Then");
	generate_code(node->child[1]); // Then
	instruction("jumpI -> %s\n", done_label);

	generate_comment("Else");
	instruction("%s:\n", false_label);
	generate_code(node->child[2]); // Else

	generate_comment("'if' end");
	instruction("%s:\n", done_label);
}

void generate_while_code(ast_node* node)
{
	char* begin_label = next_label();
	char* true_label = next_label();
	char* false_label = next_label();
	node->child[0]->true_label = true_label;
	node->child[0]->false_label = false_label;

	instruction("%s:\n", begin_label);

	generate_comment("'while' begin");
	generate_code(node->child[0]); // Conditional
	instruction("%s:\n", true_label);

	generate_comment("'while' do:");
	generate_code(node->child[1]); // Command block
	instruction("jumpI -> %s\n", begin_label);

	generate_comment("'while' end");
	instruction("%s:\n", false_label);
}

void generate_do_while_code(ast_node* node)
{
    char* begin_label = next_label();
	char* done_label = next_label();
	node->child[1]->true_label = begin_label;
	node->child[1]->false_label = done_label;
	instruction("%s:\n", begin_label);

	generate_comment("Do");
	generate_code(node->child[0]); // Body

	generate_comment("While");
	generate_code(node->child[1]); // Expression
	instruction("jumpI -> %s\n", begin_label);

	generate_comment("End do-while");
	instruction("%s:\n", done_label);
}

void generate_relational_op(ast_node* node, char* instruction_code)
{
	node->register_name = next_register();
	generate_code(node->child[0]);
	generate_code(node->child[1]);
	instruction("%s %s, %s -> %s\n",
		instruction_code,
		node->child[0]->register_name,
		node->child[1]->register_name,
		node->register_name);
    instruction("cbr %s -> %s, %s\n",
		node->register_name,
		node->true_label,
		node->false_label);
}

void generate_var_access(ast_node* node)
{
	ast_node* var_identifier_node = node->child[0];
	//printf("loading var %s\n", var_identifier_node->string_literal);
	node->register_name = generate_variable_load_code(var_identifier_node->string_literal);
	//printf("loaded\n");
}

void generate_binary_op(ast_node* node, char* instruction_name)
{
    generate_code(node->child[0]);
    generate_code(node->child[1]);
    node->register_name = next_register();
    instruction("%s %s, %s => %s\n",
        instruction_name,
        node->child[0]->register_name,
        node->child[1]->register_name,
        node->register_name
	);
}

char* next_register()
{
	static int count = 1;
	char* register_name = malloc(sizeof(char) * 10);
	sprintf(register_name, "r%d", count);
	count++;
	return register_name;
}

char* next_label()
{
	static int count = 1;
	char* label_name = malloc(sizeof(char) * 10);
	sprintf(label_name, "L%d", count);
	count++;
	return label_name;
}
