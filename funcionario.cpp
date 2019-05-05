#include "funcionario.h"

//implementação dos metodos
void funcionario::setNome(string novoNome){
    this -> nome = novoNome;
}
void funcionario::setCpf(string novoCpf){
    this -> cpf = novoCpf;
}
void funcionario::setAdmisao(int dd, int mm, int aa){
    this -> dataAdmisao.dia = dd;
    this -> dataAdmisao.mes = mm;
    this -> dataAdmisao.ano = aa;
}
string funcionario::getNome(){
    return this -> nome;
}
string funcionario::getCpf(){
    return this -> cpf;
}
ADMISAO funcionario::getAdmisao(){
    return this -> dataAdmisao;
}

//implementação dos operadores
bool funcionario::operator==(funcionario A){
    if (this -> cpf == A.cpf){
        return true;
    }else{
        return false;
    }
}
bool funcionario::operator!=(funcionario A){
    if (this -> cpf != A.cpf){
        return true;
    }else{
        return false;
    }
}
ostream & operator << (ostream &out, const funcionario &F){ 
    out << "Dados Funcionario:\n * Nome: " << F.nome <<"\n * CPF: "<< F.cpf <<"\n * Data de Entrada: "<< F.dataAdmisao.dia<<"/"<<F.dataAdmisao.mes<<"/"<<F.dataAdmisao.ano<<endl;
    return out; 
} 
