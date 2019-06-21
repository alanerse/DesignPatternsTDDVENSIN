#include "stockimp.hpp"

StockImp::StockImp(float value, string name) {

    this->value = value;
    this->name = name;

}

StockImp::~StockImp()
{
}

void StockImp::setValue(float value)
{
    this->value = value;

}


void StockImp::setName(string name) {

    this->name = name;

}


float StockImp::getValue() {

    return this->value;

}

string StockImp::getName() {

    return this->name;

}

