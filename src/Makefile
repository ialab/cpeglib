CFLAGS = -I. -g -O3

OBJS = cpeg.o cpeg_main.o

cpeg.a: $(OBJS)
	-/bin/rm $@
	ar -qv $@ $(OBJS)

$(OBJS): cpeglib.h
