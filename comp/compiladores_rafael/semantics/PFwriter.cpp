// $Id: PFwriter.cpp,v 1.45 2012-05-17 16:39:29 ist169630 Exp $ -*- c++ -*-
/*
 * $Log: PFwriter.cpp,v $
 * Revision 1.45  2012-05-17 16:39:29  ist169630
 * offset updated
 *
 * Revision 1.44  2012-05-16 18:22:36  ist169643
 * *** empty log message ***
 *
 * Revision 1.43  2012-05-16 08:34:21  ist169643
 * *** empty log message ***
 *
 * Revision 1.42  2012-05-15 18:48:46  ist169630
 * pf writer updates
 *
 * Revision 1.41  2012-05-15 18:25:03  ist169630
 * pf writer changing
 *
 * Revision 1.40  2012-05-15 17:08:04  ist169630
 * updates
 *
 * Revision 1.39  2012-05-15 16:04:50  ist169643
 * stuff
 *
 * Revision 1.38  2012-05-15 10:27:11  ist169643
 * *** empty log message ***
 *
 * Revision 1.37  2012-05-15 07:50:22  ist169643
 * *** empty log message ***
 *
 * Revision 1.36  2012-05-14 20:59:57  ist169630
 * update
 *
 * Revision 1.35  2012-05-14 14:27:10  ist169630
 * *** empty log message ***
 *
 * Revision 1.34  2012-05-14 14:16:06  ist169630
 * Type validator updated
 *
 * Revision 1.33  2012-05-14 11:26:07  ist169630
 * *** empty log message ***
 *
 * Revision 1.32  2012-05-13 11:06:54  ist169643
 * *** empty log message ***
 *
 * Revision 1.31  2012-05-13 10:25:30  ist169643
 * read node Moved
 *
 * Revision 1.30  2012-05-12 11:18:24  ist169643
 * Expression types added
 * types node removed
 *
 * Revision 1.29  2012-04-19 12:30:29  ist169630
 * functioncallnode moved to expressions
 *
 * Revision 1.28  2012-04-19 09:47:24  ist169643
 * yacc flex and some nodes updated
 *
 * Revision 1.27  2012-04-18 22:06:50  ist169630
 * Literal Node still not fixed
 *
 * Revision 1.26  2012-04-14 16:32:48  ist169643
 * very nasty things done here...
 *
 * Revision 1.25  2012-04-14 09:59:37  ist169643
 * ProgramNode and Identity deleted and some bugs fixed
 *
 * Revision 1.24  2012-04-11 07:55:38  ist169630
 * moved
 *
 * Revision 1.23  2012-04-10 13:29:59  uid169643
 * fuction up to date
 *
 * Revision 1.22  2012-04-09 10:10:31  ist169643
 * OSKADASD
 *
 * Revision 1.21  2012-03-29 22:43:08  ist169643
 * weee 2 new nodes weeee
 *
 * Revision 1.20  2012-03-29 18:06:29  ist169643
 * está organizado!!!
 *
 * Revision 1.19  2012-03-29 15:39:59  ist169643
 * Version [Loading 98%]
 *
 * Revision 1.18  2012-03-29 10:48:17  ist169643
 * epah todos os visitores Conhecidos(com todo a frente) foram feitos
 *
 * Revision 1.17  2012-03-28 23:20:27  ist169643
 * all bugs corrected (i hope)
 *
 * Revision 1.16  2012-03-28 22:33:35  ist169643
 * some errors corrected
 *
 * Revision 1.15  2012-03-28 18:49:57  ist169630
 * *** empty log message ***
 *
 * Revision 1.14  2012-03-28 18:33:32  ist169643
 * TODOOOOO
 *
 * Revision 1.13  2012-03-28 09:09:06  ist169643
 * something something [do updated]
 *
 * Revision 1.12  2012-03-27 21:42:14  ist169643
 * *** empty log message ***
 *
 * Revision 1.11  2012-03-27 20:01:36  ist169630
 * *** empty log message ***
 *
 * Revision 1.10  2012-03-27 17:28:03  ist169643
 * names updated
 *
 * Revision 1.9  2012-03-27 16:39:01  ist169643
 * [Next Return Stop Varivel Qualificador e Tipo ]Nodes adicionados
 *
 * Revision 1.8  2012-03-26 10:02:20  ist169643
 * *** empty log message ***
 *
 * Revision 1.7  2012-03-25 16:29:49  ist169643
 * PFwriter.cpp : process DoElseNode updated
 *
 * Revision 1.6  2012-03-25 14:54:36  ist169643
 * bug corrected
 *
 * Revision 1.5  2012-03-25 14:12:12  ist169643
 * *** empty log message ***
 *
 * Revision 1.4  2012-03-24 16:36:07  ist169643
 * *** empty log message ***
 *
 * Revision 1.3  2012-03-23 11:56:20  ist169643
 * *** empty log message ***
 *
 * Revision 1.2  2012-03-23 11:40:34  ist169643
 * *** empty log message ***
 *
 * Revision 1.1  2012-03-06 21:44:34  ist13500
 * This is actually Compact but renamed TLL (string level change).
 * The recognized language is still Compact, not TLL.
 *
 * Revision 1.10  2012/02/18 19:37:58  david
 * Updated TLL to support the new semantic analysis in CDK7.
 * Debug options are now integrated with semantic analysis, eliminating a long-lived
 * hack in the evaluators. Renamed Symbol to TLLSymbol, to emphasize
 * that it is language-specific.
 *
 * Revision 1.9  2011/03/07 02:27:04  david
 * Added simple left value for read and assignment operations.
 *
 * Revision 1.8  2009/03/15 19:21:15  david
 * First public revision of the CDK4-based TLL compiler.
 * Revision logs were cleaned.
 *
 * Revision 1.7  2009/03/02 17:40:21  david
 * Major changes: in addition to compiling with CDK4, TLL now has
 * its own namespace (tll). All classes are defined in it or in its
 * child namespaces. Added automatic node processing: the "nodes"
 * directory is scanned and nodes/all.h is built (contains both forward
 * declarations and include directives for all nodes -- in the appropriate
 * namespaces).
 *
 * Revision 1.5  2008/03/01 18:32:52  david
 * TLL for CDK3 (first version).
 *
 * Revision 1.3  2007/03/13 00:26:34  david
 * This version of the TLL compiler uses the new CDK2 library.
 * All nodes and visitors now use non-overloaded visitor hooks. The TLL
 * compiler now implements the abstract factory for scanners and compilers.
 */

#include <string>
#include <sstream>
#include "semantics/PFwriter.h"
#include "nodes/all.h"  // automatically generated
//---------------------------------------------------------------------------
//     THIS IS THE EVALUATOR'S DEFINITION
//---------------------------------------------------------------------------

//private:
std::string tll::semantics::PFwriter::mklbl(int lbl) {
	std::ostringstream oss;
	if (lbl < 0)
		oss << ".L" << -lbl;
	else
		oss << "_L" << lbl;
	return oss.str();
}

//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processSequence(cdk::node::Sequence * const node,
		int lvl) {
	for (size_t i = 0; i < node->size(); i++) {
		node->node(i)->accept(this, lvl);
	}
}

//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processInteger(cdk::node::expression::Integer * const node, int lvl) {
	if(_global){
	    _pf.CONST(node->value());
	  }
	  else{
	    _pf.INT(node->value()); // push an integer
	  }
}

void tll::semantics::PFwriter::processDouble(cdk::node::expression::Double * const node, int lvl) {
	if(_global){
	    _pf.DOUBLE(node->value());
	  }
	  else{
	        int lbl1;

	        /* generate the double */
	        _pf.RODATA();
	        _pf.ALIGN();
	        _pf.LABEL(mklbl(lbl1 = ++_lbl));
	        _pf.DOUBLE(node->value());

	        /* leave the address */
	        _pf.TEXT();
	        _pf.ADDR(mklbl(lbl1));
	        _pf.LOAD();
	  }

}
void tll::semantics::PFwriter::processString(cdk::node::expression::String * const node, int lvl) {
	int lbl1;

	/* generate the string */
	_pf.RODATA(); // strings are DATA readonly
	_pf.ALIGN(); // make sure we are aligned
	_pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
	_pf.STR(node->value()); // output string characters

	/* make the call */
	_pf.TEXT(); // return to the TEXT segment
	_pf.ADDR(mklbl(lbl1)); // the string to be printed
	_pf.CALL("prints"); // call the print rotine
	_pf.CALL("println"); // print a newline
	_pf.TRASH(4); // remove the string label
}

//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processIdentifier(
		cdk::node::expression::Identifier * const node, int lvl) {
	// DAVID: the horror!!
	const char *id = node->value().c_str();
	if (_symtab.find(id)) {
		_pf.ADDR(id);
		_pf.LOAD();
	}
	//TODO
}


//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processNEG(
		cdk::node::expression::NEG * const node, int lvl) {

	 try{
	  TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	  node->accept(v, lvl);

	  node->argument()->accept(this, lvl); // determine the value

	  if(node->type()->name() & ExpressionType::TYPE_INT)
	    _pf.NEG(); // 2-complement
	  else
	    _pf.DNEG();
	  }
	  catch(std::string s) {
	    std::cerr << "Error " << node->lineno() << " invalide types on NEG: " << s << std::endl;
	    return;
	  }

	/* codigo que tava antes
	 node->argument()->accept(this, lvl); // determine the value
	_pf.NEG(); // 2-complement*/
}

//---------------------------------------------------------------------------

//public:
void tll::semantics::PFwriter::processADD( cdk::node::expression::ADD * const node, int lvl) {

	try {
		TypeValidator *v = new TypeValidator(os(), _symtab, _global);
		node->accept(v, lvl);

		   if(node->type()->name() & ExpressionType::TYPE_POINTER){
			if(node->left()->type()->name() & ExpressionType::TYPE_POINTER){
			  node->left()->accept(this, lvl);
			  node->right()->accept(this, lvl);
			  if(node->left()->type()->name() & ExpressionType::TYPE_DOUBLE){
			   _pf.INT(8);
			  }
			  else{
			   _pf.INT(4);
			  }
			  _pf.MUL();
			  _pf.ADD();
			}
			else{
			  node->left()->accept(this, lvl);
			  if(node->left()->type()->name() & ExpressionType::TYPE_DOUBLE){
			   _pf.INT(8);
			  }
			  else{
			    _pf.INT(4);
			  }
			  _pf.MUL();
			  node->right()->accept(this, lvl);
			  _pf.ADD();
			}
		    }
		    else if (node->type()->name() & ExpressionType::TYPE_INT){
		      node->left()->accept(this, lvl);
		      node->right()->accept(this, lvl);
		      _pf.ADD();
		    }
		    else{
		      node->left()->accept(this, lvl);
		      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
		        _pf.I2D();

		      node->right()->accept(this, lvl);
		      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
		        _pf.I2D();

		      _pf.DADD();
		    }


	} catch (std::string s) {
		std::cerr << "Error - " << node->lineno() << " Invalid types on ADD: " << s << std::endl;
		return;
	}


}
void tll::semantics::PFwriter::processSUB(cdk::node::expression::SUB * const node, int lvl) {

	try {
		TypeValidator *v = new TypeValidator(os(), _symtab, _global);
		node->accept(v, lvl);

		if(node->type()->name() & ExpressionType::TYPE_POINTER){
			if(node->left()->type()->name() & ExpressionType::TYPE_POINTER){
			  node->left()->accept(this, lvl);
			  node->right()->accept(this, lvl);
			  if(node->left()->type()->name() & ExpressionType::TYPE_DOUBLE){
			   _pf.INT(8);
			  }
			  else{
			    _pf.INT(4);
			  }
			  _pf.MUL();
			  _pf.SUB();
			}
			else{
			  node->left()->accept(this, lvl);
			  if(node->left()->type()->name() & ExpressionType::TYPE_DOUBLE){
			   _pf.INT(8);
			  }
			  else{
			    _pf.INT(4);
			  }
			  _pf.MUL();
			  node->right()->accept(this, lvl);
			  _pf.SUB();
			}
		    }
		    else if (node->type()->name() & ExpressionType::TYPE_INT){
		      node->left()->accept(this, lvl);
		      node->right()->accept(this, lvl);
		      _pf.SUB();
		      if(node->left()->type()->name() & ExpressionType::TYPE_POINTER){
		    	  if(node->left()->type()->name() & ExpressionType::TYPE_DOUBLE){
		    		  _pf.INT(8);
		    	  }
		    	  else{
		    		  _pf.INT(4);
		    	  }
		    	  _pf.DIV();
		      }
		    }
		    else{
		      node->left()->accept(this, lvl);
		      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
		        _pf.I2D();

		      node->right()->accept(this, lvl);
		      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
		    	  _pf.I2D();
		      _pf.DSUB();
		    }

	} catch (std::string s) {
		std::cerr << "Error - " << node->lineno() << " Invalid types on SUB: " << s << std::endl;
		return;
	}


}
void tll::semantics::PFwriter::processMUL(cdk::node::expression::MUL * const node, int lvl) {
	try {
		TypeValidator *v = new TypeValidator(os(), _symtab, _global);
		node->accept(v, lvl);

	    if (node->type()->name() & ExpressionType::TYPE_INT){
	      node->left()->accept(this, lvl);
	      node->right()->accept(this, lvl);
	      _pf.MUL();
	    }
	    else{
	      node->left()->accept(this, lvl);
	      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();

	      node->right()->accept(this, lvl);
	      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();
	      _pf.DMUL();
	    }


	} catch (std::string s) {
		 std::cerr << "Error - " << node->lineno() << " Invalid types on MUL: " << s << std::endl;
		    return;
	}

}
void tll::semantics::PFwriter::processDIV(
		cdk::node::expression::DIV * const node, int lvl) {
	try {
		TypeValidator *v = new TypeValidator(os(), _symtab, _global);
		node->accept(v, lvl);

		 if (node->type()->name() & ExpressionType::TYPE_INT){
		      node->left()->accept(this, lvl);
		      node->right()->accept(this, lvl);
		      _pf.DIV();
		    }
		    else{
		      node->left()->accept(this, lvl);
		      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
		        _pf.I2D();

		      node->right()->accept(this, lvl);
		      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
		        _pf.I2D();
		      _pf.DDIV();
		    }

	} catch (std::string s) {
		std::cerr << "Error - " << node->lineno() << " Invalid types on DIV: " << s << std::endl;
		return;
	}
}
void tll::semantics::PFwriter::processMOD(cdk::node::expression::MOD * const node, int lvl) {
	try {
		TypeValidator *v = new TypeValidator(os(), _symtab, _global);
		node->accept(v, lvl);

		node->left()->accept(this, lvl);
		if(node->left()->type()->name() & ExpressionType::TYPE_DOUBLE)
		   _pf.D2I();

		node->right()->accept(this, lvl);
		if(node->right()->type()->name() & ExpressionType::TYPE_DOUBLE)
		    _pf.D2I();

		  _pf.MOD();

	} catch (std::string s) {
		 std::cerr << "Error - " << node->lineno() << " Invalid types on MOD: " << s << std::endl;
		 return;
	}
}

void tll::semantics::PFwriter::processLT(cdk::node::expression::LT * const node,
		int lvl) {
	try{
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    if(node->type()->name() & ExpressionType::TYPE_DOUBLE){
	      node->left()->accept(this, lvl);
	      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();
	      node->right()->accept(this, lvl);
	      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();

	      _pf.DCMP();
	      _pf.INT(0);
	      _pf.LT();

	    }
	    else{
	      node->left()->accept(this, lvl);
	      node->right()->accept(this, lvl);
	      _pf.LT();
	    }

	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on LT: " << s << std::endl;
	    return;
	  }

}
void tll::semantics::PFwriter::processLE(cdk::node::expression::LE * const node,
		int lvl) {
	 try{
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    if(node->type()->name() & ExpressionType::TYPE_DOUBLE){
	      node->left()->accept(this, lvl);
	      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();
	      node->right()->accept(this, lvl);
	      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();

	      _pf.DCMP();
	      _pf.INT(0);
	      _pf.LE();

	    }
	    else{
	      node->left()->accept(this, lvl);
	      node->right()->accept(this, lvl);
	      _pf.LE();
	    }

	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on LT: " << s << std::endl;
	    return;
	  }

}
void tll::semantics::PFwriter::processGE(cdk::node::expression::GE * const node,
		int lvl) {
	 try{
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    if(node->type()->name() & ExpressionType::TYPE_DOUBLE){
	      node->left()->accept(this, lvl);
	      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();
	      node->right()->accept(this, lvl);
	      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();

	      _pf.DCMP();
	      _pf.INT(0);
	      _pf.GE();

	    }
	    else{
	      node->left()->accept(this, lvl);
	      node->right()->accept(this, lvl);
	      _pf.GE();
	    }

	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on LT: " << s << std::endl;
	    return;
	  }
}
void tll::semantics::PFwriter::processGT(cdk::node::expression::GT * const node,
		int lvl) {
	 try{
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    if(node->type()->name() & ExpressionType::TYPE_DOUBLE){
	      node->left()->accept(this, lvl);
	      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();
	      node->right()->accept(this, lvl);
	      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();

	      _pf.DCMP();
	      _pf.INT(0);
	      _pf.GT();

	    }
	    else{
	      node->left()->accept(this, lvl);
	      node->right()->accept(this, lvl);
	      _pf.GT();
	    }

	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on LT: " << s << std::endl;
	    return;
	  }
}
void tll::semantics::PFwriter::processNE(cdk::node::expression::NE * const node,
		int lvl) {
	try{
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    if(node->type()->name() & ExpressionType::TYPE_DOUBLE){
	      node->left()->accept(this, lvl);
	      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();
	      node->right()->accept(this, lvl);
	      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();

	      _pf.DCMP();
	      _pf.INT(0);
	      _pf.NE();

	    }
	    else{
	      node->left()->accept(this, lvl);
	      node->right()->accept(this, lvl);
	      _pf.NE();
	    }

	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on LT: " << s << std::endl;
	    return;
	  }
}
void tll::semantics::PFwriter::processEQ(cdk::node::expression::EQ * const node,
		int lvl) {
	 try{
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    if(node->type()->name() & ExpressionType::TYPE_DOUBLE){
	      node->left()->accept(this, lvl);
	      if(node->left()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();
	      node->right()->accept(this, lvl);
	      if(node->right()->type()->name() & ExpressionType::TYPE_INT)
	        _pf.I2D();

	      _pf.DCMP();
	      _pf.INT(0);
	      _pf.EQ();

	    }
	    else{
	      node->left()->accept(this, lvl);
	      node->right()->accept(this, lvl);
	      _pf.EQ();
	    }

	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on LT: " << s << std::endl;
	    return;
	  }
}

void tll::semantics::PFwriter::processAND(tll::node::expression::AND * const node, int lvl) {
	 try {
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    int lbl1;

	        node->left()->accept(this, lvl+2);
	        _pf.DUP();
	        _pf.JZ(mklbl(lbl1 = ++_lbl));
	        _pf.TRASH(4);
	        node->right()->accept(this, lvl+2);
	        _pf.ALIGN();
	        _pf.LABEL(mklbl(lbl1));


	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on AND: " << s << std::endl;
	    return;
	  }
}
void tll::semantics::PFwriter::processOR(tll::node::expression::OR * const node,
		int lvl) {
	try {
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    int lbl1;

	    node->left()->accept(this, lvl+2);
	    _pf.DUP();
	    _pf.JNZ(mklbl(lbl1 = ++_lbl));
	    _pf.TRASH(4);
	    node->right()->accept(this, lvl+2);
	    _pf.ALIGN();
	    _pf.LABEL(mklbl(lbl1));

	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on OR: " << s << std::endl;
	    return;
	  }

}

void tll::semantics::PFwriter::processPOS(
		tll::node::expression::POS * const node, int lvl) {

}
void tll::semantics::PFwriter::processInvocationNode(tll::node::expression::InvocationNode * const node, int lvl){
	//todo
}
void tll::semantics::PFwriter::processIndexNode(tll::node::expression::IndexNode * const node, int lvl){
	//todo
}
void tll::semantics::PFwriter::processPOT(tll::node::expression::POT * const node, int lvl) {
	try {
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	    int lbl1;

	    node->left()->accept(this, lvl);
	    node->right()->accept(this, lvl);
	    _pf.INT(1);
	    _pf.SUB();

	    _pf.ALIGN();
	    _pf.LABEL(mklbl(lbl1 = ++_lbl));
	    _pf.SWAP();
	    node->left()->accept(this, lvl+2);
	    _pf.MUL();
	    _pf.SWAP();
	    _pf.INT(1);
	    _pf.SUB();
	    _pf.DUP();
	    _pf.JNZ(mklbl(lbl1));
	    _pf.TRASH(4);
	    _pf.SWAP();
	    _pf.TRASH(4);

	  }
	  catch(std::string s) {
	    std::cerr << "Error - " << node->lineno() << " Invalid types on POT: " << s << std::endl;
	    return;
	  }
}
void tll::semantics::PFwriter::processSIMETRIC(
		tll::node::expression::SIMETRIC * const node, int lvl) {
 //TODO
	}

void tll::semantics::PFwriter::processMEM(
		tll::node::expression::MEM * const node, int lvl) {
 //TODO
	}
//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processLeftValue(
		tll::node::expression::LeftValue * const node, int lvl) {
	// DAVID: the horror!!
	const char *id = node->value().c_str();
	if (_symtab.find(id)) {
		_pf.ADDR(id);
	}
}


//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processPrintNode(
		tll::node::PrintNode * const node, int lvl) {
	try {
		TypeValidator *v = new TypeValidator(os(), _symtab, _global);
		node->accept(v, lvl);

	} catch (std::string s) {
		std::cerr << "Error - " << node->lineno() << " Invalid types on print: " << s << std::endl;
		return;
	}
}


//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processReadNode(tll::node::expression::ReadNode * const node, int lvl) {
	try {
		TypeValidator *v = new TypeValidator(os(), _symtab, _global);
		node->accept(v, lvl);
		node->type()->name();

		 if(node->type()->name() & ExpressionType::TYPE_DOUBLE){
		      _pf.CALL("readd");
		      _pf.DPUSH();
		      _pf.SP();
		      _pf.LOAD();
		     // node->argument()->accept(this,lvl); TODO
		      _pf.STORE();
		 }
		 else {
			 _pf.CALL("readi");
			 _pf.PUSH();
			 _pf.DUP();
			// node->argument()->accept(this,lvl); TODO
			 _pf.STORE();

		 }


	} catch (std::string s) {
		  std::cerr << "Error: " << node->lineno() << " Invalid types on read: " << s << std::endl;
		  return;
	}
}
//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processDoElseNode(
		tll::node::instructions::DoElseNode * const node, int lvl) {

	int lbl1, lbl2;
	_pf.LABEL(mklbl(lbl1 = ++_lbl));
	node->block()->accept(this, lvl + 2);
	node->condition()->accept(this, lvl + 2);
	_pf.JZ(mklbl(lbl2 = ++_lbl));
	_pf.JMP(mklbl(lbl1));
	_pf.LABEL(mklbl(lbl2));
	node->elseblock()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processDoNode(tll::node::instructions::DoNode * const node,
		int lvl) {
	int lbl1, lbl2;
	_pf.LABEL(mklbl(lbl1 = ++_lbl));
	node->block()->accept(this, lvl + 2);
	node->condition()->accept(this, lvl + 2);
	_pf.JZ(mklbl(lbl2 = ++_lbl));
	_pf.JMP(mklbl(lbl1));
	_pf.LABEL(mklbl(lbl2));
}
//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processWhileNode(
		tll::node::instructions::WhileNode * const node, int lvl) {
	int lbl1, lbl2;
	try {
		_pf.LABEL(mklbl(lbl1 = ++_lbl));
		node->condition()->accept(this, lvl);
		_pf.JZ(mklbl(lbl2 = ++_lbl));
		node->block()->accept(this, lvl + 2);
		_pf.JMP(mklbl(lbl1));
		_pf.LABEL(mklbl(lbl2));

	} catch (std::string s) {
		std::cerr << "Error - " << node->lineno() << " Invalid types on While: " << s << std::endl;
		return;
	}


}
//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processWhileElseNode(
		tll::node::instructions::WhileElseNode * const node, int lvl) {

	int lbl1, lbl2;
	try {

		_pf.LABEL(mklbl(lbl1 = ++_lbl));
		node->condition()->accept(this, lvl);
		_pf.JZ(mklbl(lbl2 = ++_lbl));
		node->block()->accept(this, lvl + 2);
		_pf.JMP(mklbl(lbl1));
		_pf.LABEL(mklbl(lbl2));
		node->elseblock()->accept(this, lvl + 2);

	} catch (std::string s) {
		std::cerr << "Error: " << node->lineno() << " Invalid types on While-Else: " << s << std::endl;
		return;
	}

}
//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processForNode(tll::node::instructions::ForNode * const node,
		int lvl) {
	int lbl1, lbl2;
	node->init()->accept(this, lvl);
	_pf.LABEL(mklbl(lbl1 = ++_lbl));
	node->condition()->accept(this, lvl);
	_pf.JZ(mklbl(lbl2 = ++_lbl));
	node->incr()->accept(this, lvl);
	node->block()->accept(this, lvl + 2);
	_pf.JMP(mklbl(lbl1));
	_pf.LABEL(mklbl(lbl2));

}
//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processForVarNode(
		tll::node::instructions::ForVarNode * const node, int lvl) {
	int lbl1, lbl2;
	node->var()->accept(this, lvl);
	_pf.LABEL(mklbl(lbl1 = ++_lbl));
	node->condition()->accept(this, lvl);
	_pf.JZ(mklbl(lbl2 = ++_lbl));
	node->incr()->accept(this, lvl);
	node->block()->accept(this, lvl + 2);
	_pf.JMP(mklbl(lbl1));
	_pf.LABEL(mklbl(lbl2));

}
//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processAssignmentNode(
		tll::node::AssignmentNode * const node, int lvl) {
	// DAVID: horrible hack!
	const char *id = node->lvalue()->value().c_str();
	if (!_symtab.find(id)) {
		_pf.DATA(); // variables are DATA
		_pf.ALIGN(); // make sure we are aligned
		_pf.LABEL(id); // name variable location
		_pf.CONST(0); // initialize it to 0 (zero)
		_pf.TEXT(); // return to the TEXT segment
		_symtab.insert(id, new TLLSymbol(0, id, 0)); // put in the symbol table
	}
	node->rvalue()->accept(this, lvl); // determine the new value
	node->lvalue()->accept(this, lvl); // where to store the value
	_pf.STORE(); // store the value at address
}

//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processIfNode(tll::node::instructions::IfNode * const node,
		int lvl) {
	int lbl1;
	node->condition()->accept(this, lvl);
	_pf.JZ(mklbl(lbl1 = ++_lbl));
	node->block()->accept(this, lvl + 2);
	_pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void tll::semantics::PFwriter::processIfElseNode(
		tll::node::instructions::IfElseNode * const node, int lvl) {
	int lbl1, lbl2;
	node->condition()->accept(this, lvl);
	_pf.JZ(mklbl(lbl1 = ++_lbl));
	node->thenblock()->accept(this, lvl + 2);
	_pf.JMP(mklbl(lbl2 = ++_lbl));
	_pf.LABEL(mklbl(lbl1));
	node->elseblock()->accept(this, lvl + 2);
	_pf.LABEL(mklbl(lbl1 = lbl2));
}


void tll::semantics::PFwriter::processNextNode(tll::node::instructions::NextNode * const node,
		int lvl) {
 //TODO
	}
//---------------------------------------------------------------------------
void tll::semantics::PFwriter::processReturnNode(
		tll::node::instructions::ReturnNode * const node, int lvl) {
 //TODO
	}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void tll::semantics::PFwriter::processVariableNode(
		tll::node::VariableNode * const node, int lvl) {
 //TODO
	}
//---------------------------------------------------------------------------
void tll::semantics::PFwriter::processStopNode(tll::node::instructions::StopNode * const node,
		int lvl) {
 //TODO
	}
//---------------------------------------------------------------------------
void tll::semantics::PFwriter::processQualifierNode( tll::node::QualifierNode * const node, int lvl) {
 //TODO
	}





void tll::semantics::PFwriter::processUseNode(tll::node::UseNode* const node, int lvl){
 //TODO
	}
void tll::semantics::PFwriter::processPublicNode(tll::node::PublicNode* const node, int lvl){
 //TODO
	}


void tll::semantics::PFwriter::processBlockNode(tll::node::BlockNode * const node,int lvl){
 //TODO
	}



void tll::semantics::PFwriter::processFunctionCallNode(tll::node::expression::FunctionCallNode * const node, int lvl){
	try {
	    TypeValidator *v = new TypeValidator(os(), _symtab, _global);
	    node->accept(v, lvl);

	} catch (std::string s) {
		 std::cerr << "Error: " << node->lineno() << " In FunctionCallNode: " << s << std::endl;
		 return;
	}


	//TODO
}
void tll::semantics::PFwriter::processFunctionDeclNode(tll::node::FunctionDeclNode * const node, int lvl){
	 std::string id = ((cdk::node::expression::Identifier*) node->ident())->value();

	 _pf.TEXT();
	 _pf.ALIGN();



	 _pf.GLOBAL(id,_pf.FUNC());



}
void tll::semantics::PFwriter::processFunctionDefNode(tll::node::FunctionDefNode * const node, int lvl){

	_pf.GLOBAL("El_Rafael", _pf.FUNC());


	//TODO
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//     T H E    E N D
//---------------------------------------------------------------------------
