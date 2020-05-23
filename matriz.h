/*
	Author: Daniel Dourado da Costa
	e-mail: danieldouradocosta@gmail.com
	UFG - Universidade Federal de Goias
	May 2015
	Copyright 2015 Daniel Dourado da Costa. All rights reserved.
*/

#include <stdlib.h>
#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz
{
   float *mat;
   int l,c,tamanho;

   public:

	   void setMat(int,int,int);
	   int getMat(int,int);

	   int inline getLinha() {return l; };
	   int inline getColuna() {return c; };

		void inline setTamanho(unsigned int lin, unsigned int col)
		{
			l=lin;
			c=col;
			tamanho = lin*col;
			mat = (float*)realloc (mat, tamanho*sizeof(float));
		};
		int inline getTamanho(){ return tamanho; };

	   bool static verificarVazia(Matriz*);
	   bool procurarNumero(Matriz*,int);

	   void listarMatriz();

	   Matriz(int,int);
	   ~Matriz();
};

#endif
