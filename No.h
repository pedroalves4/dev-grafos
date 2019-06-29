#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "Aresta.h"

#include <vector>

using namespace std;

class No
{
public:

    public:
        No(int id);
        ~No();
        int id;
        int getPeso();
        void setPeso(int val);
        int getPesoAresta();
        void setPesoAresta(int val);
        int getGrau();
        void setGrau(int val);
        int getVisitado();
        void setVisitado(bool val);
        No* getProx();
        void setProx(No* val);
        vector<No *> getAdjacentes();
        Aresta * adicionaNoAdjacente(No *no,bool val,int peso);
        void adicionaNoAdjacenteSemMsg(No *no,bool direcionado,int peso);
        bool verificaAdjacencia(No *no);
        vector<No *> nosAdjacentes;
        void printAdjacentes();
        void removeAdjacente(No* adjacente);
        void removeAdjacenteSemMsg(No* adjacente);

        int peso;
        int pesoAresta;
        int grau;
        vector<Aresta *> arestas;
        bool visitado;
        bool direcionado;
        int distancia;

};

#endif // NO_H_INCLUDED
