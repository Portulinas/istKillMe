// $Id: XMLevaluator.h,v 1.1 2012-03-06 21:44:34 ist13500 Exp $
/*
 * $Log: XMLevaluator.h,v $
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.4  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.3  2009/03/02 17:40:21  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.1  2007/03/14 01:20:30  david
 * Changed compiler implementation to use evaluation strategy objects
 * instead of functions. These strategies are selected according to the
 * target selected from the command line options or from clues such as
 * the output file extension.
 */
#ifndef __TLL_SEMANTICS_XMLEVALUATOR_H__
#define __TLL_SEMANTICS_XMLEVALUATOR_H__

#include <iostream>
#include <cdk/semantics/Evaluator.h>

namespace cdk {
  class Compiler;
  namespace node {
    class Node;
  }
}

namespace tll {
  namespace semantics {

    class XMLevaluator: public cdk::semantics::Evaluator {
      static XMLevaluator _thisEvaluator;

    protected:
      XMLevaluator(const char *target = "xml") :
        cdk::semantics::Evaluator(target) {
      }

    public:
      bool evaluate(cdk::Compiler *compiler);

    }; // class XMLevaluator

  } // namespace semantics
} // namespace tll

#endif
