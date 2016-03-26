/*
 * TypeValidator.cpp
 *
 *  Created on: May 11, 2012
 *      Author: klang
 */

#include "TypeValidator.h"

namespace tll {
namespace semantics {
tll::semantics::TypeValidator::~TypeValidator() { os().flush(); }

/*Variavel*/
//void tll::semantics::TypeValidator::process
/*-------------------------------------------------------*/
void tll::semantics::TypeValidator::processSequence(cdk::node::Sequence *const node, int lvl) {
	//size_t what the hell?
  for (size_t i = 0; i < node->size(); i++) {
    cdk::node::Node *n = node->node(i);
    if (n == NULL) break;
    n->accept(this, lvl+2);
  }
}
/*-------------------------------------------------------*/

/*!!!!!!!!!!!!!!!!!!!IDENTIFIER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
void tll::semantics::TypeValidator::processIdentifier(cdk::node::expression::Identifier *const node, int lvl) {
  const char * id = node->value().c_str();
  TLLSymbol *s = _symtab.find(id);
  if(s!=NULL){
   node->type(new ExpressionType(s->type()->size(), s->type()->name()));
  }
}

/*!!!!!!!!!!!!!!!!!!!!!!!!LOAD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
void tll::semantics::TypeValidator::processAssignmentNode(tll::node::AssignmentNode* const node, int lvl){
	try{
		node->lvalue()->accept(this, lvl+2);

	node->rvalue()->accept(this, lvl+2);
	if(node->lvalue()->type()->name() != node->rvalue()->type()->name()){
		if((node->lvalue()->type()->name() == ExpressionType::TYPE_INT && node->rvalue()->type()->name() == ExpressionType::TYPE_DOUBLE)
				||(node->lvalue()->type()->name() == ExpressionType::TYPE_DOUBLE && node->rvalue()->type()->name() ==ExpressionType::TYPE_INT ) ){
			node->type(new ExpressionType(node->lvalue()->type()->size(), node->lvalue()->type()->name()));
		}
		else{
				throw std::string("erro tipos nao compativeis");

			}
	}
	else{
		node->type(node->lvalue()->type());
	}

	}

	catch(std::string s){
		throw s;
	}
}

/*!!!!!!!!!!!!!!!!!!!!!EXPRESSIONS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

void tll::semantics::TypeValidator::processInteger(cdk::node::expression::Integer * const node,  int lvl) {
  node->type(new ExpressionType(4, ExpressionType::TYPE_INT));
}

void tll::semantics::TypeValidator::processDouble(cdk::node::expression::Double * const node, int lvl) {
  node->type(new ExpressionType(8, ExpressionType::TYPE_DOUBLE));
}
void tll::semantics::TypeValidator::processString(cdk::node::expression::String * const node, int lvl) {
  node->type(new ExpressionType(4, ExpressionType::TYPE_STRING));
}


/*
void tll::semantics::TypeValidator::processUnaryExpression(cdk::node::expression::UnaryExpression *const node, int lvl) {
  node->argument()->accept(this, lvl+2);

  if (node->argument()->type()->name() & ExpressionType::TYPE_STRING){
    throw std::string("UnaryExpression does not support Strings");
  }
  else{
    node->type(new ExpressionType(node->argument()->type()->size(), node->argument()->type()->name()));
  }
}*/

//Simetrico!
void tll::semantics::TypeValidator::processSIMETRIC(tll::node::expression::SIMETRIC* const node, int lvl){
	try{
	node->argument()->accept(this, lvl+2);
	if(node->argument()->type()->name() != ExpressionType::TYPE_INT || node->argument()->type()->name() != ExpressionType::TYPE_DOUBLE)
		throw std::string("function only support Integers or Reals");
	else{
		node->type(new ExpressionType(node->argument()->type()->size() ,node->argument()->type()->name()));
	}

	}
	catch(std::string s){
		throw s;
	}

}

/*expr aditivas*/
void tll::semantics::TypeValidator::processADD(cdk::node::expression::ADD* const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->right()->type()->name() == ExpressionType::TYPE_STRING)
			throw std::string("function not support strings");
		else{
			if(node->left()->type()->name() == ExpressionType::TYPE_POINTER){
				//testa o no direito a ver se sao inteiros
			}
				else{
				if(node->left()->type()->name() != node->right()->type()->name()){
					if((node->left()->type()->name() == ExpressionType::TYPE_INT &&
							node->right()->type()->name() == ExpressionType::TYPE_DOUBLE) ||
							(node->left()->type()->name() == ExpressionType::TYPE_DOUBLE &&
									node->right()->type()->name() == ExpressionType::TYPE_INT)){
					node->type(new ExpressionType(8, ExpressionType::TYPE_DOUBLE));
					}
					else{
						node->type(new ExpressionType(
								node->left()->type()->size(), node->left()->type()->name()));
					}
				}
			}


		}
	}
	catch (std::string s) {
		throw s;
	}
}
void tll::semantics::TypeValidator::processSUB(cdk::node::expression::SUB* const node, int lvl){
	try{
			node->left()->accept(this, lvl+2);
			node->right()->accept(this, lvl+2);
			if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->right()->type()->name() == ExpressionType::TYPE_STRING)
				throw std::string("function not suport strings");
			else{
				if(node->left()->type()->name() != node->right()->type()->name()){
					if((node->left()->type()->name() == ExpressionType::TYPE_INT &&
							node->right()->type()->name() == ExpressionType::TYPE_DOUBLE) ||
							(node->left()->type()->name() == ExpressionType::TYPE_DOUBLE &&
									node->right()->type()->name() == ExpressionType::TYPE_INT)){
					node->type(new ExpressionType(8, ExpressionType::TYPE_DOUBLE));
					}
					else{
						node->type(new ExpressionType(
								node->left()->type()->size(), node->left()->type()->name()));
					}
				}


			}
		}
		catch (std::string s) {
			throw s;
		}
}
/*expr multiplicativas*/
void tll::semantics::TypeValidator::processMUL(cdk::node::expression::MUL* const node, int lvl){
	try{
				node->left()->accept(this, lvl+2);
				node->right()->accept(this, lvl+2);
				if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->right()->type()->name() == ExpressionType::TYPE_STRING)
					throw std::string("function not suport strings");
				else{
					if(node->left()->type()->name() != node->right()->type()->name()){
						if((node->left()->type()->name() == ExpressionType::TYPE_INT &&
								node->right()->type()->name() == ExpressionType::TYPE_DOUBLE) ||
								(node->left()->type()->name() == ExpressionType::TYPE_DOUBLE &&
										node->right()->type()->name() == ExpressionType::TYPE_INT)){
						node->type(new ExpressionType(8, ExpressionType::TYPE_DOUBLE));
						}
						else{
							node->type(new ExpressionType(
									node->left()->type()->size(), node->left()->type()->name()));
						}
					}


				}
			}
			catch (std::string s) {
				throw s;
			}
}
void tll::semantics::TypeValidator::processDIV(cdk::node::expression::DIV* const node, int lvl){
	try{
				node->left()->accept(this, lvl+2);
				node->right()->accept(this, lvl+2);
				if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->right()->type()->name() == ExpressionType::TYPE_STRING)
					throw std::string("function not suport strings");
				else{
					if(node->left()->type()->name() != node->right()->type()->name()){
						if((node->left()->type()->name() == ExpressionType::TYPE_INT &&
								node->right()->type()->name() == ExpressionType::TYPE_DOUBLE) ||
								(node->left()->type()->name() == ExpressionType::TYPE_DOUBLE &&
										node->right()->type()->name() == ExpressionType::TYPE_INT)){
						node->type(new ExpressionType(8, ExpressionType::TYPE_DOUBLE));
						}
						else{
							node->type(new ExpressionType(
									node->left()->type()->size(), node->left()->type()->name()));
						}
					}


				}
			}
			catch (std::string s) {
				throw s;
			}
}
//potencia
void tll::semantics::TypeValidator::processPOT(tll::node::expression::POT* const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() != ExpressionType::TYPE_INT)
			throw std::string("function only suport Intigers");
		//O tipo é o que já era ^^
		else{
			node->type(new ExpressionType(4, ExpressionType::TYPE_INT));
		}
		}
		catch(std::string s){
			throw s;
		}

}

//MOD
void tll::semantics::TypeValidator::processMOD(cdk::node::expression::MOD*const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() != ExpressionType::TYPE_INT ||node->right()->type()->name() != ExpressionType::TYPE_INT )
			throw std::string("funcion only support Integers");
		else{
			node->type(new ExpressionType(4, ExpressionType::TYPE_INT));
		}
	}
	catch(std::string s){
		throw s;
	}

}
/*Grandeza, igualdade e Lógica*/
void tll::semantics::TypeValidator::processLE(cdk::node::expression::LE * const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->left()->type()->name() == ExpressionType::TYPE_STRING)
			throw std::string("function not suport strings");
		  if ((node->left()->type()->name() & ExpressionType::TYPE_POINTER) ||
		    (node->right()->type()->name() & ExpressionType::TYPE_POINTER)){
		    throw std::string("function does not support Pointers");
		  }
		else{
			node->type(new ExpressionType(4,ExpressionType::TYPE_INT));
		}
	}
	catch(std::string s){
		throw s;
	}

}
void tll::semantics::TypeValidator::processLT(cdk::node::expression::LT * const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->left()->type()->name() == ExpressionType::TYPE_STRING)
			throw std::string("function not suport strings");
		  if ((node->left()->type()->name() & ExpressionType::TYPE_POINTER) ||
		    (node->right()->type()->name() & ExpressionType::TYPE_POINTER)){
		    throw std::string("Comparation does not support Pointers");
		  }
		else{
			node->type(new ExpressionType(4,ExpressionType::TYPE_INT));
		}
	}
	catch(std::string s){
		throw s;
	}
}
void tll::semantics::TypeValidator::processGE(cdk::node::expression::GE * const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->left()->type()->name() == ExpressionType::TYPE_STRING)
			throw std::string("function not suport strings");
		  if ((node->left()->type()->name() & ExpressionType::TYPE_POINTER) ||
		    (node->right()->type()->name() & ExpressionType::TYPE_POINTER)){
		    throw std::string("Comparation does not support Pointers");
		  }
		else{
			node->type(new ExpressionType(4,ExpressionType::TYPE_INT));
		}
	}
	catch(std::string s){
		throw s;
	}
}
void tll::semantics::TypeValidator::processGT(cdk::node::expression::GT * const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->left()->type()->name() == ExpressionType::TYPE_STRING)
			throw std::string("function not suport strings");
		  if ((node->left()->type()->name() & ExpressionType::TYPE_POINTER) ||
		    (node->right()->type()->name() & ExpressionType::TYPE_POINTER)){
		    throw std::string("Comparation does not support Pointers");
		  }
		else{
			node->type(new ExpressionType(4,ExpressionType::TYPE_INT));
		}
	}
	catch(std::string s){
		throw s;
	}
}
void tll::semantics::TypeValidator::processAND(tll::node::expression::AND * const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->left()->type()->name() == ExpressionType::TYPE_STRING)
			throw std::string("function not suport strings");
		  if ((node->left()->type()->name() & ExpressionType::TYPE_POINTER) ||
		    (node->right()->type()->name() & ExpressionType::TYPE_POINTER)){
		    throw std::string("Comparation does not support Pointers");
		  }
		else{
			node->type(new ExpressionType(4,ExpressionType::TYPE_INT));
		}
	}
	catch(std::string s){
		throw s;
	}
}
void tll::semantics::TypeValidator::processOR(tll::node::expression::OR * const node, int lvl){
	try{
		node->left()->accept(this, lvl+2);
		node->right()->accept(this, lvl+2);
		if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->left()->type()->name() == ExpressionType::TYPE_STRING)
			throw std::string("function not suport strings");
		  if ((node->left()->type()->name() & ExpressionType::TYPE_POINTER) ||
		    (node->right()->type()->name() & ExpressionType::TYPE_POINTER)){
		    throw std::string("Comparation does not support Pointers");
		  }
		else{
			node->type(new ExpressionType(4,ExpressionType::TYPE_INT));
		}
	}
	catch(std::string s){
		throw s;
	}
}
void tll::semantics::TypeValidator::processNE(cdk::node::expression::NE * const node, int lvl){
	try{
			node->left()->accept(this, lvl+2);
			node->right()->accept(this, lvl+2);
			if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->left()->type()->name() == ExpressionType::TYPE_STRING)
				throw std::string("function not suport strings");
			  if ((node->left()->type()->name() & ExpressionType::TYPE_POINTER) ||
			    (node->right()->type()->name() & ExpressionType::TYPE_POINTER)){
			    throw std::string("Comparation does not support Pointers");
			  }
			else{
				node->type(new ExpressionType(4,ExpressionType::TYPE_INT));
			}
		}
		catch(std::string s){
			throw s;
		}
}
void tll::semantics::TypeValidator::processEQ(cdk::node::expression::EQ * const node, int lvl){
	try{
			node->left()->accept(this, lvl+2);
			node->right()->accept(this, lvl+2);
			if(node->left()->type()->name() == ExpressionType::TYPE_STRING || node->left()->type()->name() == ExpressionType::TYPE_STRING)
				throw std::string("function not suport strings");
			  if ((node->left()->type()->name() & ExpressionType::TYPE_POINTER) ||
			    (node->right()->type()->name() & ExpressionType::TYPE_POINTER)){
			    throw std::string("Comparation does not support Pointers");
			  }
			else{
				node->type(new ExpressionType(4,ExpressionType::TYPE_INT));
			}
		}
		catch(std::string s){
			throw s;
		}
}
//neg!
void tll::semantics::TypeValidator::processNEG(cdk::node::expression::NEG* const node, int lvl){
	try{
	node->accept(this, lvl+2);

	if(node->argument()->type()->name() != ExpressionType::TYPE_INT)
		throw std::string("function only suport Intigers");
	else{
		node->type(new ExpressionType(4, ExpressionType::TYPE_INT));
	}
	}
	catch(std::string s){
		throw s;
	}
}

void tll::semantics::TypeValidator::processMEM(tll::node::expression::MEM * const node, int lvl){
	try{
	node->argument()->accept(this, lvl+2);
	if(node->argument()->type()->name() !=  ExpressionType::TYPE_INT){
		throw std::string("function only suport Intigers");
	}
	}
	catch(std::string s){
		throw s;
	}

}


void tll::semantics::TypeValidator::processBlockNode(tll::node::BlockNode * const node,int lvl){
	try{
	node->declarations()->accept(this, lvl+2);
	node->instructions()->accept(this, lvl+2);

	}
	catch (std::string s) {
		throw s;
	}
}


void tll::semantics::TypeValidator::processWhileElseNode(tll::node::instructions::WhileElseNode * const node, int lvl){
	try{
	node->condition()->accept(this, lvl+2);
	if(node->condition()->type()->name() != ExpressionType::TYPE_INT){
				throw std::string("integer expression expected in 'if' cycle test");
			}
	node->block()->accept(this, lvl+4);
	node->elseblock()->accept(this, lvl+4);

	}
	catch (std::string s) {
		throw s;

	}
}
void tll::semantics::TypeValidator::processWhileNode(tll::node::instructions::WhileNode * const node, int lvl){
	try{
	node->condition()->accept(this, lvl+2);
	if(node->condition()->type()->name() != ExpressionType::TYPE_INT){
				throw std::string("integer expression expected in 'if' cycle test");
			}
	node->block()->accept(this, lvl+2);
	}
	catch (std::string s) {
		throw s;
	}
}

void tll::semantics::TypeValidator::processDoNode(tll::node::instructions::DoNode * const node,int lvl) {
	try
	{node->block()->accept(this, lvl+2);
	node->condition()->accept(this, lvl+2);
	if(node->condition()->type()->name() != ExpressionType::TYPE_INT){
				throw std::string("integer expression expected in 'if' cycle test");
			}
	}
	catch(std::string s){throw s;}
}

void tll::semantics::TypeValidator::processDoElseNode(tll::node::instructions::DoElseNode * const node, int lvl){
	try{
	node->block()->accept(this, lvl+2);
	node->condition()->accept(this, lvl+2);
	if(node->condition()->type()->name() != ExpressionType::TYPE_INT){
				throw std::string("integer expression expected in 'if' cycle test");
			}
	node->elseblock()->accept(this, lvl+2);
	}
	catch (std::string s) {
		throw s;
	}
}


void tll::semantics::TypeValidator::processReadNode(tll::node::expression::ReadNode * const node, int lvl){
	//ser sempre int!
}

void tll::semantics::TypeValidator::processForNode(tll::node::instructions::ForNode * const node, int lvl){
	try{
		node->init()->accept(this, lvl+2);
		node->condition()->accept(this, lvl+2);
		if(node->condition()->type()->name() != ExpressionType::TYPE_INT){
					throw std::string("Integer expression expected in 'if' cycle test");
				}
		node->incr()->accept(this, lvl+2);
	}
	catch(std::string s){throw s;}
}

void tll::semantics::TypeValidator::processForVarNode(tll::node::instructions::ForVarNode * const node, int lvl){
	try{
		node->var()->accept(this, lvl+2);
		node->condition()->accept(this, lvl+2);
		node->incr()->accept(this, lvl+2);
	}
	catch(std::string s){throw s;}
}

void tll::semantics::TypeValidator::processIfElseNode(tll::node::instructions::IfElseNode * const node, int lvl){
	try{
		node->condition()->accept(this, lvl+2);
		if(node->condition()->type()->name() != ExpressionType::TYPE_INT){
					throw std::string("integer expression expected in 'if' cycle test");
				}
		node->thenblock()->accept(this, lvl+2);
		node->elseblock()->accept(this, lvl+2);
	}
	catch (std::string s) {
		throw s;
	}

}

void tll::semantics::TypeValidator::processIfNode(tll::node::instructions::IfNode * const node, int lvl){
	try{
		node->condition()->accept(this, lvl+2);
		if(node->condition()->type()->name() != ExpressionType::TYPE_INT){
			throw std::string("integer expression expected in 'if' cycle test");
		}
		node->block()->accept(this, lvl+2);
	}
	catch (std::string s) {
		throw s;
	}
}

void tll::semantics::TypeValidator::processNextNode(tll::node::instructions::NextNode * const node, int lvl){
	//yacc ja faz!

}

void tll::semantics::TypeValidator::processReturnNode(tll::node::instructions::ReturnNode * const node, int lvl){
	//yacc ja faz!

}

void tll::semantics::TypeValidator::processVariableNode(tll::node::VariableNode * const node, int lvl){
	try {
		//node->accept(this, lvl + 2);
		if (node->init() != NULL) {
			node->init()->accept(this, lvl + 2);
			if (node->type()->name() != node->init()->type()->name()) {
				if (!(node->type()->name() == ExpressionType::TYPE_INT
						&& node->init()->type()->name()
								== ExpressionType::TYPE_DOUBLE)
						|| !(node->type()->name()
								== ExpressionType::TYPE_DOUBLE
								&& (node->init()->type()->name()
										== ExpressionType::TYPE_INT))) {
					throw std::string("wrong type for initializer");
				}
			}
		}
	} catch (std::string s) {
		throw s;
	}

}

void tll::semantics::TypeValidator::processStopNode(tll::node::instructions::StopNode * const node, int lvl){
	//yacc ja faz!
}
void tll::semantics::TypeValidator::processLeftValue(tll::node::expression::LeftValue * const node, int lvl){
/*	try{
		if(node->type()->name() == ExpressionType::TYPE_CONST){
		throw std::string("function don't support const");
		}
	}
	catch(std::string s){
		throw s;
	}*/

	//TODO TODO TODO
}

void tll::semantics::TypeValidator::processNode(cdk::node::Node * const node, int lvl){/*empty!*/}
void tll::semantics::TypeValidator::processPOS(tll::node::expression::POS * const node, int lvl){
	//tem de ser endereçavel ==  left value
}
void tll::semantics::TypeValidator::processFunctionDefNode(tll::node::FunctionDefNode * const node, int lvl){

}
void tll::semantics::TypeValidator::processFunctionDeclNode(tll::node::FunctionDeclNode * const node, int lvl){

}
void tll::semantics::TypeValidator::processFunctionCallNode(tll::node::expression::FunctionCallNode * const node, int lvl){
		//cdk::node::Sequence* exprlist = node->_var();

}
void tll::semantics::TypeValidator::processInvocationNode(tll::node::expression::InvocationNode * const node, int lvl){
}

void tll::semantics::TypeValidator::processIndexNode(tll::node::expression::IndexNode * const node, int lvl){
	try{
		node->argument()->accept(this, lvl);
		if(node->argument()->type()->name() != ExpressionType::TYPE_INT){
			throw std::string("Vector argument only support Integers");
		}
	}
	catch (std::string s) {
		throw s;
	}
}


void tll::semantics::TypeValidator::processPrintNode(tll::node::PrintNode * const node, int lvl){
	try{
	node->argument()->accept(this, lvl);
	if(node->argument()->type()->name() == ExpressionType::TYPE_POINTER){
		throw std::string("Function does not support Pointers");
	}
	}
	catch (std::string s) {
		throw s;
	}
}


void tll::semantics::TypeValidator::processNil(cdk::node::Nil * const node, int lvl){/*empty!*/}
void tll::semantics::TypeValidator::processData(cdk::node::Data * const node, int lvl){/*empty!*/}
void tll::semantics::TypeValidator::processComposite(cdk::node::Composite * const node, int lvl){/*empty!*/}

void tll::semantics::TypeValidator::processUnaryExpression(cdk::node::expression::UnaryExpression * const node, int lvl){/*vai fazer coisas*/}
void tll::semantics::TypeValidator::processBinaryExpression(cdk::node::expression::BinaryExpression * const node, int lvl){/*vai fazer coisas*/}

} /* namespace semantics */
} /* namespace tll */
