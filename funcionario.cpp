#include "funcionario.h"

//implementação dos metodos
void funcionario::setNome(string novoNome){
    this -> nome = novoNome;
}
void funcionario::setCpf(string novoCpf){
    this -> cpf = novoCpf;
}
void funcionario::setAdmisao(int dd, int mm, int aa){
    this -> data.dia = dd;
    this -> data.mes = mm;
    this -> data.ano = aa;
}
string funcionario::getNome(){
    return this -> nome;
}
string funcionario::getCpf(){
    return this -> cpf;
}
ADMISAO funcionario::getAdmisao(){
    return this -> data;
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
    out << "Dados Funcionario:\n * Nome: " << F.nome <<"\n * CPF: "<< F.cpf <<"\n * Data de Entrada: "<< F.data.dia<<"/"<<F.data.mes<<"/"<<F.data.ano<<endl;
    return out; 
} 
