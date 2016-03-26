/*
 * InvocationNode.h
 *
 *  Created on: Mar 29, 2012
 *      Author: klang
 */

#ifndef INVOCATIONNODE_H_
#define INVOCATIONNODE_H_
#include <cdk/nodes/expressions/Expression.h>
#include <cdk/nodes/expressions/Identifier.h>

namespace tll {
namespace node {
namespace expression {

class InvocationNode : public cdk::node::expression::Expression {
	cdk::node::expression::Identifier *_ident;
public:
			inline InvocationNode(int lineno, cdk::node::expression::Identifier *ident) :
				Expression(lineno), _ident(ident) {
				type(new ExpressionType());				}


		public:
		/**
		 * @return the name of the node's class
		 */
			const char *name() const {
				return "tll::node::expression::InvocationNode";
			}

			const cdk::node::expression::Identifier *ident() {
				return _ident;

			}

		/**
		 * @param sp semantic processor visitor
		 * @param level syntactic tree level
		 */
		void accept(SemanticProcessor *sp, int level){
				 sp->processInvocationNode(this, level);
			   }


};

} /* namespace expression */
} /* namespace node */
} /* namespace tll */
#endif /* INVOCATIONNODE_H_ */
