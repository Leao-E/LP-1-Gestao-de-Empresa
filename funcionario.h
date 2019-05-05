#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

typedef struct ADMISAO
{
    int dia;
    int mes;
    int ano;
}ADMISAO;


//classe funcionario
class funcionario
{
private:

    //objetos da classe
    string nome;
    string cpf;
    ADMISAO dataAdmisao;
public:

    //metodos da classe
    void setNome(string novoNome);
    void setCpf(string novoCpf);
    void setAdmisao(int dd, int mm, int aa);
    string getNome();
    string getCpf();
    ADMISAO getAdmisao();
    
    //sobrecarga de operadores
    bool operator==(funcionario A);
    bool operator!=(funcionario A);
    friend ostream & operator << (ostream &out, const funcionario &F);
  
    //constructor da classe
    funcionario(){
        //constructor default
    }
    funcionario(string nomeInicial, string cpfInicial, int diaInicial, int mesInicial, int anoInicial){
        this -> nome = nomeInicial;
        this -> cpf = cpfInicial;
        this -> dataAdmisao.dia = diaInicial;
        this -> dataAdmisao.mes = mesInicial;
        this -> dataAdmisao.ano = anoInicial;
    }
};

#endif