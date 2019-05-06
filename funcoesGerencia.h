#ifndef _FUNCOESGERENCIA_H_
#define _FUNCOESGERENCIA_H_
#include <iostream>
#include <vector>
#include "empresa.h"

using namespace std;

//funcoes
bool adicionarEmpresa (vector<empresa> &vector, empresa A); //1 -> Erro 0-> OK
bool removerEmpresa (vector<empresa> &vector, string cnpj);
bool listarEmpresas (vector<empresa> &vector);
double mediaFuncionarios(vector<empresa> &vector);

#endif