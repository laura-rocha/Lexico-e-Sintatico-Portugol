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
	rm saidas/*.txt

run: $(PROJETO)
	./$(PROJETO) < testes/teste_01.por > saidas/saida1.txt
	./$(PROJETO) < testes/teste_02.por > saidas/saida2.txt
	./$(PROJETO) < testes/teste_03.por > saidas/saida3.txt
	./$(PROJETO) < testes/teste_04.por > saidas/saida4.txt
	./$(PROJETO) < testes/teste_05.por > saidas/saida5.txt
	./$(PROJETO) < testes/teste_06.por > saidas/saida6.txt
	./$(PROJETO) < testes/teste_07.por > saidas/saida7.txt
	./$(PROJETO) < testes/teste_08.por > saidas/saida8.txt
	./$(PROJETO) < testes/teste_09.por > saidas/saida9.txt
	./$(PROJETO) < testes/teste_10.por > saidas/saida10.txt
