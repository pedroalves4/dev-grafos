#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#include "No.h"

class No;

class Aresta
{
public:


    // Implementação antiga
    /*
    void setProx(Aresta aresta);
    Aresta getProx();
    void setNoAdj(int val);
    int getNoAdj();
    //int getPeso();
    //void setPeso(int val);
    Aresta *prox;
    int noAdj;
    */

    // Nova implementação

    Aresta();
    ~Aresta();

    explicit Aresta(No* no1, No *no2);
    explicit Aresta(No *no1, No* no2,int peso);

    No *no1;
    No *no2;
    int peso;


};

#endif // ARESTA_H_INCLUDED
