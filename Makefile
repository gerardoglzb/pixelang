all: Code Main

Code: parser.tab.c lex.yy.c
	g++ -std=c++11 ./src/compiler.cpp ./bin/parser.tab.c ./bin/lex.yy.c -o ./bin/Code
	./bin/Code

Main: Code
	g++ -std=c++11 ./src/main.cpp -o ./bin/Main
	./bin/Main

parser.tab.c: ./src/parser.y
	bison -d ./src/parser.y --output-file=./bin/parser.tab.c --defines=./bin/parser.tab.h

lex.yy.c: ./src/scanner.l
	flex -o ./bin/lex.yy.c ./src/scanner.l

clean:
	rm ./bin/Code ./bin/lex.yy.c ./bin/parser.tab.c ./bin/parser.tab.h ./bin/Main
