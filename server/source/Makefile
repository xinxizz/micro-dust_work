exclude_dirs:=build
dirs:=$(shell find . -maxdepth 1 -type d)
dirs:=$(basename $(patsubst ./%, %, $(dirs)))
subdirs:=$(filter-out $(exclude_dirs), $(dirs))
OBJS:=$(shell find . -maxdepth 1 -name "*.cpp" -type f)
OBJS:=$(patsubst ./%.cpp, %.o, $(OBJS))
all:$(OBJS)
	@for dir in $(subdirs); 	do ($(MAKE) -C $$dir); done

$(OBJS):%.o:%.cpp
	$(CC) -c $(CFLAGES) $< -o $@
	$(CP) *.o $(OBJDIR)

clean:
	@for dir in $(subdirs); 	do ($(MAKE) clean -C $$dir); done



