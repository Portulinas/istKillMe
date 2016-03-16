/*
 * Next.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef __TLL_NEXTNODE_H__
#define __TLL_NEXTNODE_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Integer.h>
namespace tll {
namespace node {
namespace instructions {

//!
//! Class for describing next nodes.
//!
class NextNode: public cdk::node::Node {

private:
	int _value;

public:
	inline NextNode(int lineno) :
			cdk::node::Node(lineno), _value(1){}

	inline NextNode(int lineno,
			int num) : cdk::node::Node(lineno), _value(num) {}

public:
   inline  int num() {
     return _value;
   }


public:
	const char *name() {
		return "tll::node::instructions::Next";
	}

	void accept(SemanticProcessor *sp, int level) {
		sp->processNextNode(this, level);
	}
};
} /* namespace instructions*/
} /* namespace node */
} /* namespace tll */
#endif /* __TLL_NEXTNODE_H__ */
