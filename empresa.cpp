#include "empresa.h"

//implementando metodos 
void empresa::setCnpj(string novoCnpj){
    this -> cnpj = novoCnpj;
}

void empresa::setNome(string novoNome){
    this -> nome = novoNome;
}

string empresa::getCnpj(){
    return this -> cnpj;
}

string empresa::getNome(){
    return this -> nome;
}
int empresa::adicionarFuncionario(funcionario A){
    for (auto it = this -> listaFuncionarios.begin(); it != this-> listaFuncionarios.end(); ++it){
        if(*it == A){
            return 1;
        }
    }
    this -> listaFuncionarios.push_back(A);
    return 0;
}
int empresa::removerFuncionario(string cpf){
    for (auto it = this -> listaFuncionarios.begin(); it != this-> listaFuncionarios.end(); ++it){
        if(it -> getCpf() == cpf){
            this -> listaFuncionarios.erase(it);
            return 0;
        }
    }
    return 1;
}
void empresa::listarTodosFuncionarios(){
    for (auto it = this -> listaFuncionarios.begin(); it != this-> listaFuncionarios.end(); ++it){
        cout << *it;
    }
}