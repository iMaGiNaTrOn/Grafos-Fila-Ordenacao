// Código com a classe lista, onde recebera o inicio, fim e tamanho dela. Foi implementado apenas as funções qu euma fila precisa, como append no fim e remover no inicio
#ifndef LISTA_HPP
#define LISTA_HPP
#include "node.hpp"
template <typename TipoInfo>

class Lista
{
private:
    Node<TipoInfo> *inicio;
    Node<TipoInfo> *fim;
    int tamanho;

public:
    // construtor e destruidor
    Lista();
    ~Lista();
    // get
    Node<TipoInfo> *getInicio();
    Node<TipoInfo> *getFim();
    int getTamanho();
    // set
    void setInicio(Node<TipoInfo> *inicio);
    void setFim(Node<TipoInfo> *fim);
    void setTamanho(int tamanho);
    // funções
    void append(TipoInfo dados);
    TipoInfo removeFirst();
    void showList();
};
// construtor
template <typename TipoInfo>
Lista<TipoInfo>::Lista()
{
    inicio = nullptr;
    fim = nullptr;
    tamanho = 0;
}
// destruidor
template <typename TipoInfo>
Lista<TipoInfo>::~Lista()
{
    inicio = nullptr;
    fim = nullptr;
}
// get
template <typename TipoInfo>
Node<TipoInfo> *Lista<TipoInfo>::getInicio()
{
    return inicio;
}
template <typename TipoInfo>
Node<TipoInfo> *Lista<TipoInfo>::getFim()
{
    return fim;
}
template <typename TipoInfo>
int Lista<TipoInfo>::getTamanho()
{
    return tamanho;
}
// set
template <typename TipoInfo>
void Lista<TipoInfo>::setInicio(Node<TipoInfo> *inicio)
{
    this->inicio = inicio;
}
template <typename TipoInfo>
void Lista<TipoInfo>::setFim(Node<TipoInfo> *fim)
{
    this->fim = fim;
}
template <typename TipoInfo>
void Lista<TipoInfo>::setTamanho(int tamanho)
{
    this->tamanho = tamanho;
}
// funções
// adiciona no final
template <typename TipoInfo>
void Lista<TipoInfo>::append(TipoInfo dado)
{
    Node<TipoInfo> *node = new Node<TipoInfo>();
    node->setDados(dado);
    node->setProximo(nullptr);
    if (tamanho == 0)
    {
        inicio = node;
        fim = node;
    }
    else
    {
        fim->setProximo(node);
        fim = node;
    }
    tamanho++;
}
// remove o primeiro
template <typename TipoInfo>
TipoInfo Lista<TipoInfo>::removeFirst()
{
    Node<TipoInfo> *node;
    TipoInfo aux;
    if (tamanho == 0)
    {
        std::cout << "Lista vazia" << std::endl;
        return (TipoInfo(0));
    }
    else if (tamanho == 1)
    {
        node = inicio;
        aux = inicio->getDados();
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
        delete node;
    }
    else if (tamanho > 1)
    {
        node = inicio;
        aux = inicio->getDados();
        inicio = inicio->getProximo();
        tamanho--;
        delete node;
    }

    return aux;
}
// mostra lista
template <typename TipoInfo>
void Lista<TipoInfo>::showList()
{
    Node<TipoInfo> *node = inicio;
    if (tamanho == 0)
    {
        std::cout << "FILA VAZIA!!";
    }
    else
    {
        std::cout << "===============FILA===============" << std::endl;
        for (int i = 0; i < tamanho; i++)
        {
            std::cout << node->getDados() << std::endl;
            node = node->getProximo();
        }
        std::cout << "===================================" << std::endl;
    }
}
#endif