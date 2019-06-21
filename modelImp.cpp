/*!
 * \file modelImp.cpp
 * Arquivo contendo a implementação dos métodos de ModelImp
 */

#include "modelimp.hpp"
#include "flowimp.hpp"
#include "stockimp.hpp"
#include "flowstypes.hpp"
#include <iostream>

vector<Model*> ModelHandle::models;

Model* ModelImp::newModel(){

    ModelHandle* p = new ModelHandle();

    ModelHandle::models.push_back(p);

    return p;

}

void ModelImp::add(Stock* stock){

   ModelImp::stock.push_back(stock);

}

void ModelImp::add(Flow* flow){

    ModelImp::flow.push_back(flow);

}

void ModelImp::add(Model* model){

   ModelHandle::models.push_back(model);

}

ModelImp::ModelImp(vector<Flow*>flows){

    this->flow = flows;
}

/*ModelImp::ModelImp(Model &model){

    if(this!=&model){

        name = model.getName();
        flow.clear();
        stock.clear();

        for(int i=0; i< model.getsizeFlow();i++){

            Flow *flow = dynamic_cast<FlowExponential*>(model.getFlowPos(i));
            if(flow != NULL){
                Flow *exp  = new FlowExponential();
                *exp = *flow;
                setFlows(exp);

            }
            else{
                Flow *flow = dynamic_cast<FlowLogistic*>(model.getFlowPos(i));
                if(flow != NULL){
                    Flow *logi  = new FlowLogistic();
                    *logi = *flow;
                    setFlows(logi);
                }
            }


        }
        for(int i=0; i< model.getsizeStock();i++){

            Stock *Q3 = new StockImp(*model.getStockPos(i));
            this->setStocks(Q3);
        }
    }

}
*/
ModelImp::ModelImp(){}

ModelImp::~ModelImp()
{

    for(auto it = this->getBeginFlow(); it!=this->getEndFlow(); it++){
        delete *it;
    }

    flow.clear();

    for(auto it = this->getBeginStock(); it!=this->getEndStock(); it++){
        delete *(it);
    }

    stock.clear();

    for(auto it = this->getBeginModel(); it!=this->getEndModel(); it++){

        delete *(it);
    }

    ModelHandle::models.clear();

}

void ModelImp::execute(int iniTime, int finTime)
{
    Stock *source,*target;
    Flow *aux;
    double v[50];

    for (int i = iniTime; i < finTime; i++) {


        for (int j = 0; j < flow.size(); j++) {
            aux = this->flow[j];
            v[j] = aux->test();

        }

        for (int j = 0; j < flow.size(); j++) {
            source = this->flow[j]->getSource();
            target = this->flow[j]->getTarget();
            source->setValue(source->getValue() - v[j]);
            target->setValue(target->getValue() + v[j]);
        }




    }
}

void ModelImp::setName(string name){

    this->name=name;

}

void ModelImp::setStocks(Stock* stock){

    this->stock.push_back(stock);
}

void ModelImp::setFlows(Flow* flow){

    this->flow.push_back(flow);

}

Flow* ModelImp::getFlowPos(int i){
    return this->flow[i];

}

Stock* ModelImp::getStockPos(int i){
    return this->stock[i];
}

string ModelImp::getName(){
    return this->name;
}

int ModelImp::getsizeFlow(){
    return flow.size();
}

int ModelImp::getsizeStock(){
    return stock.size();
}

/*ModelImp& ModelImp::operator=(Model &model){

    if(this!=&model){

        name = model.getName();
        flow.clear();
        stock.clear();

        for(int i=0; i< model.getsizeFlow();i++){

            Flow *flow = dynamic_cast<FlowExponential*>(model.getFlowPos(i));
            if(flow != NULL){
                Flow *exp  = new FlowExponential();
                *exp = *flow;
                this->setFlows(exp);

            }
            else{
                Flow *flow = dynamic_cast<FlowLogistic*>(model.getFlowPos(i));
                if(flow != NULL){
                    Flow *logi  = new FlowLogistic();
                    *logi = *flow;
                    setFlows(logi);
                }
            }


        }
        for(int i=0; i< model.getsizeStock();i++){

            Stock *stock = new StockImp(*model.getStockPos(i));
            this->setStocks(stock);
        }
    }

    return *this;
}*/

Model* Model::newModel(){

    return ModelImp::newModel();

}

Stock* ModelImp::newStock(double value, string name){

    Stock *stock = new StockHandle();
    stock->setName(name);
    stock->setValue(value);
    this->add(stock);

    return stock;

}

Model::itFlow ModelImp::getBeginFlow(){ return this->flow.begin(); }
Model::itFlow ModelImp::getEndFlow(){ return this->flow.end(); }

Model::itStock ModelImp::getBeginStock(){ return this->stock.begin(); }
Model::itStock ModelImp::getEndStock(){ return this->stock.end(); }

Model::itModel ModelImp::getBeginModel(){ return ModelHandle::models.begin(); }
Model::itModel ModelImp::getEndModel(){ return ModelHandle::models.end(); }

/*Flow* ModelImp::newFlow(){

    Flow *flow = new FlowImp();
    this->add(flow);

    return flow;


}*/
