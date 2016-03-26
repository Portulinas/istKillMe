// $Id: WhileNode.cpp,v 1.1 2012-03-29 18:05:59 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: WhileNode.cpp,v $
 * Revision 1.1  2012-03-29 18:05:59  ist169643
 * está organizado!!!
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.4  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.3  2009/03/02 17:40:22  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 */
#include "nodes/instructions/WhileNode.h"
