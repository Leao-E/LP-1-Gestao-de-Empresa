/**
 * @file empresa.h
 * @brief Arquivo contendo a declaranção da classe empresa e de todos os seus metodos
*/
#ifndef _EMPRESA_H_
#define _EMPRESA_H_

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "funcionario.h"

using namespace std;

class empresa : public funcionario
{
private:
    string cnpj; 
    string nome; 
    vector <funcionario> listaFuncionarios; 
public:
    void setCnpj(string novoCnpj);
    void setNome(string novoNome);
    string getCnpj();
    string getNome();
    int getTotalFuncionarios();
    /**
     * @brief Função que permite adicionar à empresa um novo funcionario
     * @details A função percorre o vetor utilizado para armazenar os funcionarios e checa se o funcionario que está tentando ser adicionado já está presente; Se sim será retornado true, se não o funcionario será adicionado e valor false será retornado
     * @param funcionario Classe contendo os dados do funcionario que se deseja adicionar
     * @return true Caso o funcionario que está tentando ser adicionado já está presente no vetor
     * @return false Caso o funcionario tenha sido adicionado com sucesso
    */
    bool adicionarFuncionario(funcionario A);
    /**
     * @brief Função que permite remover um funcionario da empresa dada
     * @details A função percorre o vetor de funcionarios procurando o valor de cpf dado; Caso o valor seja encontrado o funcionario ao qual o cpf pertence será removido e a função retorna false, caso contrario a função retorna true
     * @param string Valor de cpf do funcionario que se deseja remover
     * @return true Caso nenhum funcionario no vetor possua um cpf correspondente
     * @return false Caso o funcionario dono do cpf dado seja encontrado e removido
    */
    bool removerFuncionario(string cpf);
    /**
     * @brief Função que permite listar todos os funcionarios presentes em uma empresa
     * @details A função percorre o vetor de funcionarios e exibe os dados de cada funcionario atraves do operados "<<"
     * @return true Caso o vetor de funcionarios esteja vazio
     * @return false Caso a função seja executada normalmente
    */
    bool listarTodosFuncionarios();
    /**
     * @brief Função que permite aumentar o salario de todos os funcionarios de uma empresa em X%
     * @details Esta função percorre o vetor de funcionarios e para cada funcionario de salario X ela seta o novo valor de salario como sendo X+((X*Y)/100), onde Y é a porcentagem de aumento dada
     * @param double Valor de porcentagem, calculada em cima do salario atual, que se deseja adicionar
    */
    void aumentarSalario(double porcentagem);
    /**
     * @brief Função que permite listar todos os funcionarios, com menos de 90 dias de experiência, presentes no vetor de funcionarios
     * @details A função percorre o vetor e compara a data de admissão de cada funcionario com a data atual do computador, caso a diferença seja inferior a 90 dias (7.776e+6 segundos) o funcionario será exibido
     * @return Caso o vetor contendo os funcionarios estiver vazio será retornado -1, caso contrario a quantidade de funcionarios recentes será retornada
    */
    int listarFuncionariosRecentes();
    
    bool operator==(empresa A);
    
    empresa(string nomeInicial, string cnpjInicial){
        this -> nome = nomeInicial;
        this -> cnpj = cnpjInicial;
    }
};

#endif