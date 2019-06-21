#include "stockimp.hpp"

/*!
 * \file stockimp.cpp
 * Arquivo contendo a implementação dos métodos de StockImp
 */

/*!
 * \brief Construtor
 */
StockImp::StockImp(double value, string name) {

    this->value = value;
    this->name = name;

}

/*StockImp::StockImp(Stock &stock){

    if(this != &stock){

        name = stock.getName();
        value = stock.getValue();
    }
}*/
/*!
 * \brief Destrutor
 */
StockImp::~StockImp(){
}

/*StockImp& StockHandle::operator=(Stock &sto) {
    if(this != &sto){

        name = sto.getName();
        value = sto.getValue();
    }
    return *this;
}*/

void StockImp::setValue(double value)
{
    this->value = value;

}


void StockImp::setName(string name) {

    this->name = name;

}


double StockImp::getValue() {

    return this->value;

}

string StockImp::getName() {

    return this->name;

}

