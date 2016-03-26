/*
 * Return.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef __TLL_RETURNNODE_H__
#define __TLL_RETURNNODE_H__

#include <cdk/nodes/Node.h>

namespace tll {
namespace node {
namespace instructions{
class ReturnNode : public cdk::node::Node{

public:
     inline ReturnNode(int lineno) :
       cdk::node::Node(lineno) {}
  const char *name() {
    return "tll::node::instructions::Return";
  }

  void accept(SemanticProcessor *sp, int level) {
    sp->processReturnNode(this, level);
  }
};

} /* namespace instructions */
} /* namespace node */
} /* namespace tll */
#endif /*__TLL_RETURNNODE_H__ */
