/**
 * @file corpo.cpp
 * @brief Arquivo contendo a função main do programa
*/
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
    double auxSalario;
    string stringAux1, stringAux2, stringAux3;
    empresa auxEmpresa("NONE", "NONE");
    funcionario auxFuncionario("NONE", "NONE",0, 0,0,0);
    
    vector <empresa> listaEmpresas;

    system("clear");
    showMenuCabeca();
    showMenuPrimario();

    while (aux1 != 6)
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
                auxEmpresa.setNome(stringAux1);
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
            case 3: //Entrando no menu secundario
                cout << "Entre CNPJ: ";
                cin.ignore();
                getline(cin, stringAux1);
                //checa se a empresa existe no vector listaEmpresas
                for (auto it = listaEmpresas.begin(); it != listaEmpresas.end(); ++it){
                    aux2 = 0;
                    if (it -> getCnpj() == stringAux1){
                        aux2 = 1;
                        aux3 = 0;
                        while(aux3 != 8){
                            showMenuSecundario();
                            cin >> aux3;
                            switch (aux3){                            
                                case 1: //excluindo empresa                    
                                    if(removerEmpresa(listaEmpresas, stringAux1)){
                                        cout << "ERRO: CPNJ inexistente" << endl;
                                    }else{
                                        cout << "Empresa removida com sucesso" << endl;
                                        aux3 = 8;
                                    }
                                    break;
                                case 2: //adicionanado funcionario                                                
                                    cout << "Entre nome: ";
                                    cin.ignore();
                                    getline(cin, stringAux2);
                                    auxFuncionario.setNome(stringAux2);
                                    cout << "Entre CPF: ";
                                    getline(cin, stringAux3);
                                    auxFuncionario.setCpf(stringAux3);
                                    cout << "Entre salario: ";
                                    cin >> auxSalario;
                                    auxFuncionario.setSalario(auxSalario);
                                    time(&data);
                                    dataTM = localtime(&data);
                                    auxFuncionario.setAdmisao(dataTM -> tm_mday, dataTM -> tm_mon+1, dataTM -> tm_year+1900);
                                    if(it -> adicionarFuncionario(auxFuncionario)){
                                        cout << "ERRO: CPF ja cadastrado" << endl;
                                    }else{
                                        cout << "Funcionario cadastrado com sucesso" << endl;
                                    }                            
                                    break;                                           
                                case 3: //Excluindo funcionario                                                        
                                    cout << "Entre CPF: ";
                                    cin.ignore();
                                    getline(cin, stringAux2);
                                    if(it -> removerFuncionario(stringAux2)){
                                        cout << "ERRO: CPF inexistente" << endl;
                                    }else{
                                        cout << "Funcionario removido com sucesso" << endl;
                                    }                            
                                    break;
                                case 4://listando todos os funcionarios                                                    
                                    if(it -> listarTodosFuncionarios()){
                                        cout << "ERRO: Empresa nao possui funcionarios" << endl;
                                    }
                                    break;                        
                                case 5: //Listar Recentes
                                    if((aux4 = it -> listarFuncionariosRecentes()) == -1){
                                        cout << "ERRO: Empresa nao possui funcionarios" << endl;
                                    }else{
                                        if(aux4 == 0){
                                            cout << "Nenhum funcionario recente" << endl; 
                                        }                                     
                                    }
                                    break;
                                case 6: //Aumentando salario                                               
                                    if (it -> getTotalFuncionarios() > 0){
                                        cout << "Entre aumento (0 a 100): ";
                                        cin >> auxSalario;                        
                                        it -> aumentarSalario(auxSalario);
                                        cout << "Salario aumentado com sucesso" << endl;  
                                    }else{
                                        cout << "ERRO: Empresa nao possui funcionarios"<<endl;
                                    }                                      
                                    break;
                                case 7: //limpando a tela
                                    system("clear");
                                    showMenuCabeca();
                                    break;
                                case 8: //Voltando ao Menu anterior
                                    break;                                
                                default:
                                    cout << "ERRO: Opcao invalida" << endl;
                                    break;
                            }
                        }
                        break;
                    }
                }
                if (aux2 == 0){
                    cout << "ERRO: CNPJ inexistente" << endl;
                }        
                break;
            case 4: //limpando tela
                system("clear");
                showMenuCabeca();
                break;
            case 5://media de funcionarios por empresa 
                if(mediaFuncionarios(listaEmpresas) == -1){
                    cout << "ERRO: Nenhuma empresa cadastrada" << endl;
                }else{
                    cout << "Media de Funcionarios: " << mediaFuncionarios(listaEmpresas) << endl;
                }   
                break;
            case 6:
                cout << "Obrigado por usar o programa" << endl;
                break;
            default:
                cout << "ERRO: Opcao invalida" << endl;
                break;
        }
        if(aux1 == 6){
            break;
        }else{
            showMenuPrimario();
        }
    }
    
    return 0;
}