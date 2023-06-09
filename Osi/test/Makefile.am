# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.
#
# Author:  Andreas Waechter           IBM    2006-04-13

include $(top_srcdir)/BuildTools/Makemain.inc

########################################################################
#                         unitTest for Coin                            #
########################################################################

noinst_PROGRAMS = unitTest

unitTest_SOURCES = unitTest.cpp \
  OsiTestSolver.cpp \
  OsiTestSolverInterface.cpp \
  OsiTestSolverInterfaceIO.cpp \
  OsiTestSolverInterfaceTest.cpp

# List libraries of COIN projects
unitTest_LDADD = ../src/OsiCommonTest/libOsiCommonTest.la

AM_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.
AM_CPPFLAGS = -I$(srcdir)/../src/Osi -I$(srcdir)/../src/OsiCommonTest

# Depending of what solvers are available, we add the corresponding files,
# libraries and compile flags

if COIN_HAS_CPLEX
  unitTest_SOURCES += OsiCpxSolverInterfaceTest.cpp
  AM_CPPFLAGS += -DOSI_HAS_CPLEX -I$(srcdir)/../src/OsiCpx
  unitTest_LDADD += ../src/OsiCpx/libOsiCpx.la
endif

if COIN_HAS_GLPK
  unitTest_SOURCES += OsiGlpkSolverInterfaceTest.cpp
  AM_CPPFLAGS += -DOSI_HAS_GLPK -I$(srcdir)/../src/OsiGlpk
  unitTest_LDADD += ../src/OsiGlpk/libOsiGlpk.la
endif

if COIN_HAS_MOSEK
  unitTest_SOURCES += OsiMskSolverInterfaceTest.cpp
  AM_CPPFLAGS += -DOSI_HAS_MOSEK -I$(srcdir)/../src/OsiMsk
  unitTest_LDADD += ../src/OsiMsk/libOsiMsk.la
endif

if COIN_HAS_XPRESS
  unitTest_SOURCES += OsiXprSolverInterfaceTest.cpp
  AM_CPPFLAGS += -DOSI_HAS_XPRESS -I$(srcdir)/../src/OsiXpr
  unitTest_LDADD += ../src/OsiXpr/libOsiXpr.la
endif

if COIN_HAS_GUROBI
  unitTest_SOURCES += OsiGrbSolverInterfaceTest.cpp
  AM_CPPFLAGS += -DOSI_HAS_GUROBI -I$(srcdir)/../src/OsiGrb
  unitTest_LDADD += ../src/OsiGrb/libOsiGrb.la
endif

if COIN_HAS_SOPLEX
  unitTest_SOURCES += OsiSpxSolverInterfaceTest.cpp
  AM_CPPFLAGS += -DOSI_HAS_SOPLEX -I$(srcdir)/../src/OsiSpx
  unitTest_LDADD += ../src/OsiSpx/libOsiSpx.la
endif

# put this one after the -I$(srcdir)/../src/OsiXyz from above
AM_CPPFLAGS += $(OSITEST_CFLAGS)

unittestflags =
if COIN_HAS_SAMPLE
  unittestflags += -mpsDir=`$(CYGPATH_W) $(SAMPLE_DATA)`
endif
if COIN_HAS_NETLIB
  unittestflags += -netlibDir=`$(CYGPATH_W) $(NETLIB_DATA)` -testOsiSolverInterface
endif

test: unitTest$(EXEEXT)
	./unitTest$(EXEEXT) $(unittestflags)

.PHONY: test

########################################################################
#                          Cleaning stuff                              #
########################################################################

# Here we list everything that is not generated by the compiler, e.g.,
# output files of a program

CLEANFILES = *.mps *.mps.gz *.lp test2out *.out.gz *.out
