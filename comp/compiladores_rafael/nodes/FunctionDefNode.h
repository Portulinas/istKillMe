/*
 * Function.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef __TLL_FUNCTIONNODE_H__
#define __TLL_FUNCTIONNODE_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Identifier.h>
#include <cdk/nodes/Sequence.h>
#include "nodes/QualifierNode.h"
#include "nodes/VariableNode.h"

#include "nodes/BlockNode.h"
#include "semantics/ExpressionType.h"
namespace tll {
namespace node {

class FunctionDefNode : public cdk::node::Node {
cdk::node::Sequence *_qualifier;
ExpressionType *_type;
cdk::node::expression::Identifier *_ident;
cdk::node::Sequence *_var;
tll::node::BlockNode *_body;
cdk::node::Sequence *_defaultReturn;
public:
   inline FunctionDefNode(int lineno, cdk::node::Sequence *qualifier ,ExpressionType *type,cdk::node::expression::Identifier *ident,
		   cdk::node::Sequence *var,tll::node::BlockNode *body, cdk::node::Sequence *defaultReturn )
   	   	   :cdk::node::Node(lineno), _qualifier(qualifier), _type(type), _ident(ident), _var(var), _body(body) , _defaultReturn(defaultReturn) {

	   //]qualificador] (tipo|void) identificador [variaveis] [literal equivale a retorno por omissao] [corpo]
   }

 public:
   const char *name() {
     return "tll::node::FunctionDefinition";
   }

   cdk::node::Sequence *qualifier(){
	   return _qualifier;
   }

   ExpressionType *type(){
	   return _type;
   }

   cdk::node::expression::Identifier *ident(){
	   return _ident;
   }

   cdk::node::Sequence *var(){
	   return _var;
   }

   tll::node::BlockNode *body(){
	   return _body;
   }

   cdk::node::Sequence *defaultReturn(){
	   return _defaultReturn;
   }


   void accept(SemanticProcessor *sp, int level) {

     sp->processFunctionDefNode(this, level);

   }
};

} /* namespace node */
} /* namespace tll */
#endif /* __TLL_FUNCTIONNODE_H__ */
