# -*- MakeFile -*-

# target : dependencies
#		action

	
	
src = $(wildcard /main.c) \
	$(wildcard crypto/*.c) 
	
	
obj = $(src: .c=.o)

LDFLAGS = -lpng -lz -lm

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)
.PHONY: clean
clean:
	rm -f $(obj) myprog
	
