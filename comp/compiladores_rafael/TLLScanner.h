// $Id: TLLScanner.h,v 1.1 2012-03-06 21:44:34 ist13500 Exp $ -*- c++ -*-
/*
 * $Log: TLLScanner.h,v $
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.10  2009/03/15 19:21:14  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.8  2009/03/02 20:16:14  david
 * Corrected stupid recursion bug.
 *
 * Revision 1.7  2009/02/20 06:04:35  david
 * TLL in new version. The new CDK is independent from particular
 * tools (such as Flex and BYACC). Must adapt. This is the first version
 * and will probably change.
 *
 */
#ifndef __TLLSCANNER_H__
#define __TLLSCANNER_H__

#undef yyFlexLexer
#define yyFlexLexer TLLScanner
#include <FlexLexer.h>

#endif
