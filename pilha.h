/*
	Author: Daniel Dourado da Costa
	e-mail: danieldouradocosta@gmail.com
	UFG - Universidade Federal de Goias
	May 2015
	Copyright 2015 Daniel Dourado da Costa. All rights reserved.
*/

#ifndef PILHA_H
#define PILHA_H

class Pilha
{
	//long *pilha;
	long tamanho,qtdeElementos,qtdePush,qtdePop,qtdeRedMaior,qtdeRedMenor;

   public:

		void inline setTamanho(long tam){ tamanho = tam; };
		long inline getTamanho(){ return tamanho; };

		void inline setQtdeElementos(long qtde){ qtdeElementos = qtde; };
		long inline getQtdeElementos(){ return qtdeElementos; }

		void inline setQtdePush(long qtde){ qtdePush = qtde; };
		long inline getQtdePush(){ return qtdePush; }

		void inline setQtdePop(long qtde){ qtdePop = qtde; };
		long inline getQtdePop(){ return qtdePop; }

		void inline setQtdeRedMaior(long qRedMaior){ qtdeRedMaior = qRedMaior; }
		long inline getQtdeRedMaior(){ return qtdeRedMaior; }

		void inline setQtdeRedMenor(long qRedMenor){ qtdeRedMenor = qRedMenor; }
	    long inline getQtdeRedMenor(){ return qtdeRedMenor; }

		bool cheia();
		bool vazia();
		void push(int,int,long*);
		void pop(int,long*);

		Pilha(long);
		//~Pilha();
};

#endif
