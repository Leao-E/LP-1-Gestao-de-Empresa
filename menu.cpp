#include "menu.h"

void showMenuCabeca(){
    cout << "\n ___     _______     ____\n|   |   |       |   |    |\n|   |   |    _  |____|   |\n|   |   |   |_| |____|   |\n|   |___|    ___|    |   |\n|       |   |        |   |\n|_______|___|        |___|\n"<<endl;
}

void showMenuPrimario(){
    cout << "**Menu**\n1 - Criar Empresa\n2 - Listar Empresas\n3 - Gerenciar Empresas\n4 - Limpar Tela\n5 - Media de Funcionarios\n6 - Sair\n::";
}

void showMenuSecundario(){
    cout << "**Menu**\n1 - Excluir Empresa\n2 - Adicionar Funcionario\n3 - Remover Funcionario\n4 - Listar Todos os Funcionario\n5 - Listar Funcionarios Recentes\n6 - Aumentar Salario\n7 - Limpar Tela\n8 - Volar\n::";
}