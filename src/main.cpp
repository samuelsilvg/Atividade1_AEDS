#include "minMax.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

int main(){

    for(int indice = 0; indice < 4; indice++){

        int tamanhoVetor = definirTamanhoVetor(indice);
        int vetor[tamanhoVetor];

        string ordem = "Aleatorio";
        gerarVetorAleatorio(vetor, tamanhoVetor);
        executarMinMax1(vetor, tamanhoVetor, ordem);
        executarMinMax2(vetor, tamanhoVetor, ordem);
        executarMinMax3(vetor, tamanhoVetor, ordem);
        
        ordem = "Crescente";
        sort(vetor, vetor + tamanhoVetor);
        executarMinMax1(vetor, tamanhoVetor, ordem);
        executarMinMax2(vetor, tamanhoVetor, ordem);
        executarMinMax3(vetor, tamanhoVetor, ordem);
        
        ordem = "Decrescente";
        sort(vetor, vetor + tamanhoVetor, compararDecrescente);
        executarMinMax1(vetor, tamanhoVetor, ordem);
        executarMinMax2(vetor, tamanhoVetor, ordem);
        executarMinMax3(vetor, tamanhoVetor, ordem);
    }

    return 0;
}