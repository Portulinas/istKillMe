// $Id: SemanticProcessor.h,v 1.25 2012-05-15 10:27:11 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: SemanticProcessor.h,v $
 * Revision 1.25  2012-05-15 10:27:11  ist169643
 * *** empty log message ***
 *
 * Revision 1.24  2012-05-13 11:06:54  ist169643
 * *** empty log message ***
 *
 * Revision 1.23  2012-05-13 10:25:30  ist169643
 * read node Moved
 *
 * Revision 1.22  2012-05-12 11:18:24  ist169643
 * Expression types added
 * types node removed
 *
 * Revision 1.21  2012-04-19 12:30:29  ist169630
 * functioncallnode moved to expressions
 *
 * Revision 1.20  2012-04-19 09:47:24  ist169643
 * yacc flex and some nodes updated
 *
 * Revision 1.19  2012-04-18 22:06:50  ist169630
 * Literal Node still not fixed
 *
 * Revision 1.18  2012-04-14 09:59:36  ist169643
 * ProgramNode and Identity deleted and some bugs fixed
 *
 * Revision 1.17  2012-04-10 14:50:07  ist169630
 * *** empty log message ***
 *
 * Revision 1.16  2012-03-29 22:43:08  ist169643
 * weee 2 new nodes weeee
 *
 * Revision 1.15  2012-03-29 18:06:30  ist169643
 * está organizado!!!
 *
 * Revision 1.14  2012-03-29 15:39:58  ist169643
 * Version [Loading 98%]
 *
 * Revision 1.13  2012-03-29 10:48:17  ist169643
 * epah todos os visitores Conhecidos(com todo a frente) foram feitos
 *
 * Revision 1.12  2012-03-28 23:20:27  ist169643
 * all bugs corrected (i hope)
 *
 * Revision 1.11  2012-03-28 22:33:35  ist169643
 * some errors corrected
 *
 * Revision 1.10  2012-03-28 19:07:27  ist169630
 * *** empty log message ***
 *
 * Revision 1.9  2012-03-28 09:09:06  ist169643
 * something something [do updated]
 *
 * Revision 1.8  2012-03-28 09:03:37  ist169630
 * *** empty log message ***
 *
 * Revision 1.7  2012-03-27 20:01:36  ist169630
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
 * Revision 1.2  2012-03-23 11:07:54  ist169643
 * teste2
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.9  2012/02/18 19:37:58  david
 * Updated TLL to support the new semantic analysis in CDK7.
 * Debug options are now integrated with semantic analysis, eliminating a long-lived
 * hack in the evaluators. Renamed Symbol to TLLSymbol, to emphasize
 * that it is language-specific.
 *
 * Revision 1.8  2011/03/07 02:27:04  david
 * Added simple left value for read and assignment operations.
 *
 * Revision 1.7  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.6  2009/03/02 17:40:21  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.5  2008/03/01 18:32:52  david
 * TLL for CDK3 (first version).
 *
 * Revision 1.3  2007/03/13 00:26:34  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 */

#ifndef __TLL_SEMANTICS_SEMANTICPROCESSOR_H__
#define __TLL_SEMANTICS_SEMANTICPROCESSOR_H__

#include <string>
#include <iostream>

/* include node forward declarations */
#define __NODE_DECLARATIONS_ONLY__
#include "nodes/all.h"  // automatically generated
#undef __NODE_DECLARATIONS_ONLY__

//!
//! Print nodes as XML elements to the output stream.
//!
class SemanticProcessor {
	//! The output stream
	std::ostream &_os;

protected:
	//! Debug flag
	bool _debug;

protected:
	SemanticProcessor(std::ostream &o = std::cout, bool debug = false) :
			_os(o) {
	}
	inline std::ostream &os() {
		return _os;
	}

public:
	virtual ~SemanticProcessor() {
	}

public:
	virtual void processNode(cdk::node::Node * const node, int lvl) = 0;
	virtual void processNil(cdk::node::Nil * const node, int lvl) = 0;
	virtual void processData(cdk::node::Data * const node, int lvl) = 0;
	virtual void processComposite(cdk::node::Composite * const node,
			int lvl) = 0;
	virtual void processSequence(cdk::node::Sequence * const node, int lvl) = 0;

public:
	template<typename T> void processSimple(
			cdk::node::expression::Simple<T> * const node, int lvl) {
		throw 42;
	}
	virtual void processInteger(cdk::node::expression::Integer * const node,
			int lvl) = 0;
	virtual void processDouble(cdk::node::expression::Double * const node,
			int lvl) = 0;
	virtual void processString(cdk::node::expression::String * const node,
			int lvl) = 0;
	virtual void processIdentifier(
			cdk::node::expression::Identifier * const node, int lvl) = 0;

public:
	virtual void
	processUnaryExpression(cdk::node::expression::UnaryExpression * const node,
			int lvl) = 0;
	virtual void processNEG(cdk::node::expression::NEG * const node,
			int lvl) = 0;

public:
	virtual void processBinaryExpression(
			cdk::node::expression::BinaryExpression * const node, int lvl) = 0;
	virtual void processADD(cdk::node::expression::ADD * const node,
			int lvl) = 0;
	virtual void processSUB(cdk::node::expression::SUB * const node,
			int lvl) = 0;
	virtual void processMUL(cdk::node::expression::MUL * const node,
			int lvl) = 0;
	virtual void processDIV(cdk::node::expression::DIV * const node,
			int lvl) = 0;
	virtual void processMOD(cdk::node::expression::MOD * const node,
			int lvl) = 0;
	virtual void processLT(cdk::node::expression::LT * const node, int lvl) = 0;
	virtual void processLE(cdk::node::expression::LE * const node, int lvl) = 0;
	virtual void processGE(cdk::node::expression::GE * const node, int lvl) = 0;
	virtual void processGT(cdk::node::expression::GT * const node, int lvl) = 0;
	virtual void processNE(cdk::node::expression::NE * const node, int lvl) = 0;
	virtual void processEQ(cdk::node::expression::EQ * const node, int lvl) = 0;
	virtual void processAND(tll::node::expression::AND * const node,
			int lvl) = 0;
	virtual void processOR(tll::node::expression::OR * const node, int lvl) = 0;
	virtual void processSIMETRIC(tll::node::expression::SIMETRIC * const node,
			int lvl) = 0;
	virtual void processPOT(tll::node::expression::POT * const node,
			int lvl) = 0;
	virtual void processMEM(tll::node::expression::MEM * const node,
			int lvl) = 0;
	virtual void processPOS(tll::node::expression::POS * const node,
			int lvl) = 0;
	virtual void processInvocationNode(tll::node::expression::InvocationNode * const node,
				int lvl) = 0;
	virtual void processIndexNode(tll::node::expression::IndexNode * const node,
				int lvl) = 0;

public:
	virtual void processLeftValue(tll::node::expression::LeftValue * const node,
			int lvl) = 0;

public:
	virtual void processPrintNode(tll::node::PrintNode * const node,
			int lvl) = 0;
	virtual void processReadNode(tll::node::expression::ReadNode * const node, int lvl) = 0;
	virtual void processForNode(tll::node::instructions::ForNode * const node, int lvl) = 0;
	virtual void processForVarNode(tll::node::instructions::ForVarNode * const node,
			int lvl) = 0;
	virtual void processDoElseNode(tll::node::instructions::DoElseNode * const node,
			int lvl) = 0;
	virtual void processDoNode(tll::node::instructions::DoNode * const node, int lvl) = 0;
	virtual void processWhileNode(tll::node::instructions::WhileNode * const node,
			int lvl) = 0;
	virtual void processWhileElseNode(tll::node::instructions::WhileElseNode * const node,
			int lvl) = 0;
	virtual void processAssignmentNode(tll::node::AssignmentNode * const node,
			int lvl) = 0;
	virtual void processIfNode(tll::node::instructions::IfNode * const node, int lvl) = 0;
	virtual void processIfElseNode(tll::node::instructions::IfElseNode * const node,
			int lvl) = 0;
	//virtual void processElseIfNode(tll::node::ElseIfNode * const node,
			//int lvl) = 0;
	virtual void processNextNode(tll::node::instructions::NextNode * const node, int lvl) = 0;
	virtual void processReturnNode(tll::node::instructions::ReturnNode * const node,
			int lvl) = 0;
	virtual void processStopNode(tll::node::instructions::StopNode * const node, int lvl) = 0;
	virtual void processVariableNode(tll::node::VariableNode * const node,
			int lvl) = 0;

	virtual void processBlockNode(tll::node::BlockNode * const node,
				int lvl) = 0;
	virtual void processFunctionCallNode(tll::node::expression::FunctionCallNode * const node,
							int lvl) = 0;
	virtual void processFunctionDeclNode(tll::node::FunctionDeclNode * const node,
								int lvl) = 0;
	virtual void processFunctionDefNode(tll::node::FunctionDefNode * const node, int lvl) = 0;
};
// class

#endif
