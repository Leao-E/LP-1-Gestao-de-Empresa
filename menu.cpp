#include "menu.h"

void showMenuCabeca(){
    cout << "\n ___     _______     ____\n|   |   |       |   |    |\n|   |   |    _  |____|   |\n|   |   |   |_| |____|   |\n|   |___|    ___|    |   |\n|       |   |        |   |\n|_______|___|        |___|"<<endl;
    cout << "\n**Menu**\n1 - Criar Empresa\n2 - Listar Empresas\n3 - Gerenciar Empresas\n4 - Sair\n::";
}

void showMenuPrimario(){
    cout << "\n**Menu**\n1 - Criar Empresa\n2 - Listar Empresas\n3 - Gerenciar Empresas\n4 - Sair\n::";
}

void showMenuSecundario(int i){
    int i2;
    switch (i)
    {
    case 1:
        //cria empresa;
        break;
    case 2:
        //lista empresas;
        break;
    case 3:
        cout << "\n   1 - Excluir Empresa\n   2 - Adicionar Funcionario\n   3 - Remover Funcionario\n   4 - Listar Todos os Funcionario\n   5 - Listar Funcionarios Recentes\n::";
        cin >> i2;
        break;
    case 4:
        cout << "\nObrigado Por Usar o Programa" << endl;
        break;
    default:
        cout << "\nERRO: Opcao Invalida" << endl;
        break;
    }
}