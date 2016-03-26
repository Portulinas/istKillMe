/*
 * Qualificador.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef __TLL_QUALIFIERNODE_H__
#define __TLL_QUALIFIERNODE_H__

#include <cdk/nodes/Node.h>

namespace tll {
namespace node {

class QualifierNode: public cdk::node::Node {
public:
	inline QualifierNode(int lineno) :
			cdk::node::Node(lineno) {
	}

public:
	const char *name() {
		return "tll::node::Qualifier";
	}

	void accept(SemanticProcessor *sp, int level) {
	//	sp->processQualifierNode(this, level);
	}
};

} /* namespace node */
} /* namespace tll */
#endif /* __TLL_QUALIFIERNODE_H_ */
