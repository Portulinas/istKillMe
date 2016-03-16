#ifndef __TLL_FORNODE_H__
#define __TLL_FORNODE_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Expression.h>

namespace tll {
namespace node {
namespace instructions{
//!
//! Class for describing For-cycle nodes.
//!
class ForNode: public cdk::node::Node {
	cdk::node::expression::Expression *_init;
	cdk::node::expression::Expression *_condition;
	cdk::node::expression::Expression *_incr;
	cdk::node::Node *_block;

public:
	inline ForNode(int lineno, cdk::node::expression::Expression *init,
			cdk::node::expression::Expression *condition,
			cdk::node::expression::Expression *incr, cdk::node::Node *block) :
			cdk::node::Node(lineno), _init(init), _condition(condition), _incr(
					incr), _block(block) {
	}

public:
	inline cdk::node::expression::Expression *init() {
			return _init;
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
		return "tll::node::instructions::ForNode";
	}

	void accept(SemanticProcessor *sp, int level) {
		sp->processForNode(this, level);
	}

};
// class
} // namespace instructions
}// namespace node
} // namespace tll

#endif
