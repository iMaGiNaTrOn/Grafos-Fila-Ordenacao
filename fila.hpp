#ifndef FILA_HPP
#define FILA_HPP
#include "lista.hpp"
template <typename TipoInfo>

class Fila : private Lista<TipoInfo>
{
public:
    Fila();
    ~Fila();

    TipoInfo remover();
    void enfileirar(TipoInfo dado);
    void showFila();
};

template <typename TipoInfo>
Fila<TipoInfo>::Fila()
{
}

template <typename TipoInfo>
Fila<TipoInfo>::~Fila()
{
}

template <typename TipoInfo>
TipoInfo Fila<TipoInfo>::remover()
{
    return Lista<TipoInfo>::removeFirst();
}

template <typename TipoInfo>
void Fila<TipoInfo>::enfileirar(TipoInfo dado)
{
    Lista<TipoInfo>::append(dado);
}

template <typename TipoInfo>
void Fila<TipoInfo>::showFila()
{
    Lista<TipoInfo>::showList();
}

#endif