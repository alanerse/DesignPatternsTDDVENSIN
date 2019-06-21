/*!
 * \file stock.hpp
 * Arquivo contendo a Declaração da Interface NetworkManager
 */

#ifndef STOCK_HPP
#define STOCK_HPP
#include<string.h>
#include <iostream>
using namespace std;
class Stock{

public:

    /*!
     * \brief Destrutor da classe Stock
    */
    virtual ~Stock(){}
    //virtual Stock &operator=(Stock&)=0;

    /*!
     * \brief Método para atribuir um valor para o estoque
     * \param double Value, valor a ser atribuido
    */
    virtual void setValue(double value)=0;

    /*!
     * \brief Método para atribuir um nome ao estoque
     * \param string Name
    */
    virtual void setName(string name)=0;

    /*!
     * \brief Método que retorna o valor do estoque
    */
    virtual double getValue()=0;

    /*!
     * \brief Método que retorna o nome do estoque
    */
    virtual string getName()=0;

};

#endif // STOCK_HPP
