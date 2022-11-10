#nome do projeto
PROJETO = portugol

#arquivos .cpp
ARQUIVOS_CPP = $(wildcard *.cpp)

#arquivos .hpp
ARQUIVOS_HPP = $(wildcard *.hpp)

#gera a lista de arquivos-objeto usando a lista de arquivos-fonte
OBJ = $(ARQUIVOS_CPP:.cpp=.o)

#flags para o compilador
FLAGS = -Wall -ansi -pedantic -std=c++11 -fstack-protector-all -g

#ligação com as bibliotecas
LINKER_FLAGS = -lm

#compilador
CC = g++

#linking e compilaçao

all: $(PROJETO)

$(PROJETO): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(LINKER_FLAGS)

%.o: %.cpp %.hpp
	$(CC) -o $@ $< -c $(FLAGS) $(LINKER_FLAGS)

clean:
	rm -rf *.o $(PROJETO) *~