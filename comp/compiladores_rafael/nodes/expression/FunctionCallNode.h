/*
 * FunctionCallNode.h
 *
 *  Created on: Apr 10, 2012
 *      Author: klang
 */

#ifndef FUNCTIONCALLNODE_H_
#define FUNCTIONCALLNODE_H_

#include <cdk/nodes/expressions/Expression.h>
#include <cdk/nodes/Sequence.h>
#include "nodes/VariableNode.h"
#include <cdk/nodes/expressions/Identifier.h>
//TODO change to Expressions
namespace tll {
namespace node {
namespace expression {

class FunctionCallNode: public  cdk::node::expression::Expression {
	cdk::node::expression::Identifier *_ident;
	cdk::node::Sequence *_var; //sequence of arguments
public:
   inline FunctionCallNode(int lineno, cdk::node::expression::Identifier *ident ,cdk::node::Sequence *var):
   cdk::node::expression::Expression(lineno), _ident(ident), _var(var) {
	   type(new ExpressionType());   }

 public:
   const char *name() {
     return "tll::node::FunctionCall";
   }
   inline cdk::node::Sequence* var() {
   			return _var;
   		}

   inline cdk::node::expression::Identifier* ident(){
	   return _ident;
   }

   void accept(SemanticProcessor *sp, int level) {
    // sp->processFunctionCallNode(this, level);
   }
};
} /*namespace expression*/
} /* namespace node */
} /* namespace tll */
#endif /* FUNCTIONCALLNODE_H_ */
