/*
 * DoElseNode.h
 *
 *  Created on: Mar 25, 2012
 *      Author: klang
 */

#ifndef __TLL_DOELSENODE_H__
#define __TLL_DOELSENODE_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Expression.h>

namespace tll {
  namespace node {
  namespace instructions{

    //!
    //! Class for describing do-else nodes.
    //!
    class DoElseNode: public cdk::node::Node {
      cdk::node::expression::Expression *_condition;
      cdk::node::Node *_block, *_elseblock;

    public:
      inline DoElseNode(int lineno,cdk::node::Node *block, cdk::node::expression::Expression *condition,
                       cdk::node::Node *elseblock) :
        cdk::node::Node(lineno), _condition(condition), _block(block),
            _elseblock(elseblock) {
      }

    public:
      inline cdk::node::expression::Expression *condition() {
        return _condition;
      }
      inline cdk::node::Node *block() {
        return _block;
      }
      inline cdk::node::Node *elseblock() {
        return _elseblock;
      }

    public:
      const char *name() {
        return "tll::node::instructions::DoElseNode";
      }

      void accept(SemanticProcessor *sp, int level) {
        sp->processDoElseNode(this, level);
      }

    }; // class
  } //namesapce instructions
  } // namespace node
} // namespace tll

#endif
