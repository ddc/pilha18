/*
	Author: Daniel Dourado da Costa
	e-mail: danieldouradocosta@gmail.com
	UFG - Universidade Federal de Goias
	May 2015
	Copyright 2015 Daniel Dourado da Costa. All rights reserved.
*/

#include <iostream>
#include "matriz.h"
using namespace std;
///////////////////////////////////////////////////////////////////
///////////////////////////////////// setMat //////////////////////
///////////////////////////////////////////////////////////////////
void Matriz::setMat(int el, int i, int j)
{
   mat[i*c+j] = el;
}
////////////////////////////////////////////////////////////////////
///////////////////////////////////// getMat ///////////////////////
///////////////////////////////////////////////////////////////////
int Matriz::getMat(int i, int j)
{
   return  mat[i*c+j];
}
///////////////////////////////////////////////////////////////////
//////////////////////////////////// VERIFICAR VAZIO //////////////
///////////////////////////////////////////////////////////////////
bool Matriz::verificarVazia(Matriz *a)
{
	if((a->getLinha() == 0) && (a->getColuna() == 0))
		return true;

   return false;
}
//////////////////////////////////////////////////////////
////////////////////////// PROCURAR NUMERO //////////////
/////////////////////////////////////////////////////////
bool procurarNumero(Matriz* a, int num)
{
   int i,j;

   for(i=0;i<a->getLinha();i++)
   {
	  for(j=0;j<a->getColuna();j++)
	  {
		  if(a->getMat(i,j) == num)
			  return true;
	  }
   }

   return false;
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////// LISTAR MATRIZ ///////////
///////////////////////////////////////////////////////////////////
void Matriz::listarMatriz()
{
   int i,j;

   for(i=0;i<this->getLinha();i++)
   {
      for(j=0;j<this->getColuna();j++)
      {
		 cout  << this->getMat(i,j)
			   << "               ";
      }
      cout  << endl;
   }
}
///////////////////////////////////////////////////////////////////
///////////////////////////////// CONSTRUTOR //////////////////////
///////////////////////////////////////////////////////////////////
Matriz::Matriz(int li, int co)
{
   mat = new float[li*co];
   l=li;
   c=co;
   tamanho=l*c;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////// DESTRUTOR ///////////////////////////
///////////////////////////////////////////////////////////////////////

Matriz::~Matriz()
{
	delete [] mat;
}
