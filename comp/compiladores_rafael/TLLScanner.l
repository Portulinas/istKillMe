%option c++ yyclass="TLLScanner" outfile="TLLScanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
/* $Id: TLLScanner.l,v 1.35 2012-05-17 21:16:52 ist169643 Exp $ */
/*
 * $Log: TLLScanner.l,v $
 * Revision 1.35  2012-05-17 21:16:52  ist169643
 * *** empty log message ***
 *
 * Revision 1.34  2012-05-17 16:24:07  ist169643
 * lex updated
 *
 * Revision 1.33  2012-05-15 23:08:42  ist169643
 * *** empty log message ***
 *
 * Revision 1.32  2012-05-15 10:27:11  ist169643
 * *** empty log message ***
 *
 * Revision 1.31  2012-05-14 18:08:18  ist169643
 * yacc and lex updated
 *
 * Revision 1.30  2012-05-14 11:21:20  ist169643
 * *** empty log message ***
 *
 * Revision 1.29  2012-05-14 09:50:24  ist169643
 * *** empty log message ***
 *
 * Revision 1.28  2012-05-13 21:28:55  ist169643
 * *** empty log message ***
 *
 * Revision 1.27  2012-05-13 10:25:31  ist169643
 * read node Moved
 *
 * Revision 1.26  2012-05-12 11:18:25  ist169643
 * Expression types added
 * types node removed
 *
 * Revision 1.25  2012-05-10 11:04:44  ist169643
 * lex and yacc updated
 *
 * Revision 1.24  2012-05-09 08:55:34  ist169643
 * *** empty log message ***
 *
 * Revision 1.23  2012-05-05 16:10:09  ist169643
 * a lot was uptodate
 *
 * Revision 1.22  2012-05-05 09:39:38  ist169643
 * *** empty log message ***
 *
 * Revision 1.21  2012-05-02 09:13:26  ist169630
 * teca teca
 *
 * Revision 1.20  2012-05-02 08:44:53  ist169643
 * *** empty log message ***
 *
 * Revision 1.19  2012-04-20 10:03:32  ist169643
 * *** empty log message ***
 *
 * Revision 1.18  2012-04-20 08:27:49  ist169643
 * updated
 *
 * Revision 1.17  2012-04-20 07:40:15  uid169630
 * cmments fixed in lex
 *
 * Revision 1.16  2012-04-20 07:22:32  ist169643
 * FINALY!
 *
 * Revision 1.15  2012-04-19 15:40:00  ist169643
 * wweeeee
 *
 * Revision 1.14  2012-04-19 13:59:13  ist169643
 * asdsa
 *
 * Revision 1.13  2012-04-19 09:47:24  ist169643
 * yacc flex and some nodes updated
 *
 * Revision 1.12  2012-04-19 01:53:49  ist169643
 * reals finished [we hope so...]
 *
 * Revision 1.11  2012-04-19 01:42:33  ist169630141
 * *** empty log message ***
 *
 * Revision 1.10  2012-04-19 01:00:47  ist169643
 * yacc updated
 *
 * Revision 1.9  2012-04-19 00:57:58  ist169630
 * Lex almost there
 *
 * Revision 1.8  2012-04-18 22:01:26  ist169643
 * flex updated
 *
 * Revision 1.7  2012-04-18 20:23:02  ist169643
 * flex updated
 *
 * Revision 1.6  2012-04-17 22:45:27  uid169643
 * more stuff
 *
 * Revision 1.5  2012-04-17 17:05:03  ist169643
 * *** empty log message ***
 *
 * Revision 1.4  2012-04-16 17:33:16  uid169643
 * FLEX WEEE
 *
 * Revision 1.3  2012-04-14 16:32:47  ist169643
 * very nasty things done here...
 *
 * Revision 1.2  2012-04-14 10:29:17  ist169643
 * adada
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.11  2011/03/07 02:27:04  david
 * Added simple left value for read and assignment operations.
 *
 * Revision 1.10  2009/03/15 19:21:14  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.9  2009/03/02 20:16:14  david
 * Corrected stupid recursion bug.
 *
 * Revision 1.7  2009/02/20 06:04:35  david
 * TLL in new version. The new CDK is independent from particular
 * tools (such as Flex and BYACC). Must adapt. This is the first version
 * and will probably change.
 *
 * Revision 1.6  2008/03/01 18:32:48  david
 * TLL for CDK3 (first version).
 *
 * Revision 1.4  2007/03/14 01:20:20  david
 * Changed compiler implementation to use evaluation strategy objects
 * instead of functions. These strategies are selected according to the
 * target selected from the command line options or from clues such as
 * the output file extension.
 *
 * Revision 1.3  2007/03/13 00:26:19  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 *
 * Revision 1.2  2006/04/03 18:11:38  david
 * Added debug settings to flex files.
 */

#include <iostream>
#include <string>
#include <cdk/nodes/Node.h>
#include <cdk/nodes/Sequence.h>
#include <cdk/nodes/expressions/Expression.h>
#include "TLLScanner.h"
#include <cmath>
// ensure that relevant includes are made before including the following
#include "TLLParser.tab.h"
#include <map>
#include <vector>

static std::vector<int> Ident; /*para a identacao*/
int Nid; /*numero de espaços do nível*/
static int Nspaces=0; /*numero de espaços*/



std::string string; /*para strings*/
float num=0;
float dig=0;
float expo=0;
bool newline = false;
bool jaLeu = false;
std::map<char, int> mapEng;
// this is terrible, but Flex's but C++ lexers are crap...
#define yyerror LexerError
#define NUMBTAB 8
%}
%x X_STRING X_COMMENT X_COMMENT1 X_ENG X_ENGA X_BLOCK X_CONT
ENG 	[yzafpnumkMGPEZY]
DIG		[[:digit:]]
EXA 	[[:xdigit:]]
OCTO	[0-7]
%%
					  { set_debug(1); } 
					

\t					{if(Nspaces%8 != 0)
						Nspaces = Nspaces - Nspaces%8 + 8;
					else
						Nspaces += 8;}
						
" "					Nspaces++;

\n 					{Nspaces=0;
						if(jaLeu){
						newline = true;}
						}
						
"//"				yy_push_state(X_COMMENT);			
\{             		{yy_push_state(X_COMMENT1);
						//std::cout<< "comentário" << std::endl;
						}
						
<<EOF>>				{  // std::cout<< " EOF EOF EOF EOF EOF" << std::endl << "WWEEEEEEEEEEEEEEEEEEEE" << std::endl;
						if(!Ident.empty()){
						//std::cout << "OLAAA" << std::endl;
						//std::cout << Ident.size() << std::endl;
						Ident.pop_back();
						return tEND_BLOCK;
						}
						//std::cout << Ident.size() << std::endl;
						//std::cout << "FIIIIM" << std::endl;
						
						return 0;
					}						
	
.					{	
						//std::cout << "LEU" << std::endl;
						jaLeu = true;
						
						yyless(0);
						if(Ident.empty() && Nspaces == 0){
							if(newline && jaLeu){
								newline = false;
								yy_push_state(X_BLOCK);
								return tENDLINE;
							}
							
							yy_push_state(X_BLOCK);
						}

						
						
						else{
							
							if(!Ident.empty()  && Nspaces < Ident.back() ){
								//std::cout << "segundo" << std::endl;
								Ident.pop_back();
								return tEND_BLOCK;
								} 					    
							if(!Ident.empty()  && Nspaces == Ident.back()){
								newline = false;
							//	std::cout << "NAO TE QUIERO" << std::endl;
								yy_push_state(X_BLOCK);
								//nao manda o endline se antes houve um endblock! 
								return tENDLINE;
								}
							

								
							if(!Ident.empty() && Nspaces > Ident.back()){
								yy_push_state(X_BLOCK);	
								//std::cout << "terceiro" << std::endl;	
								Ident.push_back(Nspaces);
								//std::cout << Ident.size() << std::endl;
								return tSTART_BLOCK;
								}
							if(Nspaces > 0){
								yy_push_state(X_BLOCK);
								//std::cout << "Ultimo   " <<Nspaces<< "   --  "  << std::endl;
								Ident.push_back(Nspaces);
								//std::cout << Ident.size() << std::endl;
								return tSTART_BLOCK;
							}
						
						}				
						}	
					



<X_BLOCK>\\\n			; /*une linhas logicas*/
<X_BLOCK>\n				{yy_pop_state();			/*falta fim da linha logica*/
						newline = true;
						Nspaces=0;
					}		

<X_BLOCK>">="			return tGE;
<X_BLOCK>"<="			return tLE;
<X_BLOCK>"=="			return tEQ;
<X_BLOCK>"<>"			return tNE;
<X_BLOCK>"!!"			return tPN;


<X_BLOCK>"while"		return tWHILE;
<X_BLOCK>"for"			return tFOR;
<X_BLOCK>"do"			return tDO;
<X_BLOCK>"until"		return tUNTIL;
<X_BLOCK>"int"			return tTYPEINT;
<X_BLOCK>"real"			return tTYPEREAL;
<X_BLOCK>"string"		return tTYPESTRING;
<X_BLOCK>"public"		return tPUBLIC;
<X_BLOCK>"use"			return tUSE;
<X_BLOCK>"next"			return tNEXT;
<X_BLOCK>"stop"			return tSTOP;
<X_BLOCK>"return"		return tRETURN;
<X_BLOCK>"if"			return tIF; 
<X_BLOCK>"else"			return tELSE; 
<X_BLOCK>"end"			return tEND;
<X_BLOCK>"void"			return tVOID;
<X_BLOCK>"then"			return tTHEN;
<X_BLOCK>"elsif"		return tELSIF;



<X_BLOCK>\"		{yy_push_state(X_STRING);
					string.clear();}
<X_STRING>\\\"  	{string += '"';} /*Amanda[loira de olhos azuis] só " */
<X_STRING>\\\\		{string += '\\';} /*Amanda[loira de olhos azuis] só \ */
<X_STRING>\\n		{string += '\n';} /*Amanda[loira de olhos azuis] só \n */
<X_STRING>\\t		{string += '\t';} /*Amanda[loira de olhos azuis] só \t */
<X_STRING>\\r		{string += '\r';} /*Amanda[loira de olhos azuis] só \r */
<X_STRING>\\{EXA}{1,2}        { string+= strtol(yytext, NULL, 16);}
					/*<X_STRING>\"([ \t]*('\'\n)?[ \t]*)*\"		; */ /*concatena strings consecutivas!*/
<X_STRING>\"    	{string += '\0';
					yylval.s = &string;
					yy_pop_state(); /*Amanda a string*/
					return tSTRING;
					}
<X_STRING>\0		yyerror("NULL '\0' in string");
<X_STRING>.     	{string += *yytext;} /*come come come come*/
    				/*<X_STRING>\n yyerror("newline in string");*/ /*em construção casos especiais podem tar?*/

<X_BLOCK>"//"			yy_push_state(X_COMMENT);
<X_COMMENT>\n			{yyless(0);
						yy_pop_state();
						Nspaces = 0;
						if(jaLeu)
							newline = true;
						}
<X_COMMENT>.			; /*Ignora ^^*/

<X_BLOCK>\{             yy_push_state(X_COMMENT1);
<X_COMMENT1>\{ 			yy_push_state(X_COMMENT1);
<X_COMMENT1>\} 			yy_pop_state();	
<X_COMMENT1>.|\n		;


<X_BLOCK>[ \t]*			; /*ignora espaços weee*/
<X_BLOCK>[_A-Za-z][A-Za-z0-9_]*  	{ yylval.s = new std::string(yytext); return tIDENTIFIER; }
<X_BLOCK>\'[^']*\'		       	{ yytext[yyleng-1] = 0; yylval.s = new std::string(yytext+1); return tSTRING; }
<X_BLOCK>0b[01]+			   		{ yylval.i = strtol(yytext, NULL, 2); return tINTEGER; }/*base 2*/
<X_BLOCK>0[0-7]+			   		{ yylval.i = strtol(yytext, NULL, 8); return tINTEGER; }/*base 8*/
<X_BLOCK>[0-9]+ 			       	{ yylval.i = strtol(yytext, NULL, 10); return tINTEGER; }/*base 10*/
<X_BLOCK>0x{EXA}+		 		{ yylval.i = strtol(yytext, NULL, 16); return tINTEGER; }/*base 16*/

<X_BLOCK>(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*)|([0-9]+))([eE][-]?[0-9]+)? {yylval.r = strtod(yytext, NULL); return tREAL;}

<X_BLOCK>[0-9]+{ENG}				/*why god why?*/
						{yyless(0);
						yy_push_state(X_ENG); 
						}						
<X_ENG>[0-9]+			{num=strtod(yytext, NULL);}
<X_ENG>{ENG}			{switch(yytext[0]) {
								case 'y':
								    expo = -24;
								    break;
								case 'z':
								    expo = -21;
								    break;
								case 'a':
								    expo = -18;
								    break;
								case 'f':
								    expo = -15;
								    break;
								case 'p':
								    expo = -12;
								    break;
								case 'n':
								    expo = -9;
								    break;
								case 'u':
								    expo = -6;
								    break;
								case 'm':
								    expo = -3;
								    break;
								case 'k':
								    expo = 3;
								    break;
								case 'M':
								    expo = 6;
								    break;
								case 'G':
								    expo = 9;
								    break;
								case 'P':
								    expo = 15;
								    break;
								case 'Z':
								    expo = 21;
								    break;
								case 'Y':
								    expo = 24;
								    break;
								}    
						yy_push_state(X_ENGA);}
						
<X_ENGA>[0-9]+			{dig=strtod(yytext, NULL); dig= dig*pow(10, -yyleng);
						 num += dig;
						 yylval.r = num*pow(10, expo);
						 num = dig = expo = 0; /*mete variaveis a 0*/
						 yy_pop_state();
						 yy_pop_state();
						 }
		
		
		
<X_BLOCK>[-()<>=+*/%;#^|&~\[\]\?,!@]	   	return *yytext; 



<X_BLOCK>.			yyerror("Unknown character");
%%
/** Very, very dirty hack: flex is a mess generating C++.*/

int TLLScanner::yywrap() { return 1;}




