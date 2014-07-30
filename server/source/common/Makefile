OBJS:=$(shell find . -maxdepth 1 -name "*.cpp" -type f)
OBJS:=$(patsubst ./%.cpp, %.o, $(OBJS))
all:$(OBJS)
$(OBJS):%.o:%.cpp
	$(CC) -c $(CFLAGES) $< -o $@
	$(CP) *.o $(OBJDIR)
clean:
	rm -f $(OBJS)



