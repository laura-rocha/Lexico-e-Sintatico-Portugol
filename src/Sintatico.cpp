#include "Sintatico.hpp"

using namespace std;

Lexico lexico;
int ultimoToken;
string entrada;

void Sintatico::iniciaVariaveisGlobais(){
	char eof = std::cin.eof();
	std::getline(std::cin, entrada, eof);
	ultimoToken = lexico.getToken(entrada);
	while(ultimoToken == COMENTARIO_DE_BLOCO || ultimoToken == COMENTARIO_DE_LINHA || ultimoToken == NOVA_LINHA)
		ultimoToken = lexico.getToken(entrada);
	
	cout << "PrimeiroToken: " << ultimoToken;
}

int Sintatico::getLastToken(){
	return ultimoToken;
}

void Sintatico::comparaToken(int i){

	if(getLastToken() == i){
		ultimoToken = lexico.getToken(entrada);
		while(ultimoToken == COMENTARIO_DE_BLOCO || ultimoToken == COMENTARIO_DE_LINHA || ultimoToken == NOVA_LINHA)
			ultimoToken = lexico.getToken(entrada);
	}
	else
		erroToken();
}

void Sintatico::erroToken(){
	cout << "ERRO SINTÁTICO" << endl;
	exit(1);
}

void Sintatico::Programa(){ 
	switch(getLastToken()){
		case ALGORITMO:
			comparaToken(ALGORITMO);
			comparaToken(IDENTIFICADOR);
			comparaToken(PONTO_E_VIRGULA);
			BlocoVariaveis();
			ProcedimentoFuncao();
			BlocoComandos();
			comparaToken(PONTO);
			comparaToken(-1); //verificar erro
			break; 
		default:
			erroToken();
	}
}

void Sintatico::BlocoVariaveis(){ //Expressão é nullable
	switch (getLastToken()){
		case VARIAVEIS:
			comparaToken(VARIAVEIS);
			Declaracoes();
			break; 
		case INICIO:
			break;
		case FUNCAO:
			break;
		case PROCEDIMENTO:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::Parametros(){ //Expressão é nullable
	switch(getLastToken()){
		case ABRE_PARENTESES:
			comparaToken(ABRE_PARENTESES);
			DeclaraIdentificador();
			comparaToken(FECHA_PARENTESES);
			break; 
		case DOIS_PONTOS:
			break;
		case PONTO_E_VIRGULA:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::Variavel(){ 
	switch(getLastToken()){
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			Var();
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::ExprIt(){ // Expressão é nullable
	switch(getLastToken()){
		case VIRGULA:
			comparaToken(VIRGULA);
			ExprIter();
			break; 
		case FECHA_PARENTESES:
			break;
		case FECHA_COLCHETES:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::Var(){ // Expressão é nullable
	switch (getLastToken()) {
		case ABRE_COLCHETES:
			comparaToken(ABRE_COLCHETES);
			ExprIter();
			comparaToken(FECHA_COLCHETES);
			break; 
		case FECHA_PARENTESES:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::Com2(){ 
	switch(getLastToken()){
		case FIM:
			comparaToken(FIM);
			comparaToken(SE);
			break; 
		case SENAO:
			comparaToken(SENAO);
			ListaComandos();
			comparaToken(FIM);
			comparaToken(SE);
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::Exp2(){ // Expressão é nullable
	switch(getLastToken()){
		case MAIS:
			comparaToken(MAIS);
			Termo();
			Exp2();
			break; 
		case MENOS:
			comparaToken(MENOS);
			Termo();
			Exp2();
			break; 
		case OU:
			comparaToken(OU);
			Termo();
			Exp2();
			break; 
		case FACA:
			break;
		case PASSO:
			break;
		case ATE:
			break;
		case PONTO_E_VIRGULA:
			break;
		case ENTAO:
			break;
		case DIFERENTE:
			break;
		case IGUAL:
			break;
		case MAIOR:
			break;
		case MAIOR_IGUAL:
			break;
		case MENOR:
			break;
		case MENOR_IGUAL:
			break;
		case FECHA_PARENTESES:
			break;
		case FECHA_COLCHETES:
			break;
		case VIRGULA:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::Exp(){ // Expressão é nullable
	switch(getLastToken()){
		case DIFERENTE:
			comparaToken(DIFERENTE);
			ExpressaoSimples();
			Exp();
			break; 
		case IGUAL:
			comparaToken(IGUAL);
			ExpressaoSimples();
			Exp();
			break; 
		case MAIOR:
			comparaToken(MAIOR);
			ExpressaoSimples();
			Exp();
			break; 
		case MAIOR_IGUAL:
			comparaToken(MAIOR_IGUAL);
			ExpressaoSimples();
			Exp();
			break; 
		case MENOR:
			comparaToken(MENOR);
			ExpressaoSimples();
			Exp();
			break; 
		case MENOR_IGUAL:
			comparaToken(MENOR_IGUAL);
			ExpressaoSimples();
			Exp();
			break; 
		case FACA:
			break;
		case PASSO:
			break;
		case ATE:
			break;
		case PONTO_E_VIRGULA:
			break;
		case ENTAO:
			break;
		case FECHA_PARENTESES:
			break;
		case FECHA_COLCHETES:
			break;
		case VIRGULA:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::VetorMatriz(){ 
	switch(getLastToken()){
		case MATRIZ:
			comparaToken(MATRIZ);
			break; 
		case VETOR:
			comparaToken(VETOR);
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::BlocoComandos(){ 
	switch(getLastToken()){
		case INICIO:
			comparaToken(INICIO);
			ListaComandos();
			comparaToken(FIM);
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::DecId(){ // Expressão é nullable
	switch(getLastToken()){
		case VIRGULA:
			comparaToken(VIRGULA);
			DeclaraIdentificador();
			break; 
		case PONTO_E_VIRGULA:
			break;
		case FECHA_PARENTESES:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::Dec(){ // Expressão é nullable
	switch (getLastToken()) {
		case CARACTERE:
			comparaToken(CARACTERE);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case INTEIRO:
			comparaToken(INTEIRO);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case LOGICO:
			comparaToken(LOGICO);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case REAL:
			comparaToken(REAL);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case TIPO:
			comparaToken(TIPO);
			comparaToken(IDENTIFICADOR);
			comparaToken(IGUAL);
			VetorMatriz();
			comparaToken(ABRE_COLCHETES);
			Dimensao();
			comparaToken(FECHA_COLCHETES);
			TipoBasico();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case INICIO:
			break;
		case FUNCAO:
			break;
		case PROCEDIMENTO:
			break;
		case VARIAVEIS:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::DeclaraParametros(){ // Expressão é nullable
	switch(getLastToken()){
		case CARACTERE:
			comparaToken(CARACTERE);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case INTEIRO:
			comparaToken(INTEIRO);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case LOGICO:
			comparaToken(LOGICO);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case REAL:
			comparaToken(REAL);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case TIPO:
			comparaToken(TIPO);
			comparaToken(IDENTIFICADOR);
			comparaToken(IGUAL);
			VetorMatriz();
			comparaToken(ABRE_COLCHETES);
			Dimensao();
			comparaToken(FECHA_COLCHETES);
			TipoBasico();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case INICIO:
			break;
		case VARIAVEIS:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::Com3(){ 
	switch(getLastToken()){
		case FACA:
			comparaToken(FACA);
			ListaComandos();
			comparaToken(FIM);
			comparaToken(PARA);
			break; 
		case PASSO:
			comparaToken(PASSO);
			Expressao();
			comparaToken(FACA);
			ListaComandos();
			comparaToken(FIM);
			comparaToken(PARA);
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::Term(){ // Expressão é nullable
	switch(getLastToken()){
		case DIV:
			comparaToken(DIV);
			Fator();
			Term();
			break; 
		case DIVISAO:
			comparaToken(DIVISAO);
			Fator();
			Term();
			break; 
		case E:
			comparaToken(E);
			Fator();
			Term();
			break; 
		case VEZES:
			comparaToken(VEZES);
			Fator();
			Term();
			break;
		case FACA:
			break;
		case PASSO:
			break;
		case ATE:
			break;
		case PONTO_E_VIRGULA:
			break;
		case ENTAO:
			break;
		case DIFERENTE:
			break;
		case IGUAL:
			break;
		case MAIOR:
			break;
		case MAIOR_IGUAL:
			break;
		case MENOR:
			break;
		case MENOR_IGUAL:
			break;
		case MAIS:
			break;
		case MENOS:
			break;
		case OU:
			break;
		case FECHA_PARENTESES:
			break;
		case FECHA_COLCHETES:
			break;
		case VIRGULA:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::ListaComandos(){ 
	switch(getLastToken()){
		case ENQUANTO:
			comparaToken(ENQUANTO);
			Expressao();
			comparaToken(FACA);
			ListaComandos();
			comparaToken(FIM);
			comparaToken(ENQUANTO);
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			List2();
			break; 
		case IMPRIMA:
			comparaToken(IMPRIMA);
			comparaToken(ABRE_PARENTESES);
			ExprIter();
			comparaToken(FECHA_PARENTESES);
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case LEIA:
			comparaToken(LEIA);
			comparaToken(ABRE_PARENTESES);
			Variavel();
			comparaToken(FECHA_PARENTESES);
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case PARA:
			comparaToken(PARA);
			comparaToken(IDENTIFICADOR);
			comparaToken(DE);
			Expressao();
			comparaToken(ATE);
			Expressao();
			Com3();
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case REPITA:
			comparaToken(REPITA);
			ListaComandos();
			comparaToken(ATE);
			Expressao();
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case SE:
			comparaToken(SE);
			Expressao();
			comparaToken(ENTAO);
			ListaComandos();
			Com2();
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::Fator(){ 
	switch(getLastToken()){
		case ABRE_PARENTESES:
			comparaToken(ABRE_PARENTESES);
			Expressao();
			comparaToken(FECHA_PARENTESES);
			break; 
		case FALSO:
			comparaToken(FALSO);
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			Fat();
			break; 
		case NAO:
			comparaToken(NAO);
			Fator();
			break; 
		case NUMERO_INTEIRO:
			comparaToken(NUMERO_INTEIRO);
			break; 
		case NUMERO_REAL:
			comparaToken(NUMERO_REAL);
			break; 
		case STRING:
			comparaToken(STRING);
			break; 
		case VERDADEIRO:
			comparaToken(VERDADEIRO);
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::ExprIter(){ 
	switch(getLastToken()){
		case ABRE_PARENTESES:
			comparaToken(ABRE_PARENTESES);
			Expressao();
			comparaToken(FECHA_PARENTESES);
			Term();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case FALSO:
			comparaToken(FALSO);
			Term();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			Fat();
			Term();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case MAIS:
			comparaToken(MAIS);
			Termo();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case MENOS:
			comparaToken(MENOS);
			Termo();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case NAO:
			comparaToken(NAO);
			Fator();
			Term();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case NUMERO_INTEIRO:
			comparaToken(NUMERO_INTEIRO);
			Term();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case NUMERO_REAL:
			comparaToken(NUMERO_REAL);
			Term();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case STRING:
			comparaToken(STRING);
			Term();
			Exp2();
			Exp();
			ExprIt();
			break; 
		case VERDADEIRO:
			comparaToken(VERDADEIRO);
			Term();
			Exp2();
			Exp();
			ExprIt();
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::List2(){ 
	switch(getLastToken()){
		case ABRE_COLCHETES:
			comparaToken(ABRE_COLCHETES);
			ExprIter();
			comparaToken(FECHA_COLCHETES);
			comparaToken(ATRIBUICAO);
			Expressao();
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case ABRE_PARENTESES:
			comparaToken(ABRE_PARENTESES);
			ExprIter();
			comparaToken(FECHA_PARENTESES);
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::Declaracoes(){ 
	switch(getLastToken()){
		case CARACTERE:
			comparaToken(CARACTERE);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case INTEIRO:
			comparaToken(INTEIRO);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case LOGICO:
			comparaToken(LOGICO);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case REAL:
			comparaToken(REAL);
			comparaToken(DOIS_PONTOS);
			DeclaraIdentificador();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		case TIPO:
			comparaToken(TIPO);
			comparaToken(IDENTIFICADOR);
			comparaToken(IGUAL);
			VetorMatriz();
			comparaToken(ABRE_COLCHETES);
			Dimensao();
			comparaToken(FECHA_COLCHETES);
			TipoBasico();
			comparaToken(PONTO_E_VIRGULA);
			Dec();
			break; 
		default:
			erroToken();
	}
}  

void Sintatico::ProcedimentoFuncao(){ // Expressão é nullable
	switch(getLastToken()){
		case FUNCAO:
			comparaToken(FUNCAO);
			comparaToken(IDENTIFICADOR);
			Parametros();
			comparaToken(DOIS_PONTOS);
			TipoBasico();
			comparaToken(PONTO_E_VIRGULA);
			DeclaraParametros();
			BlocoVariaveis();
			BlocoComandos();
			comparaToken(PONTO_E_VIRGULA);
			ProcedimentoFuncao();
			break; 
		case PROCEDIMENTO:
			comparaToken(PROCEDIMENTO);
			comparaToken(IDENTIFICADOR);
			Parametros();
			comparaToken(PONTO_E_VIRGULA);
			DeclaraParametros();
			BlocoVariaveis();
			BlocoComandos();
			comparaToken(PONTO_E_VIRGULA);
			ProcedimentoFuncao();
			break; 
		case INICIO:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::Fat(){ // Expressão é nullable
	switch(getLastToken()){
		case ABRE_COLCHETES:
			comparaToken(ABRE_COLCHETES);
			ExprIter();
			comparaToken(FECHA_COLCHETES);
			break; 
		case ABRE_PARENTESES:
			comparaToken(ABRE_PARENTESES);
			ExprIter();
			comparaToken(FECHA_PARENTESES);
			break; 
		case FACA:
			break;
		case PASSO:
			break;
		case ATE:
			break;
		case PONTO_E_VIRGULA:
			break;
		case ENTAO:
			break;
		case FECHA_PARENTESES:
			break;
		case DIFERENTE:
			break;
		case IGUAL:
			break;
		case MAIOR:
			break;
		case MAIOR_IGUAL:
			break;
		case MENOR:
			break;
		case MENOR_IGUAL:
			break;
		case MAIS:
			break;
		case MENOS:
			break;
		case OU:
			break;
		case DIV:
			break;
		case DIVISAO:
			break;
		case E:
			break;
		case VEZES:
			break;
		case FECHA_COLCHETES:
			break;
		case VIRGULA:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::TipoBasico(){ 
	switch(getLastToken()){
		case CARACTERE:
			comparaToken(CARACTERE);
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			break; 
		case INTEIRO:
			comparaToken(INTEIRO);
			break; 
		case LOGICO:
			comparaToken(LOGICO);
			break; 
		case REAL:
			comparaToken(REAL);
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::DeclaraIdentificador(){ 
	switch(getLastToken()){
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			DecId();
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::Dim(){ // Expressão é nullable
	switch(getLastToken()){
		case VIRGULA:
			comparaToken(VIRGULA);
			Dimensao();
			break; 
		case FECHA_COLCHETES:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::List(){ // Expressão é nullable
	switch(getLastToken()){
		case ENQUANTO:
			comparaToken(ENQUANTO);
			Expressao();
			comparaToken(FACA);
			ListaComandos();
			comparaToken(FIM);
			comparaToken(ENQUANTO);
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			List2();
			break; 
		case IMPRIMA:
			comparaToken(IMPRIMA);
			comparaToken(ABRE_PARENTESES);
			ExprIter();
			comparaToken(FECHA_PARENTESES);
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case LEIA:
			comparaToken(LEIA);
			comparaToken(ABRE_PARENTESES);
			Variavel();
			comparaToken(FECHA_PARENTESES);
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case PARA:
			comparaToken(PARA);
			comparaToken(IDENTIFICADOR);
			comparaToken(DE);
			Expressao();
			comparaToken(ATE);
			Expressao();
			Com3();
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case REPITA:
			comparaToken(REPITA);
			ListaComandos();
			comparaToken(ATE);
			Expressao();
			comparaToken(PONTO_E_VIRGULA);
			List();
			break; 
		case SE:
			comparaToken(SE);
			Expressao();
			comparaToken(ENTAO);
			ListaComandos();
			Com2();
			comparaToken(PONTO_E_VIRGULA);
			List();
			break;
		case FIM:
			break;
		case ATE:
			break;
		case SENAO:
			break;
		default:
			erroToken();
	}
} 

void Sintatico::ExpressaoSimples(){ 
	switch(getLastToken()){
		case ABRE_PARENTESES:
			comparaToken(ABRE_PARENTESES);
			Expressao();
			comparaToken(FECHA_PARENTESES);
			Term();
			Exp2();
			break; 
		case FALSO:
			comparaToken(FALSO);
			Term();
			Exp2();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			Fat();
			Term();
			Exp2();
			break; 
		case MAIS:
			comparaToken(MAIS);
			Termo();
			Exp2();
			break; 
		case MENOS:
			comparaToken(MENOS);
			Termo();
			Exp2();
			break; 
		case NAO:
			comparaToken(NAO);
			Fator();
			Term();
			Exp2();
			break; 
		case NUMERO_INTEIRO:
			comparaToken(NUMERO_INTEIRO);
			Term();
			Exp2();
			break; 
		case NUMERO_REAL:
			comparaToken(NUMERO_REAL);
			Term();
			Exp2();
			break; 
		case STRING:
			comparaToken(STRING);
			Term();
			Exp2();
			break; 
		case VERDADEIRO:
			comparaToken(VERDADEIRO);
			Term();
			Exp2();
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::Dimensao(){ 
	switch(getLastToken()){
		case NUMERO_INTEIRO:
			comparaToken(NUMERO_INTEIRO);
			comparaToken(DOIS_PONTOS);
			comparaToken(NUMERO_INTEIRO);
			Dim();
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::Termo(){ 
	switch(getLastToken()){
		case ABRE_PARENTESES:
			comparaToken(ABRE_PARENTESES);
			Expressao();
			comparaToken(FECHA_PARENTESES);
			Term();
			break; 
		case FALSO:
			comparaToken(FALSO);
			Term();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			Fat();
			Term();
			break; 
		case NAO:
			comparaToken(NAO);
			Fator();
			Term();
			break; 
		case NUMERO_INTEIRO:
			comparaToken(NUMERO_INTEIRO);
			Term();
			break; 
		case NUMERO_REAL:
			comparaToken(NUMERO_REAL);
			Term();
			break; 
		case STRING:
			comparaToken(STRING);
			Term();
			break; 
		case VERDADEIRO:
			comparaToken(VERDADEIRO);
			Term();
			break; 
		default:
			erroToken();
	}
} 

void Sintatico::Expressao(){ 
	switch(getLastToken()){
		case ABRE_PARENTESES:
			comparaToken(ABRE_PARENTESES);
			Expressao();
			comparaToken(FECHA_PARENTESES);
			Term();
			Exp2();
			Exp();
			break; 
		case FALSO:
			comparaToken(FALSO);
			Term();
			Exp2();
			Exp();
			break; 
		case IDENTIFICADOR:
			comparaToken(IDENTIFICADOR);
			Fat();
			Term();
			Exp2();
			Exp();
			break; 
		case MAIS:
			comparaToken(MAIS);
			Termo();
			Exp2();
			Exp();
			break; 
		case MENOS:
			comparaToken(MENOS);
			Termo();
			Exp2();
			Exp();
			break; 
		case NAO:
			comparaToken(NAO);
			Fator();
			Term();
			Exp2();
			Exp();
			break; 
		case NUMERO_INTEIRO:
			comparaToken(NUMERO_INTEIRO);
			Term();
			Exp2();
			Exp();
			break; 
		case NUMERO_REAL:
			comparaToken(NUMERO_REAL);
			Term();
			Exp2();
			Exp();
			break; 
		case STRING:
			comparaToken(STRING);
			Term();
			Exp2();
			Exp();
			break; 
		case VERDADEIRO:
			comparaToken(VERDADEIRO);
			Term();
			Exp2();
			Exp();
			break; 
		default:
			erroToken();
	}
} 

