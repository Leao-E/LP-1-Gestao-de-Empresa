#include <iostream>
#include <vector>
#include <stdlib.h>
#include "funcionario.h"
#include "empresa.h"
#include "menu.h"

using namespace std;

int main(){
    empresa Teste("Teste", "123");
    cout << Teste.getNome() << Teste.getCnpj() << endl;
    cout << Teste.adicionarFuncionario(funcionario("jose", "123",1,2,3)) << endl;
    cout << Teste.adicionarFuncionario(funcionario("joao", "456",5,273,43)) << endl;
    cout << Teste.adicionarFuncionario(funcionario("joao", "135",5,273,43)) << endl;
    cout << Teste.adicionarFuncionario(funcionario("maria", "123",5,273,43)) << endl;
    Teste.listarTodosFuncionarios();
    cout << Teste.removerFuncionario("4556") << endl;
    cout << Teste.removerFuncionario("456") << endl;
    Teste.listarTodosFuncionarios();


    /*int aux = 0;

    vector <empresa> listaEmpresas;

    system("clear");

    showMenuCabeca();
    while (aux != 4)
    {   
        cin >> aux;
        showMenuSecundario(aux);
        if(aux == 4){
            break;
        }else{
            showMenuPrimario();
        }
    }*/
    
    return 0;
}