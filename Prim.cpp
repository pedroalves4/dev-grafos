#include "Prim.h"
#include "Grafo.h"
#include "No.h"
#include "Aresta.h"
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * Recebe um grafo e gera uma árvore geradora mínima para ele
 * @param Grafo
 * @return void
*/
void Prim::arvoreGeradoraMinima(Grafo *grafo)
{

    /// verifica se um grafo eh conexo.
    if (grafo->ehConexo())
    {
        auto *arvoreGeradoraMinima = new Grafo();

        int tam = grafo->listaNo.size();

        /// pega um vértice aleatório e o insere na AGM.
        auto *noInicial = new No(grafo->listaNo.at(rand() % tam-1)->id);
        arvoreGeradoraMinima->listaNo.push_back(noInicial);

        /// adiciona nós e arestas de menor peso enquanto a AGM não possuir todos os vértices.
        while (arvoreGeradoraMinima->listaNo.size() < tam)
        {
            Aresta *aresta = getArestaMenorPeso(grafo, arvoreGeradoraMinima);

            auto *No1 = new No(aresta->no1->id);
            auto *No2 = new No(aresta->no2->id);

            if (!arvoreGeradoraMinima->verificaId(No1->id))
            {
                arvoreGeradoraMinima->listaNo.push_back(No1);
            }

            if (!arvoreGeradoraMinima->verificaId(No2->id))
            {
                arvoreGeradoraMinima->listaNo.push_back(No2);
            }

            arvoreGeradoraMinima->arestas.push_back(aresta);
        }

        imprimeSolucao(arvoreGeradoraMinima);
    }
    else
    {
        cout << "O grafo precisa ser conexo." << endl;
    }
}

/**
 * Retorna a aresta de menor peso de um grafo
 * @param Grafo
 * @param Grafo
 * @return Aresta
*/
Aresta *Prim::getArestaMenorPeso(Grafo *grafo, Grafo *arvoreGeradoraMinima)
{
    auto *arestaMenorPeso = new Aresta();
    int pesoMinimo = numeric_limits<int>::max();

    for (auto aresta : grafo->arestas)
    {
        if (!(arvoreGeradoraMinima->verificaId(aresta->no1->id) && arvoreGeradoraMinima->verificaId(aresta->no2->id)))
        {
            if (arvoreGeradoraMinima->verificaId(aresta->no1->id)|| arvoreGeradoraMinima->verificaId(aresta->no2->id))
            {
                if (aresta->peso < pesoMinimo)
                {
                    arestaMenorPeso = aresta;
                    pesoMinimo = aresta->peso;
                }
            }
        }
    }

    return arestaMenorPeso;
}

/**
 * Imprime uma árvore geradora mínima de um grafo
 * @param Grafo
 * @return void
*/
void Prim::imprimeSolucao(Grafo *grafo)
{
    cout << "Arvore Geradora Minima - Prim:" << endl;
    for (auto aresta : grafo->arestas)
    {
        cout << "(" << aresta->no1->id << "," << aresta->no2->id << ") ";
    }
    cout << endl;
}
