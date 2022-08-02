#ifndef NODE_HPP
#define NODE_HPP
template <typename TipoInfo>
class Node
{
private:
    TipoInfo dados;
    Node<TipoInfo> *proximo;

public:
    Node();  // construtor
    ~Node(); // destruidor

    TipoInfo getDados();
    void setDados(TipoInfo dados);
    Node<TipoInfo> *getProximo();
    void setProximo(Node<TipoInfo> *proximo);
};
// construtor
template <typename TipoInfo>
Node<TipoInfo>::Node()
{
    dados = TipoInfo(0);
    proximo = nullptr;
}
// destruidor
template <typename TipoInfo>
Node<TipoInfo>::~Node()
{
    proximo = nullptr;
}
// gets
template <typename TipoInfo>
TipoInfo Node<TipoInfo>::getDados()
{
    return dados;
}
template <typename TipoInfo>
Node<TipoInfo> *Node<TipoInfo>::getProximo()
{
    return proximo;
}
// sets
template <typename TipoInfo>
void Node<TipoInfo>::setDados(TipoInfo dados)
{
    this->dados = dados;
}
template <typename TipoInfo>
void Node<TipoInfo>::setProximo(Node<TipoInfo> *proximo)
{
    this->proximo = proximo;
}
#endif
