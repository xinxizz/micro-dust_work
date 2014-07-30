CURRENT:=$(shell pwd)
BINDIR:=$(CURRENT)/bin/
export OBJDIR:=$(CURRENT)/objs/
export CFLAGS:=-I
export MAKE:=make
export CC:=g++
export CP:=cp
LFLAGS:=
TARGET:=MDJSS
all:$(TARGET)
MDJSS:SUBTARGETS
	$(CC) -o ./bin/MDJSS $(shell find ./objs -maxdepth 1 -name "*.o" -type f) $(LFLAGS)
SUBTARGETS:
	$(MAKE) -C ../
clean:
	$(MAKE) clean -C ../
	rm -rf ./bin/* ./objs/*



