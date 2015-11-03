%{
	#include "y.tab.h"
	#include <stdlib.h>
	#include <stdio.h>
	void yyerror(char *);
%}

%%


"boolean"                                        {
 							printf("LEXER: BOOLEAN Found!\n");
							return BOOLEAN;
						}

"number"                                        {
 							printf("LEXER: NUMBER Found!\n");
							return NUMBER;
						}

"string"                                        {
							printf("LEXER: STRING Found!\n");
							return STRING;
						}

"void"                                        	{
							printf("LEXER: VOID Found!\n");
							return VOID;
						}

"true"                                        	{
							printf("LEXER: TRUE_LITERAL Found!\n");
							yylval.string = (char*) malloc(2 * sizeof(char));
							yylval.string[0] = '1';
							yylval.string[1] = '\0';
							return TRUE_LITERAL;
						}

"false"                                        	{
							printf("LEXER: FALSE_LITERAL Found!\n");
							yylval.string = (char*) malloc(2 * sizeof(char));
							yylval.string[0] = '0';
							yylval.string[1] = '\0';
							return FALSE_LITERAL;
						}

"function"					{
							printf("LEXER: FUNCTION Found!\n");
							return FUNCTION;
						}

"while"                                         {
							printf("LEXER: WHILE Found!\n");
							return WHILE;
						}

"if"                                            {
							printf("LEXER: IF Found!\n");
							return IF;
						}

"else"                                          {
							printf("LEXER: ELSE Found!\n");
							return ELSE;
						}

"print"						{
							printf("LEXER: PRINT Found!\n");
							return PRINT;
						}

"scan"						{	
							printf("LEXER: SCAN Found!\n");
							return SCAN;
						}

"break"						{
							printf("LEXER: BREAK Found!\n");
							return BREAK;
						}

"continue"					{
							printf("LEXER: CONTINUE Found!\n");
							return CONTINUE;
						}

"successful"					{
							printf("LEXER: SUCCESSFUL Found!\n");
							return SUCCESSFUL;
						}

"failed"					{
							printf("LEXER: FAILED Found!\n");
							return FAILED;
						}

"exit"						{
							printf("LEXER: EXIT Found!\n");
							return EXIT;
						}

[a-zA-Z][a-zA-Z0-9]*                            {
							char * newStr = (char*) malloc((strlen(yytext) + 1) * sizeof(char));
							strcpy(newStr, yytext);
							yylval.string = newStr;
							printf("LEXER: IDENTIFIER %s Found!\n", yytext);
							return IDENTIFIER;
						}
[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?   	       	{
							char * newStr = (char*) malloc((strlen(yytext) + 1) * sizeof(char));
							strcpy(newStr, yytext);
							yylval.string = newStr;
							printf("LEXER: NUMBER_LITERAL %s Found!\n", yytext);
							return NUMBER_LITERAL;
						}
\"(\\.|[^\\"])*\"                               {
							char * newStr = (char*) malloc((strlen(yytext) + 1) * sizeof(char));
							strcpy(newStr, yytext);
							yylval.string = newStr;
							printf("LEXER: STRING_LITERAL %s Found!\n", yytext);
                                                        return STRING_LITERAL;
						}

"=="						{
							printf("LEXER: EQ_OP Found!\n");
							return EQ_OP;
						}

">="						{
							printf("LEXER: GE_OP Found!\n");
							return GE_OP;
						}

"<="						{
							printf("LEXER: LE_OP Found!\n");
							return LE_OP;
						}

"!="						{
							printf("LEXER: NE_OP Found!\n");
							return NE_OP;
						}

"++"						{
							printf("LEXER: INC_OP Found!\n");
							return INC_OP;
						}

"--"						{
							printf("LEXER: DEC_OP Found!\n");
							return DEC_OP;
						}

[-+*><\[\]{}|^()/=;&%!,]                        {
							printf("LEXER: \'%s\' Found!\n", yytext);
							return *yytext;
						}

[ \t]+                                          ;	// ignore whitespaces

"//"[^\r\n]*(\r|\n)				;	// ignore comments
			
.                                               yyerror("Unknown character");
%%

int yywrap(void){
	return 1;
}
