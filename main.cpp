#include <istream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "No.h"
#include "Aresta.h"
#include "Grafo.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Dijkstra.h"
#include "FloydWarshall.h"
#include <vector>
#include <fstream>
#include <cstdio>
#include <chrono>


using namespace std;

int lerOuConstruirMenu()
{
    int opcao = 0;
    cout << "-------------------------------------------------------MENU--------------------------------------------------" << endl;
    cout << "Voce deseja ler um arquivo de grafos ou montar seu proprio grafo?" << endl;
    cout << "[1] Ler" << endl;
    cout << "[2] Construir" << endl;
    cin >> opcao;
    return opcao;
}

int tipoDeRepresentacaoMenu()
{
    int opcao = 0;
    cout << "-------------------------------------------------------MENU--------------------------------------------------" << endl;
    cout << "Escolha o tipo de representacao: " << endl;
    cout << "[1] Matriz de Adjacencia" << endl;
    cout << "[2] Lista de Adjacencia" << endl;
    cout << "[-1] Para encerrar o programa" << endl;
    cout << endl;
    cin >> opcao;
    return opcao;
}

int noMenu()
{
    int opcao = 0;
    string opcoesMenu[] =
    {
        "[1] Adicionar No",
        "[2] Adicionar vizinhos a um No",
        "[3] Adicionar arestas a um no",
        "[4] Lista de vertices do grafo",
        "[5] Representar o grafo",
        "[6] Lista de adjacentes a um no",
        "[7] Remover uma aresta",
        "[8] Remover um vertice",
        "[9] Criar grafo complementar e representa-lo por Lista de Adjacencia",
        "[10] Criar grafo complementar e representa-lo por Matriz de Adjacencia",
        "[11] Busca em profundidade",
        "[12] Busca em largura",
        "[13] Componentes Conexas",
        "[14] Imprimir peso do vertice",
        "[15] Imprimir peso da aresta",
        "[16] Ordenacao topologia",
        "[17] Obter solucao pelo algoritmo guloso",
        "[18] Obter solucao pelo algoritmo guloso randomizado",
        "[19] Imprimir sequencia de grau",
        "[20] Componentes fortemente conexas",
        "[21] Arvore geradora minima - Kruskal",
        "[22] Arvore geradora minima - Prim",
        "[23] Caminho minimo entre dois nos - Dijkstra",
        "[24] Matriz com menores distancias entre nos  - Floyd Warshall"

    };

    cout << endl << "Selecione uma das opcoes: " << endl;
    for(op : opcoesMenu)
    {
        cout << op << endl;
    }
    cin >> opcao;
    return opcao;
}

int noMenuLeitura()
{
    int opcao = 0;
    string opcoesMenu[] =
    {
        "[1] Lista de vertices do grafo",
        "[2] Representar o grafo",
        "[3] Lista de adjacentes a um no",
        "[4] Remover uma aresta",
        "[5] Remover um vertice",
        "[6] Criar grafo complementar e representa-lo por Lista de Adjacencia",
        "[7] Criar grafo complementar e representa-lo por Matriz de Adjacencia",
        "[8] Busca em profundidade",
        "[9] Busca em largura",
        "[10] Componentes Conexas",
        "[11] Imprimir peso do vertice",
        "[12] Imprimir peso da aresta",
        "[13] Ordenacao topologia",
        "[14] Obter solucao pelo algoritmo guloso",
        "[15] Obter solucao pelo algoritmo guloso randomizado",
        "[16] Obter solucao pelo algoritmo guloso randomizado reativo",
        "[17] Componentes fortemente conexas",
        "[18] Imprimir sequencia de grau",
        "[19] Arvore geradora minima - Kruskal",
        "[20] Arvore geradora minima - Prim",
        "[21] Caminho minimo entre dois nos - Dijkstra",
        "[24] Matriz com menores distancias entre nos  - Floyd Warshall"
    };

    cout << endl << "Selecione uma das opcoes: " << endl;
    for(op : opcoesMenu)
    {
        cout << op << endl;
    }
    cin >> opcao;
    return opcao;
}
int tipodeGrafo()
{

    int opcao = 0;
    cout << "-------------------------------------------------------MENU--------------------------------------------------" << endl;
    cout << "Selecione uma opcao: " << endl;
    cout << "[1] Grafo ponderado no vertice" << endl;
    cout << "[2] Grafo ponderado na aresta" << endl;
    cout << "[3] Grafo direcionado" << endl;
    cout << "[4] Nenhuma das opcoes" <<endl;
    cout << "[-1] Para encerrar o programa" << endl;
    cin >> opcao;
    return opcao;
}

Grafo* criaGrafoComplementar(Grafo* grafo)
{
    bool direcionado = false; /// grafo->ehDirecionado();
    Grafo* grafoComplementar = new Grafo();
    for(int i = 0; i < grafo->listaNo.size(); i++)
    {
        No* noOriginal = grafo->listaNo[i];
        No* noComplementar = noOriginal;
        for(int j = 0; j < grafo->listaNo.size() && i!=j; j++)
        {
            if(noOriginal->verificaAdjacencia(grafo->listaNo[j]))
            {
                noComplementar->removeAdjacente(grafo->listaNo[j]);
                grafo->listaNo[j]->removeAdjacente(noComplementar);

            }
            else
            {
                noComplementar->adicionaNoAdjacente(grafo->listaNo[j], direcionado, 0);
            }
        }
        grafoComplementar->adicionaVertice(noComplementar);
    }

    return grafoComplementar;
}

int main(int argc, char * argv[])
{

    int pesoVertice;
    int pesoAresta;
    int idDijkstra1 = 0;
    int idDijkstra2 = 0;
    int id = 0;
    int idAdj = 0;
    int opcao = 0;
    bool direcionado = 0;
    bool ponderadoVertice = 0 ;
    bool ponderadoAresta = 0;
    vector< No > vertices;
    Grafo *grafo = new Grafo();
    Kruskal *kruskal = new Kruskal();
    Prim *prim = new Prim();
    Dijkstra *dijkistra = new Dijkstra();
    FloydWarshall *floydWarshall = new FloydWarshall();

    ///************* CONSTRUÇÃO DO GRAFO ******************///
    /*
        if(lerOuConstruirMenu() == 2)
        {
            int opcaorepresenta = tipodeGrafo();
            /// Menu do tipo de representação do grafo
            switch(opcaorepresenta)
            {
            case 1:
                cout<< "Digite [1] para grafo ponderado no vertice ou [0] para grafo nao ponderado" << endl ;
                cin >> ponderadoVertice;
            case 2:
                cout<< "Digite [1] para grafo ponderado na aresta ou [0] para grafo nao ponderado" << endl ;
                cin >> ponderadoAresta;
            case 3:
                cout<< "Digite [1] para grafo direcionado ou [0] para grafo nao direcionado" << endl;
                cin >>direcionado;
            }

            /// Menu de opções para o grafo
            cout << "Criando seu Grafo " << endl;
            while(id != -1)
            {
                opcao = noMenu();
                switch(opcao)
                {
                /// Adicionar Nó
                case 1:
                {
                    cout << "Adicione um vertice informando seu id ou aperte [-1] para terminar o grafo" << endl;
                    cin >> id;
                    if(id == -1)
                        break;
                    if(ponderadoVertice == 1)
                    {
                        No *vertice = new No(id);
                        cout<< "Adiciono um peso ao vertice " <<id<<endl;
                        cin>>pesoVertice;
                        grafo->adicionaVerticePonderado(vertice,pesoVertice);
                    }
                    else
                    {
                        No *vertice = new No(id);
                        grafo->adicionaVertice(vertice);
                    }
                }
                break;
                /// Adicionar vizinho a um No
                case 2:
                    cout << "Digite o id do no que voce quer acessar: " << endl;
                    cin >> id;
                    if(id == -1)
                        break;
                    while(!grafo->verificaId(id))
                    {
                        cout << "Id invalido, esse no nao foi encontrado no grafo, digite outro id: " << endl;
                        cin >> id;
                        if(id == -1)
                            break;
                    }
                    cout << "Voce esta no vertice " << grafo->getNo(id)->id << ", digite um vertice adjacente a esse: " << endl;
                    cin >> idAdj;
                    if(id == idAdj)
                    {
                        cout<<"Nao e permitido self-loop"<<endl;
                    }
                    else
                    {
                        if(ponderadoAresta)
                        {
                            cout<< "Adicione o peso da aresta ["<<id<<"] ["<<idAdj<<"]"<<endl;
                            cin>>pesoAresta;
                            grafo->arestas.push_back(grafo->getNo(id)->adicionaNoAdjacente(grafo->getNo(idAdj),direcionado,pesoAresta));
                        }
                        else
                        {
                            grafo->arestas.push_back(grafo->getNo(id)->adicionaNoAdjacente(grafo->getNo(idAdj),direcionado,pesoAresta));
                        }
                    }
                    break;
                /// Adicionar Aresta a um no
                case 3:
                    break;
                /// Imprime lista de vértices do no
                case 4:
                    grafo->printNos();
                    break;
                /// Menu de Representação do Grafo
                case 5:
                {
                    int opcaorepresenta = tipoDeRepresentacaoMenu();
                    if(opcaorepresenta == 1)
                    {
                        cout << "Matriz de adjacencia: " << endl;
                        grafo->matrizAdjacencia(direcionado);
                    }
                    else if(opcaorepresenta == 2)
                    {
                        cout<<"Lista de adjacencia: "<<endl;
                        grafo->printListaAdjacencia();
                    }
                    else if(opcaorepresenta == -1)
                    {
                        break;
                    }
                }
                break;
                /// Imprime nos adjacentes
                case 6:
                    grafo->printAdjacentesAoNo();
                    break;
                /// Remove uma aresta
                case 7:
                    grafo->removeAresta();
                    break;
                /// Remover um vértice
                case 8:
                    grafo->removeVertice();
                    break;
                /// Cria um grafo complementar e representa o mesmo em lista de adjacência
                case 9:
                    criaGrafoComplementar(grafo)->printListaAdjacencia();
                    break;
                /// Cria um grafo complementar e representa o mesmo em matriz de adjacência
                case 10:
                    criaGrafoComplementar(grafo)->matrizAdjacencia(direcionado);
                    break;
                /// Aplica um algortimo de busca em profundidade
                case 11:
                    grafo->caminhamentoEmProfundidade();
                    break;
                /// Aplica um algortimo de busca em largura
                case 12:
                    grafo->caminhamentoEmLargura(1);
                    break;
                /// Imprime as componentes conexas do grafo
                case 13:
                    grafo->componentesConexas();
                    break;
                /// Imprime peso do vertice
                case 14:
                    grafo->imprimePesoVertice();
                    break;
                case 15:
                    ///Imprime peso da aresta
                    grafo->imprimePesoAresta();
                    break;
                case 16:
                    /// Ordenação Topológica
                    grafo->ordenacaoTopologica();
                    break;
                case 17:
                    /// Algoritmo guloso
                    grafo->algoritmoGuloso();
                    break;
                case 18:
                    ///Algoritmo guloso randomizado
                    grafo->iniciaAlgoritmoGulosoRandomizado();
                    break;
                case 19:
                    /// Algoritmo guloso
                    grafo->printSequenciaDeGraus();
                    break;
                case 20:
                    ///Componente fortemente conexa
                    grafo->imprimirComponentesFortementeConexas();
                    break;
                case 21:
                    /// Algoritmo de Kruskal
                    kruskal->arvoreGeradoraMinima(grafo);
                    break;
                case 22:
                    /// Algoritmo de Prim
                    prim->arvoreGeradoraMinima(grafo);
                    break;
                case 23:
                {
                    /// Algoritmo de Dijkistra
                    cout << "Digite o id do No 1: " << endl;
                    cin >> idDijkstra1;
                    cout << "Digite o id do No 2: " << endl;
                    cin >> idDijkstra2;

                    dijkistra->custoCaminhoMinimo(grafo,idDijkstra1, idDijkstra2);
                }
                break;
                case 24:
                    /// Algoritmo de Floyd Warshall
                    floydWarshall->imprimeFloydWarshall(grafo);
                    break;
                default:
                    cout << "Digite uma opcao valida" << endl;
                    break;
                }
            }
        }
    */
    ///*******************************////////


    ///*********** LEITURA DO GRAFO *************/////
    /*
        else if(lerOuConstruirMenu() == 1)
        {
            int opcaorepresenta = tipodeGrafo();
            /// Menu do tipo de representação do grafo
            switch(opcaorepresenta)
            {
            case 1:
                cout<< "Digite [1] para grafo ponderado no vertice ou [0] para grafo nao ponderado" << endl ;
                cin >> ponderadoVertice;
            case 2:
                cout<< "Digite [1] para grafo ponderado na aresta ou [0] para grafo nao ponderado" << endl ;
                cin >> ponderadoAresta;
            case 3:
                cout<< "Digite [1] para grafo direcionado ou [0] para grafo nao direcionado" << endl;
                cin >>direcionado;
            }

            string aux;
            ifstream myfile ("instancia1.MIS"); // ifstream = padrão ios:in     teste1.txt      instancia1.MIS
            ofstream saida;
            saida.open("saida.txt");
            auto start = std::chrono::high_resolution_clock::now();
            if (myfile.is_open())
            {
                while (!myfile.eof()) //enquanto end of file for false continua
                {
                    getline (myfile, aux, ' ');
                    int id1 = atoi (aux.c_str());
                    No *vertice = new No(id1);
                    saida << vertice->id;
                    grafo->adicionaVertice(vertice);
                    aux.clear();
                    getline (myfile, aux);
                    int id2 = atoi (aux.c_str());
                    No *vertice1 = new No(id2);
                    grafo->adicionaVertice(vertice1);
                    aux.clear();
                    grafo->arestas.push_back(grafo->getNo(vertice->id)->adicionaNoAdjacente(grafo->getNo(vertice1->id),direcionado,pesoAresta));
                }
                myfile.close();
            }

            cout << "********* GRAFO CARREGADO **************" << endl;
            auto finish = std::chrono::high_resolution_clock::now();
            auto elapsed = finish - start;
            float tempo = elapsed.count()/1000000000;

            cout << "Tempo levado para ler o arquivo de entrada e popular o grafo: " << tempo << " seconds" << endl;

            while(id != -1)
            {
                opcao = noMenuLeitura();
                switch(opcao)
                {
                /// Imprime lista de vértices do no
                case 1:
                    grafo->printNos();
                    break;
                /// Menu de Representação do Grafo
                case 2:
                {
                    int opcaorepresenta = tipoDeRepresentacaoMenu();
                    if(opcaorepresenta == 1)
                    {
                        cout << "Matriz de adjacencia: " << endl;
                        grafo->matrizAdjacencia(direcionado);
                    }
                    else if(opcaorepresenta == 2)
                    {
                        cout<<"Lista de adjacencia: "<<endl;
                        grafo->printListaAdjacencia();
                    }
                    else if(opcaorepresenta == -1)
                    {
                        break;
                    }
                }
                break;
                /// Imprime nos adjacentes
                case 3:
                    grafo->printAdjacentesAoNo();
                    break;
                /// Remove uma aresta
                case 4:
                    grafo->removeAresta();
                    break;
                /// Remover um vértice
                case 5:
                    grafo->removeVertice();
                    break;
                /// Cria um grafo complementar e representa o mesmo em lista de adjacência
                case 6:
                    criaGrafoComplementar(grafo)->printListaAdjacencia();
                    break;
                /// Cria um grafo complementar e representa o mesmo em matriz de adjacência
                case 7:
                    criaGrafoComplementar(grafo)->matrizAdjacencia(direcionado);
                    break;
                /// Aplica um algortimo de busca em profundidade
                case 8:
                    grafo->caminhamentoEmProfundidade();
                    break;
                /// Aplica um algortimo de busca em largura
                case 9:
                    grafo->caminhamentoEmLargura(1);
                    break;
                /// Imprime as componentes conexas do grafo
                case 10:
                    grafo->componentesConexas();
                    break;
                /// Imprime peso do vertice
                case 11:
                    grafo->imprimePesoVertice();
                    break;
                case 12:
                    ///Imprime peso da aresta
                    grafo->imprimePesoAresta();
                    break;
                case 13:
                    /// Ordenação Topológica
                    grafo->ordenacaoTopologica();
                    break;
                case 14:
                    /// Algoritmo guloso
                    grafo->algoritmoGuloso();
                    break;
                case 15:
                    ///Algoritmo guloso randomizado
                    grafo->iniciaAlgoritmoGulosoRandomizado();
                    break;
                case 16:
                    /// Algoritmo guloso
                    grafo->algoritmoGulosoRandomizadoReativo();
                    break;
                case 17:
                    ///Componente fortemente conexa
                    grafo->imprimirComponentesFortementeConexas();
                    break;
                case 18:
                    ///Componente fortemente conexa
                    grafo->printSequenciaDeGraus();
                    break;
                case 19:
                    /// Algoritmo de Kruskal
                    kruskal->arvoreGeradoraMinima(grafo);
                    break;
                case 20:
                    /// Algoritmo de Prim
                    prim->arvoreGeradoraMinima(grafo);
                    break;
                default:
                    cout << "Digite uma opcao valida" << endl;
                    break;
                }
            }
        }


    */

    cout << argv[1] << endl;

    ifstream myfile (argv[1]);
    ofstream outfile;
    outfile.open(argv[2], std::ofstream::app);
    string aux;

    while(!myfile.eof())
    {
        getline (myfile, aux, ' ');
        int id1 = atoi (aux.c_str());
        //cout << id1 << endl;
        No *vertice = new No(id1);
        //saida << vertice->id;
        grafo->adicionaVertice(vertice);
        aux.clear();
        getline (myfile, aux);
        int id2 = atoi (aux.c_str());
        //cout << id2 << endl;
        No *vertice1 = new No(id2);
        grafo->adicionaVertice(vertice1);
        aux.clear();
        grafo->arestas.push_back(grafo->getNo(vertice->id)->adicionaNoAdjacente(grafo->getNo(vertice1->id),direcionado,pesoAresta));
    }

    cout << "********* GRAFO CARREGADO **************" << endl;

    if(atoi(argv[3]) != 0)
    {
        grafo->algoritmoGuloso(outfile);
    }
    if(atoi(argv[4]) != 0)
    {

    }
    if(atoi(argv[5]) != 0)
    {
        grafo->algoritmoGulosoRandomizadoReativo();
    }

    return 0;
}
