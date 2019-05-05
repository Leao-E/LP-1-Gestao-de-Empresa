#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "funcoesGerencia.h"
#include "funcionario.h"
#include "empresa.h"
#include "menu.h"

using namespace std;

int main(){
    time_t data;
    struct tm *dataTM;
    int aux1, aux2, aux3, aux4;
    string stringAux1, stringAux2, stringAux3;
    empresa auxEmpresa("NONE", "NONE");
    funcionario auxFuncionario("NONE", "NONE", 0,0,0);
    
    vector <empresa> listaEmpresas;

    system("clear");
    showMenuCabeca();
    showMenuPrimario();

    while (aux1 != 5)
    {   
        cin >> aux1;
        switch (aux1)
        {
            case 1: //criando empresa
                cout << "Entre Nome: ";
                cin.ignore();
                getline(cin, stringAux1);
                cout << "Entre CNPJ: ";
                getline(cin, stringAux2);
                auxEmpresa.empresa::setNome(stringAux1);
                auxEmpresa.setCnpj(stringAux2);
                if (adicionarEmpresa(listaEmpresas, auxEmpresa)){
                    cout << "ERRO: CNPJ já existe" << endl;
                }else{
                    cout << "Empresa criada com sucesso" << endl;
                }
                break;
            case 2: //listando empresas
                if (listarEmpresas(listaEmpresas)){
                    cout << "ERRO: Nenhuma empresa criada" << endl;
                }
                break;
            case 3:
                cout << "1 - Excluir Empresa\n2 - Adicionar Funcionario\n3 - Remover Funcionario\n4 - Listar Todos os Funcionario\n5 - Listar Funcionarios Recentes\n6 - Voltar\n::";
                cin >> aux2;
                switch (aux2)
                {
                case 1: //escluindo empresa
                    cout << "Entre CNPJ: ";
                    cin.ignore();
                    getline(cin, stringAux1);
                    if(removerEmpresa(listaEmpresas, stringAux1)){
                        cout << "ERRO: CPNJ inexistente" << endl;
                    }else{
                        cout << "Empresa removida com sucesso" << endl;
                    }
                    break;
                case 2: //adicionanado funcionario
                    cout << "Entre CNPJ: ";
                    cin.ignore();
                    getline(cin, stringAux1);
                    for (auto it = listaEmpresas.begin(); it != listaEmpresas.end(); ++it){
                        aux3 = 0;
                        if (it -> getCnpj() == stringAux1){                
                            aux3 = 1;
                            cout << "Entre nome: ";
                            getline(cin, stringAux2);
                            auxFuncionario.setNome(stringAux2);
                            cout << "Entre CPF: ";
                            getline(cin, stringAux3);
                            auxFuncionario.setCpf(stringAux3);    
                            time(&data);
                            dataTM = localtime(&data);
                            auxFuncionario.setAdmisao(dataTM -> tm_mday, dataTM -> tm_mon+1, dataTM -> tm_year+1900);
                            if(it -> adicionarFuncionario(auxFuncionario)){
                                cout << "ERRO: CPF ja cadastrado" << endl;
                            }else{
                                cout << "Funcionario cadastrado com sucesso" << endl;
                            }                            
                            break;
                        }
                    }
                    if(aux3 == 0){
                        cout << "ERRO: CNPJ inexistente" << endl;
                    }
                    break;
                case 3: //Excluindo funcionario
                    cout << "Entre CNPJ: ";
                    cin.ignore();
                    getline(cin, stringAux1);
                    for (auto it = listaEmpresas.begin(); it != listaEmpresas.end(); ++it){
                        aux3 = 0;
                        if (it -> getCnpj() == stringAux1){
                            aux3 = 1;                
                            cout << "Entre CPF: ";
                            getline(cin, stringAux2);
                            if(it -> removerFuncionario(stringAux2)){
                                cout << "ERRO: CPF inexistente" << endl;
                            }else{
                                cout << "Funcionario removido com sucesso" << endl;
                            }
                            break;
                        }
                    }
                    if(aux3 == 0){
                        cout << "ERRO: CNPJ inexistente" << endl;
                    }
                    break;
                case 4://listando todos os funcionarios
                    cout << "Entre CNPJ: ";
                    cin.ignore();
                    getline(cin, stringAux1);
                    for (auto it = listaEmpresas.begin(); it != listaEmpresas.end(); ++it){
                        aux3 = 0;
                        if(it -> getCnpj() == stringAux1){
                            aux3 = 1;
                            if(it -> listarTodosFuncionarios()){
                                cout << "ERRO: Empresa nao possui funcionarios" << endl;
                            }
                            break;
                        }                               
                    }
                    if (aux3 == 0){
                        cout << "ERRO: CPNJ inexistente" << endl;
                    }
                    break;
                case 5:
                    //Listar Recentes                
                    break;
                case 6:
                    break;
                default:
                    cout << "ERRO: Opcao invalida" << endl;
                    break;
                }
                break;
            case 4:
                system("clear");
                showMenuCabeca();
                break;
            case 5:
                cout << "Obrigado por usar o programa" << endl;
                break;
            default:
                cout << "ERRO: Opcao invalida" << endl;
                break;
        }
        if(aux1 == 5){
            break;
        }else{
            showMenuPrimario();
        }
    }
    
    return 0;
}