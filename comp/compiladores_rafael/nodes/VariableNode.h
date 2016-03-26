/*
 * Variavel.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef __TLL_VARIABLENODE_H__
#define __TLL_VARIABLENODE_H__

#include <string>
#include <cdk/nodes/Node.h>
#include "nodes/QualifierNode.h"
#include <cdk/nodes/expressions/Expression.h>
#include <cdk/nodes/expressions/Identifier.h>
#include "semantics/ExpressionType.h"
#include <cdk/nodes/expressions/Expression.h>
namespace tll {
namespace node {

class VariableNode: public cdk::node::Node {
	ExpressionType * _type;
	std::string* _name;//fixme ta mali
	cdk::node::Sequence * _qualifier;
	cdk::node::expression::Identifier* _ident;
	cdk::node::Sequence * _expr;
	cdk::node::expression::Expression *_init;
public:
   inline VariableNode(int lineno, ExpressionType *type ,cdk::node::expression::Identifier* ident, cdk::node::expression::Expression *init) :
   cdk::node::Node(lineno),_type(type) ,_ident(ident), _init(init) {

   }

 public:
   const char *name() {
     return "tll::node::Variable";
   }

   void accept(SemanticProcessor *sp, int level) {
     sp->processVariableNode(this, level);
   }
   cdk::node::expression::Expression *init(){
	   return _init;
   }
   cdk::node::expression::Identifier* identifier(){
	   return _ident;
   }
   ExpressionType* type(){
	   return _type;
   }

};

} /* namespace node */
} /* namespace tll */
#endif /* __TLL_VARIAVEL_H__ */
