FACDIR:= ./cfac-1.4.1
FACINCLUDE:= -I$(FACDIR)/faclib/ -I$(FACDIR)/include/ -I$(FACDIR)
FACLIB:= $(FACDIR)/faclib
FACDEP_MAINS:= bingen read rootgen
FAC_EXCLUDE_BASE:= 
FACEXCLUDE:= $(FAC_EXCLUDE_BASE:%=bin/%.o)
FACEXCLUDE_SRC:=$(FAC_EXCLUDE_BASE:%=src/%.cc)
FACDEPEND:= src/dbase.cc

INCLUDE:= -Iinclude -Ilib -IRLlib/include $(FACINCLUDE)

LIBS:= $(shell root-config --ldflags --libs --glibs) -LRLlib -lRLlib

SRC:= $(filter-out $(FACEXCLUDE_SRC), $(wildcard src/*.cc))
OBJ:= $(SRC:src/%.cc=bin/%.o)

RLLIB:= RLlib/libRLlib.a



MAINS:= $(FACDEP_MAINS) rootfitmake dumpvalues rfacTotalRateCalculator

MAINSOBJ:= $(MAINS:%=bin/%.o)

DICTBIN:= bin/Dictionary.o

CCFLAGS := -pthread -Wall -DExcludeInternalDependencies=1 -fPIC -O3
CCFLAGS +=  -std=c++03 -pedantic -Wno-long-long -Woverloaded-virtual

ROOTERS:= EnergyLevel QuantumNumbers StrongFieldQuantumNumbers rfacEssentialData rfacSpecificLevelData rfacInterpolatorContainer rfacQuantumNumberLister rfacLevelPicker rfacInterpolation rfacInterpolatorPicker rfacException rfacLinearInterpolation rfacFieldGridPicker rfacFieldGridPoint rfacFieldGridContainer rfacQuantumNumberContainer rfacLevelContainer rfacDecayableObject rfacFieldRegimeTranslator GeneralQuantumNumbers


G4OBJ:= lib/libG4Dictionary.a

DICTIONARY:= Dictionary.so

GLOBALDEPEND:= RLlib/libRLlib.a

ROOTCCFLAGS:=  $(shell root-config --cflags) -lProof -lProofPlayer

CC:= g++

ROOTCINT:= $(shell which rootcint)

DOXY:= doxygen

TEST:= test/RunTests

.PHONY: clean doc

all: bin $(RLLIB) $(FACDEPEND) $(OBJ) $(MAINS) $(DICTIONARY) $(G4OBJ) $(TEST)

bin: 
	mkdir -p bin

$(TEST): $(G4OBJ)
	$(MAKE) -C test makerun

$(MAINS): %: $(filter-out $(MAINSOBJ), $(OBJ)) $(DICTBIN)
	@echo Compiling $@...
	@$(CC) $(CCFLAGS) $(INCLUDE) bin/$@.o $^ $(ROOTCCFLAGS) $(LIBS) -o $@  

$(G4OBJ):  $(filter-out $(MAINSOBJ), $(OBJ)) $(DICTBIN)	
	@echo Making static object $@...
	@ar rs $@ $^ 

$(OBJ): bin/%.o: src/%.cc include/%.hh $(GLOBALDEPEND)
	@echo Compiling $@...
	@$(CC) $(CCFLAGS) $(INCLUDE) -c $< $(ROOTCCFLAGS) $(LIBS) -o $@

$(DICTIONARY): $(ROOTERS:%=bin/%.o)  bin/Dictionary.o
	@echo Compiling shared object $@
	@$(CC) $(CCFLAGS) $(INCLUDE) $^ $(ROOTCCFLAGS) $(LIBS) -shared -o $@ 

bin/Dictionary.o: lib/Dictionary.cxx
	@echo Making ROOT dictionary...
	@$(CC) $(CCFLAGS) $(INCLUDE) -I. -c $<  $(ROOTCCFLAGS) $(LIBS) -o $@

lib/Dictionary.cxx: $(ROOTERS:%=include/%.hh) include/linkdef.h 
	@echo Running ROOTCINT on selected files...
	@mkdir -p lib
	@$(ROOTCINT) -f $@ -c -DUSE_ROOT=1 -Iinclude $(INCLUDE) -I$(shell root-config --incdir) $^

src/dbase.cc: include/dbase.hh
	@echo Softlinking dbase.cc...
	@ln -sf $(FACLIB)/dbase.c src/dbase.cc

include/dbase.hh:
	@echo Softlinking dbase.hh...
	@ln -sf $(FACLIB)/dbase.h include/dbase.hh

$(RLLIB):
	$(cd RLlib && ./setup.sh)
	$(MAKE) -C RLlib


doc:
	@echo Running Doxygen...
	@$(DOXY) Doxyfile

clean:
	@echo Cleaning up...
	@rm -rf $(MAINS)
	@rm -rf Dictionary.so
	@rm -rf bin/*
	@rm -rf lib/*
	@find . -path ./output -prune -o -type f -name "*.o" -exec rm -f {} \;
	@find . -path ./output -prune -o -type f -name "*.a" -exec rm -f {} \;
	@find . -path ./output -prune -o -type f -name "*.d" -exec rm -f {} \;
	@find . -path "*/output/*" -prune -o -type f -name "*.of" -exec rm -f {} \;
	@find . -path "*/output/*" -prune -o -type f -name "*~" -exec rm -f {} \;
	@find . -path "*/output/*" -prune -o -type f -name "\#*\#" -exec rm -f {} \;
	@find . -path "*/output/*" -prune -o -type f -name "*_C.so" -exec rm -f {} \;
	@find . -path "*/output/*" -prune -o -type f -name "*AutoDict*" -exec rm -f {} \;
	@$(MAKE) -C test clean
	@$(MAKE) -C RLlib clean
