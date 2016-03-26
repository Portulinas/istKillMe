/*
 * DoNode.h
 *
 *  Created on: Mar 28, 2012
 *      Author: klang
 */

#ifndef __TLL_DONODE_H__
#define __TLL_DONODE_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Expression.h>

namespace tll {
namespace node {
namespace instructions{
//!
//! Class for describing do nodes.
//!
class DoNode: public cdk::node::Node {
	cdk::node::expression::Expression *_condition;
	cdk::node::Node *_block;

public:
	inline DoNode(int lineno, cdk::node::Node *block, cdk::node::expression::Expression *condition) :
			cdk::node::Node(lineno), _condition(condition), _block(block) {
	}

public:
	inline cdk::node::expression::Expression *condition() {
		return _condition;
	}
	inline cdk::node::Node *block() {
		return _block;
	}


public:
	const char *name() {
		return "tll::node::instructions::DoNode";
	}

	void accept(SemanticProcessor *sp, int level) {
		sp->processDoNode(this, level);
	}

};
} /* namespace instructions */
} /* namespace node */
} /* namespace tll */
#endif /* __TLL_DONODE_H__ */
