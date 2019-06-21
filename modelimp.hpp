/*!
 * \file modelimp.hpp
 * Arquivo contendo a Declaração da Classe ModelImp, separada em handle-body
 */

#ifndef MODEL_HPP
#define MODEL_HPP
#include <flowimp.hpp>
#include <stockimp.hpp>
#include <vector>
#include "model.hpp"
#include "handlebody.hpp"
using namespace std;


/*!
 * \class ModelImp
 * \brief Implementação das funções de ModelHandle
 */
class ModelImp:public Body{

    /*!
     * \brief Container dos estoques
     */
    vector<Stock*> stock;

    /*!
     * \brief Container dos fluxos
     */
    vector<Flow*> flow;

    /*!
     * \brief Nome do modelo
     */
    string name;    

public:
    ModelImp(vector<Flow*>flows);
    ModelImp(Model &model);
    ModelImp();
    ~ModelImp();

    Model::itFlow getBeginFlow();
    Model::itFlow getEndFlow();

    Model::itStock getBeginStock();
    Model::itStock getEndStock();

    Model::itModel getBeginModel();
    Model::itModel getEndModel();

    void execute(int,int);
    void setName(string);
    void setStocks(Stock*);
    void setFlows(Flow*);
    Flow* getFlowPos(int);
    Stock* getStockPos(int);
    string getName();
    int getsizeFlow();
    int getsizeStock();

    //ModelImp &operator=(Model &model);

    static Model* newModel();
    Stock* newStock(double,string);
    Flow* newFlow(string,Stock*,Stock*);
    void add(Stock*);
    void add(Flow*);
    void add(Model*);

};


/*!
 * \class ModelHandle
 * \brief Implementação da Interface Model
 */
class ModelHandle:public Model, public Handle<ModelImp>{

public:

    /*!
     * \brief Container de modelos existentes
     */
    static vector<Model*> models;

    void add(Stock* stock){ pImpl_->add(stock);}
    void add(Flow* flow){ pImpl_->add(flow);}
    void add(Model* model){ pImpl_->add(model);}


    itFlow getBeginFlow(){return pImpl_->getBeginFlow();}
    itFlow getEndFlow(){return pImpl_->getEndFlow();}

    itStock getBeginStock(){return pImpl_->getBeginStock();}
    itStock getEndStock(){return pImpl_->getEndStock();}

    itModel getBeginModel(){return pImpl_->getBeginModel();}
    itModel getEndModel(){return pImpl_->getEndModel();}

    void execute(int tIni,int tFin){ pImpl_->execute(tIni,tFin);}
    void setName(string name){ pImpl_->setName(name);}
    void setStocks(Stock* stock){ pImpl_->setStocks(stock);}
    void setFlows(Flow* flow){ pImpl_->setFlows(flow);}
    Flow* getFlowPos(int pos){ pImpl_->getFlowPos(pos);}
    Stock* getStockPos(int pos){ pImpl_->getStockPos(pos);}
    string getName(){ return pImpl_->getName();}
    int getsizeFlow(){ return pImpl_->getsizeFlow();}
    int getsizeStock(){ return pImpl_->getsizeStock();}

    //ModelImp &operator=(Model &model);

    static Model* newModel(){ return newModel();}
    Stock* newStock(double val, string name){ return pImpl_->newStock(val,name);}
    Flow* newFlow(string name, Stock* source, Stock* target){pImpl_->newFlow(name,source,target);}


};
#endif // MODEL_HPP
