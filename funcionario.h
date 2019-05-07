/**
 * @file funcionario.h
 * @brief Arquivo contendo a declaração da classe funcionario e todos os seus metodos
*/
#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

/**
 * @brief Struct utilizada para armazenar a data de admissão do funcionario
*/
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
    double salario;
    ADMISAO dataAdmisao;
public:

    //metodos da classe
    void setNome(string novoNome);
    void setCpf(string novoCpf);
    void setAdmisao(int dd, int mm, int aa);
    void setSalario(double novoSalario);
    string getNome();
    string getCpf();
    ADMISAO getAdmisao();
    double getSalario();

    //sobrecarga de operadores
    bool operator==(funcionario A);
    bool operator!=(funcionario A);
    friend ostream & operator << (ostream &out, const funcionario &F);
  
    //constructor da classe
    funcionario(){
        //constructor default
    }
    funcionario(string nomeInicial, string cpfInicial, double salarioInicial, int diaInicial, int mesInicial, int anoInicial){
        this -> nome = nomeInicial;
        this -> cpf = cpfInicial;
        this -> salario = salarioInicial;
        this -> dataAdmisao.dia = diaInicial;
        this -> dataAdmisao.mes = mesInicial;
        this -> dataAdmisao.ano = anoInicial;
    }
};

#endif