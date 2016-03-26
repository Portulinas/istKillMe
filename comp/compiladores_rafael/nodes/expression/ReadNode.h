// $Id: ReadNode.h,v 1.3 2012-05-16 18:22:37 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: ReadNode.h,v $
 * Revision 1.3  2012-05-16 18:22:37  ist169643
 * *** empty log message ***
 *
 * Revision 1.2  2012-05-13 11:06:55  ist169643
 * *** empty log message ***
 *
 * Revision 1.1  2012-05-13 10:25:31  ist169643
 * read node Moved
 *
 * Revision 1.4  2012-03-28 18:43:11  ist169643
 * new classes and names updates
 *
 * Revision 1.1  2012-03-28 18:33:31  ist169643
 * TODOOOOO
 *
 * Revision 1.2  2012-03-28 08:20:25  ist169630
 * *** empty log message ***
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.5  2011/03/07 02:27:05  david
 * Added simple left value for read and assignment operations.
 *
 * Revision 1.4  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.3  2009/03/02 17:40:22  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.2  2007/03/13 00:26:28  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 * A separate evaluator is no longer needed since the compiler implementation
 * (CompilerImpl) now provides a better encapsulation.
 *
 */
#ifndef __TLL_READNODE_H__
#define __TLL_READNODE_H__

#include <cdk/nodes/expressions/UnaryExpression.h>
#include "nodes/expression/LeftValue.h"

namespace tll {
  namespace node {
  namespace expression{

    //!
    //! Class for describing read nodes.
    //!
    class ReadNode: public cdk::node::expression::Expression {

    public:
      inline ReadNode(int lineno) :
        cdk::node::expression::Expression(lineno) {
    	  type(new ExpressionType());      }



    public:
      const char *name() {
        return "tll::node::ReadNode";
      }

     void accept(SemanticProcessor *sp, int level) {
        sp->processReadNode(this, level);
      }

    }; // class
  } //namepsace expression
  } // namespace node
} // namespace tll

#endif
