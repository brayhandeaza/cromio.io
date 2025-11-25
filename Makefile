.PHONY: build run grammar clean

build: clean grammar run

run:
	@cd ./build && cmake ..
	@cd ./build && make -j
	@cd ./build && ./cromio ../test.io


grammar:
	@cd ./src/lexer/tokens && antlr -Dlanguage=Cpp Tokens.g4 -o ../antlr/ -visitor
	@cd ./src/lexer/grammars && antlr -Dlanguage=Cpp Grammar.g4 -o ../antlr/ -visitor

clean:
	@rm -rf build gen .idea && mkdir "build"
	@cd ./src/lexer && rm -rf antlr .antlr *.tokens *.tokens.txt