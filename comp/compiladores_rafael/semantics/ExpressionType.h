// $Id: ExpressionType.h,v 1.2 2012-05-15 11:07:18 ist169643 Exp $ -*- c++ -*-
/*
 * $Log: ExpressionType.h,v $
 * Revision 1.2  2012-05-15 11:07:18  ist169643
 * *** empty log message ***
 *
 * Revision 1.1  2012-05-15 10:27:11  ist169643
 * *** empty log message ***
 *
 * Revision 1.3  2012/03/06 15:07:46  david
 * Added subtype to ExpressionType. This allows for more expressiveness in
 * type description.
 *
 * Revision 1.2  2011/03/06 15:30:35  david
 * Major code cleanup (but no extra features or bugs added).
 * Compilation guards are now set to CDK6.
 *
 * Revision 1.1  2010/03/22 14:55:04  david
 * Expression types are now in the semantics directory but are not part of
 * the semantics package. This is because we defined them to be
 * drop-in-replaceable. That is, if the compiler provides, in its semantics
 * directory, an ExpressionType.h file (this file must contain a class called
 * ExpressionType), then that class will be used instead of the one
 * provided by the CDK.
 *
 *
 */

#ifndef __TLL_SEMANTICS_EXPRESSIONTYPE_H__
#define __TLL_SEMANTICS_EXPRESSIONTYPE_H__

#include <cstdlib>

/**
 * This is a quick and very dirty approach to type information.
 * It is defined this way (even though it's not extensible at all)
 * for simplicity.
 *
 * Nevertheless, new types can be added simply by using other
 * integer values other than the ones listed.
 */
struct ExpressionType {
  typedef unsigned long int type;
  size_t _size; // in bytes
  type _name;

  // For supporting simple complex types (NULL by default)
  ExpressionType *_subtype;

  static const type TYPE_UNSPEC;
  static const type TYPE_INT;
  static const type TYPE_DOUBLE;
  static const type TYPE_BOOLEAN;
  static const type TYPE_STRING;
  static const type TYPE_POINTER;
  static const type TYPE_STRUCT;
  static const type TYPE_ERROR;
  static const type TYPE_VOID;
  static const type TYPE_CONST;

  inline ExpressionType() :
    _size(0), _name(TYPE_UNSPEC), _subtype(NULL) {}
  inline ExpressionType(size_t size, type name) :
    _size(size), _name(name), _subtype(NULL) {}

  inline ExpressionType(size_t size, type name, ExpressionType* subtype) :
    _size(size), _name(name), _subtype(subtype) {}
  inline size_t size() {
    return _size;
  }
  inline type name() {
    return _name;
  }
  inline ExpressionType *subtype() {
    return _subtype;
  }
};

#endif

