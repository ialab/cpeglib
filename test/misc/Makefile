LIBDIR	=	../../src

CFLAGS	=	-I$(LIBDIR) -O3

EXPR3	=	expr3-memo expr3-nomemo expr3-memo-1 expr3-memo-16 expr3-memo-1024 expr3-memo-4096

all: expr1 expr2 expr3 expr4 $(EXPR3) cpeg_test

expr1: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr1.o
	$(CC) $(LIBDIR)/cpeg.a $@.o -o $@

expr2: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr2.o
	$(CC) $(LIBDIR)/cpeg.a $@.o -o $@

expr3: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr3.o
	$(CC) $(LIBDIR)/cpeg.a $@.o -o $@

expr4: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr4.o
	$(CC) $(LIBDIR)/cpeg.a $@.o -o $@

expr3-memo: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr3.c
	$(CC) $(CFLAGS) -DCPEG_DO_MEMOIZE=1 expr3.c $(LIBDIR)/cpeg.a -o $@

expr3-memo-16: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr3.c
	$(CC) $(CFLAGS) -DCPEG_MEMO_SIZE=16 -DCPEG_DO_MEMOIZE=1 expr3.c $(LIBDIR)/cpeg.a -o $@

expr3-memo-1: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr3.c
	$(CC) $(CFLAGS) -DCPEG_MEMO_SIZE=1 -DCPEG_DO_MEMOIZE=1 expr3.c $(LIBDIR)/cpeg.a -o $@

expr3-memo-1024: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr3.c
	$(CC) $(CFLAGS) -DCPEG_MEMO_SIZE=1024 -DCPEG_DO_MEMOIZE=1 expr3.c $(LIBDIR)/cpeg.a -o $@

expr3-memo-4096: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr3.c
	$(CC) $(CFLAGS) -DCPEG_MEMO_SIZE=4096 -DCPEG_DO_MEMOIZE=1 expr3.c $(LIBDIR)/cpeg.a -o $@

expr3-nomemo: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a expr3.c
	$(CC) $(CFLAGS) -DCPEG_DO_MEMOIZE=false expr3.c $(LIBDIR)/cpeg.a -o $@

cpeg_test: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.a cpeg_test.o
	$(CC) $(LIBDIR)/cpeg.a $@.o -o $@

