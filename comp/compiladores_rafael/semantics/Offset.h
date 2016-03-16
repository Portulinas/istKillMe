/*
 * Offset.h
 *
 *  Created on: May 12, 2012
 *      Author: klang
 */

#ifndef OFFSET_H_
#define OFFSET_H_

#include <string>
#include <iostream>
#include <cdk/semantics/SymbolTable.h>
#include <cdk/generators/Postfix.h>
#include "SemanticProcessor.h"
#include "TLLSymbol.h"
#include "nodes/all.h"

namespace tll {
namespace semantics {

class Offset : public SemanticProcessor {
	cdk::semantics::SymbolTable<TLLSymbol> &_symtab;
	int offSet;
public:
	/**/
	Offset(std::ostream &os, cdk::semantics::SymbolTable<TLLSymbol> &symtab):
		SemanticProcessor(os), _symtab(symtab){
	}

	cdk::semantics::SymbolTable<TLLSymbol> &getSymbolTable() 	{ return this->_symtab;}
	std::ostream &getOstream()	{ return this->os();}

	int getOffSet();
	void chooseOffSet(Offset *offset1, Offset *offset2);
	void addOffSet(int x);

	  void processNode(cdk::node::Node * const node, int lvl) {}
	  void processNil(cdk::node::Nil * const node, int lvl) {}
	  void processData(cdk::node::Data * const node, int lvl) {}
	  void processComposite(cdk::node::Composite * const node, int lvl) {}
	  void processSequence(cdk::node::Sequence * const node, int lvl);


public:
     template<typename T> void processSimple(cdk::node::expression::Simple<T> * const node,int lvl) {}
     void processInteger(cdk::node::expression::Integer * const node, int lvl);
     void processDouble(cdk::node::expression::Double * const node, int lvl);
     void processString(cdk::node::expression::String * const node, int lvl);
     void processIdentifier(cdk::node::expression::Identifier * const node, int lvl);

   public:
     void processUnaryExpression(cdk::node::expression::UnaryExpression * const node, int lvl);
     void processNEG(cdk::node::expression::NEG * const node, int lvl);

   public:
     void processBinaryExpression(cdk::node::expression::BinaryExpression * const node, int lvl);
     void processADD(cdk::node::expression::ADD * const node, int lvl);
     void processSUB(cdk::node::expression::SUB * const node, int lvl);
     void processMUL(cdk::node::expression::MUL * const node, int lvl);
     void processDIV(cdk::node::expression::DIV * const node, int lvl);
     void processMOD(cdk::node::expression::MOD * const node, int lvl);
     void processLT(cdk::node::expression::LT * const node, int lvl);
     void processLE(cdk::node::expression::LE * const node, int lvl);
     void processGE(cdk::node::expression::GE * const node, int lvl);
     void processGT(cdk::node::expression::GT * const node, int lvl);
     void processNE(cdk::node::expression::NE * const node, int lvl);
     void processEQ(cdk::node::expression::EQ * const node, int lvl);

     void processAND(tll::node::expression::AND *const node, int lvl);
     void processMEM(tll::node::expression::MEM *const node, int lvl);
     void processOR(tll::node::expression::OR *const node, int lvl);
     void processPOS(tll::node::expression::POS *const node, int lvl);
     void processPOT(tll::node::expression::POT *const node, int lvl);
     void processSIMETRIC(tll::node::expression::SIMETRIC *const node, int lvl);


   public:
     void processAssignmentNode (tll::node::AssignmentNode * const node, int lvl);
     void processBlockNode (tll::node::BlockNode * const node, int lvl);
	 void processFunctionDeclNode (tll::node::FunctionDeclNode * const node, int lvl);
	 void processFunctionDefNode (tll::node::FunctionDefNode * const node, int lvl);
	 void processPrintNode(tll::node::PrintNode * const node, int lvl);
	 void processPublicNode(tll::node::PublicNode * const node, int lvl);
	 void processReadNode(tll::node::expression::ReadNode * const node, int lvl);
	 void processUseNode(tll::node::UseNode * const node, int lvl);
	 void processVariableNode(tll::node::VariableNode * const node, int lvl);

	 void processFunctionCallNode(tll::node::expression::FunctionCallNode * const node, int lvl);
	 void processIndexNode(tll::node::expression::IndexNode * const node, int lvl);
	 void processInvocationNode(tll::node::expression::InvocationNode * const node, int lvl);
	 void processLeftValue(tll::node::expression::LeftValue * const node, int lvl);
	 void processLoadValue(tll::node::expression::LoadValue * const node, int lvl);

	 void processDoElseNode (tll::node::instructions::DoElseNode * const node, int lvl);
	 void processDoNode(tll::node::instructions::DoNode * const node, int lvl);
	 void processForNode(tll::node::instructions::ForNode * const node, int lvl);
	 void processForVarNode(tll::node::instructions::ForVarNode * const node, int lvl);
	 void processIfElseNode(tll::node::instructions::IfElseNode * const node, int lvl);
	 void processIfNode(tll::node::instructions::IfNode * const node, int lvl);
	 void processNextNode(tll::node::instructions::NextNode * const node, int lvl);
	 void processReturnNode(tll::node::instructions::ReturnNode * const node, int lvl);
	 void processStopNode(tll::node::instructions::StopNode * const node, int lvl);
	 void processWhileElseNode(tll::node::instructions::WhileElseNode * const node, int lvl);
	 void processWhileNode(tll::node::instructions::WhileNode * const node, int lvl);






}; /*namespace classe */

} /* namespace semantics */
} /* namespace tll */
#endif /* OFFSET_H_ */
