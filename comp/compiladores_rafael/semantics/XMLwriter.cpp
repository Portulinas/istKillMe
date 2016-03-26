// $Id: XMLwriter.cpp,v 1.33 2012-05-16 18:22:36 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: XMLwriter.cpp,v $
 * Revision 1.33  2012-05-16 18:22:36  ist169643
 * *** empty log message ***
 *
 * Revision 1.32  2012-05-15 16:04:50  ist169643
 * stuff
 *
 * Revision 1.31  2012-05-13 11:06:54  ist169643
 * *** empty log message ***
 *
 * Revision 1.30  2012-05-13 10:25:30  ist169643
 * read node Moved
 *
 * Revision 1.29  2012-05-12 11:18:25  ist169643
 * Expression types added
 * types node removed
 *
 * Revision 1.28  2012-04-20 10:23:28  uid169630
 * visitors fixed
 *
 * Revision 1.27  2012-04-19 12:30:29  ist169630
 * functioncallnode moved to expressions
 *
 * Revision 1.26  2012-04-19 09:47:25  ist169643
 * yacc flex and some nodes updated
 *
 * Revision 1.25  2012-04-18 22:06:50  ist169630
 * Literal Node still not fixed
 *
 * Revision 1.24  2012-04-14 09:59:37  ist169643
 * ProgramNode and Identity deleted and some bugs fixed
 *
 * Revision 1.23  2012-04-11 07:55:38  ist169630
 * moved
 *
 * Revision 1.22  2012-04-10 14:50:06  ist169630
 * *** empty log message ***
 *
 * Revision 1.21  2012-04-10 13:48:43  ist169630
 * O rafael é mau.
 *
 * Revision 1.20  2012-04-10 13:29:59  uid169643
 * fuction up to date
 *
 * Revision 1.19  2012-04-09 13:02:54  ist169630
 * IntegerNode bug solved
 *
 * Revision 1.18  2012-04-09 10:10:31  ist169643
 * OSKADASD
 *
 * Revision 1.17  2012-03-29 22:43:08  ist169643
 * weee 2 new nodes weeee
 *
 * Revision 1.16  2012-03-29 18:06:30  ist169643
 * está organizado!!!
 *
 * Revision 1.15  2012-03-29 15:39:58  ist169643
 * Version [Loading 98%]
 *
 * Revision 1.14  2012-03-29 10:48:17  ist169643
 * epah todos os visitores Conhecidos(com todo a frente) foram feitos
 *
 * Revision 1.13  2012-03-28 23:20:27  ist169643
 * all bugs corrected (i hope)
 *
 * Revision 1.12  2012-03-28 22:33:35  ist169643
 * some errors corrected
 *
 * Revision 1.11  2012-03-28 19:07:27  ist169630
 * *** empty log message ***
 *
 * Revision 1.10  2012-03-28 18:49:57  ist169630
 * *** empty log message ***
 *
 * Revision 1.9  2012-03-28 09:09:06  ist169643
 * something something [do updated]
 *
 * Revision 1.8  2012-03-28 09:03:37  ist169630
 * *** empty log message ***
 *
 * Revision 1.7  2012-03-27 20:01:35  ist169630
 * *** empty log message ***
 *
 * Revision 1.6  2012-03-27 17:28:03  ist169643
 * names updated
 *
 * Revision 1.5  2012-03-27 16:39:01  ist169643
 * [Next Return Stop Varivel Qualificador e Tipo ]Nodes adicionados
 *
 * Revision 1.4  2012-03-25 14:12:12  ist169643
 * *** empty log message ***
 *
 * Revision 1.3  2012-03-24 16:36:07  ist169643
 * *** empty log message ***
 *
 * Revision 1.2  2012-03-23 11:40:34  ist169643
 * *** empty log message ***
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.7  2011/03/07 02:27:04  david
 * Added simple left value for read and assignment operations.
 *
 * Revision 1.6  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.5  2009/03/02 17:40:21  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.4  2008/03/01 18:32:52  david
 * TLL for CDK3 (first version).
 *
 * Revision 1.2  2007/03/13 00:26:35  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 */

#include <string>
#include "semantics/XMLwriter.h"
#include "nodes/all.h"  // automatically generated
void tll::semantics::XMLwriter::processData(cdk::node::Data * const node,
		int lvl) {
	os() << std::string(lvl, ' ') << "<data size='" << node->size() << "'>";
	for (size_t i = 0; i < node->size(); i++)
		os() << ((unsigned char*) node->data())[i];
	os() << "</data>" << std::endl;
}

void tll::semantics::XMLwriter::processComposite(
		cdk::node::Composite * const node, int lvl) {

	os() << std::string(lvl, ' ') << "<composite>" << std::endl;
	for (size_t i = 0; i < node->size(); i++)
		node->at(i)->accept(this, lvl + 2);
	os() << std::string(lvl, ' ') << "</composite>" << std::endl;
}

void tll::semantics::XMLwriter::processSequence(
		cdk::node::Sequence * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<sequence size='" << node->size() << "'>"
			<< std::endl;
	for (size_t i = 0; i < node->size(); i++) {
		node->node(i)->accept(this, lvl + 2);
	}
	os() << std::string(lvl, ' ') << "</sequence>" << std::endl;
}

//public:
void tll::semantics::XMLwriter::processInteger(
		cdk::node::expression::Integer * const node, int lvl) {
	processSimple(node, lvl, "integer");
}

void tll::semantics::XMLwriter::processDouble(
		cdk::node::expression::Double * const node, int lvl) {
	processSimple(node, lvl, "double");
}

void tll::semantics::XMLwriter::processString(
		cdk::node::expression::String * const node, int lvl) {
	processSimple(node, lvl, "string");
}

void tll::semantics::XMLwriter::processIdentifier(
		cdk::node::expression::Identifier * const node, int lvl) {
	processSimple(node, lvl, "identifier");
}

//protected:
inline void tll::semantics::XMLwriter::processUnaryExpression(
		cdk::node::expression::UnaryExpression * const node, int lvl,
		const char *tag) {
	os() << std::string(lvl, ' ') << "<" << tag << ">" << std::endl;
	node->argument()->accept(this, lvl + 2);
	os() << std::string(lvl, ' ') << "</" << tag << ">" << std::endl;
}

//public:
void tll::semantics::XMLwriter::processNEG(
		cdk::node::expression::NEG * const node, int lvl) {
	processUnaryExpression(node, lvl, "NEG");
}

//protected:
inline void tll::semantics::XMLwriter::processBinaryExpression(
		cdk::node::expression::BinaryExpression * const node, int lvl,
		const char *tag) {
	os() << std::string(lvl, ' ') << "<" << tag << ">" << std::endl;
	node->left()->accept(this, lvl + 2);
	node->right()->accept(this, lvl + 2);
	os() << std::string(lvl, ' ') << "</" << tag << ">" << std::endl;
}

//public:
void tll::semantics::XMLwriter::processADD(
		cdk::node::expression::ADD * const node, int lvl) {
	processBinaryExpression(node, lvl, "ADD");
}
void tll::semantics::XMLwriter::processSUB(
		cdk::node::expression::SUB * const node, int lvl) {
	processBinaryExpression(node, lvl, "SUB");
}
void tll::semantics::XMLwriter::processMUL(
		cdk::node::expression::MUL * const node, int lvl) {
	processBinaryExpression(node, lvl, "MUL");
}
void tll::semantics::XMLwriter::processDIV(
		cdk::node::expression::DIV * const node, int lvl) {
	processBinaryExpression(node, lvl, "DIV");
}
void tll::semantics::XMLwriter::processMOD(
		cdk::node::expression::MOD * const node, int lvl) {
	processBinaryExpression(node, lvl, "MOD");
}
void tll::semantics::XMLwriter::processLT(
		cdk::node::expression::LT * const node, int lvl) {
	processBinaryExpression(node, lvl, "LT");
}
void tll::semantics::XMLwriter::processLE(
		cdk::node::expression::LE * const node, int lvl) {
	processBinaryExpression(node, lvl, "LE");
}
void tll::semantics::XMLwriter::processGE(
		cdk::node::expression::GE * const node, int lvl) {
	processBinaryExpression(node, lvl, "GE");
}
void tll::semantics::XMLwriter::processGT(
		cdk::node::expression::GT * const node, int lvl) {
	processBinaryExpression(node, lvl, "GT");
}
void tll::semantics::XMLwriter::processNE(
		cdk::node::expression::NE * const node, int lvl) {
	processBinaryExpression(node, lvl, "NE");
}
void tll::semantics::XMLwriter::processEQ(
		cdk::node::expression::EQ * const node, int lvl) {
	processBinaryExpression(node, lvl, "EQ");
}

void tll::semantics::XMLwriter::processAND(
		tll::node::expression::AND * const node, int lvl) {
	processBinaryExpression(node, lvl, "AND");
}
void tll::semantics::XMLwriter::processOR(
		tll::node::expression::OR * const node, int lvl) {
	processBinaryExpression(node, lvl, "OR");
}
void tll::semantics::XMLwriter::processPOT(
		tll::node::expression::POT * const node, int lvl) {
	processBinaryExpression(node, lvl, "POT");
}
void tll::semantics::XMLwriter::processPOS(
		tll::node::expression::POS * const node, int lvl) {
	processUnaryExpression(node, lvl, "POS");
}
void tll::semantics::XMLwriter::processInvocationNode(
		tll::node::expression::InvocationNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<invocation>" << std::endl;
	os() << std::string(lvl + 2, ' ') << node->ident() << std::endl;
	os() << std::string(lvl, ' ') << "</invocation>" << std::endl;
}
void tll::semantics::XMLwriter::processIndexNode(
		tll::node::expression::IndexNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<index>" << std::endl;
	os() << std::string(lvl + 2, ' ') << node->pointer() << std::endl;
	os() << std::string(lvl, ' ') << "</index>" << std::endl;
}
void tll::semantics::XMLwriter::processSIMETRIC(
		tll::node::expression::SIMETRIC * const node, int lvl) {
	processUnaryExpression(node, lvl, "SIMETRIC");
}

void tll::semantics::XMLwriter::processMEM(
		tll::node::expression::MEM * const node, int lvl) {
	processUnaryExpression(node, lvl, "MEM");
}
void tll::semantics::XMLwriter::processLeftValue(
		tll::node::expression::LeftValue * const node, int lvl) {
	processSimple(node, lvl, "lvalue");
}

void tll::semantics::XMLwriter::processPrintNode(
		tll::node::PrintNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<print>" << std::endl;
	node->argument()->accept(this, lvl + 2);
	os() << std::string(lvl, ' ') << "</print>" << std::endl;
}

void tll::semantics::XMLwriter::processReadNode(
		tll::node::expression::ReadNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<read>" << std::endl;
	//node->argument()->accept(this, lvl + 2);
	os() << std::string(lvl, ' ') << "</read>" << std::endl;
}
void tll::semantics::XMLwriter::processDoElseNode(
		tll::node::instructions::DoElseNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<do-else>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<block>" << std::endl;
	node->block()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</block>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<condition>" << std::endl;
	node->condition()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</condition>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<else>" << std::endl;
	node->elseblock()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</else>" << std::endl;
	os() << std::string(lvl, ' ') << "</do-else>" << std::endl;
}
void tll::semantics::XMLwriter::processDoNode(
		tll::node::instructions::DoNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<do>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<block>" << std::endl;
	node->block()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</block>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<condition>" << std::endl;
	node->condition()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</condition>" << std::endl;
	os() << std::string(lvl, ' ') << "</do>" << std::endl;
}

void tll::semantics::XMLwriter::processWhileNode(
		tll::node::instructions::WhileNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<while>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<condition>" << std::endl;
	node->condition()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</condition>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<block>" << std::endl;
	node->block()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</block>" << std::endl;
	os() << std::string(lvl, ' ') << "</while>" << std::endl;
}

void tll::semantics::XMLwriter::processWhileElseNode(
		tll::node::instructions::WhileElseNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<while-else>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<condition>" << std::endl;
	node->condition()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</condition>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<block>" << std::endl;
	node->block()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</block>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<else>" << std::endl;
	node->elseblock()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</else>" << std::endl;
	os() << std::string(lvl, ' ') << "</while-else>" << std::endl;
}

void tll::semantics::XMLwriter::processForNode(
		tll::node::instructions::ForNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<for>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<init>" << std::endl;
	node->init()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</init>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<condition>" << std::endl;
	node->condition()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</condition>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<incr>" << std::endl;
	node->incr()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</incr>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<block>" << std::endl;
	node->block()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</block>" << std::endl;
	os() << std::string(lvl, ' ') << "</for>" << std::endl;
}
void tll::semantics::XMLwriter::processForVarNode(
		tll::node::instructions::ForVarNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<for>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<init>" << std::endl;
	//node->init()->accept(this, lvl + 4); //TODO
	os() << std::string(lvl + 2, ' ') << "</init>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<condition>" << std::endl;
	node->condition()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</condition>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<incr>" << std::endl;
	node->incr()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</incr>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<block>" << std::endl;
	node->block()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</block>" << std::endl;
	os() << std::string(lvl, ' ') << "</for>" << std::endl;
}

void tll::semantics::XMLwriter::processAssignmentNode(tll::node::AssignmentNode * const node,int lvl) {
	os() << std::string(lvl, ' ') << "<assignment>" << std::endl;
	node->lvalue()->accept(this, lvl + 2);
	os() << std::string(lvl + 2, ' ') << "<rvalue>" << std::endl;
	node->rvalue()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</rvalue>" << std::endl;
	os() << std::string(lvl, ' ') << "</assignment>" << std::endl;
}

void tll::semantics::XMLwriter::processIfNode( tll::node::instructions::IfNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<if>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<condition>" << std::endl;
	node->condition()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</condition>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<then>" << std::endl;
	node->block()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</then>" << std::endl;
	os() << std::string(lvl, ' ') << "</if>" << std::endl;
}

void tll::semantics::XMLwriter::processIfElseNode( tll::node::instructions::IfElseNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<if>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<condition>" << std::endl;
	node->condition()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</condition>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<then>" << std::endl;
	node->thenblock()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</then>" << std::endl;
	os() << std::string(lvl + 2, ' ') << "<else>" << std::endl;
	node->elseblock()->accept(this, lvl + 4);
	os() << std::string(lvl + 2, ' ') << "</else>" << std::endl;
	os() << std::string(lvl, ' ') << "</if>" << std::endl;
}

void tll::semantics::XMLwriter::processNextNode( tll::node::instructions::NextNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<next>" << std::endl;
	os() << std::string(lvl + 2, ' ') << node->num() << std::endl;
	os() << std::string(lvl, ' ') << "</next>" << std::endl;
}

void tll::semantics::XMLwriter::processReturnNode(tll::node::instructions::ReturnNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<return>" << std::endl;
	os() << std::string(lvl, ' ') << "</return>" << std::endl;
}



void tll::semantics::XMLwriter::processVariableNode( tll::node::VariableNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<variable>" << std::endl;
	os() << std::string(lvl + 2, ' ') << node->name() << std::endl;
	os() << std::string(lvl, ' ') << "</variable>" << std::endl;

}

void tll::semantics::XMLwriter::processStopNode( tll::node::instructions::StopNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<stop>" << std::endl;
	os() << std::string(lvl + 2, ' ') << node->num() << std::endl;
	os() << std::string(lvl, ' ') << "</stop>" << std::endl;

}

void tll::semantics::XMLwriter::processQualifierNode( tll::node::QualifierNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<qualifier>" << std::endl;
	os() << std::string(lvl, ' ') << "</qualifier>" << std::endl;

}

void tll::semantics::XMLwriter::processUseNode(tll::node::UseNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<use>" << std::endl;
	os() << std::string(lvl, ' ') << "</use>" << std::endl;
}
void tll::semantics::XMLwriter::processPublicNode(tll::node::PublicNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<public>" << std::endl;
	os() << std::string(lvl, ' ') << "</public>" << std::endl;

}

















void tll::semantics::XMLwriter::processBlockNode( tll::node::BlockNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<block>" << std::endl;
	os() << std::string(lvl, ' ') << "</block>" << std::endl;

}




void tll::semantics::XMLwriter::processFunctionDeclNode( tll::node::FunctionDeclNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<functionDeclaration>" << std::endl;
	os() << std::string(lvl, ' ') << "</functionDeclaration>" << std::endl;

}

void tll::semantics::XMLwriter::processFunctionDefNode( tll::node::FunctionDefNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<functionDefinition>" << std::endl;
	os() << std::string(lvl, ' ') << "</functionDefinition>" << std::endl;

}

void tll::semantics::XMLwriter::processFunctionCallNode( tll::node::expression::FunctionCallNode * const node, int lvl) {
	os() << std::string(lvl, ' ') << "<functionCall>" << std::endl;
	os() << std::string(lvl, ' ') << "</functionCall>" << std::endl;

}

//---------------------------------------------------------------------------
//     T H E    E N D
//---------------------------------------------------------------------------
