LIBSDIR:= libs 
EXEDIR:=bin
word-dot = $(word $2,$(subst  , ,$1))
EXE:=$(EXEDIR)/main

TESTCASESDIR:= tests
TESTCASES_INPUT_FILES:= $(wildcard $(TESTCASESDIR)/*.in)
TESTCASES_FILE_NAMES:=$(patsubst tests/%.in,%,$(TESTCASES_INPUT_FILES))

all:
	g++ -o bin/main -I ./include src/*.cpp
	@echo "Finished Successfully"

bin/main:
	@echo ""
prepare:
	@echo "input file path : " \
	&& read inp1 \
	&& echo "output file path : " \
	&& read inp2 \
	&& echo `./bin/main < $${inp1} > $${inp2}` > temp.sh;
run: temp.sh
	@bash temp.sh
	@rm -f temp.sh
temp.sh:
	./bin/main < run.in > run.out
Tests:${TESTCASES_FILE_NAMES}

test%:
	@echo `./bin/main < tests/$@.in > tests/junk.out` > temp.sh;
	@bash temp.sh
	@bash test.sh tests/$@.out
