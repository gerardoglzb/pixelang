all:
	bison -d parser.y
	flex scanner.l
	g++ parser.tab.c lex.yy.c -o Code
	./Code

clean:
	rm Code lex.yy.c parser.tab.c parser.tab.h
