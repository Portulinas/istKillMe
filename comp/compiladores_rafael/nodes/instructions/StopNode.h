/*
 * Stop.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef __TLL_STOP_H__
#define __TLL_STOP_H__

#include <cdk/nodes/Node.h>
#include <cdk/nodes/expressions/Integer.h>

namespace tll {
namespace node {
namespace instructions{

class StopNode: public cdk::node::Node {
private:
	int _value;

	public:
	inline StopNode(int lineno) :
	cdk::node::Node(lineno), _value(1){}


	inline StopNode(int lineno,
			int num) :
			cdk::node::Node(lineno) {
		_value = num;
	}


	public:
	   inline  int num() {
	     return _value;
	   }


 public:
   const char *name() {
     return "tll::node::instructions::Stop";
   }

   void accept(SemanticProcessor *sp, int level) {
     sp->processStopNode(this, level);
   }
};

} /* namespace instrucitons */
} /* namespace node */
} /* namespace tll */
#endif /* STOP_H_ */
