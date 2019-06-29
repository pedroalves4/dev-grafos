#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include "Grafo.h"
#include <vector>

class Dijkstra
{
    public:
        static void custoCaminhoMinimo(Grafo *grafo, int idNo1, int idNo2);
        static No *getNoDistanciaMinima(vector<No *> Nos);
    private:

};

#endif // DIJKSTRA_H_INCLUDED
