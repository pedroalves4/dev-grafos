#include "No.h"
#include "Aresta.h"
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

No::No(int i)
{
    id=i;
    grau=0;
    visitado=false;
    distancia = numeric_limits<int>::max();
}

No::~No()
{

}

int No::getGrau()
{
    return grau;
}

void No::setGrau(int val)
{
    grau = val;
}

int No::getPeso()
{
    return peso;
}

void No::setPeso(int val)
{
    peso = val;
}
int No::getVisitado()
{
    return visitado;
}

void No::setVisitado(bool val)
{
    this->visitado = val;
}

vector<No*> No::getAdjacentes()
{
    return this->nosAdjacentes;
}

bool No::verificaAdjacencia(No *no)
{
    vector<No*> adjacentes = this->getAdjacentes();
    int contador = count(adjacentes.begin(), adjacentes.end(), no);
    return (contador == 1);
}


Aresta * No::adicionaNoAdjacente(No *no, bool direcionado, int peso)
{
    Aresta *aresta = new Aresta();
    aresta->no1 = this;
    aresta->no2 = no;
    aresta->peso = peso;

    this->arestas.push_back(aresta);
    no->arestas.push_back(aresta);

    if(!this->verificaAdjacencia(no))
    {
        if(direcionado)
        {
            nosAdjacentes.push_back(no);
            no->setGrau(no->getGrau()+1);
        }
        else
        {
            if(peso!= 0 )
            {
//                no->setPesoAresta(peso);
                nosAdjacentes.push_back(no);
                no->nosAdjacentes.push_back(this);

            }
            else
            {
                nosAdjacentes.push_back(no);
                no->nosAdjacentes.push_back(this);
            }
        }
        //cout << "No " << no->id << " adicionado as adjacencias do no " << this->id << "!" << endl;
        this->setGrau(this->getGrau()+1);
        no->setGrau(no->getGrau()+1);
        return aresta;
    }
    else
    {
        //cout << "Este no ja eh adjacente!" << endl;
        return aresta;
    }

}

void No::adicionaNoAdjacenteSemMsg(No *no, bool direcionado, int peso)
{
    if(!this->verificaAdjacencia(no))
    {
        if(direcionado)
        {
            nosAdjacentes.push_back(no);
            no->setGrau(no->getGrau()+1);
        }
        else
        {
            if(peso!= 0 )
            {
                //no->setPesoAresta(peso);
                nosAdjacentes.push_back(no);
                no->nosAdjacentes.push_back(this);

            }
            else
            {
                nosAdjacentes.push_back(no);
                no->nosAdjacentes.push_back(this);
            }
        }
    }
    else
    {
        return;
    }

}

void No::printAdjacentes()
{
    cout << "Nos adjacentes ao no " << this->id << ": ";
    for(adjacente : nosAdjacentes)
    {
        cout << adjacente->id << " ";
    }
    cout << endl;
}

void No::removeAdjacente(No* adjacente)
{
    if(!verificaAdjacencia(adjacente))
    {
        cout << "Este no nao eh adjacente!" << endl;
        return;
    }
    for(int i = 0; i < nosAdjacentes.size(); i++)
    {
        if(nosAdjacentes[i] == adjacente)
            nosAdjacentes.erase(nosAdjacentes.begin() + i);
        //cout << "O no " << adjacente->id << " nao eh mais adjacente ao no " << this->id << "!" << endl;
        this->setGrau(this->getGrau()-1);
        return;
    }
}

void No::removeAdjacenteSemMsg(No* adjacente)
{
    if(!verificaAdjacencia(adjacente))
    {

        return;
    }
    for(int i = 0; i < nosAdjacentes.size(); i++)
    {
        if(nosAdjacentes[i] == adjacente)
            nosAdjacentes.erase(nosAdjacentes.begin() + i);

        return;
    }
}
