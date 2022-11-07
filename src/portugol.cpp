#include "Sintatico.hpp"

using namespace std;

int main(){

	Sintatico sintatico;

	sintatico.iniciaVariaveisGlobais();
	sintatico.Programa();

	cout << "PROGRAMA CORRETO.";

	return EXIT_SUCCESS;
}