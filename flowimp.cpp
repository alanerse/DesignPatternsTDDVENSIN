/*!
 * \file flowimp.cpp
 * Arquivo contendo a implementação dos métodos de FlowImp
 */

#include "flowimp.hpp"
#include "stockimp.hpp"
#include<iostream>

/*!
 * \brief Construtor
 */

FlowImp::FlowImp(string name, Stock *source, Stock *target)
{
    this->name = name;
    this->source = source;
    this->target = target;

}

/*FlowImp::FlowImp(Flow &flow)
{
    if(this != &flow){

        name = flow.getName();
        source = new StockImp((*flow.getSource()));
        target =  new StockImp((*flow.getTarget()));
    }

}*/

/*!
 * \brief Construtor padrao
 */

FlowImp::FlowImp(){};

string FlowImp::getName(){

    return this->name;

}

Stock * FlowImp::getSource(){
    return this->source;
}

Stock * FlowImp::getTarget(){
    return this->target;
}


FlowImp::~FlowImp(){

}

double FlowImp::test(){ return -1.0; }

void FlowImp::setSource(Stock* source){

    this->source=source;

};
void FlowImp::setTarget(Stock* target){

    this->target=target;

};

void FlowImp::setName(string name){

    this->name=name;

};

/*FlowImp& FlowImp::operator=(Flow &flow) {
    if(this != &flow){
        name = flow.getName();
        source = new StockImp((*flow.getSource()));
        target =  new StockImp((*flow.getTarget()));
    }
    return *this;
}*/
