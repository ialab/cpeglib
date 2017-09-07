LIBDIR	=	../../src

CFLAGS	=	-I$(LIBDIR) -O3

all: cpeg_json cpeg_json_no cpeg_json_4 cpeg_json_16 cpeg_json_64 cpeg_json_256 cpeg_json_1024 cpeg_json_4096

cpeg_json: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.o cpeg_json.o
	$(CC) $(LIBDIR)/cpeg.o cpeg_json.o -o $@

cpeg_json_no: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.o cpeg_json.o
	$(CC) -DCPEG_DO_MEMOIZE=false $(LIBDIR)/cpeg.o cpeg_json.o -o $@

cpeg_json_4: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.o cpeg_json.o
	$(CC) -DCPEG_MEMO_SIZE=1 -DCPEG_DO_MEMOIZE=4 $(LIBDIR)/cpeg.o cpeg_json.o -o $@

cpeg_json_16: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.o cpeg_json.o
	$(CC) -DCPEG_MEMO_SIZE=1 -DCPEG_DO_MEMOIZE=16 $(LIBDIR)/cpeg.o cpeg_json.o -o $@

cpeg_json_64: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.o cpeg_json.o
	$(CC) -DCPEG_MEMO_SIZE=1 -DCPEG_DO_MEMOIZE=64 $(LIBDIR)/cpeg.o cpeg_json.o -o $@

cpeg_json_256: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.o cpeg_json.o
	$(CC) -DCPEG_MEMO_SIZE=1 -DCPEG_DO_MEMOIZE=256 $(LIBDIR)/cpeg.o cpeg_json.o -o $@

cpeg_json_1024: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.o cpeg_json.o
	$(CC) -DCPEG_MEMO_SIZE=1 -DCPEG_DO_MEMOIZE=1024 $(LIBDIR)/cpeg.o cpeg_json.o -o $@


cpeg_json_4096: $(LIBDIR)/cpeglib.h $(LIBDIR)/cpeg.o cpeg_json.o
	$(CC) -DCPEG_MEMO_SIZE=1 -DCPEG_DO_MEMOIZE=4096 $(LIBDIR)/cpeg.o cpeg_json.o -o $@
