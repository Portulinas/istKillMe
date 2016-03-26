%{
/* $Id: TLLParser.y,v 1.49 2012-05-18 17:42:09 ist169643 Exp $ */
/*
 * $Log: TLLParser.y,v $
 * Revision 1.49  2012-05-18 17:42:09  ist169643
 * yacc updated
 *
 * Revision 1.47  2012-05-17 13:30:40  ist169643
 * yacc updated
 *
 * Revision 1.46  2012-05-16 22:02:04  ist169643
 * yacc updated
 *
 * Revision 1.45  2012-05-16 18:22:37  ist169643
 * *** empty log message ***
 *
 * Revision 1.44  2012-05-16 08:34:21  ist169643
 * *** empty log message ***
 *
 * Revision 1.43  2012-05-15 17:31:33  ist169643
 * yacc
 *
 * Revision 1.42  2012-05-15 17:30:23  ist169643
 * *** empty log message ***
 *
 * Revision 1.41  2012-05-15 17:09:18  ist169643
 * *** empty log message ***
 *
 * Revision 1.40  2012-05-15 16:04:51  ist169643
 * stuff
 *
 * Revision 1.39  2012-05-15 11:07:18  ist169643
 * *** empty log message ***
 *
 * Revision 1.38  2012-05-14 18:08:18  ist169643
 * yacc and lex updated
 *
 * Revision 1.37  2012-05-14 11:21:20  ist169643
 * *** empty log message ***
 *
 * Revision 1.36  2012-05-14 09:50:24  ist169643
 * *** empty log message ***
 *
 * Revision 1.35  2012-05-13 21:28:55  ist169643
 * *** empty log message ***
 *
 * Revision 1.34  2012-05-13 12:49:58  ist169643
 * *** empty log message ***
 *
 * Revision 1.33  2012-05-13 11:06:59  ist169643
 * *** empty log message ***
 *
 * Revision 1.32  2012-05-13 10:25:31  ist169643
 * read node Moved
 *
 * Revision 1.31  2012-05-12 11:18:25  ist169643
 * Expression types added
 * types node removed
 *
 * Revision 1.30  2012-05-10 15:40:55  ist169643
 * instrusction can be blocks now
 *
 * Revision 1.29  2012-05-10 11:04:44  ist169643
 * lex and yacc updated
 *
 * Revision 1.28  2012-05-09 08:55:34  ist169643
 * *** empty log message ***
 *
 * Revision 1.27  2012-05-05 16:21:47  ist169643
 * *** empty log message ***
 *
 * Revision 1.25  2012-05-02 08:44:53  ist169643
 * *** empty log message ***
 *
 * Revision 1.24  2012-04-20 10:50:54  ist169643
 * *** empty log message ***
 *
 * Revision 1.23  2012-04-20 10:33:21  ist169643
 * *** empty log message ***
 *
 * Revision 1.22  2012-04-20 10:25:40  ist169643
 * yy  updated
 *
 * Revision 1.21  2012-04-20 10:03:32  ist169643
 * *** empty log message ***
 *
 * Revision 1.20  2012-04-20 08:27:50  ist169643
 * updated
 *
 * Revision 1.19  2012-04-20 07:22:32  ist169643
 * FINALY!
 *
 * Revision 1.18  2012-04-19 16:37:50  ist169643
 * asd
 *
 * Revision 1.17  2012-04-19 15:40:00  ist169643
 * wweeeee
 *
 * Revision 1.16  2012-04-19 13:59:13  ist169643
 * asdsa
 *
 * Revision 1.15  2012-04-19 13:44:03  ist169630
 * TLLParser changed
 *
 * Revision 1.14  2012-04-19 13:24:48  ist169630
 * yacc changed
 *
 * Revision 1.13  2012-04-19 12:44:43  ist169630
 * functioncallnode fixed
 *
 * Revision 1.12  2012-04-19 12:30:30  ist169630
 * functioncallnode moved to expressions
 *
 * Revision 1.11  2012-04-19 09:47:22  ist169643
 * yacc flex and some nodes updated
 *
 * Revision 1.10  2012-04-19 01:00:47  ist169643
 * yacc updated
 *
 * Revision 1.9  2012-04-18 22:01:26  ist169643
 * flex updated
 *
 * Revision 1.8  2012-04-17 22:45:27  uid169643
 * more stuff
 *
 * Revision 1.7  2012-04-17 17:05:03  ist169643
 * *** empty log message ***
 *
 * Revision 1.6  2012-04-16 17:33:16  uid169643
 * FLEX WEEE
 *
 * Revision 1.5  2012-04-15 16:27:07  ist169643
 * weeee
 *
 * Revision 1.4  2012-04-14 16:32:45  ist169643
 * very nasty things done here...
 *
 * Revision 1.3  2012-04-14 09:59:48  ist169643
 * ProgramNode and Identity deleted and some bugs fixed
 *
 * Revision 1.2  2012-03-29 18:06:29  ist169643
 * está organizado!!!
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.13  2012/02/18 19:37:58  david
 * Updated TLL to support the new semantic analysis in CDK7.
 * Debug options are now integrated with semantic analysis, eliminating a long-lived
 * hack in the evaluators. Renamed Symbol to TLLSymbol, to emphasize
 * that it is language-specific.
 *
 * Revision 1.12  2011/03/07 02:27:04  david
 * Added simple left value for read and assignment operations.
 *
 * Revision 1.11  2009/03/15 19:21:14  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.10  2009/03/02 17:40:19  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.9  2009/02/20 06:04:35  david
 * TLL in new version. The new CDK is independent from particular
 * tools (such as Flex and BYACC). Must adapt. This is the first version
 * and will probably change.
 *
 * Revision 1.8  2008/03/01 18:32:48  david
 * TLL for CDK3 (first version).
 *
 * Revision 1.6  2007/03/14 01:20:20  david
 * Changed compiler implementation to use evaluation strategy objects
 * instead of functions. These strategies are selected according to the
 * target selected from the command line options or from clues such as
 * the output file extension.
 *
 * Revision 1.5  2007/03/13 00:26:19  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 *
 * Revision 1.4  2006/03/19 21:46:50  david
 * Miscellaneous corrections to i/o streams.
 *
 * Revision 1.2  2006/01/03 18:10:46  david
 * Evaluators are now defined separately from the parser.
 */
#include <cstdlib>  // needed for getenv
#include <iostream>
#include <string>
#include "syntax/FlexBYACC.h"
#include "nodes/all.h"

#define LINE scanner()->lineno()

// The rules below will be included in the function yyparse, the main
// parsing function. The macro below will cause the function to become
// a method instead. This is very fragile, but works with byacc.
// The class is FlexBYACC, a cdk::Parser subclass for the Flex+BYACC
// toolset.
#define yyparse tll::syntax::FlexBYACC::yyparse

#include "semantics/ExpressionType.h"


%}

%union {
  int                                i;	/* integer value */
  float								 r; /* real value */
  std::string                       *s;	/* symbol name or string literal */
  cdk::node::Node                   *node;	/* node pointer */
  cdk::node::Sequence               *sequence;
  cdk::node::expression::Expression *expression; /* expression nodes */
  ExpressionType					*expressiontype; /*types*/	
  tll::node::BlockNode				*block;		
};

%token <i> tINTEGER
%token <r> tREAL
%token <s> tIDENTIFIER tSTRING
%token tWHILE tFOR tDO tIF tREAD tEND tUSE tPUBLIC tRETURN tNEXT tSTOP 
%token tTYPEINT tTYPEREAL tTYPESTRING tVOID tUNTIL tMINUS tPLUS tPOS tMUL tDIV
%token tTHEN tELSIF tSTART_BLOCK tEND_BLOCK tLITREAL tLITINT tLITSTR tENDLINE tELSE

%nonassoc tWHX tDOX tIFX tBLOCKS
%nonassoc tIFEX
%nonassoc tELSE
%nonassoc tELSIF
%right '='
%left '|'
%left '&'
%right '~'
%left tPN '!'
%left tEQ tNE 
%left tGE tLE '>' '<' 
%left tPO
%left '+' '-' 
%left '*' '/' '%'
%right '^'
%nonassoc tUMINUS '#' '?'


%type <s> string
%type <node> stmt decl funct var elsif
%type <sequence> file list varlist qualif fret listd exprlist
%type <expression> expr literal
%type <block> block
%type <expressiontype> type spectype 

%%



file	: decl listd
		{
		_compiler->ast(new cdk::node::Sequence(LINE, $1, $2));
		}
		;

decl: var					{$$ = $1;}
	| funct					{$$ = $1;}
	;
	 
var:	 qualif type tIDENTIFIER '=' expr        {
         $$ = new tll::node::VariableNode(LINE, $2,new cdk::node::expression::Identifier(LINE,$3), $5);
        }
        |type tIDENTIFIER '=' expr        {
         $$ = new tll::node::VariableNode(LINE, $1,new cdk::node::expression::Identifier(LINE,$2), $4);
        }
		| type tIDENTIFIER { $$ = new tll::node::VariableNode(LINE, $1 ,new cdk::node::expression::Identifier(LINE,$2), NULL); } 
		;
		
type	: tTYPEINT		{$$ = new ExpressionType(4,ExpressionType::TYPE_INT);}
		| tTYPEREAL		{$$ = new ExpressionType(8,ExpressionType::TYPE_DOUBLE);}
		| tTYPESTRING	{$$ =  new ExpressionType(4, ExpressionType::TYPE_STRING);}
		| spectype		{$$ = $1;}
		;
		
		/*Definition*/
funct	: qualif type tIDENTIFIER '(' varlist ')' fret  {$$ = new tll::node::FunctionDefNode(LINE, $1, $2, new cdk::node::expression::Identifier(LINE,$3), $5,NULL, $7 );}
		| qualif type tIDENTIFIER '(' varlist ')' fret  block { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, $1, $2, new cdk::node::expression::Identifier(LINE,$3), $5, $8,$7);}
		|qualif type tIDENTIFIER '(' varlist ')'  block { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, $1, $2, new cdk::node::expression::Identifier(LINE,$3), $5, $7,NULL); }
		| type tIDENTIFIER '(' varlist ')' fret  { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, NULL, $1, new cdk::node::expression::Identifier(LINE,$2), $4,NULL, $6 );}
		|  type tIDENTIFIER '(' varlist ')' fret  block { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, NULL, $1, new cdk::node::expression::Identifier(LINE,$2), $4, $7,$6); }
		| type tIDENTIFIER '(' varlist ')'  block { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, NULL, $1, new cdk::node::expression::Identifier(LINE,$2), $4, $6,NULL); }
		/*void*/
		|qualif tVOID tIDENTIFIER '(' varlist ')' fret  {$$ = new tll::node::FunctionDefNode(LINE, $1, new ExpressionType(0,ExpressionType::TYPE_VOID) , new cdk::node::expression::Identifier(LINE,$3), $5,NULL, $7 );}
		| qualif tVOID tIDENTIFIER '(' varlist ')' fret  block { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, $1, new ExpressionType(0,ExpressionType::TYPE_VOID), new cdk::node::expression::Identifier(LINE,$3), $5, $8,$7); }
		|qualif tVOID tIDENTIFIER '(' varlist ')'  block { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, $1, new ExpressionType(0,ExpressionType::TYPE_VOID), new cdk::node::expression::Identifier(LINE,$3), $5, $7,NULL); }
		| tVOID tIDENTIFIER '(' varlist ')' fret  { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, NULL, new ExpressionType(0,ExpressionType::TYPE_VOID), new cdk::node::expression::Identifier(LINE,$2), $4,NULL, $6 );}
		|  tVOID tIDENTIFIER '(' varlist ')' fret  block { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, NULL, new ExpressionType(0,ExpressionType::TYPE_VOID), new cdk::node::expression::Identifier(LINE,$2), $4, $7,$6); }
		| tVOID tIDENTIFIER '(' varlist ')'  block { /*Definition*/$$ = new tll::node::FunctionDefNode(LINE, NULL, new ExpressionType(0,ExpressionType::TYPE_VOID), new cdk::node::expression::Identifier(LINE,$2), $4, $6,NULL); }
		
		/*Declaration*/
		| qualif type tIDENTIFIER '(' varlist ')'  {$$ = new tll::node::FunctionDeclNode(LINE, $1,$2,new cdk::node::expression::Identifier(LINE,$3), $5 );}
		|type tIDENTIFIER '(' varlist ')'  { $$ = new tll::node::FunctionDeclNode(LINE, NULL,$1 ,new cdk::node::expression::Identifier(LINE,$2), $4 );}
		/*void*/
		| qualif tVOID tIDENTIFIER '(' varlist ')'  {$$ = new tll::node::FunctionDeclNode(LINE, $1,new ExpressionType(0,ExpressionType::TYPE_VOID),new cdk::node::expression::Identifier(LINE,$3), $5 );}
		|tVOID tIDENTIFIER '(' varlist ')'  { $$ = new tll::node::FunctionDeclNode(LINE, NULL,new ExpressionType(0,ExpressionType::TYPE_VOID) ,new cdk::node::expression::Identifier(LINE,$2), $4 );}		
		;
		

qualif	: tPUBLIC 	{ $$ = new cdk::node::Sequence(LINE, new tll::node::PublicNode(LINE));}
		| tUSE	  	{ $$ = new cdk::node::Sequence(LINE, new tll::node::UseNode(LINE));}
		;
		
		

		
spectype: '<' tTYPEINT '>' 		{ $$ =  new ExpressionType(4,  ExpressionType::TYPE_CONST,  new ExpressionType(4, ExpressionType::TYPE_INT));}
		| '<' tTYPEREAL '>' 	{  $$ =  new ExpressionType(4, ExpressionType::TYPE_CONST, new ExpressionType(8, ExpressionType::TYPE_DOUBLE));}
		| '<' tTYPESTRING '>' 	{  $$ =  new ExpressionType(4, ExpressionType::TYPE_CONST, new ExpressionType(4, ExpressionType::TYPE_STRING));}
		| '<' spectype '>' 		{ $$ =  new ExpressionType(4,  ExpressionType::TYPE_CONST, $2);}
		
		| '[' tTYPEINT ']'	{ $$ =  new ExpressionType(4, ExpressionType::TYPE_POINTER, new ExpressionType(4, ExpressionType::TYPE_INT));}
		| '[' tTYPEREAL ']'	{  $$ =  new ExpressionType(4, ExpressionType::TYPE_POINTER, new ExpressionType(8, ExpressionType::TYPE_DOUBLE));} 
		| '[' tTYPESTRING ']'	{  $$ =  new ExpressionType(4, ExpressionType::TYPE_POINTER, new ExpressionType(4, ExpressionType::TYPE_STRING));}
		| '[' spectype ']'	{ $$ =  new ExpressionType(4, ExpressionType::TYPE_POINTER, $2); } 
		;
		
fret	: '=' literal  	{ $$ = new cdk::node::Sequence(LINE,$2);} 
		;
	


literal	: tREAL		{ $$ = new cdk::node::expression::Double(LINE, $1);}
		| tINTEGER		{ $$ = new cdk::node::expression::Integer(LINE, $1);}
		| string		{$$ = new cdk::node::expression::String(LINE, $1); }
		;
		
string	: tSTRING			{ $$ = $1; }
		| string tSTRING    { *$$ =(*$1 += *$2);}
		;
		

block	: tSTART_BLOCK  decl listd tENDLINE stmt list tEND_BLOCK	{$$ = new tll::node::BlockNode(LINE, new cdk::node::Sequence(LINE, $2, $3), new cdk::node::Sequence(LINE, $5, $6));}
		| tSTART_BLOCK  decl listd tEND_BLOCK       {$$ = new tll::node::BlockNode(LINE, new cdk::node::Sequence(LINE, $2, $3), NULL);}
		| tSTART_BLOCK  stmt list tEND_BLOCK		{$$ = new tll::node::BlockNode(LINE, new cdk::node::Sequence(LINE, $2, $3),NULL);}
		| tSTART_BLOCK tEND_BLOCK		{$$ = new tll::node::BlockNode(LINE, NULL,NULL);}
		;
		
listd: /*Epslon */		/*decl tENDLINE				{ $$ = new cdk::node::Sequence(LINE, $1); }*/
	 | listd  tENDLINE decl 		{ $$ = new cdk::node::Sequence(LINE, $3, $1); } 
	;       
				
		
stmt	: expr tPN			{ $$ = new tll::node::PrintNode(LINE, $1, true); }
 		| expr '!'   		{ $$ = new tll::node::PrintNode(LINE, $1, false); }
        | expr					{$$ = $1;}
        | tWHILE  expr tDO stmt   %prec tWHX	{ $$ = new tll::node::instructions::WhileNode(LINE, $2, $4); }
		| tWHILE  expr tDO stmt  tELSE stmt  	{ $$ = new tll::node::instructions::WhileElseNode(LINE, $2, $4, $6); }
        | tFOR	 expr ';' expr ';' expr	tDO stmt	{ $$ = new tll::node::instructions::ForNode(LINE, $2, $4, $6, $8); }
        | tFOR	 varlist ';' expr ';' expr	tDO stmt{ $$ = new tll::node::instructions::ForVarNode(LINE, $2, $4, $6, $8); }
        | tDO	stmt tUNTIL expr 	%prec tDOX				 { $$ = new tll::node::instructions::DoNode(LINE, $2, $4); }
        | tDO	stmt tUNTIL expr tELSE stmt { $$ = new tll::node::instructions::DoElseNode(LINE, $2, $4, $6); }      
        | block				     	{$$ = $1;}/*next stop return*/
        | tRETURN					{$$ = new tll::node::instructions::ReturnNode(LINE);}
        | tNEXT 					{$$ = new tll::node::instructions::NextNode(LINE);}
        | tSTOP						{$$ = new tll::node::instructions::NextNode(LINE);}
        | tNEXT tINTEGER			{$$ = new tll::node::instructions::NextNode(LINE, $2);}
        | tSTOP tINTEGER			{$$ = new tll::node::instructions::NextNode(LINE, $2);}
        | tIF  expr tTHEN  stmt %prec tIFX 		{ $$ = new tll::node::instructions::IfNode(LINE, $2, $4); }
        | tIF  expr tTHEN  stmt tELSE stmt 		{ $$ = new tll::node::instructions::IfElseNode(LINE, $2, $4, $6); }
        | tIF  expr tTHEN  stmt elsif  			{ $$ = new tll::node::instructions::IfElseNode(LINE, $2, $4, $5); }
        ;
        
elsif	: tELSIF expr tTHEN stmt elsif {$$ = new tll::node::instructions::IfElseNode(LINE, $2, $4, $5); }
		| tELSIF expr tTHEN stmt %prec tIFX  {$$ = new tll::node::instructions::IfNode(LINE, $2, $4);} 	
		| tELSIF expr tTHEN stmt tELSE stmt {$$ = new tll::node::instructions::IfElseNode(LINE, $2, $4, $6);} 	 	
		;




varlist	: var	    	  { $$ = new cdk::node::Sequence(LINE, $1); } 
	    | varlist ',' var { $$ = new cdk::node::Sequence(LINE, $3, $1); }
	    | /*epslon*/
	    ;
	    
exprlist : exprlist ',' expr {$$ = new cdk::node::Sequence(LINE, $3,$1);}
	 	 | expr		         {$$ = new cdk::node::Sequence(LINE,$1);}
	 	 | /*epslon*/
	 	 ;

		
list	: /*Epslon*/   			  /*  { $$ = new cdk::node::Sequence(LINE, $1); }*/
		| list tENDLINE  stmt   { $$ = new cdk::node::Sequence(LINE, $3, $1); }
	    ;
	    	    

expr : tINTEGER 	            { $$ = new cdk::node::expression::Integer(LINE, $1); }
	 | tIDENTIFIER '=' expr		{$$ = new tll::node::AssignmentNode(LINE, new tll::node::expression::LeftValue(LINE, $1), $3);}
	 | tREAL					{ $$ = new cdk::node::expression::Double(LINE, $1); }
	 | string					{ $$ = new cdk::node::expression::String(LINE, $1); }
     | tIDENTIFIER             	{ $$ = new cdk::node::expression::Identifier(LINE, $1); }
     | '+' expr %prec tUMINUS	{$$ = $2;}
     | '-' expr %prec tUMINUS  	{ $$ = new cdk::node::expression::NEG(LINE, $2); }
     | expr '?' 			   	{ $$ = new tll::node::expression::POS(LINE, $1); }
     | expr '+' expr	       	{ $$ = new cdk::node::expression::ADD(LINE, $1, $3); }
     | expr '-' expr	       	{ $$ = new cdk::node::expression::SUB(LINE, $1, $3); }
     | expr '*' expr	       	{ $$ = new cdk::node::expression::MUL(LINE, $1, $3); }
     | expr '/' expr	       	{ $$ = new cdk::node::expression::DIV(LINE, $1, $3); }
     | expr '%' expr	       	{ $$ = new cdk::node::expression::MOD(LINE, $1, $3); }
     | expr '<' expr	       	{ $$ = new cdk::node::expression::LT(LINE, $1, $3); }
     | expr '>' expr	       	{ $$ = new cdk::node::expression::GT(LINE, $1, $3); }
     | expr tGE expr	       	{ $$ = new cdk::node::expression::GE(LINE, $1, $3); }
     | expr tLE expr           	{ $$ = new cdk::node::expression::LE(LINE, $1, $3); }
     | expr tNE expr	       	{ $$ = new cdk::node::expression::NE(LINE, $1, $3); }
     | expr tEQ expr	       	{ $$ = new cdk::node::expression::EQ(LINE, $1, $3); }
     | expr '|' expr			{ $$ = new tll::node::expression::OR(LINE, $1, $3);}
     | expr '&' expr			{ $$ =  new tll::node::expression::AND(LINE, $1, $3);}
     | '(' expr ')'			 	{$$ = $2;}
     | '@'   {$$ = new tll::node::expression::ReadNode(LINE);} 
     | expr '^' expr	        { $$ = new tll::node::expression::POT(LINE, $1, $3); }
     /*Call*/
     | tIDENTIFIER '(' exprlist ')'  { $$ = new tll::node::expression::FunctionCallNode( LINE, new cdk::node::expression::Identifier(LINE,$1), $3);}
   	 | '@' '=' expr				{ $$ = new tll::node::AssignmentNode(LINE, new tll::node::expression::LeftValue(LINE, "@"), $3);} 
     | '@' '(' exprlist ')'	    {$$ = new tll::node::expression::FunctionCallNode(LINE, new cdk::node::expression::Identifier(LINE,"@"), $3);}
     | tIDENTIFIER '[' expr ']'	   { $$ = new tll::node::expression::IndexNode(LINE, /*$1,*/ $3); } /*na da vector de vector*/
     | tIDENTIFIER '[' expr ']' '=' expr { $$ = new tll::node::expression::IndexNode(LINE, /*$1,*/ $3); } /*na da vector de vector*/
     | '#' expr  			{ $$ = new tll::node::expression::MEM(LINE, $2); }
     ;

%%
