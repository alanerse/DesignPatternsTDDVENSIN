/*!
 * \file flowimp.h
 * Arquivo contendo a Declaração da Classe FlowImp, separada em Handle-Body
 */

#ifndef FLOW_HPP
#define FLOW_HPP
#include "flow.hpp"
#include <string.h>
#include <iostream>
#include "handlebody.hpp"
using namespace std;

/*!
 * \class FlowImp
 * \brief Implementação dos métodos de FlowHandle
 */
class FlowImp:public Body{

    string name;
    Stock *source, *target;

public:

    FlowImp(Flow &flow);
    FlowImp();
    FlowImp(string,Stock*,Stock*);
    double test();
    Stock* getSource();
    Stock* getTarget();
    string getName();
    void setSource(Stock*);
    void setTarget(Stock*);
    void setName(string);
    virtual ~FlowImp();

   // FlowImp &operator=(Flow &flow);

};

/*!
 * \class FlowHandle
 * \brief Implementação da Interface Flow
 */
template <class T>
class FlowHandle:public Flow, public Handle<T>{

public:

    FlowHandle() : Handle<T>(){}
    virtual ~FlowHandle(){}

    double test(){return this->pImpl_->test();}
    Stock* getSource(){return this->pImpl_->getSource();}
    Stock* getTarget(){return this->pImpl_->getTarget();}
    string getName(){return this->pImpl_->getName();}
    void setSource(Stock* stock){ this->pImpl_->setSource(stock);}
    void setTarget(Stock* stock){ this->pImpl_->setTarget(stock);}
    void setName(string name){ this->pImpl_->setName(name);}

};

#endif // FLOW_HPP
