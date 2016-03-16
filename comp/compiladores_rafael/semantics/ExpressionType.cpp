/*
 * ExpressionType.cpp
 *
 *  Created on: May 15, 2012
 *      Author: klang
 */




#include "semantics/ExpressionType.h"

const unsigned long int ExpressionType::TYPE_UNSPEC  = 0;
const unsigned long int ExpressionType::TYPE_INT     = 1UL<<0;
const unsigned long int ExpressionType::TYPE_DOUBLE  = 1UL<<1;
const unsigned long int ExpressionType::TYPE_BOOLEAN = 1UL<<2;
const unsigned long int ExpressionType::TYPE_STRING  = 1UL<<3;
const unsigned long int ExpressionType::TYPE_POINTER = 1UL<<4;
const unsigned long int ExpressionType::TYPE_STRUCT  = 1UL<<5;
const unsigned long int ExpressionType::TYPE_CONST	 = 1UL<<6;
const unsigned long int ExpressionType::TYPE_VOID    = 1UL<<31;

