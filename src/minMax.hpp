#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;

int definirTamanhoVetor(int indice);
void gerarVetorAleatorio(int vetor[], int numEntradas);
bool compararDecrescente(int a, int b);

void minMax1(int vetor[], int tam, int *max, int *min);
void minMax2(int vetor[], int tam, int *max, int *min);
void minMax3(int vetor[], int tam, int *max, int *min);

void executarMinMax1(int vetor[], int numEntradas, string ordem);
void executarMinMax2(int vetor[], int numEntradas, string ordem);
void executarMinMax3(int vetor[], int numEntradas, string ordem);

#endif //MINMAX_HPP 