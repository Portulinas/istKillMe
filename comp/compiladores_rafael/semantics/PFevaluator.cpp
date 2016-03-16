// $Id: PFevaluator.cpp,v 1.1 2012-03-06 21:44:34 ist13500 Exp $
/*
 * $Log: PFevaluator.cpp,v $
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.6  2012/02/18 19:37:58  david
 * Updated TLL to support the new semantic analysis in CDK7.
 * Debug options are now integrated with semantic analysis, eliminating a long-lived
 * hack in the evaluators. Renamed Symbol to TLLSymbol, to emphasize
 * that it is language-specific.
 *
 * Revision 1.5  2011/03/06 16:12:42  david
 * Updated for CDK6.
 *
 * Revision 1.4  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.3  2009/03/02 17:40:21  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.1  2007/03/14 01:20:28  david
 * Changed compiler implementation to use evaluation strategy objects
 * instead of functions. These strategies are selected according to the
 * target selected from the command line options or from clues such as
 * the output file extension.
 *
 */

//---------------------------------------------------------------------------

#include <cdk/nodes/Node.h>
#include <cdk/Compiler.h>
#include <cdk/semantics/SymbolTable.h>
#include <cdk/generators/ix86.h>
#include "semantics/PFevaluator.h"
#include "semantics/PFwriter.h"
#include "semantics/TLLSymbol.h"

//---------------------------------------------------------------------------

/**
 * Postfix for ix86.
 * @var create and register an evaluator for ASM targets.
 */
tll::semantics::PFevaluator tll::semantics::PFevaluator::_thisEvaluator("asm");

//---------------------------------------------------------------------------

bool tll::semantics::PFevaluator::evaluate(cdk::Compiler *compiler) {
  std::ostream &os = compiler->ostream();

  // this symbol table will be used to check identifiers
  cdk::semantics::SymbolTable<TLLSymbol> symtab;
  cdk::generator::ix86 pf(os, compiler->debug());

  // we must open the outer function
  //
  pf.TEXT();
  pf.ALIGN();
  pf.GLOBAL("_main", pf.FUNC());
  pf.LABEL("_main");
  pf.ENTER(0);

  // now the rest of the nasm code will be generated
  // identifiers will be checked during code generation
  //
  PFwriter pfwriter(os, compiler->debug(), symtab, pf);
  compiler->ast()->accept(&pfwriter, 0);

  // We must close the outer function
  // the output stream must be the same used for the two processors
  //
  pf.INT(0);
  pf.POP();
  pf.LEAVE();
  pf.RET();

  // these are just a few library function imports
  //
  pf.EXTERN("readi");
  pf.EXTERN("printi");
  pf.EXTERN("prints");
  pf.EXTERN("println");

  return true;
}

//---------------------------------------------------------------------------
//     T H E    E N D
//---------------------------------------------------------------------------
