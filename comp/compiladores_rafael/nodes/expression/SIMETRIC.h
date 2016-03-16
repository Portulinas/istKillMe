/*
 * SIMETRIC.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef SIMETRIC_H_
#define SIMETRIC_H_

#include <cdk/nodes/expressions/UnaryExpression.h>

namespace tll {
	namespace node {
		namespace expression {

		class SIMETRIC: public cdk::node::expression::UnaryExpression {

		public:
			inline SIMETRIC(int lineno, Expression *arg) :
				UnaryExpression(lineno, arg) {
				type(new ExpressionType());				}


		public:
		/**
		 * @return the name of the node's class
		 */
			const char *name() const {
				return "cdk::node::expression::SIMETRIC";
			}

		/**
		 * @param sp semantic processor visitor
		 * @param level syntactic tree level
		 */
			 virtual void accept(SemanticProcessor *sp, int level){
				 sp->processSIMETRIC(this, level);
			   }

			};

		} /* namespace expression */
	} /* namespace node */
} /* namespace tll */

#endif /* SIMETRIC_H_ */
