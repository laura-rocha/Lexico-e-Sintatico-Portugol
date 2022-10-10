#nome do projeto
PROJETO = portugol

#arquivos .c
ARQUIVOS_CPP = $(wildcard *.cpp)

#arquivos .h
ARQUIVOS_H = $(wildcard *.h)

#gera a lista de arquivos-objeto usando a lista de arquivos-fonte
OBJ = $(ARQUIVOS_CPP:.cpp=.o)

#compilador
CC = gcc

#flags para o compilador
FLAGS = -Wall -ansi -pedantic -std=c99 -fstack-protector-all -g

#ligação com as bibliotecas
LINKER_FLAGS = -lm

#linking e compilaçao

all: $(PROJETO)

$(PROJETO): 
	g++ -o $(PROJETO) $(PROJETO).cpp

clean:
	rm -rf *.o $(PROJETO)

run: $(PROJETO) teste.por
	./$(PROJETO) < teste.por
