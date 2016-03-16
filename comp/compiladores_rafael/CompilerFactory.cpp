// $Id: CompilerFactory.cpp,v 1.1 2012-03-06 21:44:34 ist13500 Exp $ -*- c++ -*-
/*
 * $Log: CompilerFactory.cpp,v $
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.2  2009/03/15 19:21:14  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.1  2009/03/02 17:40:20  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.3  2009/02/20 06:04:35  david
 * TLL in new version. The new CDK is independent from particular
 * tools (such as Flex and BYACC). Must adapt. This is the first version
 * and will probably change.
 *
 * Revision 1.1  2007/03/14 01:20:19  david
 * Changed compiler implementation to use evaluation strategy objects
 * instead of functions. These strategies are selected according to the
 * target selected from the command line options or from clues such as
 * the output file extension.
 *
 * Revision 1.1  2007/03/13 00:26:20  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 */

#include "CompilerFactory.h"
#include "syntax/FlexBYACC.h"

/**
 * This object is automatically registered by the constructor in the
 * superclass' language registry.
 */
tll::CompilerFactory tll::CompilerFactory::_thisFactory("tll");

/**
 * Create a parser object for the TLL language.
 * This method is now private and is called only from the compiler creation
 * method.
 * @param name name of the input file (for debug only)
 * @return parser object pointer
 * @see createCompiler
 */
cdk::syntax::Parser *tll::CompilerFactory::createParser(const char *name) {
  tll::syntax::FlexBYACC *parser = new tll::syntax::FlexBYACC();
  parser->scanner(new TLLScanner(NULL, NULL));
  return parser;
}

/**
 * Create a compiler object for a given language.
 * @param name name of the language handled by the compiler
 * @return compiler object pointer
 */
cdk::Compiler *tll::CompilerFactory::createCompiler(const char *name) {
  cdk::syntax::Parser *parser = createParser(name);
  return new cdk::Compiler(name, parser);
}
