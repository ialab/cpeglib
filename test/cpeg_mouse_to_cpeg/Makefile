LIBDIR	=	../../src
PROGS = test_mouse_parser m2c Java.1.7 Java.1.8 Java.1.7_no Java.1.7_4 Java.1.7_16 Java.1.7_64 Java.1.7_256 Java.1.7_1024 Java.1.7_4096
OBJS = mouse_tree.o mouse_parser.o allocate.o string.o

CFLAGS	=	-I$(LIBDIR) -O3 -g -DCPEG_DO_COUNT=1

all: $(PROGS)

test_mouse_parser: $(LIBDIR)/cpeg.a test_mouse_parser.o $(OBJS)
	$(CC) $(LIBDIR)/cpeg.a $@.o $(OBJS) -o $@

m2c: $(LIBDIR)/cpeg.a m2c.o $(OBJS)
	$(CC) $(LIBDIR)/cpeg.a $@.o $(OBJS) -o $@

Java.1.7: $(LIBDIR)/cpeg.a Java.1.7.o
	$(CC) $(LIBDIR)/cpeg.a $@.o -o $@

Java.1.7.c: m2c ../Mouse/Java.1.7.peg
	./m2c -f ../Mouse/Java.1.7.peg > Java.1.7.c

Java.1.8: $(LIBDIR)/cpeg.a Java.1.8.o
	$(CC) $(LIBDIR)/cpeg.a $@.o -o $@

Java.1.8.c: m2c ../Mouse/Java.1.8.peg
	./m2c -f ../Mouse/Java.1.8.peg > Java.1.8.c

#メモ化表サイズを変更したものを生成

Java.1.7_no: $(LIBDIR)/cpeg.a Java.1.7.o
	$(CC) -DCPEG_DO_MEMOIZE=false $(LIBDIR)/cpeg.a Java.1.7.o -o $@

Java.1.7_4: $(LIBDIR)/cpeg.a Java.1.7.o
	$(CC) -DCPEG_MEMO_SIZE=4 -DCPEG_DO_MEMOIZE=1  $(LIBDIR)/cpeg.a Java.1.7.o -o $@

Java.1.7_16: $(LIBDIR)/cpeg.a Java.1.7.o
	$(CC) -DCPEG_MEMO_SIZE=16 -DCPEG_DO_MEMOIZE=1  $(LIBDIR)/cpeg.a Java.1.7.o -o $@

Java.1.7_64: $(LIBDIR)/cpeg.a Java.1.7.o
	$(CC) -DCPEG_MEMO_SIZE=64 -DCPEG_DO_MEMOIZE=1  $(LIBDIR)/cpeg.a Java.1.7.o -o $@

Java.1.7_256: $(LIBDIR)/cpeg.a Java.1.7.o
	$(CC) -DCPEG_MEMO_SIZE=256 -DCPEG_DO_MEMOIZE=1  $(LIBDIR)/cpeg.a Java.1.7.o -o $@

Java.1.7_1024: $(LIBDIR)/cpeg.a Java.1.7.o
	$(CC) -DCPEG_MEMO_SIZE=1024 -DCPEG_DO_MEMOIZE=1  $(LIBDIR)/cpeg.a Java.1.7.o -o $@

Java.1.7_4096: $(LIBDIR)/cpeg.a Java.1.7.o
	$(CC) -DCPEG_MEMO_SIZE=4096 -DCPEG_DO_MEMOIZE=1  $(LIBDIR)/cpeg.a Java.1.7.o -o $@

m2c.o: mouse_parser.h
mouse_parser.o: $(LIBDIR)/cpeglib.h mouse_parser.h
mouse_tree.o: mouse_tree.h allocate.h string.h
allocate.o: allocate.h
string.o: string.h allocate.h

clean:
	rm $(OBJS) $(PROGS)
	rm -f *.o
	rm -f Java.*
