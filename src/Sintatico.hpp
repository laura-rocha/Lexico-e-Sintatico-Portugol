#ifndef CLASSE_SINTATICO
#define CLASSE_SINTATICO

#include "Lexico.hpp"
using namespace std;

class Sintatico{

    public:
        void iniciaVariaveisGlobais();
        void Programa ();          
        int getLastToken();
        void comparaToken(int i);
        void erroToken();
        void BlocoVariaveis ();
        void Declaracoes ();
        void DeclaraIdentificador ();
        void DecId ();
        void Dec ();
        void VetorMatriz ();
        void Dimensao ();
        void Dim ();
        void TipoBasico ();
        void ProcedimentoFuncao ();
        void Parametros ();
        void DeclaraParametros ();
        void BlocoComandos ();
        void ListaComandos ();
        void Expressao ();
        void Term ();
        void Fator ();
        void Fat ();
        void ExprIter ();
        void Exp2 ();
        void Termo ();
        void Exp ();
        void ExpressaoSimples ();
        void ExprIt ();
        void List ();
        void List2 ();
        void Variavel ();
        void Var ();
        void Com3 ();
        void Com2 ();
};

#endif /* CLASSE_SINTATICO */
