#include "codegen.h"

void generate_code(ast_node* node)
{
    switch (node->type)
    {
        case NODE_PROGRAM:
            generate_code(node->child[0]);
            generate_code(node->child[1]);
      	break;

      	case NODE_FUNCTION_DEFINITION:
            generate_code(node->child[4]); // Body
      	break;

			case NODE_ASSIGNMENT:
				// TODO:
			break;

      	case NODE_LOCAL_VAR:
            // TODO:
      	break;

      	case NODE_BOOL_LITERAL:
            // TODO:
      	break;

      	case NODE_COMMAND_LIST:
            generate_code(node->child[0]);
            generate_code(node->child[1]);
      	break;

      	case NODE_VAR_ACCESS:
            generate_var_access(node);
      	break;

      	case NODE_IF:
            // TODO:
      	break;

      	case NODE_WHILE:
            // TODO:
      	break;

      	case NODE_DO_WHILE:
            // TODO:
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
				generate_relational_op(node, "and");
			break;

			case NODE_OR:
				generate_relational_op(node, "or");
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
            printf("loadI %d => %s", node->int_literal, node->register_name);
       	break;
    }
}

void generate_relational_op(ast_node* node, char* instruction_code)
{
    // TODO:
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
    printf("%s %s %s => %s", 
        instruction_name,
        node->child[0]->register_name, 
        node->child[1]->register_name, 
        node->register_name);
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