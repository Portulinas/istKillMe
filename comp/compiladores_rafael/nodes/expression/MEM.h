/*
 * MEM.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef MEM_H_
#define MEM_H_

#include <cdk/nodes/expressions/UnaryExpression.h>
#include <cdk/nodes/expressions/Expression.h>
namespace tll {
namespace node {
namespace expression {

class MEM: public cdk::node::expression::UnaryExpression {
cdk::node::expression::Expression *_arg;
public:
	inline MEM(int lineno, Expression *arg) :
			UnaryExpression(lineno, arg) {
		_arg = arg;/*check later*/
		type(new ExpressionType());	}

public:
	/**
	 * @return the name of the node's class
	 */
	const char *name() const {
		return "cdk::node::expression::MEM";
	}
	inline cdk::node::expression::Expression *argument() {
		return _arg;
	}

	/**
	 * @param sp semantic processor visitor
	 * @param level syntactic tree level
	 */
	virtual void accept(SemanticProcessor *sp, int level) {
		sp->processMEM(this, level);
	}

};
} /* namespace expression */
} /* namespace node */
} /* namespace tll */
#endif /* MEM_H_ */
