%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	enum types{
		ARRAY = 1, TYPE_STRING, TYPE_STRING_ARRAY, TYPE_BOOLEAN, TYPE_BOOLEAN_ARRAY, TYPE_NUMBER, TYPE_NUMBER_ARRAY, TYPE_VOID, NOT_FOUND
	};
	
	struct symbol_node{
		char * name;
		int type;
		int scope_level;
		struct symbol_node * next;
	};
	
	struct function_node{
		char * name;
		int * param_types;
		int param_count;
		int return_type;
		int is_defined;
		struct function_node * next;
	};


	int yylex(void);
	void yyerror(char *);
	void add_symbol(char * name, int type, int level);
	int get_symbol_type(char * name);
	void delete_symbols(int level);
	void add_function(char * name, int * param_types, int param_count, int return_type);
	int get_function_return_type(char * name);
	struct function_node * get_function(char * name);
	extern FILE * yyin;


	struct function_node * function_list = NULL;
	struct symbol_node * symbol_list = NULL;
	int current_level = 0;
	FILE * output = NULL;
	
%}

%code requires{

	struct string_list_node{
		char * data;
		struct string_list_node * next;
	};

	struct string_and_type_list_node{
		char * data;
		int type;
		struct string_and_type_list_node * next;
	};

	struct integer_list_node{
		int data;
		struct integer_list_node * next;
	};

	struct function_parameters{
		struct string_and_type_list_node * params;
		int size;
	};

	struct function_signature{
		struct string_list_node * identifiers;
		struct string_and_type_list_node * params;
		struct integer_list_node * param_count;
	};

	struct data_with_type{
		char * data;
		int type;
	};

	struct name_with_data{
		char * data;
		char * name;
	};

}

%union{
	char* string;
	struct function_parameters function_params;
	struct function_signature function;
	struct data_with_type data_and_type;
	struct name_with_data name_and_data;
}

%token <string> IDENTIFIER STRING_LITERAL NUMBER_LITERAL TRUE_LITERAL FALSE_LITERAL EXIT NUMBER STRING BOOLEAN VOID FUNCTION IF ELSE WHILE BREAK CONTINUE PRINT SCAN EQ_OP GE_OP LE_OP NE_OP INC_OP DEC_OP SUCCESSFUL FAILED

%precedence IFX
%precedence ELSE

%left '|' '&'
%nonassoc '>' '<' EQ_OP GE_OP LE_OP NE_OP
%left '+' '-'
%left '*' '/' '%'
%precedence UNARY_MINUS


%type <string> program function_declaration_statement function_declaration function_definition_block
%type <string> statements statement while_statement main while_statements start
%type <string> function_definition
%type <function_params> args arg_list param_list params
%type <function> function function_call
%type <data_and_type> expression var_type
%type <name_and_data> function_call_statement

%start start

%%

start
		: program								{
												printf("PARSER: start Found!\n");
												fprintf(output, "#include<stdio.h>\n#include<stdlib.h>\n\n%s", $1);
												printf("\nCompilation was successful!\n\n");
											
											}
		;

program
		: function_declaration_statement program function_definition_block	{
												printf("PARSER: program Found!\n");
												int size = strlen($1) + strlen($2) + strlen($3) + 4;
												$$ = (char*) malloc(size * sizeof(char));
												sprintf($$, "%s\n\n%s\n%s", $1, $2, $3);
												free($1);
												free($2);
												free($3);
											}

		| main									{
												printf("PARSER: program Found!\n");
												int size = strlen($1) + strlen("\nint main()\n\n{\nreturn 0;\n}") + 1;
												$$ = (char*) malloc(size * sizeof(char));
												sprintf($$, "\nint main()\n\n{\n%sreturn 0;\n}", $1);
												free($1);
											}
		;


main
		: statements						{
										printf("PARSER: main Found!\n");
										$$ = $1;
									}

		;

function_declaration_statement
		: FUNCTION function_declaration ';'			{
										printf("PARSER: function_declaration_statement Found!\n");
										int size = strlen($2) + 2;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "%s;", $2);
									}
		;

function_declaration
		: var_type function					{
										printf("PARSER: function_declaration Found!\n");
										struct string_list_node * current = $2.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $2.identifiers;
										struct integer_list_node * current_count = $2.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0, param_count = 0;
										struct string_and_type_list_node * current_param = $2.params;
										while(current_param != NULL){
											param_count++;
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										int * param_types = (int *) malloc(param_count * sizeof(int));
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $2.params;
										int i = 0;
										while(current_param != NULL){
											param_types[i++] = current_param->type;
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = strlen($1.data) + functionId_size + params_size + 4;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "%s %s(%s)", $1.data, functionId, params);
										if(get_function(functionId) != NULL){
											yyerror("Semantic Error: Function is already declared!");
											exit(1);
										}
										add_function(functionId, param_types, param_count, $1.type);
										free(params);
									}

		| var_type function IDENTIFIER				{
										printf("PARSER: function_declaration Found!\n");
										struct string_list_node * current = $2.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen($3) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $2.identifiers;
										struct integer_list_node * current_count = $2.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen($3) + 2) * sizeof(char));
										sprintf(temp, "%s%d", $3, (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										
										int params_size = 0, param_count = 0;
										struct string_and_type_list_node * current_param = $2.params;
										while(current_param != NULL){
											param_count++;
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										int * param_types = (int *) malloc(param_count * sizeof(int));
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $2.params;
										int i = 0;
										while(current_param != NULL){
											param_types[i++] = current_param->type;
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = strlen($1.data) + functionId_size + params_size + 4;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "%s %s(%s)", $1.data, functionId, params);
										if(get_function(functionId) != NULL){
											yyerror("Semantic Error: Function is already declared!");
											exit(1);
										}
										add_function(functionId, param_types, param_count, $1.type);
										free(params);
									}

		| VOID function						{
										printf("PARSER: function_declaration Found!\n");
										struct string_list_node * current = $2.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $2.identifiers;
										struct integer_list_node * current_count = $2.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0, param_count = 0;
										struct string_and_type_list_node * current_param = $2.params;
										while(current_param != NULL){
											param_count++;
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										int * param_types = (int *) malloc(param_count * sizeof(int));
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $2.params;
										int i = 0;
										while(current_param != NULL){
											param_types[i++] = current_param->type;
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = strlen("void") + functionId_size + params_size + 4;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "void %s(%s)", functionId, params);
										if(get_function(functionId) != NULL){
											yyerror("Semantic Error: Function is already declared!");
											exit(1);
										}
										add_function(functionId, param_types, param_count, TYPE_VOID);
										free(params);
									}

		| VOID function IDENTIFIER				{
										printf("PARSER: function_declaration Found!\n");
										struct string_list_node * current = $2.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen($3) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $2.identifiers;
										struct integer_list_node * current_count = $2.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen($3) + 2) * sizeof(char));
										sprintf(temp, "%s%d", $3, (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										int params_size = 0, param_count = 0;
										struct string_and_type_list_node * current_param = $2.params;
										while(current_param != NULL){
											param_count++;
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										int * param_types = (int *) malloc(param_count * sizeof(int));
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $2.params;
										int i = 0;
										while(current_param != NULL){
											param_types[i++] = current_param->type;
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = strlen("void") + functionId_size + params_size + 4;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "void %s(%s)", functionId, params);
										if(get_function(functionId) != NULL){
											yyerror("Semantic Error: Function is already declared!");
											exit(1);
										}
										add_function(functionId, param_types, param_count, TYPE_VOID);
										free(params);
									}
		;


var_type
		: STRING						{
										printf("PARSER: var_type Found!\n");
										$$.data = "char*";
										$$.type = TYPE_STRING;
									}

		| NUMBER						{
										printf("PARSER: var_type Found!\n");
										$$.data = "double";
										$$.type = TYPE_NUMBER;
									}

		| BOOLEAN						{
										printf("PARSER: var_type Found!\n");
										$$.data = "int";
										$$.type = TYPE_NUMBER;
									}
		;


function
		: function IDENTIFIER params				{
										printf("PARSER: function Found!\n");
										struct string_list_node * current = $1.identifiers;
										while(current->next != NULL){
											current = current->next;
										}
										current->next = (struct string_list_node*) malloc(sizeof(struct string_list_node));
										current->next->data = $2;
										current->next->next = NULL;

										struct string_and_type_list_node* current_param = $1.params;
										while(current_param->next != NULL){
											current_param = current_param->next;
										}
										current_param->next = $3.params;
										struct integer_list_node* current_count = $1.param_count;
										while(current_count->next != NULL){
											current_count = current_count->next;
										}
										current_count->next = (struct integer_list_node*) malloc(sizeof(struct integer_list_node));
										current_count->next->data = $3.size;
										current_count->next->next = NULL;
										$$ = $1;
 									}

		| IDENTIFIER params					{
										printf("PARSER: function Found!\n");

										$$.identifiers = (struct string_list_node*) malloc(sizeof(struct string_list_node));
										$$.identifiers->data = $1;
										$$.identifiers->next = NULL;
										$$.params = $2.params;
										$$.param_count = (struct integer_list_node*) malloc(sizeof(struct integer_list_node));
										$$.param_count->data = $2.size;
										$$.param_count->next = NULL;
									}
		;

params
		: '(' param_list ')'					{
										printf("PARSER: params Found!\n");
										$$ = $2;
									}

		| '(' ')'						{
										printf("PARSER: params Found!\n");
										$$.params = NULL;
										$$.size = 0;
									}
		;

param_list
		: param_list ',' var_type IDENTIFIER			{
										printf("PARSER: param_list Found!\n");
										struct string_and_type_list_node * current = $1.params;
										while(current->next != NULL){
											current = current->next;
										}
										current->next = (struct string_and_type_list_node*) malloc(sizeof(struct string_and_type_list_node));
										current->next->next = NULL;
										int size = strlen($3.data) + strlen($4) + 2;
										current->next->data = (char*) malloc(size * sizeof(char));
										sprintf(current->next->data, "%s %s", $3.data, $4);
										current->next->type = $3.type;
										free($4);
										$1.size++;
										$$ = $1;
									}

		| var_type IDENTIFIER					{
										printf("PARSER: param_list Found!\n");
										$$.params = (struct string_and_type_list_node *) malloc(sizeof(struct string_and_type_list_node));
										$$.params->next = NULL;
										int size = strlen($1.data) + strlen($2) + 2;
										$$.params->data = (char*) malloc(size * sizeof(char));
										sprintf($$.params->data, "%s %s", $1.data, $2);
										free($2);
										$$.params->type = $1.type;
										$$.size = 1;
									}
		;


function_definition_block

		: FUNCTION function_definition '{'					{
												printf("SEMANTIC ANALYSER: setting scope level to 1\n");
												current_level = 1;
											}
		  statements '}'							{
												printf("PARSER: function_definition_block Found!\n");
												int size = strlen($2) + strlen($5) + 7;
												$$ = (char *) malloc(size * sizeof(char));
												sprintf($$, "%s\n{\n%s\n}\n", $2, $5);
												free($2);
												free($5);
												printf("SEMANTIC ANALYSER: deleting local symbols and decreasing scope level...\n");
												delete_symbols(current_level--);
											}

		| FUNCTION function_definition '{' '}'					{
												printf("PARSER: function_definition_block Found!\n");
												int size = strlen($2) + 6;
												$$ = (char *) malloc(size * sizeof(char));
												sprintf($$, "%s\n{\n}\n", $2);
												free($2);
											}
		;		
				


function_definition

		: var_type function					{
										printf("PARSER: function_definition Found!\n");
										struct string_list_node * current = $2.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $2.identifiers;
										struct integer_list_node * current_count = $2.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0;
										struct string_and_type_list_node * current_param = $2.params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL || function -> is_defined == 1){
											yyerror("Semantic Error: Function not found or it's already defined!");
											exit(1);
										}
										if(function->return_type != $1.type){
											yyerror("Semantic Error: Function return type does not match it's declaration!");
											exit(1);
										}
										int index = 0;
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $2.params;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function parameter types does not match it's declaration!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											char * oldParamName = strchr(current_param->data, ' ') + 1;
											char * newParamName = (char *) malloc((strlen(oldParamName) + 1) * sizeof(char));
											strcpy(newParamName, oldParamName);
											add_symbol(newParamName, current_param->type, current_level + 1);
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										function->is_defined = 1;
										int size = strlen($1.data) + functionId_size + params_size + 4;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "%s %s(%s)", $1.data, functionId, params);
										free(functionId);
										free(params);
									}

		| var_type function IDENTIFIER				{
										printf("PARSER: function_definition Found!\n");
										struct string_list_node * current = $2.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen($3) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $2.identifiers;
										struct integer_list_node * current_count = $2.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen($3) + 2) * sizeof(char));
										sprintf(temp, "%s%d", $3, (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										
										int params_size = 0;
										struct string_and_type_list_node * current_param = $2.params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL || function -> is_defined == 1){
											yyerror("Semantic Error: Function not found or it's already defined!");
											exit(1);
										}
										if(function->return_type != $1.type){
											yyerror("Semantic Error: Function return type does not match it's declaration!");
											exit(1);
										}
										int index = 0;
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $2.params;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function parameter types does not match it's declaration!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											char * oldParamName = strchr(current_param->data, ' ') + 1;
											char * newParamName = (char *) malloc((strlen(oldParamName) + 1) * sizeof(char));
											strcpy(newParamName, oldParamName);
											add_symbol(newParamName, current_param->type, current_level + 1);
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										function->is_defined = 1;
										int size = strlen($1.data) + functionId_size + params_size + 4;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "%s %s(%s)", $1.data, functionId, params);
										free(functionId);
										free(params);
									}

		| VOID function						{
										printf("PARSER: function_definition Found!\n");
										struct string_list_node * current = $2.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $2.identifiers;
										struct integer_list_node * current_count = $2.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0;
										struct string_and_type_list_node * current_param = $2.params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL || function -> is_defined == 1){
											yyerror("Semantic Error: Function not found or it's already defined!");
											exit(1);
										}
										if(function->return_type != TYPE_VOID){
											yyerror("Semantic Error: Function return type does not match it's declaration!");
											exit(1);
										}
										int index = 0;
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $2.params;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function parameter types does not match it's declaration!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											char * oldParamName = strchr(current_param->data, ' ') + 1;
											char * newParamName = (char *) malloc((strlen(oldParamName) + 1) * sizeof(char));
											strcpy(newParamName, oldParamName);
											add_symbol(newParamName, current_param->type, current_level + 1);
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										function->is_defined = 1;
										int size = strlen("void") + functionId_size + params_size + 4;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "void %s(%s)", functionId, params);
										free(functionId);
										free(params);
									}

		| VOID function IDENTIFIER				{
										printf("PARSER: function_definition Found!\n");
										struct string_list_node * current = $2.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen($3) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $2.identifiers;
										struct integer_list_node * current_count = $2.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(((struct string_list_node *)delete_temp)->data);
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen($3) + 2) * sizeof(char));
										sprintf(temp, "%s%d", $3, (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										
										int params_size = 0;
										struct string_and_type_list_node * current_param = $2.params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL || function -> is_defined == 1){
											yyerror("Semantic Error: Function not found or it's already defined!");
											exit(1);
										}
										if(function->return_type != TYPE_VOID){
											yyerror("Semantic Error: Function return type does not match it's declaration!");
											exit(1);
										}
										int index = 0;
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $2.params;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function parameter types does not match it's declaration!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											char * oldParamName = strchr(current_param->data, ' ') + 1;
											char * newParamName = (char *) malloc((strlen(oldParamName) + 1) * sizeof(char));
											strcpy(newParamName, oldParamName);
											add_symbol(newParamName, current_param->type, current_level + 1);
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										function->is_defined = 1;
										int size = strlen("void") + functionId_size + params_size + 4;
										$$ = (char *) malloc(size * sizeof(char));
										sprintf($$, "void %s(%s)", functionId, params);
										free(functionId);
										free(params);
									}
		;


	
statements
		: statements statement					{
										printf("PARSER: statements Found!\n");
										int size = strlen($1) + strlen($2) + 1;
										$$ = (char*) malloc(size * sizeof(char));
										$$[0] = '\0';
										strcpy($$, $1);
										strcat($$, $2);
										free($1);
										free($2);
 									}

		| statement						{
										printf("PARSER: statements Found!\n");
 										$$ = $1;
									}
		;





statement
		: '{'							{
										printf("SEMANTIC ANALYSER: setting scope level to %d\n", ++current_level);
									}
		  statements '}'					{
										printf("PARSER: statement Found!\n");
										int size = strlen($3) + 5;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "{\n%s}\n", $3);
										free($3);
										printf("SEMANTIC ANALYSER: deleting local symbols and decreasing scope level...\n");
										delete_symbols(current_level--);
									}


		| var_type IDENTIFIER ';'				{
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type($2);
										if(type != NOT_FOUND){
											yyerror("Semantic Error: Identifier is already defined!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($2) + 4;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "%s %s;\n", $1.data, $2);
										add_symbol($2, $1.type, current_level);
									}

		| var_type IDENTIFIER '[' NUMBER_LITERAL ']' ';'	{
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type($2);
										if(type != NOT_FOUND){
											yyerror("Semantic Error: Identifier is already defined!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($2) + strlen($4) + 20;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "%s %s[(unsigned int)%s];\n", $1.data, $2, $4);
										free($4);
										add_symbol($2, $1.type + ARRAY, current_level);
									}



		| WHILE '(' expression ')' while_statement		{
										printf("PARSER: statement Found!\n");
										if($3.type != TYPE_BOOLEAN){
											yyerror("Semantic Error: Expression type is not Boolean!");
											exit(1);
										}
										if($5[0] != '{'){
											yyerror("Syntax Error: while statements must be wrapped in \'{\' and \'}\' !");
											exit(1);
										}
										int size = strlen($3.data) + strlen($5) + 9;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "while(%s)\n%s", $3.data, $5);
										free($3.data);
										free($5);
									}

		| IF '(' expression ')' statement %prec IFX		{
										printf("PARSER: statement Found!\n");
										if($3.type != TYPE_BOOLEAN){
											yyerror("Semantic Error: Expression type is not Boolean!");
											exit(1);
										}
										if($5[0] != '{'){
											yyerror("Syntax Error: if statements must be wrapped in \'{\' and \'}\' !");
											exit(1);
										}
										int size = strlen($3.data) + strlen($5) + 6;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "if(%s)\n%s", $3.data, $5);
										free($3.data);
										free($5);
									}

		| IF '(' expression ')' statement ELSE statement	{
										printf("PARSER: statement Found!\n");
										if($3.type != TYPE_BOOLEAN){
											yyerror("Semantic Error: Expression type is not Boolean!");
											exit(1);
										}
										if($5[0] != '{' || $7[0] != '{'){
											yyerror("Syntax Error: if and else statements must be wrapped in \'{\' and \'}\' !");
											exit(1);
										}
										int size = strlen($3.data) + strlen($5) + strlen($7) + 12;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "if(%s)\n%s\nelse\n%s", $3.data, $5, $7);
										free($3.data);
										free($5);
										free($7);
									}

		| IDENTIFIER  '=' expression ';'			{
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type($1);
										if(type != $3.type){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										int size = strlen($1) + strlen($3.data) + 6;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "%s = %s;\n", $1, $3.data);
										free($1);
										free($3.data);
 									}

		| PRINT expression ';'					{
										printf("PARSER: statement Found!\n");
										int size = strlen($2.data) + 17;
										$$ = (char*) malloc(size * sizeof(char));
										if($2.type == TYPE_NUMBER){											
											sprintf($$, "printf(\"%%g\", %s);\n", $2.data);
										}
										if($2.type == TYPE_BOOLEAN){
											sprintf($$, "printf(\"%%d\", %s);\n", $2.data);
										}
										if($2.type == TYPE_STRING){
											sprintf($$, "printf(\"%%s\", %s);\n", $2.data);
										}
										free($2.data);
 									}

		| SCAN IDENTIFIER ';'					{
										printf("PARSER: statement Found!\n");
				 						int type = get_symbol_type($2);
										if(type != TYPE_NUMBER && type != TYPE_STRING){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										if(type == TYPE_NUMBER){
											int size = strlen($2) + 18;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "scanf(\"%%lf\", &%s);\n", $2);
										} else {
											int size = strlen($2) + 16;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "scanf(\"%%s\", %s);\n", $2);
										}
										free($2);
 									}

		| IDENTIFIER INC_OP ';'					{
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type($1);
										if(type != TYPE_NUMBER){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										int size = strlen($1) + 5;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "%s++;\n", $1);
										free($1);
 									}

		| IDENTIFIER DEC_OP ';'					{
										printf("PARSER: statement Found!\n");
										int type = get_symbol_type($1);
										if(type != TYPE_NUMBER){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
										}
										int size = strlen($1) + 5;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "%s--;\n", $1);
										free($1);
 									}

		| SUCCESSFUL EXIT ';'					{
										printf("PARSER: statement Found!\n");
										int size = 10;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "exit(0);\n");
 									}

		| FAILED EXIT ';'					{
										printf("PARSER: statement Found!\n");
										int size = 10;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "exit(1);\n");
 									}

		| function_call_statement ';'				{
										printf("PARSER: statement Found!\n");
										int size = strlen($1.data) + 3;
										$$ = (char*) malloc(size * sizeof(char));
										sprintf($$, "%s;\n", $1.data);
										free($1.data);
									}
		;



while_statement

		: '{'								{
											printf("SEMANTIC ANALYSER: setting scope level to %d\n", ++current_level);
										}
		  while_statements '}'						{
											printf("PARSER: while_statement Found!\n");
											int size = strlen($3) + 6;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "{\n%s}\n", $3);
											free($3);
											printf("SEMANTIC ANALYSER: deleting local symbols and decreasing scope level...\n");
											delete_symbols(current_level--);
										}


		| var_type IDENTIFIER ';'					{
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type($2);
											if(type != NOT_FOUND){
												yyerror("Semantic Error: Identifier is already defined!");
												exit(1);
											}
											int size = strlen($1.data) + strlen($2) + 4;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "%s %s;\n", $1.data, $2);
											add_symbol($2, $1.type, current_level);
										}

		| var_type IDENTIFIER '[' NUMBER_LITERAL ']' ';'		{
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type($2);
											if(type != NOT_FOUND){
												yyerror("Semantic Error: Identifier is already defined!");
												exit(1);
											}
											int size = strlen($1.data) + strlen($2) + strlen($4) + 20;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "%s %s[(unsigned int)%s];\n", $1.data, $2, $4);
											free($4);
											add_symbol($2, $1.type + ARRAY, current_level);
										}



		| WHILE '(' expression ')' while_statement			{
											printf("PARSER: while_statement Found!\n");
											if($3.type != TYPE_BOOLEAN){
												yyerror("Semantic Error: Expression type is not Boolean!");
												exit(1);
											}
											if($5[0] != '{'){
												yyerror("Syntax Error: while statements must be wrapped in \'{\' and \'}\' !");
												exit(1);
											}
											int size = strlen($3.data) + strlen($5) + 9;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "while(%s)\n%s", $3.data, $5);
											free($3.data);
											free($5);
										}

		| IF '(' expression ')' statement %prec IFX			{
											printf("PARSER: while_statement Found!\n");
											if($3.type != TYPE_BOOLEAN){
												yyerror("Semantic Error: Expression type is not Boolean!");
												exit(1);
											}
											if($5[0] != '{'){
												yyerror("Syntax Error: if statements must be wrapped in \'{\' and \'}\' !");
												exit(1);
											}
											int size = strlen($3.data) + strlen($5) + 6;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "if(%s)\n%s", $3.data, $5);
											free($3.data);
											free($5);
										}

		| IF '(' expression ')' statement ELSE statement		{
											printf("PARSER: while_statement Found!\n");
											if($3.type != TYPE_BOOLEAN){
												yyerror("Semantic Error: Expression type is not Boolean!");
												exit(1);
											}
											if($5[0] != '{' || $7[0] != '}'){
												yyerror("Syntax Error: if and else statements must be wrapped in \'{\' and \'}\' !");
												exit(1);
											}
											int size = strlen($3.data) + strlen($5) + strlen($7) + 12;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "if(%s)\n%s\nelse\n%s", $3.data, $5, $7);
											free($3.data);
											free($5);
											free($7);
										}


		| IDENTIFIER  '=' expression ';'				{
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type($1);
											if(type != $3.type){
												yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
											}
											int size = strlen($1) + strlen($3.data) + 6;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "%s = %s;\n", $1, $3.data);
											free($1);
											free($3.data);
 										}


		| PRINT expression ';'						{
											printf("PARSER: while_statement Found!\n");
											int size = strlen($2.data) + 17;
											$$ = (char*) malloc(size * sizeof(char));
											if($2.type == TYPE_NUMBER){											
												sprintf($$, "printf(\"%%g\", %s);\n", $2.data);
											}
											if($2.type == TYPE_BOOLEAN){
												sprintf($$, "printf(\"%%d\", %s);\n", $2.data);
											}
											if($2.type == TYPE_STRING){
												sprintf($$, "printf(\"%%s\", %s);\n", $2.data);
											}
											free($2.data);
 										}

		| SCAN IDENTIFIER ';'						{
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type($2);
											if(type != TYPE_NUMBER && type != TYPE_STRING){
												yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
											}
											if(type == TYPE_NUMBER){
												int size = strlen($2) + 18;
												$$ = (char*) malloc(size * sizeof(char));
												sprintf($$, "scanf(\"%%lf\", &%s);\n", $2);
											} else {
												int size = strlen($2) + 16;
												$$ = (char*) malloc(size * sizeof(char));
												sprintf($$, "scanf(\"%%s\", %s);\n", $2);
											}
											free($2);
 										}

		| IDENTIFIER INC_OP ';'						{
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type($1);
											if(type != TYPE_NUMBER){
												yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
											}
											int size = strlen($1) + 5;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "%s++;\n", $1);
											free($1);
 										}

		| IDENTIFIER DEC_OP ';'						{
											printf("PARSER: while_statement Found!\n");
											int type = get_symbol_type($1);
											if(type != TYPE_NUMBER){
												yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
												exit(1);
											}
											int size = strlen($1) + 5;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "%s--;\n", $1);
											free($1);
 										}

		| BREAK ';'							{
											printf("PARSER: while_statement Found!\n");
											int size = 8;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "break;\n");
 										}

		| CONTINUE ';'							{
											printf("PARSER: while_statement Found!\n");
											int size = 11;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "continue;\n");
 										}

		| SUCCESSFUL EXIT ';'						{
											printf("PARSER: while_statement Found!\n");
											int size = 10;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "exit(0);\n");
 										}
	
		| FAILED EXIT ';'						{
											printf("PARSER: while_statement Found!\n");
											int size = 10;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "exit(1);\n");
 										}

		| function_call_statement ';'					{
											printf("PARSER: while_statement Found!\n");
											int size = strlen($1.data) + 3;
											$$ = (char*) malloc(size * sizeof(char));
											sprintf($$, "%s;\n", $1.data);
											free($1.data);
										}
		;



while_statements

		: while_statements while_statement				{
											printf("PARSER: while_statements Found!\n");
											int size = strlen($1) + strlen($2) + 1;
											$$ = (char*) malloc(size * sizeof(char));
											$$[0] = '\0';
											strcpy($$, $1);
											strcat($$, $2);
 										}

		| while_statement						{
											printf("PARSER: while_statements Found!\n");
											$$ = $1;
										}
		;
 

expression
		: expression '+' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 4;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s + %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_NUMBER;
									}

		| expression '-' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 4;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s - %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_NUMBER;
									}

		| expression '*' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 4;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s * %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_NUMBER;
									}

		| expression '/' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 4;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s / %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_NUMBER;
									}

		| expression '%' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 14;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "(int)%s %% (int)%s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_NUMBER;
									}

		| IDENTIFIER INC_OP					{
										printf("PARSER: expression Found!\n");
										int type = get_symbol_type($1);
										if(type != TYPE_NUMBER){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										int size = strlen($1) + 3;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s++", $1);
										free($1);
										$$.type = TYPE_NUMBER;
 									}

		| IDENTIFIER DEC_OP					{
										printf("PARSER: expression Found!\n");
										int type = get_symbol_type($1);
										if(type != TYPE_NUMBER){
											yyerror("Semantic Error: Identifier is undefined or it's type is incompatible!");
											exit(1);
										}
										int size = strlen($1) + 3;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s--", $1);
										free($1);
										$$.type = TYPE_NUMBER;
 									}

		| expression '>' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 4;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s > %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_BOOLEAN;
									}

		| expression '<' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 4;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s < %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_BOOLEAN;
									}

		| expression '&' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_BOOLEAN && $3.type == TYPE_BOOLEAN)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 5;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s && %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_BOOLEAN;
									}

		| expression '|' expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_BOOLEAN && $3.type == TYPE_BOOLEAN)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 5;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s || %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_BOOLEAN;
									}

		| expression EQ_OP expression				{
										printf("PARSER: expression Found!\n");
										if(!(($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)||($1.type == TYPE_BOOLEAN && $3.type == TYPE_BOOLEAN))){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 5;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s == %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_BOOLEAN;
									}

		| expression GE_OP expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 5;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s >= %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_BOOLEAN;
									}

		| expression LE_OP expression				{
										printf("PARSER: expression Found!\n");
										if(!($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 5;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s <= %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_BOOLEAN;
									}

		| expression NE_OP expression				{
										printf("PARSER: expression Found!\n");
										if(!(($1.type == TYPE_NUMBER && $3.type == TYPE_NUMBER)||($1.type == TYPE_BOOLEAN && $3.type == TYPE_BOOLEAN))){
											yyerror("Semantic Error: Expression types are incompatible!");
											exit(1);
										}
										int size = strlen($1.data) + strlen($3.data) + 5;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s != %s", $1.data, $3.data);
										free($1.data);
										free($3.data);
										$$.type = TYPE_BOOLEAN;
									}

		| '-' expression %prec UNARY_MINUS			{
										printf("PARSER: expression Found!\n");
										if($2.type != TYPE_NUMBER){
											yyerror("Semantic Error: Expression type is not number!");
											exit(1);
										}
										int size = strlen($2.data) + 2;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "-%s", $2.data);
										free($2.data);
										$$.type = $2.type;
									}

		| IDENTIFIER '[' expression ']'				{
										printf("PARSER: expression Found!\n");
										int type = get_symbol_type($1);
										if(type != TYPE_STRING_ARRAY && type != TYPE_NUMBER_ARRAY && type != TYPE_BOOLEAN_ARRAY){
											yyerror("Semantic Error: Identifier is not an array!");
											exit(1);
										}
										if($3.type != TYPE_NUMBER){
											yyerror("Semantic Error: Expression type is not number!");
											exit(1);
										}
										
										$$.type = type - ARRAY;
										int size = strlen($1) + strlen($3.data) + 19;
										$$.data = (char*) malloc(size * sizeof(char));
										sprintf($$.data, "%s[(unsigned int)(%s)]", $1, $3.data);
										free($1);
										free($3.data);
									}

		| IDENTIFIER						{
										printf("PARSER: expression Found!\n");
										int type = get_symbol_type($1);
										if(type == NOT_FOUND){
											yyerror("Semantic Error: Identifier is undefined!");
											exit(1);
										}
										$$.type = type;
										$$.data = $1;
									}

		| NUMBER_LITERAL					{
										printf("PARSER: expression Found!\n");
										$$.data = $1;
										$$.type = TYPE_NUMBER;
									}

		| STRING_LITERAL					{
										printf("PARSER: expression Found!\n");
										$$.data = $1;
										$$.type = TYPE_STRING;
									}

		| TRUE_LITERAL						{
										printf("PARSER: expression Found!\n");
										$$.data = $1;
										$$.type = TYPE_BOOLEAN;
									}

		| FALSE_LITERAL						{
										printf("PARSER: expression Found!\n");
										$$.data = $1;
										$$.type = TYPE_BOOLEAN;
									}

		| function_call_statement				{
										printf("PARSER: expression Found!\n");
										int type = get_function_return_type($1.name);
										if(type == TYPE_VOID || type == NOT_FOUND){
											yyerror("Semantic Error: Function not found or it's type is void!");
											exit(1);
										}
										$$.type = type;
										$$.data = $1.data;
									}
		;




function_call_statement

		: function_call						{
										printf("PARSER: function_call_statement Found!\n");
										struct string_list_node * current = $1.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp;
										current = $1.identifiers;
										struct integer_list_node * current_count = $1.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										int params_size = 0;
										struct string_and_type_list_node * current_param = $1.params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL){
											yyerror("Semantic Error: Function is not declared!");
											exit(1);
										}
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $1.params;
										int index = 0;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function arguments does not match it's declared parameter types!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = functionId_size + params_size + 4;
										$$.data = (char *) malloc(size * sizeof(char));
										sprintf($$.data, "%s(%s)", functionId, params);
										$$.name = functionId;
										free(params);
									}

		| function_call IDENTIFIER				{
										printf("PARSER: function_call_statement Found!\n");
										struct string_list_node * current = $1.identifiers;
										void * delete_temp = NULL;
										int functionId_size = 0;
										while(current != NULL){
											functionId_size += strlen(current->data) + 2;
											current = current->next;
										}
										functionId_size += strlen($2) + 2;
										char * functionId = (char *) malloc(functionId_size * sizeof(char));
										functionId[0] = '\0';
										char * temp = NULL;
										current = $1.identifiers;
										struct integer_list_node * current_count = $1.param_count;
										while(current != NULL){
											temp = (char *) malloc((strlen(current->data) + 2) * sizeof(char));
											sprintf(temp, "%s%d", current->data, (current_count != NULL) ? current_count->data : 0);
											strcat(functionId, temp);
											delete_temp = current;
											current = current->next;
											free(delete_temp);
											delete_temp = current_count;
											current_count = current_count->next;
											free(delete_temp);
											free(temp);
										}
										temp = (char *) malloc((strlen($2) + 2) * sizeof(char));
										sprintf(temp, "%s%d", $2, (current_count != NULL) ? current_count->data : 0);
										strcat(functionId, temp);
										free(temp);
										int params_size = 0;
										struct string_and_type_list_node * current_param = $1.params;
										while(current_param != NULL){
											params_size += strlen(current_param->data) + 2;
											current_param = current_param->next;
										}
										struct function_node * function = get_function(functionId);
										if(function == NULL){
											yyerror("Semantic Error: Function is not declared!");
											exit(1);
										}
										char * params = (char *) malloc(params_size * sizeof(char));
										params[0] = '\0';
										current_param = $1.params;
										int index = 0;
										while(current_param != NULL){
											if(index == function->param_count || function->param_types[index++] != current_param->type){
												yyerror("Semantic Error: Function arguments does not match it's declared parameter types!");
												exit(1);
											}
											strcat(params, current_param->data);
											if(current_param->next != NULL){
												strcat(params, ", ");
											}
											delete_temp = current_param;
											current_param = current_param->next;
											free(((struct string_and_type_list_node *)delete_temp)->data);
											free(delete_temp);
										}
										int size = functionId_size + params_size + 3;
										$$.data = (char *) malloc(size * sizeof(char));
										sprintf($$.data, "%s(%s)", functionId, params);
										$$.name = functionId;
										free(params);
									}
		;

function_call
		: function_call IDENTIFIER args				{
										printf("PARSER: function_call Found!\n");										
										struct string_list_node * current = $1.identifiers;
										while(current->next != NULL){
											current = current->next;
										}
										current->next = (struct string_list_node*) malloc(sizeof(struct string_list_node));
										current->next->data = $2;
										current->next->next = NULL;

										struct string_and_type_list_node * current_param = $1.params;
										while(current_param->next != NULL){
											current_param = current_param->next;
										}
										current_param->next = $3.params;
										struct integer_list_node* current_count = $1.param_count;
										while(current_count->next != NULL){
											current_count = current_count->next;
										}
										current_count->next = (struct integer_list_node*) malloc(sizeof(struct integer_list_node));
										current_count->next->data = $3.size;
										current_count->next->next = NULL;
 									}

		| IDENTIFIER args					{
										printf("PARSER: function_call Found!\n");
										$$.identifiers = (struct string_list_node*) malloc(sizeof(struct string_list_node));
										$$.identifiers->data = $1;
										$$.identifiers->next = NULL;
										$$.params = $2.params;
										$$.param_count = (struct integer_list_node*) malloc(sizeof(struct integer_list_node));
										$$.param_count->data = $2.size;
										$$.param_count->next = NULL;
									}
		;

args
		: '(' arg_list ')'					{
										printf("PARSER: args Found!\n");
										$$ = $2;
									}

		| '(' ')'						{
										printf("PARSER: args Found!\n");
										$$.params = NULL;
										$$.size = 0;
									}
		;

arg_list
		: arg_list ',' expression				{
										printf("PARSER: arg_list Found!\n");
										struct string_and_type_list_node * current = $1.params;
										while(current->next != NULL){
											current = current->next;
										}
										current->next = (struct string_and_type_list_node *) malloc(sizeof(struct string_and_type_list_node));
										current->next->next = NULL;
										current->next->data = $3.data;
										current->next->type = $3.type;
										$1.size++;
										$$ = $1;
									}

		| expression						{
										printf("PARSER: arg_list Found!\n");
										$$.params = (struct string_and_type_list_node *) malloc(sizeof(struct string_and_type_list_node));
										$$.params->next = NULL;
										$$.params->data = $1.data;
										$$.params->type = $1.type;
										$$.size = 1;
									}
		;


		
%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

void add_symbol(char * name, int type, int level){
	struct symbol_node * temp = (struct symbol_node *) malloc(sizeof(struct symbol_node));
	temp->name = name;
	temp->type = type;
	temp->scope_level = level;
	temp->next = symbol_list;
	symbol_list = temp;
}

void delete_symbols(int level){
	struct symbol_node * temp;
	while(symbol_list != NULL && symbol_list->scope_level == level){
		temp = symbol_list->next;
		free(symbol_list->name);
		free(symbol_list);
		symbol_list = temp;
	}
}

int get_symbol_type(char * name){
	struct symbol_node * list = symbol_list;
	while(list != NULL){
		if(strcmp(list->name, name) == 0){
			return list->type;
		}
		list = list->next;
	}
	return NOT_FOUND;
}

void add_function(char * name, int * param_types, int param_count, int return_type){
	struct function_node * temp = (struct function_node *) malloc(sizeof(struct function_node));
	temp->name = name;
	temp->param_types = param_types;
	temp->param_count = param_count;
	temp->return_type = return_type;
	temp->is_defined = 0;
	temp->next = function_list;
	function_list = temp;
}

int get_function_return_type(char * name){
	struct function_node * list = function_list;
	while(list != NULL){
		if(strcmp(list->name, name) == 0){
			return list->return_type;
		}
		list = list->next;
	}
	return NOT_FOUND;
}


struct function_node * get_function(char * name){
	struct function_node * list = function_list;
	while(list != NULL){
		if(strcmp(list->name, name) == 0){
			return list;
		}
		list = list->next;
	}
	return NULL;
}


int main(int argc, char **argv) {
	if(argc != 3){
		printf("Error: bad arguments!\nThis compiler compiles an input file to C language!\nUSAGE: compiler [input_file_name] [output_file_name]\n");
		return 1;
	}
	yyin = fopen(argv[1], "r");
	if(yyin == NULL){
		printf("Error:\tCan't open input file!\n");
		return 1;
	}
	output = fopen(argv[2], "w");
	if(yyin == NULL){
		printf("Error:\tCan't open output file!\n");
		return 1;
	}
	yyparse();
	return 0;
}
