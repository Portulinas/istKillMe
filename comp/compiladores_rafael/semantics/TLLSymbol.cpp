// $Id: TLLSymbol.cpp,v 1.1 2012-03-06 21:44:34 ist13500 Exp $
/*
 * $Log: TLLSymbol.cpp,v $
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.1  2012/02/18 19:37:59  david
 * Updated TLL to support the new semantic analysis in CDK7.
 * Debug options are now integrated with semantic analysis, eliminating a long-lived
 * hack in the evaluators. Renamed Symbol to TLLSymbol, to emphasize
 * that it is language-specific.
 *
 * Revision 1.2  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.1  2009/03/02 17:40:21  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.1  2009/03/01 20:40:34  david
 * Class Symbol is now a part of TLL.
 *
 */
#include "semantics/TLLSymbol.h"
