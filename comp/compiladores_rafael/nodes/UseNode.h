/*
 * UseNode.h
 *
 *  Created on: Mar 28, 2012
 *      Author: klang
 */

#ifndef USENODE_H_
#define USENODE_H_

#include <cdk/nodes/Node.h>


namespace tll {
namespace node {

class UseNode: public cdk::node::Node {

public:
	inline UseNode(int lineno) :
			cdk::node::Node(lineno) {
	}
	const char *name() {
		return "tll::node::Use";
	}

	void accept(SemanticProcessor *sp, int level) {
		//sp->processUseNode(this, level);
	}
};

} /* namespace node */
} /* namespace tll */
#endif /* USENODE_H_ */
