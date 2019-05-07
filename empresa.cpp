/**
 * @file empresa.cpp
 * @brief Aquivo contendo a implementação dos metodos do arquivo "empresa.h"
*/
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
int empresa::getTotalFuncionarios(){
    return this -> listaFuncionarios.size();
}
bool empresa::adicionarFuncionario(funcionario A){
    for (auto it = this -> listaFuncionarios.begin(); it != this-> listaFuncionarios.end(); ++it){
        if(*it == A){
            return true;
        }
    }
    this -> listaFuncionarios.push_back(A);
    return false;
}
bool empresa::removerFuncionario(string cpf){
    for (auto it = this -> listaFuncionarios.begin(); it != this-> listaFuncionarios.end(); ++it){
        if(it -> getCpf() == cpf){
            this -> listaFuncionarios.erase(it);
            return false;
        }
    }
    return true;
}
bool empresa::listarTodosFuncionarios(){
    if(this -> listaFuncionarios.empty()){
        return true;
    }else{
        for (auto it = this -> listaFuncionarios.begin(); it != this-> listaFuncionarios.end(); ++it){
          cout << *it;
        }
        return false;
    }
}
int empresa::listarFuncionariosRecentes(){
    int i = 0;
    time_t dataAtual;
    ADMISAO aux;
    struct tm *dataAdmisao;
    if (listaFuncionarios.empty()){
        return -1;
    }
    for (auto it = listaFuncionarios.begin(); it != listaFuncionarios.end(); ++it){
        aux = it -> getAdmisao();
        time(&dataAtual);
        dataAdmisao = localtime(&dataAtual);
        dataAdmisao -> tm_mday = aux.dia;
        dataAdmisao -> tm_mon = aux.mes - 1;
        dataAdmisao -> tm_year = aux.ano - 1900;
        if(difftime(time(&dataAtual), mktime(dataAdmisao)) <= 7.776e+6){
            cout << *it;
            ++i;
        }
    }
    return i;
}
void empresa::aumentarSalario(double porcentagem){
    double auxSalario;
    for (auto it = listaFuncionarios.begin(); it != listaFuncionarios.end(); ++it){
        auxSalario = it -> getSalario();
        it -> setSalario(auxSalario += auxSalario*(porcentagem/100));
    }
}
//implementando operadores
bool empresa::operator==(empresa A){
    if (this -> cnpj == A.cnpj){
        return true;
    }else{
        return false;
    }
}
