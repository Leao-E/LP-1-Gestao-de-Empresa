#ifndef _EMPRESA_H_
#define _EMPRESA_H_

#include <iostream>
#include <vector>
#include <string>
#include "funcionario.h"

using namespace std;

class empresa : public funcionario
{
private:
    //objetos da classe
    string cnpj;
    string nome;
    vector <funcionario> listaFuncionarios;
public:
    //metodos da classe
    void setCnpj(string novoCnpj);
    void setNome(string novoNome);
    string getCnpj();
    string getNome();
    bool adicionarFuncionario(funcionario A); //1 -> Erro; 0 -> Sucesso
    bool removerFuncionario(string cpf); //1 -> Erro; 0 -> Sucesso
    bool listarTodosFuncionarios();
    //falta só listar funcionarios recentes
    
    //sobrecarga de operadores
    bool operator==(empresa A);
    
    //constructor da classe
    empresa(string nomeInicial, string cnpjInicial){
        this -> nome = nomeInicial;
        this -> cnpj = cnpjInicial;
    }
};

#endif