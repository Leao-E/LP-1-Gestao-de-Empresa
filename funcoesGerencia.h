/**
 * @file funcoesGerencia.h
 * @brief Arquivo contendo a declaração de todas as funções necessária para manipular o vetor que armazena as empresas
*/
#ifndef _FUNCOESGERENCIA_H_
#define _FUNCOESGERENCIA_H_
#include <iostream>
#include <vector>
#include "empresa.h"

using namespace std;

/**
 * @brief Função que permite adicionar uma nova empresa a um vetor
 * @detail Esta função percorre o vetor passado e checa se a empresa A já está presente no vetor. Se sim a empresa não será adicionada e o valor true será retornado, caso contrario a empresa será adicionada ao vetor e o valor retornado será false
 * @param vector<empresa>  Vetor de classes empresa, utilizado para armazenar todas as empresas
 * @param empresa Classe contendo empresa que se deseja adicionar
 * @return true Caso a empresa a ser adicionada já estiver contida no vetor em questão
 * @return false Caso a empresa seja adicionada com sucesso
*/
bool adicionarEmpresa (vector<empresa> &vector, empresa A);
/**
 * @brief Função que permite remover uma empresa já existente no vetor, dado apenas seu cnpj
 * @detail Esta função percorre o vetor passado e checa se a empresa A já está presente no vetor. Se sim a empresa é removida e o valor false será retornado, caso contrario significa dizer que nenhuma empresa no vetor possui o cnpj dado; logo o valor true é retornado
 * @param vector<empresa>  Vetor de classes empresa, utilizado para armazenar todas as empresas
 * @param string String com o valor de cnpj da empresa que o usuario deseja remover
 * @return true Caso nenhuma empresa no vector dado possua o cnpj dado
 * @return false Caso uma empresa com o valor de cnpj dado tenha sido encontrada e removida
*/
bool removerEmpresa (vector<empresa> &vector, string cnpj);
/**
 * @brief Função que permite listar todas as empresas presente no vetor dado
 * @details Esta função percorre o vetor e exibe na tela o nome e cnpj de todas as empresas presentes no dado vetor
 * @param vector<empresa> Vetor contendo as empresas que serão exibidas
 * @return true Caso o vetor contendo as empresas esteja vazio
 * @return false Caso a função seja executada com sucesso
*/
bool listarEmpresas (vector<empresa> &vector);
/**
 * @brief Função que informa a media de funcionarios por empresa
 * @details Esta função armazena o numero de empresa numa variável int totalEmpresa e percorre o vetor que armazena as empresas. A quantidade de funcionarios de todas as empresas é armazenda numa variavel int totalFuncionarios. Por fim a função retorna a relação do total de funcionarios pelo total de empresas
 * @param vector<empresa> Vetor contendo as empresas que serão analisadas
 * @return O valor retorna será a relação entre funcionarios e empresas sendo do tipo double
*/
double mediaFuncionarios(vector<empresa> &vector);

#endif