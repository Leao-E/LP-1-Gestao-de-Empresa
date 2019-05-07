/**
 * @file funcoesGerencia.cpp
 * @brief Aquivo contendo a implementação das funções do arquivo "funcoesGerencia.h"
*/
#include "funcoesGerencia.h"

bool adicionarEmpresa (vector<empresa> &vector, empresa A){
    for(auto it = vector.begin(); it != vector.end(); ++it){
        if(*it == A){
            return true;
        }
    }
    vector.push_back(A);
    return false;
}
bool listarEmpresas (vector<empresa> &vector){
    if (vector.empty()){
        return true;
    }
    for (auto it = vector.begin(); it != vector.end(); ++it){
        cout << "Dados Empresa "<< distance(vector.begin(), it) + 1 << ":\n   nome: " << it -> empresa::getNome() << "\n   CNPJ: " << it -> getCnpj() << endl;
    }
    return false;
}
bool removerEmpresa (vector<empresa> &vector, string cnpj){
    for(auto it = vector.begin(); it != vector.end(); ++it){
        if (it -> getCnpj() == cnpj){
            vector.erase(it);
            return false;
        }
    }
    return true;
}
double mediaFuncionarios(vector<empresa> &vector){
    double result, totalEmpresas, totalFuncionarios = 0;
    totalEmpresas = vector.size();
    for(auto it = vector.begin(); it != vector.end(); ++it){
        totalFuncionarios += it -> getTotalFuncionarios();
    }
    if(totalEmpresas == 0){
        return -1;
    }else{
        result = totalFuncionarios/totalEmpresas;
        return result;
    }
}
