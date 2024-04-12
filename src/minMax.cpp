#include "minMax.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;


int definirTamanhoVetor(int indice){
    int tamVetor;
    
    if (indice==0){
        tamVetor = 1000;
    }

    if (indice==1){
        tamVetor = 10000;
    }

    if (indice==2){
        tamVetor = 100000;
    }

    if (indice==3){
        tamVetor = 500000;
    }

    return tamVetor;
}


void gerarVetorAleatorio(int vetor[], int numEntradas){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 1000);

    for (int i = 0; i < numEntradas; ++i) {
        vetor[i] = dist(mt);
    }
}


bool compararDecrescente(int a, int b){
    return a > b;
}


void minMax1(int vetor[], int tam, int *max, int *min){
    *max = vetor[0];
    *min = vetor[0];

    for(int i=1; i<tam; i++){
        if(vetor[i] > *max){
            *max = vetor[i];
        }

        if(vetor[i] < *min){
            *min = vetor[i];
        }
    }

}


void minMax2(int vetor[], int tam, int *max, int *min){
    *max = vetor[0];
    *min = vetor[0];

    for(int i=1; i<tam; i++){
        if(vetor[i] > *max){
            *max = vetor[i];
        }
        else if(vetor[i] < *min){
            *min = vetor[i];
        }
    }

}


void minMax3(int vetor[], int tam, int *max, int *min){
    int i, FimDoAnel;
    
    if ((tam & 1) > 0){ 
        vetor[tam] = vetor[tam - 1]; 
        FimDoAnel = tam;
    }
    
    else {
        FimDoAnel = tam - 1;
    }


    if (vetor[0] > vetor[1]){
        *max = vetor[0]; 
        *min = vetor[1]; 
    }

    else { 
        *max = vetor[1]; 
        *min = vetor[0];
    }

    i = 3;

    while (i <= FimDoAnel){
        if (vetor[tam - 1] > vetor[i]){ 
            if (vetor[i - 1] > *max) 
                *max = vetor[i - 1];

            if (vetor[i] < *min) 
                *min = vetor[i];
        }

        else { 
            if (vetor[i - 1] < *min){ 
                *min = vetor[i - 1];
            }
            if (vetor[i] > *max){ 
                *max = vetor[i];
            }
        }

        i += 2;
    }
}


void executarMinMax1(int vetor[], int numEntradas, string ordem){
    ofstream infos("datasets/infos.txt", ios::app);
    if(!infos.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    int max, min;
    chrono::duration<double>soma;

    for(int i=0; i<10; i++){
        auto inicio = chrono::high_resolution_clock::now();

        minMax1(vetor, numEntradas, &max, &min);
                
        auto fim = chrono::high_resolution_clock::now();
        chrono::duration<double> duracao = fim - inicio;
        soma += duracao;
        cout << "Tempo de execucao: " << duracao.count() << " segundos." << endl;
    }
            
    chrono::duration<double>media = soma/10;
    infos << "\n[minMax1] / " << numEntradas << " / " << ordem << " / Media: "  << media.count() << " segundos." << endl;
    infos.close();
}


void executarMinMax2(int vetor[], int numEntradas, string ordem){
    ofstream infos("datasets/infos.txt", ios::app);
    if(!infos.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    int max, min;
    chrono::duration<double>soma;

    for(int i=0; i<10; i++){
        auto inicio = chrono::high_resolution_clock::now();

        minMax2(vetor, numEntradas, &max, &min);
                
        auto fim = chrono::high_resolution_clock::now();
        chrono::duration<double> duracao = fim - inicio;
        soma += duracao;
        cout << "Tempo de execucao: " << duracao.count() << " segundos." << endl;
    }
            
    chrono::duration<double>media = soma/10;
    infos << "\n[minMax2] / " << numEntradas << " / " << ordem << " / Media: "  << media.count() << " segundos." << endl;
    infos.close();
}


void executarMinMax3(int vetor[], int numEntradas, string ordem){
    ofstream infos("datasets/infos.txt", ios::app);
    if(!infos.is_open()){
        cout << "Erro na leitura do arquivo.";
    }

    int max, min;
    chrono::duration<double>soma;

    for(int i=0; i<10; i++){
        auto inicio = chrono::high_resolution_clock::now();

        minMax3(vetor, numEntradas, &max, &min);
                
        auto fim = chrono::high_resolution_clock::now();
        chrono::duration<double> duracao = fim - inicio;
        soma += duracao;
        cout << "Tempo de execucao: " << duracao.count() << " segundos." << endl;
    }
            
    chrono::duration<double>media = soma/10;
    infos << "\n[minMax3] / " << numEntradas << " / " << ordem << " / Media: "  << media.count() << " segundos." << endl;
    infos.close();
}