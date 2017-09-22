SABAA is a compiler for a C based language with the folowing syntax:
 
******************************************************************* Introduction *******************************************************************

Code file consists of 3 parts :

function declarations
main code
function definitions

NOTE:
	1- There is no main function!
	2- main code is one or more statement.
	3- Each statement must end with semicolon.


********************************************************************** Types **********************************************************************

This language has only 3 types: number, string, boolean

-------------------------------------------------------------------------------------------------------------------------------------------------------

Number:

the keyword "number" represents the type "double" in c.


-------------------------------------------------------------------------------------------------------------------------------------------------------

String:

the keyword "string" represents the type "char*" in c.

-------------------------------------------------------------------------------------------------------------------------------------------------------

Boolean:

the keyword "boolean" is for declaring a boolean that can either be "true" or "false".


******************************************************************** Statements ********************************************************************

Variable Decleration:

syntax:

	type_name identifier;

		Declares identifier as a variable of type type_name.

	type identifier[number_literal];

		Declares identifier as an array of type type_name and size of number_literal.

NOTE:
	number_literal for size of the array will be converted to unsigned int.

-------------------------------------------------------------------------------------------------------------------------------------------------------
Loop & Conditions:

Loop:		while(expression) {statements}

conditions:	if(expression) {statements}

		if(expression) {statements} else {statements}

NOTE:
	1- Type of the expression must be boolean(unlike C, there is no implicit conversion to boolean).
	2- note that braces are mandatory! (unlike C)
	3- there is also "break" and "continue" keywords which work just like in the C language.
-------------------------------------------------------------------------------------------------------------------------------------------------------
I/O:

"print" keyword is for printing a string or an expression to standard output stream.
"scan" keyword is for reading a number or a string from standard input stream.

examples:
	scan variable;
	print expression;

-------------------------------------------------------------------------------------------------------------------------------------------------------
Exit:

This keyword can be used to terminate program!

syntax:
	failed exit;

		terminates program and report that program failed.
	
	succesful exit;

 		terminates program and report that program was successfully ended.

********************************************************************** Function **********************************************************************


function declaration syntax:

	function ReturnType identifier(type pram,type param,...)identifier(type param,...)...;
OR
	function ReturnType identifier(type pram,type param,...)identifier(type param,...)...(type param,...);


function definition syntax:

	function ReturnType identifier(type pram,type param,...)identifier(type param,...)...identifier { statements }
OR
	function ReturnType identifier(type pram,type param,...)identifier(type param,...)...(type param,...) { statements }

function call syntax:

	identifier(expression, ...)identifier(expression, ...)...identifer;
OR
	identifier(expression, ...)identifier(expression, ...)...(expression, ...);


NOTE:

	1-The number of identifiers and parameter list is unlimited, however the number of parameters in each parameter list is limited to 99.
	2-The end of the function can either be an identifier or a parameter(or argument) list.
	3-the keyword "function" should be writen before the return type.
	4-Each function must be declared before main code and defined after it.


****************************************************************** Allowed Operators ******************************************************************

==, +, -, *, /, =, ++, --, !, &, |, !=

NOTE:
	1- & and | operators are equivalent to && and || in the C language.

	2- other operators work just like in the C language.

************************************************************************ Scope ************************************************************************

Scope of variables in this language is just like the C language.

*********************************************************************** Comment ***********************************************************************

"//" can be used to comment a single line.


*******************************************************************************************************************************************************

Designed & implemented by: azad gandomi, sara karimi, amir mohamadi bagha, aidin rasti, benyamin hejazi.
