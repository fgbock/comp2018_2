#include "codegen.h"

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

      	case NODE_FUNCTION_DEFINITION:
            generate_code(node->child[1]); // Body
      	break;

		case NODE_FUNCTION_BODY:
			generate_code(node->child[0]); // Instructions
		break;

		case NODE_ASSIGNMENT:
			// TODO:
			generate_code(node->child[3]); // rhs
			//printf("load")
		break;

      	case NODE_LOCAL_VAR:
            // TODO:
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
            printf("loadI %d => %s\n", node->int_literal, node->register_name);
       	break;
    }
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

	printf("%s:\n", rhs->true_label);
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
	printf("%s:\n", lhs->false_label);
	generate_code(rhs);
	generate_comment("'or' end");

}

void generate_boolean_literal_code(ast_node* node)
{
	if (node->bool_literal)
	{
		printf("jumpI -> %s\n", node->true_label);
	}
	else
	{
		printf("jumpI -> %s\n", node->false_label);
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
	node->child[1]->false_label = false_label;

	generate_comment("'if' begin");
	generate_code(node->child[0]); // Expression
	printf("%s:\n", true_label);

	generate_comment("Then");
	generate_code(node->child[1]); // Then
	printf("%s:\n", false_label);
	printf("jumpI -> %s\n", done_label);
	
	generate_comment("Else");
	generate_code(node->child[2]); // Else

	generate_comment("'if' end");
	printf("%s:\n", done_label);
}

void generate_while_code(ast_node* node)
{
	char* begin_label = next_label();
	char* true_label = next_label();
	char* false_label = next_label();
	node->child[0]->true_label = true_label;
	node->child[0]->false_label = false_label;

	printf("%s:\n", begin_label);

	generate_comment("'while' begin");
	generate_code(node->child[0]); // Conditional
	printf("%s:\n", true_label);

	generate_comment("'while' do:");
	generate_code(node->child[1]); // Command block
	printf("jumpI -> %s\n", begin_label);

	generate_comment("'while' end");
	printf("%s:\n", false_label);

}

void generate_do_while_code(ast_node* node)
{
    char* begin_label = next_label();
	char* done_label = next_label();
	node->child[1]->true_label = begin_label;
	node->child[1]->false_label = done_label;
	printf("%s:\n", begin_label);

	generate_comment("Do");
	generate_code(node->child[0]); // Body

	generate_comment("While");
	generate_code(node->child[1]); // Expression
	printf("jumpI -> %s\n", begin_label);

	generate_comment("End do-while");
	printf("%s:\n", done_label);
}

void generate_relational_op(ast_node* node, char* instruction_code)
{
	node->register_name = next_register();
	generate_code(node->child[0]);
	generate_code(node->child[1]);
	printf("%s %s %s -> %s\n", 
		instruction_code, 
		node->child[0]->register_name,
		node->child[1]->register_name,
		node->register_name);
    printf("cbr %s -> %s, %s\n",
		node->register_name,
		node->true_label,
		node->false_label);
}

void generate_var_access(ast_node* node)
{
    t_entrada_simbolo* out;
    scope_stack_get(&scope_stack, &out, node->string_literal);
    //out->variavel.tipo.
    node->child[0]; // Identifier
    node->child[2]; // Optional vector access
}

void generate_binary_op(ast_node* node, char* instruction_name)
{
    generate_code(node->child[0]);
    generate_code(node->child[1]);
    node->register_name = next_register();
    printf("%s %s %s => %s\n", 
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