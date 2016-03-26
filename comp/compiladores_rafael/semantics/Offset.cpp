/*
 * Offset.cpp
 *
 *  Created on: May 12, 2012
 *      Author: klang
 */

#include "Offset.h"
#include "nodes/all.h"

int tll::semantics::Offset::getOffSet(){
	return offSet;
}



void tll::semantics::Offset::chooseOffSet(Offset *offset1, Offset *offset2){
		int a = offset1->getOffSet();
		int b = offset2->getOffSet();

		if (b <= a)
			addOffSet(a);
		else addOffSet(b);

		offset1->~Offset();
		offset2->~Offset();
	}


void tll::semantics::Offset::addOffSet(int x){
	offSet += x;
}


/*VISITORS*/

void tll::semantics::Offset::processInteger(cdk::node::expression::Integer * const node, int lvl){
	offSet += 4;
}

void tll::semantics::Offset::processDouble(cdk::node::expression::Double *const node, int lvl){
	offSet +=8;
}

void tll::semantics::Offset::processString(cdk::node::expression::String *const node, int lvl){
	offSet += 4;
}

void tll::semantics::Offset::processIdentifier(cdk::node::expression::Identifier * const node, int lvl) {
	/*empty*/
}

void tll::semantics::Offset::processUnaryExpression(cdk::node::expression::UnaryExpression * const node, int lvl) {
	/*empty*/
}

void tll::semantics::Offset::processBinaryExpression(cdk::node::expression::BinaryExpression * const node, int lvl) {
	/*empty*/
}

void tll::semantics::Offset::processNEG(cdk::node::expression::NEG * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processADD(cdk::node::expression::ADD *const node, int lvl) {
	/*empty*/
}

void tll::semantics::Offset::processSUB(cdk::node::expression::SUB * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processMUL(cdk::node::expression::MUL * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processDIV(cdk::node::expression::DIV * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processMOD(cdk::node::expression::MOD * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processLT(cdk::node::expression::LT * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processLE(cdk::node::expression::LE * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processGE(cdk::node::expression::GE * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processGT(cdk::node::expression::GT * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processNE(cdk::node::expression::NE * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processEQ(cdk::node::expression::EQ * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processAND(tll::node::expression::AND *const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processMEM(tll::node::expression::MEM *const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processOR(tll::node::expression::OR *const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processPOS(tll::node::expression::POS *const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processPOT(tll::node::expression::POT *const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processSIMETRIC(tll::node::expression::SIMETRIC *const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processAssignmentNode (tll::node::AssignmentNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processBlockNode (tll::node::BlockNode * const node, int lvl){
	cdk::node::Sequence *seq = node->declarations();
	  if(seq != NULL){
	    for (size_t i = 0; i < seq->size(); i++) {
	      seq->node(i)->accept(this, lvl+2);
	    }
	  }
}

void tll::semantics::Offset::processFunctionDeclNode (tll::node::FunctionDeclNode * const node, int lvl){

}
void tll::semantics::Offset::processFunctionDefNode (tll::node::FunctionDefNode * const node, int lvl){

}

void tll::semantics::Offset::processPrintNode(tll::node::PrintNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processPublicNode(tll::node::PublicNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processReadNode(tll::node::expression::ReadNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processUseNode(tll::node::UseNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processVariableNode(tll::node::VariableNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processFunctionCallNode(tll::node::expression::FunctionCallNode * const node, int lvl){

}

void tll::semantics::Offset::processIndexNode(tll::node::expression::IndexNode * const node, int lvl){

}

void tll::semantics::Offset::processInvocationNode(tll::node::expression::InvocationNode * const node, int lvl){

}

void tll::semantics::Offset::processLeftValue(tll::node::expression::LeftValue * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processLoadValue(tll::node::expression::LoadValue * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processDoNode(tll::node::instructions::DoNode * const node, int lvl){
	node->block()->accept(this, lvl+2);
}

void tll::semantics::Offset::processDoElseNode (tll::node::instructions::DoElseNode * const node, int lvl){
	 node->block()->accept(this, lvl+2);
	 node->elseblock()->accept(this, lvl+2);
}

void tll::semantics::Offset::processForNode(tll::node::instructions::ForNode * const node, int lvl){
	 node->block()->accept(this, lvl+2);
}

void tll::semantics::Offset::processForVarNode(tll::node::instructions::ForVarNode * const node, int lvl){
	 node->block()->accept(this, lvl+2);
}

void tll::semantics::Offset::processIfElseNode(tll::node::instructions::IfElseNode * const node, int lvl){

	/*Offset* offset_2 = new Offset(this->getOstream(),this->getSymbolTable());
	Offset* offset_3 = new Offset(this->getOstream(),this->getSymbolTable());
	node->thenblock()->accept(this, lvl+2);

	  node->elseblock()->accept(this, lvl+2);
	  chooseOffSet(offset_2,offset_3);*/

}

void tll::semantics::Offset::processIfNode(tll::node::instructions::IfNode * const node, int lvl){
	 node->block()->accept(this, lvl+2);
}

void tll::semantics::Offset::processNextNode(tll::node::instructions::NextNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processReturnNode(tll::node::instructions::ReturnNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processStopNode(tll::node::instructions::StopNode * const node, int lvl){
	/*empty*/
}

void tll::semantics::Offset::processWhileElseNode(tll::node::instructions::WhileElseNode * const node, int lvl){
	  node->block()->accept(this, lvl+2);
	  node->elseblock()->accept(this, lvl+2);
}

void tll::semantics::Offset::processWhileNode(tll::node::instructions::WhileNode * const node, int lvl){
	  node->block()->accept(this, lvl+2);
}
