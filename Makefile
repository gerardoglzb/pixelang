all:
	bison -d ./src/parser.y --output-file=./bin/parser.tab.c --defines=./bin/parser.tab.h
	flex -o ./bin/lex.yy.c ./src/scanner.l
	g++ -std=c++11 ./src/compiler.cpp ./bin/parser.tab.c ./bin/lex.yy.c -o ./bin/Code
	./bin/Code

clean:
	rm ./bin/Code ./bin/lex.yy.c ./bin/parser.tab.c ./bin/parser.tab.h
