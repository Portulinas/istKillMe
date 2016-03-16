// $Id: CompilerFactory.h,v 1.1 2012-03-06 21:44:34 ist13500 Exp $ -*- c++ -*-
/*
 * $Log: CompilerFactory.h,v $
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
 * Revision 1.1  2007/03/14 01:20:20  david
 * Changed compiler implementation to use evaluation strategy objects
 * instead of functions. These strategies are selected according to the
 * target selected from the command line options or from clues such as
 * the output file extension.
 *
 * Revision 1.1  2007/03/13 00:26:20  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 *
 */
#ifndef __TLL_TLLCOMPILERFACTORY_H__
#define __TLL_TLLCOMPILERFACTORY_H__

#include <cdk/CompilerFactory.h>

class FlexLexer;
namespace cdk {
  class Compiler;
}

namespace tll {

  /**
   * This class implements the compiler factory for the TLL compiler.
   */
  class CompilerFactory: public cdk::CompilerFactory {
    /**
     * This object is automatically registered by the constructor in the
     * superclass' language registry.
     */
    static CompilerFactory _thisFactory;

  protected:
    /**
     * @param language name of the language handled by this factory (see .cpp file)
     */
CompilerFactory  (const char *language) :
  cdk::CompilerFactory(language) {
  }

protected:
  /**
   * Create a scanner object for the TLL language.
   * This method is now private and is called only from the compiler creation
   * method.
   * @param name name of the input file (for debug only)
   * @return scanner object pointer
   * @see createCompiler
   */
  virtual cdk::syntax::Parser *createParser(const char *name);

public:
  /**
   * Create a compiler object for a given language.
   * @param name name of the language handled by the compiler
   * @return compiler object pointer
   */
  virtual cdk::Compiler *createCompiler(const char *name);

}; // class CompilerFactory

} // namespace tll

#endif
