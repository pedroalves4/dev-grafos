#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "No.h"
#include <vector>
#include <iostream>
#include <stack>
#include <time.h>
#include <fstream>

using namespace std;

class Grafo
{
public:

     struct Alfa {
        float probabilidadeDeSerEscolhido;
        float valorAlfa;
        float Qi;
        int melhorSolucao;
        float mediaSolucoes;
        int indice;
        vector<int> idsMelhorSolucao;
        int numeroDeVezesEscolhidoTotal;
    };

    Grafo();
    ~Grafo();
    vector<No*> listaNo;
    vector<Aresta *> arestas;
    void adicionaVerticePonderado(No *no, int peso);
    int getOrdem();
    void setOrdem(int val);
    int getGrau();
    void setGrau(int val);
    bool getNoPonderado();
    void setNoPonderado(bool val);
    void printMatrizAdjacencia();
    void matrizAdjacencia(bool val);
    void printListaAdjacencia();
    void printNos();
    void adicionaVertice(No *no);
    void removeVertice();
    void auxRemoveVertice(No* noASerRemovido);
    void removeTodasAdjacenciasDeUmNo(No* noASerRemovido);
    void removeAresta();
    bool possuiAresta(int id1, int id2);
    Aresta *getAresta(int id1, int id2);
    bool verificaId(int id);
    No * getNo(int id);
    void printAdjacentesAoNo();
    void caminhamentoEmProfundidade();
    void aprofunda_ComponenteConexa(No* no);
    void aprofunda(No* no);
    void caminhamentoEmLargura(int id);
    void setVisitadoEmTodosNos(bool visitado);
    void caminhaEmLargura(vector<No*> fila);
    void componentesConexas();
    void imprimePesoVertice();
    void imprimePesoAresta();
    int auxImprimePesoAresta(int val);
    void ordenacaoTopologica();
    int grauMinimo(int graus[], int n);
    void printSequenciaDeGraus();
    void preenche(No *v, stack<No*>& pilha);
    void DFS(No *v);
    Grafo *obterGrafoTransposto();
    void imprimirComponentesFortementeConexas();
    void algoritmoGuloso(ofstream &arquivoDeSaida);
    void iniciaAlgoritmoGulosoRandomizado();
    vector<int> algoritmoGulosoRandomizado(float alfa, int maximoIteracoes);
    vector<int> algoritmoGulosoRandomizado(float alfa, int maximoIteracoes, float *mediaSolucoes);
    vector<int> getSolucaoRandomizada(float alfa);
    void printSolucaoGulosa(vector<int> solucao, ofstream &arquivoDeSaida);
    void printSolucaoGulosaRandomizada(vector<int> solucao);
    vector<No*> atualizaNosCandidatos(No* candidatoSelecionado, vector<No*> nosCandidatos);
    No* getNoDeMenorGrau(vector<No*>);
    vector<vector<long int> > mDistancia; /// matriz para armazenar as distâncias
    void matrizDistancia();
    void floyd();
    vector<No*> getVetorMenorGrau(vector<No*> nosCandidatos);
    vector<No*> getPorcentagem(vector<No*> nosCandidatos, float porcentagem);
    int gerarNumeroAleatorio(int limite_inf, int limite_sup, int timer);

    void preencheAlfas(Alfa *alfas, int numeroDeAlfas, int maximoIteracoesRandomizado);
    Alfa getAlfaAleatorio(Alfa *alfas, int numeroDeAlfas);
    void atualizaProbabilidadeDosAlfas(Alfa *alfas, int numeroDeAlfas, int melhorSolucao);

    void algoritmoGulosoRandomizadoReativo();
    float calculaQi(int atualMaiorCardinalidade, float mediaSolucoes);

    bool ehConexo();

private:
    int ordem;
    int grau;
    bool noPonderado;

};


#endif // GRAFO_H_INCLUDED
