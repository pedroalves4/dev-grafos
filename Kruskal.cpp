#include "Kruskal.h"
#include "No.h"
#include <list>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


/**
 * Recebe um grafo e gera uma árvore geradora miníma
 * @param Grafo
 * @return void
*/
void Kruskal::arvoreGeradoraMinima(Grafo *grafo)
{
    /// Verifica se o grafo eh conexo
    if(grafo->ehConexo())
    {
        auto *arvoreGeradoraMinima = new Grafo;

        /// ordena a lista de arestas por peso em ordem crescente

        sort(grafo->arestas.begin(), grafo->arestas.end(),[](Aresta *aresta1, Aresta *aresta2)
        {
            return aresta1->peso < aresta2->peso;
        });

        for (auto i = grafo->arestas.begin(); arvoreGeradoraMinima->arestas.size() < grafo->listaNo.size() - 1; i++)
        {
            Aresta *aresta = *i;

            /// Verifica se o No1 e o No2 estão na solução e adiciona eles caso não esteja
            if (!arvoreGeradoraMinima->verificaId(aresta->no1->id))
            {
                arvoreGeradoraMinima->listaNo.push_back(new No(aresta->no1->id));
            }

            if (!arvoreGeradoraMinima->verificaId(aresta->no2->id))
            {
                arvoreGeradoraMinima->listaNo.push_back(new No(aresta->no2->id));
            }

            No *No1 = arvoreGeradoraMinima->getNo(aresta->no1->id);
            No *No2 = arvoreGeradoraMinima->getNo(aresta->no2->id);

            /// adiciona a aresta na solução caso não forme um circulo
            if (!arestaFormaCiclo(No1, No2))
            {
                auto *novaAresta = new Aresta(No1, No2, aresta->peso);
                arvoreGeradoraMinima->arestas.push_back(novaAresta);
            }
        }

        imprimirSolucao(arvoreGeradoraMinima);
    }
    else
        cout << "O Grafo nao eh conexo" << endl;

}

/**
 * Imprime a árvore geradora minima encontrada pelo
 * algoritmo de Kruskal
 * @param Grafo
*/
void Kruskal::imprimirSolucao(Grafo *grafo)
{
    cout << "Arvore Geradora Minima - Kruskal:" << endl;
    for (auto aresta : grafo->arestas)
    {
        cout << "(" << aresta->no1->id << "," << aresta->no2->id << ") ";
    }
    cout << endl;
}

/**
 * Verifica se foi formado um ciclo na solução do
 * algoritmo de Kruskal
 * @param No
 * @param No
 * @return bool
*/
bool Kruskal::arestaFormaCiclo(No *no1, No *no2)
{
    for (auto noAdjacente : no1->nosAdjacentes)
    {
        for (auto noAdjacenteAoAdjacente : noAdjacente->nosAdjacentes)
        {
            if (noAdjacenteAoAdjacente->id == no2->id)
            {
                return true;
            }
        }
    }

    return false;
}
