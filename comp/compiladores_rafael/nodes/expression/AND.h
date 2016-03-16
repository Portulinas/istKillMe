/*
 * AND.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef AND_H_
#define AND_H_

#include <cdk/nodes/expressions/BinaryExpression.h>

namespace tll {
	namespace node {
		namespace expression {

		 /**
		  * Class for describing the logical operator AND
		  */
		class AND: public cdk::node::expression::BinaryExpression {

		public:
			inline AND(int lineno, Expression *left, Expression *right) :
			          BinaryExpression(lineno, left, right) {
				type(new ExpressionType());
			        }

		  public:

		        /**
		         * @return the name of the node's class
		         */
		        const char *name() const {
		          return "cdk::node::expression::AND";
		        }



		        virtual void accept(SemanticProcessor *sp, int level) {
		                 sp->processAND(this, level);
		               }

			};
		} /* namespace expression*/
	} /* namespace node */
} /* namespace tll */
#endif /* AND_H_ */
