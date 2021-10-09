LIBSDIR:=lib
EXEDIR:=bin
BUILDDIR:=Build
word-dot = $(word $2,$(subst  , ,$1))
EXE:=$(EXEDIR)/main
LIBS:=$(addprefix $(LIBSDIR)/,libmatrixscaleroperations.a libmatrixoperations.so)

TESTCASESDIR:= Tests
TESTCASES_INPUT_FILES:= $(wildcard $(TESTCASESDIR)/*.in)
TESTCASES_FILE_NAMES:=$(patsubst Tests/%.in,%,$(TESTCASES_INPUT_FILES))

all: $(EXE)
	@echo "Finished Successfully"

$(EXE): Build/main.o $(LIBS) Build/matrix.o | $(EXEDIR)
	export LD_LIBRARY_PATH=$(PWD)/lib/libmatrixoperations.so/:$LD_LIBRARY_PATH
	g++ -o bin/main -I ./include/ Build/*.o -L ./lib/ -lmatrixscaleroperations -lmatrixoperations

Build/main.o: src/main.cpp include/*.h	| $(BUILDDIR)
	g++ -o Build/main.o -I include/ -c src/main.cpp

Build/matrixscaleroperations.o: src/MatrixScalerOperations.cpp include/MatrixScalerOperations.h include/log.h | $(BUILDDIR)
	g++ -o Build/matrixscaleroperations.o -I include/ -c src/MatrixScalerOperations.cpp

Build/matrixoperations.o: src/MatrixOperations.cpp include/MatrixOperations.h include/log.h | $(BUILDDIR)
	g++ -fPIC -o Build/matrixoperations.o -I include/ -c src/MatrixOperations.cpp

Build/matrix.o: src/Matrix.cpp include/Matrix.h | $(BUILDDIR)
	g++ -o Build/matrix.o -I include/ -c src/Matrix.cpp

lib/libmatrixscaleroperations.a: Build/matrixscaleroperations.o | $(LIBSDIR)
	ar rcs lib/libmatrixscaleroperations.a Build/matrixscaleroperations.o

lib/libmatrixoperations.so: Build/matrixoperations.o | $(LIBSDIR)
	g++ -shared -o lib/libmatrixoperations.so Build/matrixoperations.o

$(LIBSDIR):
	mkdir -p $(LIBSDIR)

$(EXEDIR):
	mkdir -p $(EXEDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	touch Tests/junk.out
	rm -rf bin lib Build Tests/junk.out
prepare:$(EXE) 
	@echo "input file path : " \
	&& read inp1 \
	&& echo "output file path : " \
	&& read inp2 \
	&& echo "./bin/main < $${inp1} > $${inp2}" >> temp.sh;
run:$(EXE) temp.sh
	@bash temp.sh
	@rm -f temp.sh
temp.sh:
	@echo `./bin/main < run.in > run.out` > temp.sh
libs:$(LIBS)
tests:$(EXE) ${TESTCASES_FILE_NAMES}
	@echo
test%:$(EXE)
	@echo
	@echo Running $@
	@echo `./bin/main < Tests/$@.in > Tests/junk.out` > temp.sh;

	@bash temp.sh

	@echo
	@echo "Program's Output"
	@cat Tests/junk.out
	@echo "---------------"

	@echo
	@echo "Expected Output"
	@cat Tests/$@.out
	@echo "---------------"

	@echo
	@bash test.sh Tests/$@.out
	@rm -f temp.sh