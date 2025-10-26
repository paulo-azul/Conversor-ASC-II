#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

string conversor_binario(int numero){

    string numero_binario, saida;
    stack<char>reverse_binaria;
    int conversão;

    if(numero == 0){
        return "0";
    }

    while (numero >= 1){
        conversão = numero%2;
        numero_binario += (conversão + '0');
        numero = numero/2;
    }

    for(char num : numero_binario){
        reverse_binaria.emplace(num);
    }

    while (!reverse_binaria.empty()){
        saida += reverse_binaria.top();
        reverse_binaria.pop();
    }

    while(saida.length() < 7){
        saida = '0' + saida;
    }
    
    return saida;
}

int conversor_decimal(string binario_str){

    int decimal=0, potencia =0;

    for(int i = binario_str.length() - 1; i>=0; i--){
        if(binario_str[i] == '1'){
            decimal += pow(2, potencia);
        }
        potencia++;
    }

    return decimal;
}

int contador_um(string numero_binario){

    int contador = 0;

    for(char num : numero_binario){
        if(num == '1'){
            contador++;
        }
    }

    return contador;
}

int main(){
    int numero_matricula;
    string nome, holder, saida, saida2;
    map<char, int>tabela_asc;
    vector<int>conversao_asc;
    vector<pair<string, int>>nome_asc;
    long valor_numerico;

    cout << "Olá, seja bem vindo ao conversor de ASC II" << endl << endl;
    cout << "Digite seu número de matrícula: " << endl;
    cin >> numero_matricula;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Para inicar, digite seu nome: " << endl;
    getline(cin, nome);

    for(char letra : nome){
        conversao_asc.push_back((int)letra); 
    }

    for(int i=0; i < conversao_asc.size(); i++){
        holder = conversor_binario(conversao_asc[i]);
        nome_asc.push_back(make_pair(holder, contador_um(holder)));
    }

     if(numero_matricula%2 == 0){
        cout << "Aplicando regra de paridade par" << endl;
        for(int i=0; i<nome_asc.size(); i++){
            holder = nome_asc[i].first;
            if(nome_asc[i].second%2==0){
                nome_asc[i].first = '0' + holder;
            }else{
                nome_asc[i].first = '1' + holder;
            }
        }
    }else{ 
        cout << "Aplicando regra de paridade ímpar" << endl;
        for(int i=0; i<nome_asc.size(); i++){
            holder = nome_asc[i].first;
            if(nome_asc[i].second%2==0){
                nome_asc[i].first = '1' + holder;
            }else{
                nome_asc[i].first = '0' + holder;
            }
        }
    }

    for(int i=0; i<nome_asc.size(); i++){
        if(i != nome_asc.size() - 1){
            saida += nome_asc[i].first + " ";
        }else{
            saida += nome_asc[i].first;
        }
    }

    for(int i=0; i<nome_asc.size(); i++){
        valor_numerico = conversor_decimal(nome_asc[i].first);
        saida2 += (char)valor_numerico;
    }

    cout << "Após o processamento seu nome ficou escrito como: " << endl << saida << endl;
    cout << "Ou, convertendo esse binário de volta usando a tabela ASC II: " << endl << saida2 << endl;

    return 0;
}