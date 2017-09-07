TARGET = json_notree

all: $(TARGET)

$(TARGET): lex.yy.c y.tab.c y.tab.h
	gcc -Wall -O3 -x c -o $(TARGET) lex.yy.c y.tab.c y.tab.h

y.tab.c y.tab.h: json_notree.y
	bison -y -d json_notree.y

lex.yy.c: json_notree.l
	flex json_notree.l

clean:
	$(RM) -f $(TARGET)
	$(RM) -f y.tab.h y.tab.c
	$(RM) -f lex.yy.c
	$(RM) -f *.o
