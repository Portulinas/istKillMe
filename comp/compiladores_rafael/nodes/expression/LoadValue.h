/*
 * LoadValue.h
 *
 *  Created on: Apr 10, 2012
 *      Author: klang
 */

#ifndef LOADVALUE_H_
#define LOADVALUE_H_
#include <cdk/nodes/expressions/Simple.h>
#include <string>
#include "SemanticProcessor.h"

namespace tll {
namespace node {
namespace expression {

class LoadValue: public cdk::node::expression::Simple<std::string> {
public:
	inline LoadValue(int lineno, const char *s) :
			cdk::node::expression::Simple<std::string>(lineno, s) {
		type(new ExpressionType());	}
	inline LoadValue(int lineno, const std::string &s) :
			cdk::node::expression::Simple<std::string>(lineno, s) {
		type(new ExpressionType());	}
	inline LoadValue(int lineno, const std::string *s) :
			cdk::node::expression::Simple<std::string>(lineno, *s) {
		type(new ExpressionType());	}
public:
	/**
	 * @return the name of the node's class
	 */
	const char *name() const {
		return "tll::node::expression::LeftValues";
	}

	/**
	 * @param sp semantic processor visitor
	 * @param level syntactic tree level
	 */
	virtual void accept(SemanticProcessor *sp, int level) {
		//sp->processLoadValue(this, level);
	}

};

} // expression
} // node
} // tll

#endif /* LOADVALUE_H_ */
