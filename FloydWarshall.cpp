#include "Grafo.h"
#include <vector>
#include "FloydWarshall.h"

using namespace std;

/**
 * Gera uma matriz Distancia que sera utilizada como input no algoritmo de Floyd Warshall
 * @param Grafo
 * @return void
*/

void FloydWarshall::matrizDistancia(Grafo *grafo)
{
    int n = grafo->listaNo.size(); ///numero devertices
    int id1, id2;
    id1=id2=0;
    Aresta* aresta;
    int pesoAresta=0;

    /// ------------------------Entendendo o codigo abaixo -----------------------------------------------------------------
    /// caso seja adjacente, pega a distancia (peso) da aresta entre 2 nohs, caso nao seja, seta 9999999999
    /// com grafos orientados, quando um noh a eh direcionado ao b, se tentarmos pegar a adjacencia de b para a, seria como se
    /// fossem nao fossem adjacentes, sendo assim, a distancia seria setada como 9999999999
    /// caminho de um noh ao mesmo noh recebem 0
    /// --------------------------------------------------------------------------------------------------------------------
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                mDistancia[i][j]=0;
            }
            else if(grafo->listaNo[i]->verificaAdjacencia(grafo->listaNo[j]) && i!=j) /// no caso, ainda precisamos implementar uma funcao que
            {
                /// verifica se existe um caminho entre 2 nohs, e nao apenas  se os 2 sao adjacentes... sendo assim, este metodo
                id1=grafo->listaNo[i]->id;
                id2=grafo->listaNo[j]->id;
                aresta = grafo->getAresta(id1, id2);
                pesoAresta= aresta->peso;
                mDistancia[i][j]=pesoAresta;
            }
            else
            {
                mDistancia[i][j] = 9999999999;
            }
        }
    }
}

/**
 * Encontra o menor caminho entre todos os pares usando o algoritmo de Floyd Warshall
 * @param Grafo
 * @return void
*/

///
void FloydWarshall::floyd(Grafo *grafo)
{
    int V = grafo->listaNo.size();

    ///primeiro chamamos a funcao matrizDistancia para popular a matriz mDistancia
    matrizDistancia(grafo);

    ///matriz que conteria as menores distancias entre todos os pares de vertices
    int dist[V][V], i, j, k;

    ///inicializando os valores de dist com os mesmos valores de mDistancia
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = mDistancia[i][j];

    /*Adiciona todos os verrtices, um por um, no set de vertices intermediarios

    --->antes de comecar a iteracao, nos temos menores distancias entre todos os pares de
    vertices de forma que as menores distancias consederam apenas os vertices no set {0, 1, 2, .. k-1} como
     vertices intermediarios

     ---> Apos o fim de uma iteracao, o vertice k eh adicionado ao set de vertices intemediario e o set
     se torna {0, 1, 2, .. k} */


    for (k = 0; k < V; k++)
    {
        /// pega todos os vertices como fonte, um a um
        for (i = 0; i < V; i++)
        {
            /// pega todos os vertices como destinacao para a fonte selecionada
            for (j = 0; j < V; j++)
            {
                /// se o indice k eh o caminho mais curto de i a j, entao atualizamos o valor de dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    ///atulizando os valores de mDistancia com os mesmos valores de dist
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            mDistancia[i][j] = dist[i][j];
}

/**
 * imprimie a solucao de Floyd - funcao que eh chamada pelo menu principal
 * @param
 * @return void
*/
void FloydWarshall::imprimeFloydWarshall(Grafo *grafo)
{
    /// primeiramente chamamos a funcao que monta a matriz com as menores distancias - floyd()
    floyd(grafo);

    /// executamos a impressao
    cout<<"A seguinte matriz apresenta as menores distancias entre cada par de vertices" << endl;

    int V = grafo->listaNo.size();

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (mDistancia[i][j] == 99999)
                cout<<"inf"<<"   ";
            else
                cout<<mDistancia[i][j]<<"  ";
        }
        cout<<endl;
    }
}
