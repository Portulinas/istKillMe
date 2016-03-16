// $Id: LeftValue.h,v 1.2 2012-05-13 11:06:55 ist169643 Exp $
/*
 * $Log: LeftValue.h,v $
 * Revision 1.2  2012-05-13 11:06:55  ist169643
 * *** empty log message ***
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.2  2011/03/09 19:56:17  david
 * *** empty log message ***
 *
 * Revision 1.1  2011/03/07 02:27:05  david
 * Added simple left value for read and assignment operations.
 *
 *
 */
#ifndef __TLL_NODE_EXPRESSION_LEFTVALUE_H__
#define __TLL_NODE_EXPRESSION_LEFTVALUE_H__

#include <cdk/nodes/expressions/Simple.h>
#include <string>
#include "SemanticProcessor.h"

namespace tll {
  namespace node {
    namespace expression {

      /**
       * Class for describing syntactic tree leaves for holding lvalues.
       */
      class LeftValue: public cdk::node::expression::Simple<std::string> {
      public:
        inline LeftValue(int lineno, const char *s) :
          cdk::node::expression::Simple<std::string>(lineno, s) {
        	type(new ExpressionType());        }
        inline LeftValue(int lineno, const std::string &s) :
          cdk::node::expression::Simple<std::string>(lineno, s) {
        	type(new ExpressionType());        }
        inline LeftValue(int lineno, const std::string *s) :
          cdk::node::expression::Simple<std::string>(lineno, *s) {
        	type(new ExpressionType());        }

      public:

        /**
         * @return the name of the node's class
         */
        const char *name() const {
          return "tll::node::expression::LeftValues";
        }

        /**
         * @param sp semantic processor visitor
         * @param level syntactic tree level
         */
        virtual void accept(SemanticProcessor *sp, int level) {
          sp->processLeftValue(this, level);
        }

      };

    } // expression
  } // node
} // tll

#endif
