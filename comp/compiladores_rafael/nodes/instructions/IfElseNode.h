// $Id: IfElseNode.h,v 1.1 2012-03-29 18:05:57 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: IfElseNode.h,v $
 * Revision 1.1  2012-03-29 18:05:57  ist169643
 * está organizado!!!
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
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
#ifndef __TLL_IFELSENODE_H__
#define __TLL_IFELSENODE_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Expression.h>

namespace tll {
  namespace node {
  namespace instructions{
    //!
    //! Class for describing if-then-else nodes.
    //!
    class IfElseNode: public cdk::node::Node {
      cdk::node::expression::Expression *_condition;
      cdk::node::Node *_thenblock, *_elseblock;

    public:
      inline IfElseNode(int lineno, cdk::node::expression::Expression *condition,
                        cdk::node::Node *thenblock, cdk::node::Node *elseblock) :
        cdk::node::Node(lineno), _condition(condition), _thenblock(thenblock),
            _elseblock(elseblock) {
      }

    public:
      inline cdk::node::expression::Expression *condition() {
        return _condition;
      }
      inline cdk::node::Node *thenblock() {
        return _thenblock;
      }
      inline cdk::node::Node *elseblock() {
        return _elseblock;
      }

    public:
      const char *name() {
        return "tll::node::instructions::IfElseNode";
      }

      void accept(SemanticProcessor *sp, int level) {
        sp->processIfElseNode(this, level);
      }

    }; // class
  } //namespace instructions
  } // namespace node
} // namespace tll

#endif
