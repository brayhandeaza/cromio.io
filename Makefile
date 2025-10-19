.PHONY: build run grammar clean


build: clean grammar run

run:
	@cd ./build && cmake ..
	@cd ./build && make -j
	@cd ./build && ./cromio ../test.io


grammar:
	@cd ./grammar && antlr -Dlanguage=Cpp Tokens.g4 -o antlr/ -visitor
	@cd ./grammar && antlr -Dlanguage=Cpp Expressions.g4 -o antlr/ -visitor
	@cd ./grammar && antlr -Dlanguage=Cpp Grammar.g4 -o antlr/ -visitor

clean:
	@rm -rf build gen .idea && mkdir "build"
	@cd ./grammar && rm -rf antlr .antlr *.tokens *.tokens.txt

