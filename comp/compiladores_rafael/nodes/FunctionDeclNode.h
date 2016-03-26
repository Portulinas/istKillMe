/*
 * FunctionDeclNode.h
 *
 *  Created on: Apr 10, 2012
 *      Author: klang
 */

#ifndef FUNCTIONDECLNODE_H_
#define FUNCTIONDECLNODE_H_

#include <cdk/nodes/Node.h>
#include "semantics/ExpressionType.h"
namespace tll {
namespace node {

class FunctionDeclNode: public cdk::node::Node {
private:
	cdk::node::Sequence *_qualifier;
	ExpressionType *_type;
	cdk::node::expression::Identifier *_ident;
	cdk::node::Sequence *_var;
public:
   inline FunctionDeclNode(int lineno, cdk::node::Sequence *qualifier,ExpressionType *type,cdk::node::expression::Identifier *ident,
		   cdk::node::Sequence *var) :cdk::node::Node(lineno), _type(type), _ident(ident), _var(var) {
	  // tipo|void identificador variaveis[aka argumentos]
   }

 public:
   const char *name() {
     return "tll::node::FunctionDeclaration";
   }

   cdk::node::Sequence *qualifier(){
	   return _qualifier;
   }

   ExpressionType *type(){
	   return _type;
   }

   cdk::node::expression::Identifier *ident(){
	  return  _ident;
   }

   cdk::node::Sequence *var(){
	   return _var;
   }


   void accept(SemanticProcessor *sp, int level) {
     sp->processFunctionDeclNode(this, level);
   }

};

} /* namespace node */
} /* namespace tll */
#endif /* FUNCTIONDECLNODE_H_ */
