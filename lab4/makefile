LIBSDIR:= libs 
EXEDIR:=bin
word-dot = $(word $2,$(subst  , ,$1))
EXE:=$(EXEDIR)/main
PWD=
ARGS:=$(filter-out $@,$(MAKECMDGOALS))
all: 
	g++ -o bin/main -I ./include src/*.cpp
	@echo "Finished Successfully"
bin/main:
	@echo ""
prepare:
#	bin/main $(filter-out $@,$(MAKECMDGOALS))[0]
#	${EXE} < $(word 2,$(ARGS)) < iutput
	@echo hi

$(word 2,$(ARGS)) : 
	$(Input) = $@
	$(Ouput) = $(word 3,$(ARGS))
	@echo helloin

$(word 3,$(ARGS)) : 
	@echo helloout

run :
#	${EXE} -m < $(Input) > $(output)
	${EXE} -m < $(Input) > $(Output)
	@echo run

test:
	@echo ${a}

