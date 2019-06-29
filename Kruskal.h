#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include "Grafo.h"

using namespace std;

class Kruskal
{
public:

    static void arvoreGeradoraMinima(Grafo *grafo);
    static bool arestaFormaCiclo(No *no1, No *no2);
    static void imprimirSolucao(Grafo *grafo);


};

#endif // KRUSKAL_H_INCLUDED
