/*
 * IndexNode.h
 *
 *  Created on: Mar 29, 2012
 *      Author: klang
 */

#ifndef INDEXNODE_H_
#define INDEXNODE_H_
#include <cdk/nodes/expressions/Expression.h>
#include <cdk/nodes/expressions/UnaryExpression.h>
namespace tll {
namespace node {
namespace expression {

class IndexNode: public cdk::node::expression::Expression{
private:
	ExpressionType *_pointer;
	cdk::node::expression::Expression* _argument;
public:
	inline IndexNode(int lineno/*, ExpressionType *pointer*/, cdk::node::expression::Expression* argument ) :
			cdk::node::expression::Expression(lineno), /*_pointer(pointer), */_argument(argument) {
		type(new ExpressionType());	}

public:
	/**
	 * @return the name of the node's class
	 */
	const char *name() const {
		return "tll::node::expression::IndexNode";
	}

	const ExpressionType *pointer() {
		return _pointer;
	}
	cdk::node::expression::Expression* argument(){
		return _argument;
	}


	/**
	 * @param sp semantic processor visitor
	 * @param level syntactic tree level
	 */
		 virtual void accept(SemanticProcessor *sp, int level){
	 sp->processIndexNode(this, level);
	 }
};

} /* namespace expression */
} /* namespace node */
} /* namespace tll */
#endif /* INDEXNODE_H_ */
