// executar: make run
// Interface do código
#include <iostream>
#include "fila.hpp"

int main()
{
    Fila<int> *fila;        // cria fila
    fila = new Fila<int>(); // inicia
    int num;
    int op;

    while (1)
    {
        std::cout << "\n1 - Enfilerar" << std::endl;
        std::cout << "2 - Remover" << std::endl;
        std::cout << "3 - Mostrar Fila" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cin >> op;

        switch (op)
        {
        case 0:
            exit(0);
        case 1:
            std::cout << "Insira um numero na Fila: " << std::endl;
            std::cin >> num;
            fila->enfileirar(num);
            break;
        case 2:
            std::cout << "Removido : " << fila->remover() << " " << std::endl;
            break;
        case 3:
            fila->showFila();
            break;
        default:
            std::cout << "O número digitado não corresponde a nenhuma opção";
        }
    }
    return 0;
}