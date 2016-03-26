/*
 * ForVarNode.h
 *
 *  Created on: Mar 28, 2012
 *      Author: klang
 */

#ifndef __TLL_FORVARNODE_H__
#define __TLL_FORVARNODE_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Expression.h>
#include <cdk/nodes/Sequence.h>

namespace tll {
namespace node {
namespace instructions{
class ForVarNode: public cdk::node::Node  {
	//!
	//! Class for describing For-cycle nodes.
	//!



private:
    cdk::node::Sequence *_var;
	cdk::node::expression::Expression *_condition;
	cdk::node::expression::Expression *_incr;
	cdk::node::Node *_block;
public:
	inline ForVarNode(int lineno, cdk::node::Sequence *var,
			cdk::node::expression::Expression *condition,
			cdk::node::expression::Expression *incr, cdk::node::Node *block) :
			cdk::node::Node(lineno), _var(var), _condition(condition), _incr(incr),
			_block(block) {}

public:
	inline cdk::node::Sequence* var() {
			return _var;
		}
	inline cdk::node::expression::Expression *condition() {
			return _condition;
		}
	inline cdk::node::expression::Expression *incr() {
		return _incr;
	}
	inline cdk::node::Node *block() {
		return _block;
	}

public:
	const char *name() {
		return "tll::node::instructions::ForVarNode";
	}

	void accept(SemanticProcessor *sp, int level) {
		sp->processForVarNode(this, level);
	}




};
} /* namespace instructions */
} /* namespace node */
} /* namespace tll */
#endif /* __TLL_FORVARNODE_H__ */
