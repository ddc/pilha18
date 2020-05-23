/*
	Author: Daniel Dourado da Costa
	e-mail: danieldouradocosta@gmail.com
	UFG - Universidade Federal de Goias
	May 2015
	Copyright 2015 Daniel Dourado da Costa. All rights reserved.
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include "pilha.h"
#include "matriz.h"
using namespace std;

class Utils
{
	int li, ls, t, i, p;
	long n,qtdeTopo,tamMax,qtdeMax;
	float f;
	bool overflow;
	double tempoInicial;

	public:

		//o tamanho inicial da pilha
		long inline getTamanhoInicial(){ return n; }
		void inline setTamanhoInicial(int ti){ n = ti; }

		//limites inferior e superior, respectivamente, do intervalo de inteiros para escolha dos elementos a serem inseridos na pilha
		int inline getLimiteInferior(){ return li; }
		void inline setLimiteInferior(int l){ li = l; }

		int inline getLimiteSuperior(){ return ls; }
		void inline setLimiteSuperior(int l){ ls = l; }

		//numero total de elementos que serao escolhidos para insercoes na pilha;
		int inline getQtdeMaxElementos(){ return t; }
		void inline setQtdeMaxElementos(int qtde){ t = qtde; }

		//tipo de incremento na area alocada para a pilha (0 para incremento constante ou 1 para incremento por um fator multiplicativo);
		int inline getTipoIncremento(){ return i; }
		void inline setTipoIncremento(int tipo){ i = tipo; }

		//valor do incremento constante ou do fator multiplicativo, segundo o parametro i
		float inline getFatorMult(){ return f; }
		void inline setFatorMult(float fator){ f = fator; }

		//percentual do tamanho da matriz (em numero de possiveis elementos) para a reducao do seu tamanho.
		int inline getPercent(){ return p; }
		void inline setPercent(int percent){ p = percent; }

		//quantidade de elementos gerados iguais ao elemento no topo da pilha
		long inline getQtdeTopo(){ return qtdeTopo; }
		void inline setQtdeTopo(long qTopo){ qtdeTopo = qTopo; }

		//tamanho maximo alcancado
		long inline getTamMaxAtingido(){ return tamMax; }
		void inline setTamMaxAtingido(long tMax){ tamMax = tMax; }

		//quantidade maxima de elementos atingido dentro pa pilha
		long inline getQtdeEleMaxAtingido(){ return qtdeMax; }
		void inline setQtdeEleMaxAtingido(long qMax){ qtdeMax = qMax; }

		//flag para saber se ocorreu overflow ou nao
		bool inline getOverflow(){ return overflow; }
		void inline setOverflow(bool of){ overflow = of; }

		//tempo inicial
		time_t inline getTempoInicial(){ return tempoInicial; }
		void inline setTempoInicial(time_t tempo){ tempoInicial = tempo; }

		void menu();
		void setarTamanhoInicial();
		void setarLimitesInfSup();
		void setarQtdeMaxElementos();
		void setarTipoIncremento();
		void setarFatorMult();
		void setarPercent();
		void inserirNumeros();
		void mostrarVariaveis();
		void listarPilhaHorizontal(Pilha*,long*);
		void listarPilhaVertical(Pilha*,long*);
		void contarElemRepetidos(Pilha*,long*);
		void showDebugOutput(Pilha*,long*,long);
		void listarRelatorioFinal(Pilha*, Matriz*,long*);

		int numeroDecisao();
		int numeroPush();
		int procurarRepetido(Pilha*,long*,int);

		bool checarInt(int,string);
		bool checarLimites(int,string);
		bool procurarNumPrimColuna(Matriz*,int,int);

		Utils();
		~Utils();
};

#endif /* UTILS_H_ */
