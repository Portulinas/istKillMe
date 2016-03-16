/*
 * BlockNode.h
 *
 *  Created on: Mar 28, 2012
 *      Author: klang
 */

#ifndef __TLL_BLOCKNODE_H__
#define __TLL_BLOCKNODE_H__
#include <cdk/nodes/Node.h>


namespace tll {
namespace node {
/*body node é uma "interface"*/
class BlockNode : public cdk::node::Node{
	cdk::node::Sequence *_decl;
	cdk::node::Sequence *_inst;

public:
     inline BlockNode(int lineno,cdk::node::Sequence *decl, cdk::node::Sequence *inst ) :
     cdk::node::Node(lineno), _decl(decl), _inst(inst) {}

  const char *name() {
    return "tll::node::instructions::Block";
  }

  cdk::node::Sequence * declarations(){
  	  return _decl;
  	}
  	cdk::node::Sequence * instructions(){
  	  return _inst;
  	}


  void accept(SemanticProcessor *sp, int level) {
    sp->processBlockNode(this, level);
  }
};


} /* namespace node */
} /* namespace tll */
#endif /* __TLL_BLOCKNODE_H__ */
