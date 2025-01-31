//
// **** AUTOMATICALLY GENERATED BY mknodedecls.pl -- DO NOT EDIT ****
//
#ifdef __NODE_DECLARATIONS_ONLY__

//---------------------------------------------------------------------------
//     THESE ARE PREDEFINED NODES, AVAILABLE FROM THE CDK
//---------------------------------------------------------------------------

namespace cdk {
  class basic_node;     class nil_node;      class data_node;
  class composite_node; class sequence_node; class expression_node;
  template <typename StoredType> class simple_value_node;
  class double_node; class integer_node; class string_node; 
  class identifier_node;
  class unary_expression_node; 
  class neg_node;
  class binary_expression_node;
  class add_node;   class sub_node; class mul_node; class div_node;
  class mod_node;   class lt_node;  class le_node;  class ge_node;  
  class gt_node;    class eq_node;  class ne_node;
} // namespace cdk

//---------------------------------------------------------------------------
//     THESE ARE THE NODES DEFINED SPECIFICALLY FOR THIS APPLICATION
//---------------------------------------------------------------------------

namespace zu {
class continue_node; 
class alloc_node; 
class identifier_node; 
class functioninvocation_node; 
class address_node; 
class break_node; 
class declaration_node; 
class lvalue_node; 
class functiondefinition_node; 
class or_node; 
class index_node; 
class identity_node; 
class read_node; 
class return_node; 
class evaluation_node; 
class rvalue_node; 
class if_else_node; 
class not_node; 
class and_node; 
class assignment_node; 
class for_node; 
class if_node; 
class block_node; 
class print_node; 
class functiondeclaration_node; 

} // namespace zu

//---------------------------------------------------------------------------
//     A L I A S E S
//---------------------------------------------------------------------------

#else /* !defined(__NODE_DECLARATIONS_ONLY__) */

#ifndef __AUTOMATIC_NODE_ALLNODES_H__
#define __AUTOMATIC_NODE_ALLNODES_H__

//---------------------------------------------------------------------------
//     THESE ARE PREDEFINED NODES, AVAILABLE FROM THE CDK
//---------------------------------------------------------------------------

#include <cdk/ast/basic_node.h>
#include <cdk/ast/data_node.h>
#include <cdk/ast/nil_node.h>
#include <cdk/ast/composite_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/integer_node.h>
#include <cdk/ast/double_node.h>
#include <cdk/ast/string_node.h>
#include <cdk/ast/identifier_node.h>
#include <cdk/ast/neg_node.h>
#include <cdk/ast/add_node.h>
#include <cdk/ast/sub_node.h>
#include <cdk/ast/mul_node.h>
#include <cdk/ast/div_node.h>
#include <cdk/ast/mod_node.h>
#include <cdk/ast/lt_node.h>
#include <cdk/ast/gt_node.h>
#include <cdk/ast/ge_node.h>
#include <cdk/ast/le_node.h>
#include <cdk/ast/ne_node.h>
#include <cdk/ast/eq_node.h>

//---------------------------------------------------------------------------
//     THESE ARE THE NODES DEFINED SPECIFICALLY FOR THIS APPLICATION
//---------------------------------------------------------------------------

#include "ast/continue_node.h"
#include "ast/alloc_node.h"
#include "ast/identifier_node.h"
#include "ast/functioninvocation_node.h"
#include "ast/address_node.h"
#include "ast/break_node.h"
#include "ast/declaration_node.h"
#include "ast/lvalue_node.h"
#include "ast/functiondefinition_node.h"
#include "ast/or_node.h"
#include "ast/index_node.h"
#include "ast/identity_node.h"
#include "ast/read_node.h"
#include "ast/return_node.h"
#include "ast/evaluation_node.h"
#include "ast/rvalue_node.h"
#include "ast/if_else_node.h"
#include "ast/not_node.h"
#include "ast/and_node.h"
#include "ast/assignment_node.h"
#include "ast/for_node.h"
#include "ast/if_node.h"
#include "ast/block_node.h"
#include "ast/print_node.h"
#include "ast/functiondeclaration_node.h"


//---------------------------------------------------------------------------
//     T H E    E N D
//---------------------------------------------------------------------------

#endif /* !defined(__AUTOMATIC_NODE_ALLNODES_H__) */

#endif /* !defined(__NODE_DECLARATIONS_ONLY__) */
