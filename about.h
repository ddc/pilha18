/*
	Author: Daniel Dourado da Costa
	e-mail: danieldouradocosta@gmail.com
	UFG - Universidade Federal de Goias
	May 2015
	Copyright 2015 Daniel Dourado da Costa. All rights reserved.
*/

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ABOUT_H
#define ABOUT_H

void about()
{
   cout  << endl
         << setw(23) << "PILHA" << " v1.18" << endl
         << setw(28) << "Maio 2015" << endl
         << setw(42) << "Universidade Federal de Goias - UFG" << endl <<endl
         << setw(45) << "Estrutura de Dados e Projeto de Algoritmos" << endl << endl
         << setw(25) << "AUTORES" << endl << endl
         << setw(10) << "DANIEL D. COSTA" << setw(42) << "danieldouradocosta@gmail.com" << endl
         << setw(10) << "JEAN PIERRE B. SOUSA" << setw(27) << "jpbsousa@gmail.com" << endl;

}
#endif
