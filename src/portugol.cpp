#include <iostream>
#include "Lexico.hpp"

using namespace std;

int main(){

	Lexico lexico;
	string entrada;
	char eof = std::cin.eof();

	std::getline(std::cin, entrada, eof);

	int token = lexico.getToken(entrada);
		
	while(token != -1){ //enquanto há tokens
        
        cout << "token: " << token << endl;
        token = lexico.getToken(entrada);
    }

	return EXIT_SUCCESS;
}