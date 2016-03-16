/*
 * OR.h
 *
 *  Created on: Mar 27, 2012
 *      Author: klang
 */

#ifndef OR_H_
#define OR_H_

#include <cdk/nodes/expressions/BinaryExpression.h>

namespace tll {
	namespace node {
		namespace expression {

		/*
		 * Class for describing the logical operator OR
		 */
		class OR: public cdk::node::expression::BinaryExpression {

		public:
					inline OR(int lineno, Expression *left, Expression *right) :
					          BinaryExpression(lineno, left, right) {
						type(new ExpressionType());					        }

				  public:

				        /**
				         * @return the name of the node's class
				         */
				        const char *name() const {
				          return "cdk::node::expression::OR";
				        }



				        virtual void accept(SemanticProcessor *sp, int level) {
				                 sp->processOR(this, level);
				               }

};

		} /* namespace expression */
	} /* namespace node */
} /* namespace tll */
#endif /* OR_H_ */
