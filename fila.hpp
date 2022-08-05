// classe fila, que recebe os atributos e funções da nossa classe lista
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
// construtor
template <typename TipoInfo>
Fila<TipoInfo>::Fila()
{
}
// destruidor
template <typename TipoInfo>
Fila<TipoInfo>::~Fila()
{
}
// função de remover
template <typename TipoInfo>
TipoInfo Fila<TipoInfo>::remover()
{
    return Lista<TipoInfo>::removeFirst();
}
// função de enfileirar
template <typename TipoInfo>
void Fila<TipoInfo>::enfileirar(TipoInfo dado)
{
    Lista<TipoInfo>::append(dado);
}
// mostrar fila
template <typename TipoInfo>
void Fila<TipoInfo>::showFila()
{
    Lista<TipoInfo>::showList();
}

#endif