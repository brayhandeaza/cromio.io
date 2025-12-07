.PHONY: build run grammar clean

MODULES_DIR := $(CURDIR)/src/modules

build: clean grammar runtime run

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
	@cd ./src/lexer/tokens && rm -rf antlr .antlr *.tokens *.tokens.txt

runtime:
	@clang++ -std=c++20 -O3 -emit-llvm -c \
	$(shell find $(MODULES_DIR) -type f -name "*.cpp") \
	-I $(MODULES_DIR) -o $(MODULES_DIR)/runtime.bc





