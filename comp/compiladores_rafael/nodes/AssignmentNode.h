// $Id: AssignmentNode.h,v 1.3 2012-05-15 10:27:11 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: AssignmentNode.h,v $
 * Revision 1.3  2012-05-15 10:27:11  ist169643
 * *** empty log message ***
 *
 * Revision 1.2  2012-05-13 15:24:27  ist169643
 * typeValidator updated [AssignmentNode]
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.7  2011/03/07 02:27:05  david
 * Added simple left value for read and assignment operations.
 *
 * Revision 1.6  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.5  2009/03/02 17:40:21  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.4  2008/03/01 18:32:50  david
 * TLL for CDK3 (first version).
 *
 * Revision 1.2  2007/03/13 00:26:27  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 * A separate evaluator is no longer needed since the compiler implementation
 * (CompilerImpl) now provides a better encapsulation.
 *
 */
#ifndef __TLL_ASSIGNMENTNODE_H__
#define __TLL_ASSIGNMENTNODE_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Expression.h>
#include "nodes/expression/LeftValue.h"
namespace tll {
namespace node {

//!
//! Class for describing assignment nodes.
//!
class AssignmentNode: public cdk::node::expression::BinaryExpression {
	tll::node::expression::LeftValue *_lvalue;
	cdk::node::expression::Expression *_rvalue;

public:
	inline AssignmentNode(int lineno,
			tll::node::expression::LeftValue *lvalue,
			cdk::node::expression::Expression *rvalue) :
		cdk::node::expression::BinaryExpression(lineno, lvalue, rvalue), _lvalue(lvalue), _rvalue(rvalue) {
	}

public:
	inline tll::node::expression::LeftValue *lvalue() {
		return _lvalue;
	}
	inline cdk::node::expression::Expression *rvalue() {
		return _rvalue;
	}

public:
	const char *name() {
		return "tll::node::AssignmentNode";
	}

	void accept(SemanticProcessor *sp, int level) {
		sp->processAssignmentNode(this, level);
	}

}; // class

} // namespace node
} // namespace tll

#endif
