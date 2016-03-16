/*
 * POS.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef POS_H_
#define POS_H_

#include <cdk/nodes/expressions/UnaryExpression.h>

namespace tll {
	namespace node {
		namespace expression {

		/**
		 * Class for describing the position indicator
		 */
		class POS: public cdk::node::expression::UnaryExpression {

		  public:
		        inline POS(int lineno, Expression *arg) :
		          UnaryExpression(lineno, arg) {
		        	type(new ExpressionType());		        }
		public:

	        /**
	         * @return the name of the node's class
	         */
	        const char *name() const {
	          return "cdk::node::expression::pos";
	        }



	        virtual void accept(SemanticProcessor *sp, int level) {
	                 sp->processPOS(this, level);
	               }

		};
	} /* namespace expression*/
} /* namespace node */
} /* namespace tll */
#endif /* POS_H_ */
