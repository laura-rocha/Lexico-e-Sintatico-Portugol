#ifndef CLASSE_LEXICO 
#define CLASSE_LEXICO

#include <string>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;

#define IDENTIFICADOR 0
#define E 1
#define NUMERO_INTEIRO 2
#define DIVISAO 3
#define PONTO_E_VIRGULA 4
#define VIRGULA 5
#define DOIS_PONTOS 6
#define PONTO 7
#define ABRE_COLCHETES 8
#define FECHA_COLCHETES 9
#define ABRE_PARENTESES 10
#define FECHA_PARENTESES 11
#define IGUAL 12
#define MENOR 13
#define MAIOR 14
#define MAIS 15
#define MENOS 16
#define VEZES 17
#define STRING 18
#define DE 19
#define OU 20
#define SE 21
#define NUMERO_REAL 22
#define COMENTARIO_DE_BLOCO 23
#define COMENTARIO_DE_LINHA 24
#define ATRIBUICAO 25
#define DIFERENTE 26
#define MENOR_IGUAL 27
#define MAIOR_IGUAL 28
#define ATE 29
#define DIV 30
#define FIM 31
#define NAO 32
#define FACA 33
#define LEIA 34
#define PARA 35
#define REAL 36
#define TIPO 37
#define ENTAO 38
#define FALSO 39
#define PASSO 40
#define SENAO 41
#define VETOR 42
#define FUNCAO 43
#define INICIO 44
#define LOGICO 45
#define MATRIZ 46
#define REPITA 47
#define INTEIRO 48
#define IMPRIMA 49
#define ENQUANTO 50
#define ALGORITMO 51
#define CARACTERE 52
#define VARIAVEIS 53
#define VERDADEIRO 54
#define PROCEDIMENTO 55
#define NOVA_LINHA 56

class Lexico{

    public:
        int getToken(string entrada);
        static int indiceSimbolo(char c);
        static int estadoFinal(int estado);
        static int indiceEstadoFinal(int estado);
        static int codigoToken(int i);
        void resetaEstados(int *i, int *inicioToken, int *fimToken, int *estadoAtual, int *ultimoEstadoFinal);
        void incrementaLinha();
        void incrementaColuna();
        int getColuna();
        int getLinha();
        static void atualizaTokenAnterior(string entrada);
        string getTokenAnterior();
};

#endif /* CLASSE_LEXICO */