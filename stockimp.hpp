/*!
 * \file stockimp.hpp
 * Arquivo contendo a Declaração da Interface NetworkManager
 */

#ifndef STOCKIMP_HPP
#define STOCKIMP_HPP

#include<string.h>
#include "stock.hpp"
#include "handlebody.hpp"
using namespace std;

/*class StockBody{

    private:

    int refCount;
    double value;
    string name;

    StockBody(const StockBody&);
    StockBody& operator=(const StockBody&){ return *this; }

    public:

    StockBody(): refCount(0){}
    void attach(){refCount++;}
    void detach(){

        if(--refCount == 0)
            delete this;
    }

    int refCountVal(){ return refCount;}
    virtual ~StockBody();

    StockBody(string n,double v):name(n), value(v), refCount(0){}

    void setValue(double value);
    void setName(string name);
    double getValue();
    string getName();

};*/

/*!
 * \class StockImp
 * \brief Implementação dos métodos de StockHandle
 */
class StockImp:public Body{

private:
    double value;
    string name;
public:
    StockImp(){}
    StockImp(double value, string name);
    ~StockImp();
    StockImp(Stock &stock);
    void setValue(double value);
    void setName(string name);
    double getValue();
    string getName();
    //StockImp &operator=(Stock &stock);

};

/*!
 * \class StockHandle
 * \brief Implementação da Interface Stock
 */
class StockHandle:public Stock, public Handle<StockImp>{

public:

    //Stock &operator=(Stock& a){ return Handle<StockImp>::operator=((StockHandle&)a);}
    void setValue(double value){ pImpl_->setValue(value);}
    void setName(string name){ pImpl_->setName(name);}
    double getValue(){ return pImpl_->getValue();}
    string getName(){ return pImpl_->getName();}

};

#endif // STOCKIMP_HPP
