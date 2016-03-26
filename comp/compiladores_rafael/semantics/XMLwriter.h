// $Id: XMLwriter.h,v 1.26 2012-05-15 16:04:50 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: XMLwriter.h,v $
 * Revision 1.26  2012-05-15 16:04:50  ist169643
 * stuff
 *
 * Revision 1.25  2012-05-13 11:06:55  ist169643
 * *** empty log message ***
 *
 * Revision 1.24  2012-05-13 10:25:30  ist169643
 * read node Moved
 *
 * Revision 1.23  2012-05-12 11:18:25  ist169643
 * Expression types added
 * types node removed
 *
 * Revision 1.22  2012-04-19 12:30:29  ist169630
 * functioncallnode moved to expressions
 *
 * Revision 1.21  2012-04-19 09:47:25  ist169643
 * yacc flex and some nodes updated
 *
 * Revision 1.20  2012-04-18 22:06:50  ist169630
 * Literal Node still not fixed
 *
 * Revision 1.19  2012-04-14 09:59:37  ist169643
 * ProgramNode and Identity deleted and some bugs fixed
 *
 * Revision 1.18  2012-04-10 14:50:07  ist169630
 * *** empty log message ***
 *
 * Revision 1.17  2012-03-29 22:43:08  ist169643
 * weee 2 new nodes weeee
 *
 * Revision 1.16  2012-03-29 18:06:30  ist169643
 * está organizado!!!
 *
 * Revision 1.15  2012-03-29 15:39:59  ist169643
 * Version [Loading 98%]
 *
 * Revision 1.14  2012-03-29 10:48:18  ist169643
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
 * Revision 1.7  2012-03-27 20:01:36  ist169630
 * *** empty log message ***
 *
 * Revision 1.6  2012-03-27 17:28:04  ist169643
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
 * Revision 1.2  2012-03-23 11:32:25  ist169643
 * *** empty log message ***
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.8  2012/02/18 19:37:58  david
 * Updated TLL to support the new semantic analysis in CDK7.
 * Debug options are now integrated with semantic analysis, eliminating a long-lived
 * hack in the evaluators. Renamed Symbol to TLLSymbol, to emphasize
 * that it is language-specific.
 *
 * Revision 1.7  2011/03/07 02:27:04  david
 * Added simple left value for read and assignment operations.
 *
 * Revision 1.6  2009/03/15 19:21:14  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.5  2009/03/02 17:40:20  david
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

#ifndef __TLL_SEMANTICS_XMLWRITER_H__
#define __TLL_SEMANTICS_XMLWRITER_H__

#include <string>
#include <iostream>
#include "semantics/SemanticProcessor.h"

namespace tll {
  namespace semantics {

    //!
    //! Print nodes as XML elements to the output stream.
    //!
    class XMLwriter: public virtual SemanticProcessor {

    public:
      XMLwriter(std::ostream &os = std::cout, bool debug = false) :
        SemanticProcessor(os, debug) {
      }

    public:
      ~XMLwriter() {
        os().flush();
      }

    public:
      void processNode(cdk::node::Node * const node, int lvl) {
      }
      void processNil(cdk::node::Nil * const node, int lvl) {
      }
      void processData(cdk::node::Data * const node, int lvl);
      void processComposite(cdk::node::Composite * const node, int lvl);
      void processSequence(cdk::node::Sequence * const node, int lvl);

    protected:
      template<typename T>
      void processSimple(cdk::node::expression::Simple<T> * const node, int lvl, const char *tag) {
        os() << std::string(lvl, ' ') << "<" << tag << ">" << node->value() << "</" << tag << ">"
            << std::endl;
      }

    public:
      template<typename T> void processSimple(cdk::node::expression::Simple<T> * const node,
                                              int lvl) {
      }
      void processInteger(cdk::node::expression::Integer * const node, int lvl);
      void processDouble(cdk::node::expression::Double * const node, int lvl);
      void processString(cdk::node::expression::String * const node, int lvl);
      void processIdentifier(cdk::node::expression::Identifier * const node, int lvl);

    protected:
      void processUnaryExpression(cdk::node::expression::UnaryExpression * const node, int lvl,
                                  const char *tag);

    public:
      void processUnaryExpression(cdk::node::expression::UnaryExpression * const node, int lvl) {
      }
      void processNEG(cdk::node::expression::NEG * const node, int lvl);

    protected:
      void processBinaryExpression(cdk::node::expression::BinaryExpression * const node, int lvl,
                                   const char *tag);

    public:
      void processBinaryExpression(cdk::node::expression::BinaryExpression * const node, int lvl) {
      }
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
      void processAND(tll::node::expression::AND * const node, int lvl);
      void processOR(tll::node::expression::OR * const node, int lvl);
      void processSIMETRIC(tll::node::expression::SIMETRIC * const node, int lvl);
      void processPOT(tll::node::expression::POT * const node, int lvl);
      void processMEM(tll::node::expression::MEM * const node, int lvl);
      void processPOS(tll::node::expression::POS * const node, int lvl);
      void processInvocationNode(tll::node::expression::InvocationNode * const node, int lvl);
      void processIndexNode(tll::node::expression::IndexNode * const node, int lvl);


    public:
      void processLeftValue(tll::node::expression::LeftValue * const node, int lvl);

    public:
      void processPrintNode(tll::node::PrintNode * const node, int lvl);
      void processReadNode(tll::node::expression::ReadNode * const node, int lvl);
      void processDoElseNode(tll::node::instructions::DoElseNode * const node, int lvl);
      void processDoNode(tll::node::instructions::DoNode * const node, int lvl);
      void processForNode(tll::node::instructions::ForNode * const node, int lvl);
      void processForVarNode(tll::node::instructions::ForVarNode * const node, int lvl);
      void processWhileNode(tll::node::instructions::WhileNode * const node, int lvl);
      void processWhileElseNode(tll::node::instructions::WhileElseNode * const node, int lvl);
      void processAssignmentNode(tll::node::AssignmentNode * const node, int lvl);
      void processIfNode(tll::node::instructions::IfNode * const node, int lvl);
      void processIfElseNode(tll::node::instructions::IfElseNode * const node, int lvl);
      //void processElseIfNode(tll::node::ElseIfNode * const node, int lvl);
      void processNextNode(tll::node::instructions::NextNode * const node, int lvl);
      void processQualifierNode(tll::node::QualifierNode * const node, int lvl);
      void processReturnNode(tll::node::instructions::ReturnNode * const node, int lvl);

      void processVariableNode(tll::node::VariableNode * const node, int lvl);
      void processStopNode(tll::node::instructions::StopNode * const node, int lvl);
      void processUseNode(tll::node::UseNode * const node, int lvl);
      void processPublicNode(tll::node::PublicNode * const node, int lvl);
	  void processBlockNode(tll::node::BlockNode * const node,int lvl);
	  void processFunctionDeclNode(tll::node::FunctionDeclNode * const node, int lvl);
	  void processFunctionDefNode(tll::node::FunctionDefNode * const node, int lvl);
	  void processFunctionCallNode(tll::node::expression::FunctionCallNode * const node, int lvl);
    }; // class

  } // namespace semantics
} // namespace tll

#endif

