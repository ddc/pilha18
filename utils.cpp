/*
	Author: Daniel Dourado da Costa
	e-mail: danieldouradocosta@gmail.com
	UFG - Universidade Federal de Goias
	May 2015
	Copyright 2015 Daniel Dourado da Costa. All rights reserved.
*/

#include <string>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include "pilha.h"
#include "matriz.h"
#include "utils.h"
#include "about.h"
#include "dragao.h"
using namespace std;
//////////////////////////////////////////////////////////
/////////////////////// VARS  ////////////////////////////
//////////////////////////////////////////////////////////
#ifdef __unix__
    #define WINDOWS 0
#elif defined(_WIN32) || defined(WIN32)
    #define WINDOWS 1
#endif
#define DEBUG 1
void clear()
{
    if(WINDOWS)
        system("cls");
    else
        system("clear");
}
long lrand48()
{
    return rand();
}
double drand48()
{
    return rand() / (double)RAND_MAX;
}
void srand48(long seedval)
{
    rand() % seedval;
}
char VERSAO[7] = " v1.18";
//////////////////////////////////////////////////////////
/////////////////////////// CONSTRUTOR  /////////////////
/////////////////////////////////////////////////////////
Utils::Utils()
{
	n  				= 0;
	li 				= -1;
	ls 				= -1;
	t  				= 0;
	i  				= -1;
	f  				= 0.0;
	p  				= 0;
	qtdeTopo 		= 0;
	tamMax			= 1;
	qtdeMax			= 1;
	overflow		= false;
	tempoInicial	= 0;
}
////////////////////////////////////////////////////////
/////////////////////////// DESTRUTOR  /////////////////
////////////////////////////////////////////////////////
Utils::~Utils()
{
	n  				= 0;
	li 				= 0;
	ls 				= 0;
	t  				= 0;
	i  				= 0;
	f  				= 0.0;
	p  				= 0;
	qtdeTopo 		= 0;
	tamMax			= 0;
	qtdeMax			= 0;
	overflow		= false;
	tempoInicial	= 0;
}
////////////////////////////////////
//////////////// MENU /////////////
///////////////////////////////////
void Utils::menu()
{
	char choice;

	clear();
	choice = '0';

	while(choice!='3')
	{
	  cout << endl << setw(8) << "PILHA" << VERSAO << endl << endl;
	  cout  << "----------------" 	<< endl
			<< "1)"<< " INICIAR" 	<< endl
			<< "----------------" 	<< endl
			<< "2)"<< " SOBRE" 		<< endl
			<< "3)"<< " SAIR" 		<< endl
			<< "----------------" 	<< endl;
	  cin   >> choice;
	  cin.ignore(1,'\n');

	  switch(choice)
	  {
		 case '1':
		 {
			setarTamanhoInicial();		//n
			setarLimitesInfSup();		//li ls
			setarQtdeMaxElementos();	//t
			setarTipoIncremento();		//i
			setarFatorMult();			//f
			setarPercent();				//p
			mostrarVariaveis();
			inserirNumeros();

			getchar();
			clear();

			break;
		 }
		 case '2':
		 {
			clear();
			about();
			getchar();
			clear();
			break;
		 }
		 case '3':
		 {
		 	clear();
			dragao();
			exit(EXIT_SUCCESS);
			break;
		 }
		 default:
		 {
			clear();
			cout << endl << setw(8) << "PILHA" << VERSAO << endl << endl;
			cout  << " ===> SELECAO ERRADA <===" << endl << endl << endl
				  << " aperte \"enter\" para voltar..." << endl;
			getchar();
			clear();
		 }
	  }
	}
}
//////////////////////////////////////////////////////////
//////////////////////// CHECAR INTEIRO  /////////////////
//////////////////////////////////////////////////////////
bool Utils::checarInt(int num, string str)
{
	//int = 4 bytes <> 32 bits = -2147483648 a + 2147483647 <> numeros inteiros
	if(num == 2147483647)
	{
		cout << endl
			 << "ERRO: Tamanho inserido maior que o tamanho adequado!!" << endl
			 << "=> O tamanho foi reduzido para 2147483647."
			 << endl << endl << endl
			 << " aperte \"enter\" para continuar..." << endl;
		getchar();
	}
	else if(this->getTamanhoInicial() <= 0 || num <= 0)
	{
		cout << endl
			 << str
			 << endl
			 << "Favor Conferir!!!"
			 << endl << endl << endl
			 << " aperte \"enter\" para voltar..." << endl;
		  getchar();

		return false;
	}

	return true;
}
bool Utils::checarLimites(int num, string str)
{
	if(num == 2147483647)
	{
		cout << endl
			 << "ERRO: Tamanho inserido maior que o tamanho adequado!!" << endl
			 << "=> O tamanho foi reduzido para 2147483647."
			 << endl << endl << endl
			 << " aperte \"enter\" para continuar..." << endl;
		getchar();
	}
	else if (num == 0)
	{
		cout << endl
			 << str
			 << endl
			 << "=> O valor foi ajustado para: " << num
			 << endl << endl << endl
			 << " aperte \"enter\" para continuar..." << endl;
		  getchar();
	}

	return true;
}
//////////////////////////////////////////////////////////
///////////////////////// TAMANHO INICIAL /////////////////
//////////////////////////////////////////////////////////
void Utils::setarTamanhoInicial()
{
	int tam = 0;
	string nStr;
	bool choice = false;

	while(!choice)
	{
		clear();
		cout << endl << endl
			 << "Digite o tamanho inicial da pilha: ";
		getline(cin, nStr);
		stringstream(nStr) >> tam;
		cin.clear();

		this->setTamanhoInicial(tam);
		choice = checarInt(this->getTamanhoInicial(),"ERRO: Tamanho da pilha invalida!!!");
	}
}
//////////////////////////////////////////////////////////
/////////////////////////LIMITES INF SUP /////////////////
//////////////////////////////////////////////////////////
void Utils::setarLimitesInfSup()
{
	int limInf=0, limSup=0;
	string liStr, lsStr;
	bool ch=false, choice=false;

	clear();
	cout << endl << endl
		 << "Agora sera necessario a insercao dos limites inferior e superior," << endl
		 << "que serao respectivamente, o intervalo de inteiros para escolha" << endl
		 << "dos elementos a serem inseridos na pilha."
		 << endl << endl;

	while(!choice)
	{
		ch=false;
		while(!ch)
		{
			cout << "Digite o tamanho do limite INFERIOR:  ";
			getline(cin, liStr);
			stringstream(liStr) >> limInf;
			cin.clear();

			this->setLimiteInferior(limInf);
			ch = checarLimites(this->getLimiteInferior(),"ERRO: Tamanho do limite inferior invalido!!");
		}

		ch = false;
		while(!ch)
		{
			cout << "Digite o tamanho do limite SUPERIOR:  ";
			getline(cin, lsStr);
			stringstream(lsStr) >> limSup;
			cin.clear();

			this->setLimiteSuperior(limSup);
			ch = checarLimites(this->getLimiteSuperior(),"ERRO: Tamanho do limite superior invalido!!");
		}

		if(this->getLimiteInferior() > this->getLimiteSuperior())
		{
			cout << endl << endl
				 << "ERRO: Limite Inferior nao pode ser maior que o limite superior!!!"
				 << endl << endl << endl
				 << " aperte \"enter\" para voltar..." << endl;
			getchar();

			choice = false;
		}
		else
			choice = true;
	}
}
//////////////////////////////////////////////////////////
///////////////////////// NUMERO ELEMENTOS ///////////////
//////////////////////////////////////////////////////////
void Utils::setarQtdeMaxElementos() //t
{
	int numTotal=0;
	string str;
	bool choice=false;

	clear();
	cout << endl << endl
		 << "Numero TOTAL de elementos que serao escolhidos para insercoes na pilha."
		 << endl << endl;

	while(!choice)
	{
		cout << endl << endl
			 << "Digite o numero TOTAL de elementos:  ";
		getline(cin, str);
		stringstream(str) >> numTotal;
		cin.clear();

		this->setQtdeMaxElementos(numTotal);
		choice = checarInt(this->getQtdeMaxElementos(),"ERRO: Numero total de elementos invalido!!");
	}
}
//////////////////////////////////////////////////////////
///////////////////// TIPO DE INCREMENTO /////////////////
//////////////////////////////////////////////////////////
void Utils::setarTipoIncremento()
{
	int tipoInc=0;
	string str;
	bool choice=false;

	clear();
	cout << endl << endl
		 << "Tipo de incremento na area alocada para a pilha " << endl
		 << "(0 para incremento constante ou 1 para incremento por um fator multiplicativo)."
		 << endl << endl;

	while(!choice)
	{
		cout << endl << endl
			 << "Digite o tipo de incremento (somente 0 ou 1):  ";
		getline(cin, str);
		stringstream(str) >> tipoInc;
		cin.clear();

		this->setTipoIncremento(tipoInc);
		if(this->getTipoIncremento() < 0 || this->getTipoIncremento() > 1)
		{
			cout << endl
				 << "ERRO: Tipo de incremento diferente de 0 ou 1!!"<< endl
				 << "Favor Conferir!!!"
				 << endl << endl << endl
				 << " aperte \"enter\" para voltar..." << endl;
			getchar();

			choice = false;
		}
		else
			choice = true;
	}
}
//////////////////////////////////////////////////////////
/////////////////// FATOR MULTIPLICATIVO /////////////////
//////////////////////////////////////////////////////////
void Utils::setarFatorMult()
{
	float fatorMult;
	string str;
	bool choice=false;

	clear();
	cout << endl << endl
		 << "Valor do incremento constante ou do fator multiplicativo."
		 << endl << endl;

	while(!choice)
	{
		cout << endl << endl
			 << "Digite o valor do fator multiplicativo:  ";
		getline(cin, str);
		stringstream(str) >> fatorMult;
		cin.clear();

		//float = 4 bytes <> 1,2e-38 a 3,4e+38 <> 3.40282347e+38f
		this->setFatorMult(fatorMult);
		if(this->getFatorMult() > 2147483647.0f)
		{
			fatorMult=2147483647.0f;
			this->setFatorMult(fatorMult);
			cout << endl
				 << "ERRO: Valor inserido maior que o tamanho adequado!!" << endl
				 << "=> O valor foi reduzido para 2147483647" //2147483647.0f
				 << endl << endl << endl
				 << " aperte \"enter\" para continuar..." << endl;
			getchar();

			choice = true;
		}
		else if(this->getFatorMult() <= 0)
		{
			cout << endl
				 << "ERRO: Valor do incremento invalido!!!"<< endl
				 << "Favor Conferir!!!"
				 << endl << endl << endl
				 << " aperte \"enter\" para voltar..." << endl;
			getchar();

			choice = false;
		}
		else
			choice = true;
	}
}
//////////////////////////////////////////////////////////
/////// PERCENTUAL DO TAMANHO A SER REDUZIDO /////////////
//////////////////////////////////////////////////////////
void Utils::setarPercent()
{
	int perc=0;
	string str;
	bool choice=false;

	clear();
	cout << endl << endl
		 << "Percentual do tamanho (em numero de possiveis elementos)" << endl
		 << "para a reducao do seu tamanho, em relacao aos espacos vazios." << endl
		 << "A pilha sera reduzida esse valor do tamanho total toda vez que um POP for realizado."
		 << endl << endl;

	while(!choice)
	{
		cout << endl << endl
			 << "Digite o valor do percentual:  ";
		getline(cin, str);
		stringstream(str) >> perc;
		cin.clear();

		this->setPercent(perc);
		if(this->getPercent() <= 0 || this->getPercent() > 101)
		{
			cout << endl
				 << "ERRO: Tipo de Percentual invalido!!!"<< endl
				 << "Favor Conferir!!!"
				 << endl << endl << endl
				 << " aperte \"enter\" para voltar..." << endl;
			getchar();

			choice=false;
		}
		else
			choice=true;
	}
}
////////////////////////////////////////
/////// MOSTRAR VARIAVEIS /////////////
////////////////////////////////////////
void Utils::mostrarVariaveis()
{
	clear();

	cout << endl << setw(15) << "Variáveis" 	<< endl << endl
		 << " Tamanho da pilha: " 				<< this->getTamanhoInicial() 	<< endl //n
		 << " Limite Inferior: " 				<< this->getLimiteInferior() 	<< endl //li
		 << " Limite Superior: " 				<< this->getLimiteSuperior() 	<< endl //ls
		 << " Numero Total de elementos: " 		<< this->getQtdeMaxElementos() 	<< endl //t
		 << " Tipo de Incremento: "				<< this->getTipoIncremento() 	<< endl //i
		 << " Fator multiplicativo: "			<< this->getFatorMult() 		<< endl //f
		 << " Percentual do tamanho: "			<< this->getPercent() 			<< endl //p
		 << endl << endl
		 << " aperte \"enter\" para continuar..." << endl;
	getchar();
}
//////////////////////////////////////////////////////////
///////////////// INSERIR NUMEROS NA PILHA //////////////
/////////////////////////////////////////////////////////
void Utils::inserirNumeros()
{
	time_t tempoInicio = time(NULL); //iniciar o relogio do processador
	Pilha pilhaObj(getTamanhoInicial());
	long *pilha = (long*) malloc(getTamanhoInicial() * sizeof(pilha));
	long *pilhaTemp = NULL;
	long i,j,k,numPush,numDecisao,media,numTopo,qtdeElem,tam,tamAtualDiminuir,percDiminuir;

	i				= 0;
	numTopo			= 0;
	media			= (this->getLimiteSuperior() + this->getLimiteInferior()) / 2;

	this->setTempoInicial(tempoInicio);
	this->setTamMaxAtingido(getTamanhoInicial()); //setar o tamanho maximo atingido igual ao tamanho inicial

	srand48(time(0));

	for(k=this->getQtdeMaxElementos(); k > 0 ; k--)
	{
		numDecisao 	= numeroDecisao(); // numero para saber se vai ser push ou pop (prob cresecente)
		numPush		= numeroPush(); // numero aleatorio a ser inserido na pilha (prob constante)

		// numero gerado eh igual ao numero do top da pilha, realizar o pop
		if(!pilhaObj.vazia() && numTopo == numPush)
		{
			pilhaObj.pop(i-1,pilha);

			if(!pilhaObj.vazia())
				numTopo = pilha[i-2];

			i--;
			this->setQtdeTopo(this->getQtdeTopo()+1);

			if(DEBUG == 1)
			{
				cout << endl
					 << "ACHOU IGUAL AO TOPO: " << numPush << endl;
				showDebugOutput(&pilhaObj,pilha,numTopo);
			}
		}
		else if(numDecisao >= media) //push
		{
			if(pilhaObj.cheia())
			{
				if(this->getTipoIncremento() == 0) // incremento usando o fator constante da variavel f
				{
					if(DEBUG == 1)
					{
						cout << "AUMENTAR (" << pilhaObj.getTamanho() << "+" <<  this->getFatorMult() << ")" << endl
							 << " anterior: " << pilhaObj.getTamanho();
					}

					tam	= (pilhaObj.getTamanho() + this->getFatorMult());

					pilhaTemp = (long*) malloc(tam* sizeof(pilhaTemp));

					if(pilhaTemp == NULL)
					{
						if(DEBUG == 1)
							cout << endl << endl << " => Estourou memoria ao tentar aumentar a pilha <=" << endl << endl;

						this->setOverflow(true);
						contarElemRepetidos(&pilhaObj,pilha);
					}

					if(this->getTamMaxAtingido() < tam)
						this->setTamMaxAtingido(tam);

					for(j=0;j<pilhaObj.getQtdeElementos();j++)
						pilhaTemp[j] = pilha[j];

					free(pilha);
					pilha = NULL;

					pilha = pilhaTemp;
					pilhaTemp = NULL;
					free(pilhaTemp);

					pilhaObj.setQtdeRedMaior(pilhaObj.getQtdeRedMaior()+1);
					pilhaObj.setTamanho(tam);

					if(DEBUG == 1)
					{
						cout << " <> atual: " << pilhaObj.getTamanho() << endl;
						showDebugOutput(&pilhaObj,pilha,numTopo);
					}
				}
				else // incremento usando o fator multiplicativo da variavel f
				{
					if(DEBUG == 1)
					{
						cout << "AUMENTAR (" << pilhaObj.getTamanho() << "*" <<  this->getFatorMult() << ")" << endl
							 << " anterior: " << pilhaObj.getTamanho();
					}

					tam	= (pilhaObj.getTamanho() * this->getFatorMult());

					pilhaTemp = (long*) malloc(tam* sizeof(pilhaTemp));

					if(pilhaTemp == NULL)
					{
						if(DEBUG == 1)
							cout << endl << endl << " => Estourou memoria ao tentar aumentar a pilha <=" << endl << endl;

						this->setOverflow(true);
						contarElemRepetidos(&pilhaObj,pilha);
					}

					if(this->getTamMaxAtingido() < tam)
						this->setTamMaxAtingido(tam);

					for(j=0;j<pilhaObj.getQtdeElementos();j++)
						pilhaTemp[j] = pilha[j];

					free(pilha);
					pilha = NULL;

					pilha = pilhaTemp;
					pilhaTemp = NULL;
					free(pilhaTemp);

					pilhaObj.setQtdeRedMaior(pilhaObj.getQtdeRedMaior()+1);
					pilhaObj.setTamanho(tam);

					if(DEBUG == 1)
					{
						cout << " <> atual: " << pilhaObj.getTamanho() << endl;
						showDebugOutput(&pilhaObj,pilha,numTopo);
					}
				}
			}

			pilhaObj.push(i,numPush,pilha);
			numTopo = numPush;
			i++;

			if(this->getQtdeEleMaxAtingido() < pilhaObj.getQtdeElementos())
				this->setQtdeEleMaxAtingido(pilhaObj.getQtdeElementos());

			if(DEBUG == 1)
			{
				cout << endl << "PUSH (" << numPush << ")" << endl;
				showDebugOutput(&pilhaObj,pilha,numTopo);
			}
		}
		else if(!pilhaObj.vazia() && numDecisao < media) //pop
		{
			if(DEBUG == 1)
				cout << endl << "POP (" << pilha[i-1] << ")" << endl;

			pilhaObj.pop(i-1,pilha);

			if(!pilhaObj.vazia())
				numTopo = pilha[i-2];

			i--;

			if(DEBUG == 1)
				showDebugOutput(&pilhaObj,pilha,numTopo);

			//ajustar o tamanho para menor de acordo com o parametro p
			qtdeElem 			= pilhaObj.getQtdeElementos();
			tam 				= pilhaObj.getTamanho();
			percDiminuir		= this->getPercent() * tam / 100; //porcentagem que ira diminuir do tamanho total
			tamAtualDiminuir	= (tam - percDiminuir); //tamanho atual menos a porcentagem

			if(qtdeElem <= tamAtualDiminuir) //nunca diminuir mais que a quantidade de elementos
			{
				if(DEBUG == 1)
				{
					cout << "DIMINUIR (" << tam  << "-" <<  percDiminuir << ")" << endl
						 << " anterior: " << pilhaObj.getTamanho();
				}

				pilhaTemp = (long*) malloc(tamAtualDiminuir * sizeof(pilhaTemp));

				if(pilhaTemp == NULL)
				{
					if(DEBUG == 1)
						cout << endl << endl << " => Estourou memoria ao tentar diminuir a pilha <=" << endl << endl;

					this->setOverflow(true);
					contarElemRepetidos(&pilhaObj,pilha);
				}

				for(j=0;j<pilhaObj.getQtdeElementos();j++)
					pilhaTemp[j] = pilha[j];

				free(pilha);
				pilha = NULL;

				pilha = pilhaTemp;
				pilhaTemp = NULL;
				free(pilhaTemp);

				pilhaObj.setQtdeRedMenor(pilhaObj.getQtdeRedMenor()+1);
				pilhaObj.setTamanho(tamAtualDiminuir);

				if(DEBUG == 1)
				{
					cout << " <> atual: " << pilhaObj.getTamanho() << endl;
					showDebugOutput(&pilhaObj,pilha,numTopo);
				}
			}
		}
	}

	contarElemRepetidos(&pilhaObj,pilha);
}
//////////////////////////////////////////////////////////
/////////// GERADORES DE NUMERO ALEATORIO //////////////
/////////////////////////////////////////////////////////
int Utils::numeroDecisao() // probabilidade crescente para definir onde sera inserido de acordo com a media do ls e li
{
	return (int) (sqrt(drand48()) * (this->getLimiteSuperior()-this->getLimiteInferior()+1) + this->getLimiteInferior());
	//return (int) (sqrt(drand48()) * (ls-li+1) + li);
}
int Utils::numeroPush() // numero a ser inserido usando probabilidade constante
{
	return (int) (drand48() * (this->getLimiteSuperior()-this->getLimiteInferior()+1) + this->getLimiteInferior());
	//return (int) (drand48() * (ls-li+1) + li);
}
////////////////////////////////////////////////////
////////////// LISTAR PILHA HORIZONTAL //////////////
/////////////////////////////////////////////////////
void Utils::listarPilhaHorizontal(Pilha *pilhaObj, long *pilha)
{
	long i,qtElem = pilhaObj->getQtdeElementos();

	if(pilhaObj->vazia())
		cout << "VAZIA";
	else
	{
		for(i=0;i<qtElem;i++)
			  cout << pilha[i] << ",";
	}

	cout << endl;
}
////////////////////////////////////////////////////
////////////// LISTAR PILHA VERTICAL //////////////
/////////////////////////////////////////////////////
void Utils::listarPilhaVertical(Pilha *pilhaObj, long *pilha)
{
	long i,qtElem = pilhaObj->getQtdeElementos();

	if(pilhaObj->vazia())
		cout << "VAZIA";
	else
	{
		for(i=0;i<qtElem;i++)
			  cout << pilha[i] << endl;
	}
}
//////////////////////////////////////////////////////////
////////////// CONTAR ELEMENTOS REPETIDOS //////////////
/////////////////////////////////////////////////////////
void Utils::contarElemRepetidos(Pilha* pilhaObj, long *pilha)
{
	int j,linhas,colunas,qtde,numProcurado;
	bool existeRepetidos=false; //flag para deletar a matriz caso nao exista repetidos

	linhas			= 0;
	colunas 		= 2;
	j				= 0;
	qtde			= 0;
	numProcurado	= 0;

	Matriz mat(linhas,colunas);

	if(DEBUG == 1)
		cout << " procurando elementos repetidos..." << endl;

	for(int i=0;i<pilhaObj->getQtdeElementos();i++)
	{
		numProcurado 	= pilha[i];
		qtde 			= procurarRepetido(pilhaObj,pilha,numProcurado);

		if(qtde > 1)
		{
			existeRepetidos = true;

			//procurar se o numero ja existe na matriz
			if(!procurarNumPrimColuna(&mat,linhas,numProcurado))
			{
				if(DEBUG == 1)
					cout << " inserindo numero repetido dentro da matriz: " << numProcurado << " (" << qtde << ") vezes." << endl;

				linhas++;
				mat.setTamanho(linhas,colunas);//redimencionar a matriz aumentando uma linha
				mat.setMat(numProcurado,j,0);
				mat.setMat(qtde,j,1);
				j++;

				//mat.listarMatriz();
			}
		}
	}

	if(!existeRepetidos)
		mat.setTamanho(0,0);

	listarRelatorioFinal(pilhaObj,&mat,pilha);
}
/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// REPETIDOS /////////////////////////
/////////////////////////////////////////////////////////////////////////////
int Utils::procurarRepetido(Pilha *pilhaObj, long *pilha, int el)
{
   int j=0;

   if(pilhaObj->getQtdeElementos()!=0)
   {
      for(int i=0;i<pilhaObj->getQtdeElementos();i++)
      {
         if(el==pilha[i])
            j++;
      }
   }
   return j;
}
//////////////////////////////////////////////////////////
//// PROCURAR NUMERO NA PRIMEIRA COLUNA DA MATRIZ////////
/////////////////////////////////////////////////////////
bool Utils::procurarNumPrimColuna(Matriz* mat, int lin, int num)
{
	for(int i=0;i<lin;i++)
	{
		  if(mat->getMat(i,0) == num)
			  return true;
	}

	return false;
}
///////////////////////////////////////////////
/////////// MOSTRAR DEBUG//////////////////////
///////////////////////////////////////////////
void Utils::showDebugOutput(Pilha* pilhaObj, long* pilha, long numTopo)
{
	cout << " qtde de elementos iguais ao topo: " 	<< this->getQtdeTopo() 			<< endl
		 << " tamanho da pilha: " 					<< pilhaObj->getTamanho() 		<< endl
		 << " qtde de push: " 						<< pilhaObj->getQtdePush() 		<< endl
		 << " qtde de pop: " 						<< pilhaObj->getQtdePop() 		<< endl
		 << " qtde red maior: " 					<< pilhaObj->getQtdeRedMaior()	<< endl
		 << " qtde red menor: " 					<< pilhaObj->getQtdeRedMenor()	<< endl
		 << " qtde de elementos na pilha: "			<< pilhaObj->getQtdeElementos() << endl
		 << " qtde de elementos processados: "		<< pilhaObj->getQtdePush()+pilhaObj->getQtdePop()  << endl;

	if(!pilhaObj->vazia())
		cout << " numero atual do topo: " << numTopo << endl;

	listarPilhaHorizontal(pilhaObj,pilha); cout << endl;
}
//////////////////////////////////////////////////////////
/////////// DISPLAY RELATORIO FINAL //////////////////////
/////////////////////////////////////////////////////////
void Utils::listarRelatorioFinal(Pilha* pilhaObj, Matriz* mat, long* pilha)
{
	time_t tempoFinal 	= time(NULL);
	double tempoTotal 	= difftime(tempoFinal, this->getTempoInicial());

	clear();
	cout << endl << endl
		 << "============================================================================" << endl
		 << setw(35) << "RELATORIO FINAL" << endl << endl
		 << "Intervalo de numeros gerados: " << this->getLimiteInferior() << " a "  << this->getLimiteSuperior() 	<< endl
		 << "Quantidade total de elementos inicialmente: "							<< this->getQtdeMaxElementos()	<< endl
		 << "Quantidade total de elementos processados: "							<< pilhaObj->getQtdePush()+pilhaObj->getQtdePop()<< endl
		 << "Quantidade de PUSH realizados: " 										<< pilhaObj->getQtdePush() 		<< endl
		 << "Quantidade de POP realizados: " 										<< pilhaObj->getQtdePop() 		<< endl
		 << "Quantidade de Redimensionamentos para aumentar o tamanho: " 			<< pilhaObj->getQtdeRedMaior() 	<< endl
		 << "Quantidade de Redimensionamentos para reduzir o tamanho: " 			<< pilhaObj->getQtdeRedMenor() 	<< endl
		 << "Quantidade de elementos gerados iguais ao elemento no topo da pilha: " << this->getQtdeTopo() 			<< endl
		 << "Tamanho inicial da pilha: " 											<< this->getTamanhoInicial() 	<< endl
		 << "Tamanho final da pilha: " 												<< pilhaObj->getTamanho() 		<< endl
		 << "Tamanho maximo alcancado: " 											<< this->getTamMaxAtingido() 	<< endl
		 << "Quantidade maxima de elementos atingido dentro da pilha: " 			<< this->getQtdeEleMaxAtingido()<< endl
		 << "Quantidade final de elementos dentro da pilha: " 						<< pilhaObj->getQtdeElementos() << endl
		 << "Ocorreu Overflow: " 													<< (this->getOverflow() ? "Sim" : "Nao") << endl
		 << "Tempo total: "
		 << "(" << tempoTotal << " segs)"
		 << "(" << (int)tempoTotal / 60 << " min)"
		 << endl;

		if(!mat->verificarVazia(mat))
		 {
			 cout << "Numero       Qtde vezes encontrado" << endl;
			 mat->listarMatriz();
		 }
		 else
			 cout << "Nenhum elemento esta repetido!!!!" << endl;

		 cout << "============================================================================"
			  << endl;

		 listarPilhaHorizontal(pilhaObj,pilha); cout << endl;
		 //listarPilhaVertical(pilhaObj,pilha); cout << endl;

	exit(EXIT_SUCCESS);
}
