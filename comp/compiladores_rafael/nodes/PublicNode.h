/*			TEOREMA DOS NODES
 *
 * [especie induçao] Node 0 feito; node 1 feito, node 2 feito => Todos os Nodes tao feitos
 *
 *
 */


/*
 * PublicNode.h
 *
 *  Created on: Mar 28, 2012
 *      Author: klang
 */

#ifndef PUBLICNODE_H_
#define PUBLICNODE_H_


#include "nodes/QualifierNode.h"

namespace tll {
	namespace node {

		class PublicNode : public tll::node::QualifierNode{

		public:
		     inline PublicNode(int lineno) :
		     tll::node::QualifierNode(lineno) {}

		     const char *name() {
		    	 return "tll::node::Public";
		  }

		  void accept(SemanticProcessor *sp, int level) {
		  //  sp->processPublicNode(this, level);
		  }
		};

} /* namespace node */
} /* namespace tll */
#endif /* PUBLICNODE_H_ */
