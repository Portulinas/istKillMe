/*
 * POT.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef POT_H_
#define POT_H_

#include <cdk/nodes/expressions/BinaryExpression.h>

namespace tll {
	namespace node {
		namespace expression {

		 /**
		  * Class for describing the logical operator AND
		  */
		class POT: public cdk::node::expression::BinaryExpression {

		public:
			inline POT(int lineno, Expression *left, Expression *right) :
			          BinaryExpression(lineno, left, right) {
				type(new ExpressionType());			        }

		  public:

		        /**
		         * @return the name of the node's class
		         */
		        const char *name() const {
		          return "cdk::node::expression::POT";
		        }



		        virtual void accept(SemanticProcessor *sp, int level) {
		                 sp->processPOT(this, level);
		               }
			};
		} /* namespace expression*/
	} /* namespace node */
} /* namespace tll */
#endif /* POT_H_ */
