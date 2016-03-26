# $Id: Makefile,v 1.2 2012-03-23 11:04:42 ist169643 Exp $
# $Log: Makefile,v $
# Revision 1.2  2012-03-23 11:04:42  ist169643
# teste1
#
# Revision 1.1  2012-03-06 21:44:34  ist13500
# This is actually Compact but renamed TLL (string level change).
# The recognized language is still Compact, not TLL.
#
# Revision 1.12  2012/02/06 20:36:25  david
# Added makefile for example programs.
#
# Revision 1.11  2011/03/09 19:56:17  david
# *** empty log message ***
#
# Revision 1.10  2010/06/19 17:36:03  david
# *** empty log message ***
#
# Revision 1.9  2010/03/22 15:34:20  david
# Changed code to be compatible with CDK5. For TLL, this is only
# a matter of changing a compilation flag. For other compilers, it opens
# a number of sophisticated possibilities.
#
# Revision 1.8  2009/03/03 17:45:22  david
# Minor cleanup.
#
# Revision 1.7  2009/03/02 17:40:20  david
# Major changes: in addition to compiling with CDK4, TLL now has
# its own namespace (tll). All classes are defined in it or in its
# child namespaces. Added automatic node processing: the "nodes"
# directory is scanned and nodes/all.h is built (contains both forward
# declarations and include directives for all nodes -- in the appropriate
# namespaces).
#
#---------------------------------------------------------------
#             CONFIGURE THESE VARIABLES IF NEEDED
#---------------------------------------------------------------

ROOT = #${HOME}/compiladores/root
CDK_INC_DIR = $(ROOT)/usr/include
CDK_LIB_DIR = $(ROOT)/usr/lib

L_NAME=TLLScanner
Y_NAME=TLLParser

#---------------------------------------------------------------
#    PROBABLY, NO NEED TO CHANGE ANYTHING BEYOND THIS POINT
#---------------------------------------------------------------

LFLAGS   = 
YFLAGS   = -dtv
# CXXFLAGS = -Wall -O6 -s -Isemantics -I. -I$(CDK_INC_DIR) -I$(CDK_INC_DIR)/cdk
CXXFLAGS = -ansi -DYYDEBUG=1 -Wall -O3 -ggdb -Isemantics -I. -I$(CDK_INC_DIR) -I$(CDK_INC_DIR)/cdk
LDFLAGS  = -L$(CDK_LIB_DIR) -lcdk
COMPILER = tll

SRC_CPP = $(wildcard nodes/**/*.cpp) $(wildcard semantics/*.cpp) $(wildcard ./*.cpp)
OFILES  = $(SRC_CPP:%.cpp=%.o)

#---------------------------------------------------------------
#                DO NOT CHANGE AFTER THIS LINE
#---------------------------------------------------------------

all: nodes/all.h $(COMPILER)

%.tab.o:: %.tab.c
	$(CXX) $(CXXFLAGS) -DYYDEBUG -c $< -o $@

%.o:: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.tab.c:: %.y
	 byacc -dtv -b $* $<

%.tab.h:: %.y
	 byacc -dtv -b $* $<

$(L_NAME).cpp: $(L_NAME).l
	flex $(LFLAGS) $<

$(Y_NAME).tab.c: $(Y_NAME).y
$(Y_NAME).tab.h: $(Y_NAME).y

# this is needed to force byacc to run
$(L_NAME).o: $(L_NAME).cpp $(Y_NAME).tab.h

.PHONY: ./mknodedecls.pl
nodes/all.h: ./mknodedecls.pl
	./mknodedecls.pl > nodes/all.h

$(COMPILER): $(L_NAME).o $(Y_NAME).tab.o $(OFILES)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) *.tab.[ch] *.o $(OFILES) $(L_NAME).cpp $(Y_NAME).output $(COMPILER)

depend: nodes/all.h
	$(CXX) $(CXXFLAGS) -MM $(SRC_CPP) > .makedeps

-include .makedeps

#---------------------------------------------------------------
#                           THE END
#---------------------------------------------------------------
