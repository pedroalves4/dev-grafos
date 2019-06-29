#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include "Grafo.h"
#include <vector>


class FloydWarshall
{
    public:
        void imprimeFloydWarshall(Grafo *grafo);

    private:
        vector<vector<long int> > mDistancia; /// matriz para armazenar as distâncias
        void matrizDistancia(Grafo *grafo);
        void floyd(Grafo *grafo);

};

#endif // FLOYDWARSHALL_H
