// $Id: TLLSymbol.h,v 1.3 2012-05-15 10:27:11 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: TLLSymbol.h,v $
 * Revision 1.3  2012-05-15 10:27:11  ist169643
 * *** empty log message ***
 *
 * Revision 1.2  2012-05-13 15:24:27  ist169643
 * typeValidator updated [AssignmentNode]
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.1  2012/02/18 19:37:58  david
 * Updated TLL to support the new semantic analysis in CDK7.
 * Debug options are now integrated with semantic analysis, eliminating a long-lived
 * hack in the evaluators. Renamed Symbol to TLLSymbol, to emphasize
 * that it is language-specific.
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
 *
 */
#ifndef __TLL_SEMANTICS_SYMBOL_H__
#define __TLL_SEMANTICS_SYMBOL_H__

#include "semantics/ExpressionType.h"
#include <string>

class TLLSymbol {
  ExpressionType *_type;
  std::string _name;
  int _value;

public:
  inline TLLSymbol(ExpressionType *type, const std::string &name, int value) :
    _type(type), _name(name), _value(value) {
  }

  inline TLLSymbol(ExpressionType *type, const char *name, int value) :
    _type(type), _name(name), _value(value) {
  }

  virtual ~TLLSymbol() {
  }

  inline ExpressionType* type() const {
    return _type;
  }
  inline const std::string &name() const {
    return _name;
  }
  inline int value() const {
    return _value;
  }
  inline int value(int v) {
    return _value = v;
  }
};

#endif
