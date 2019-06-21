
/*!
 * \file testes.cpp
 * Arquivo contendo a implementação dos testes
 */

#include "stockimp.hpp"
//#include "flowimp.hpp"
#include "modelimp.hpp"
#include "flowstypes.cpp"
#include "testes.hpp"
#include <vector>
#include<iostream>
#include <assert.h>
#include <cmath>

int numHandleCreated;
int numHandleDeleted;
int numBodyCreated;
int numBodyDeleted;

/*void unitTest1(){

    Stock *s1 = new StockImp(100, "s1");
    assert(s1!=NULL);
    assert(s1->getName()=="s1");
    assert(s1->getValue()-100<0.0001);

    vector<Flow*>flow;
    assert(flow.size()==0);

    Flow *exponential = new FlowExponential();
    assert(exponential!=NULL);

    exponential->setName("Exponential");
    exponential->setSource(s1);
    exponential->setTarget(s1);
    assert(exponential->getName()=="Exponential");
    assert(exponential->getSource()==s1);
    assert(exponential->getTarget()==s1);

    flow.push_back(exponential);
    assert(flow.size()>0);

    Model *mod1 = new ModelImp(flow);
    assert(mod1!=NULL);
}
*/

/*void unitTest2(){

    Stock *s1 = new StockImp(100, "s1");
    assert(s1->getName()=="s1");
    Stock *s2 = new StockImp(*s1);

    cout<<"S1: "<<s1<<" S2: "<<s2<<endl;

    assert(s1!=s2);
    assert(s2->getName()=="s1");
    assert(s2->getValue()-100 < 0.0001);

    Stock *s3 = new StockImp(0,"a");

    *s3=*s2;

    cout<<"S3: "<<s3<<" S2: "<<s2<<endl;
    assert(s3!=s2);

    delete (StockImp*)s2;

    assert(s3->getName()=="s1");
    assert(s3->getValue()-100 < 0.0001);
//-------------------------------------------------------------------------------------------------
    Flow *f1 = new FlowExponential();
    f1->setName("Exponential");
    f1->setSource(s1);
    f1->setTarget(s1);

    Flow *f2 = new FlowImp(*f1);

    assert(f2!=f1);
    assert(f2->getName()=="Exponential");

    Flow *f3 = new FlowImp();

    *f3=*f2;
    assert(f3!=f2);

    cout<<"F3: "<<f3<<" F2: "<<f2<<endl;
    delete (FlowImp*)f2;

    assert(f3->getName()=="Exponential");
    assert(f3->getSource()!=s1);
//--------------------------------------------------------------------------------------------
    Model *m1 = new ModelImp();
    m1->setFlows(f2);
    m1->setName("model");
    assert(m1->getName()=="model");
    assert(m1->getFlowPos(0)==f2);

    Model *m2 = new ModelImp(*m1);
    assert(m2->getName()=="model");
    assert(m2!=m1);

    Model *m3 = new ModelImp();

    *m3=*m2;

    cout<<"M3: "<<m3<<" M2: "<<m2<<endl;
    delete (ModelImp*)m2;

    assert(m3->getName()=="model");
    assert(m3!=m2);


}*/

/*void testCase1() {

    Stock *s1 = new StockImp(100, "s1");
    Stock *s2 = new StockImp(0, "s2");

    vector<Flow*>flow;

    Flow *exponential = new FlowExponential();
    exponential->setName("Exponential");
    exponential->setSource(s1);
    exponential->setTarget(s2);
    flow.push_back(exponential);

    Model *mod1 = new ModelImp(flow);

    mod1->execute(0, 100);
    cout << "Valor do stock 1:"<< s1->getValue()<<endl;
    cout << "Valor do stock 2:"<< s2->getValue()<<endl;

    assert((s1->getValue() - 36.6032) < 0.0001);
    assert((s2->getValue() - 63.3968) < 0.0001);

}*/

/*void testCase2() {

    Stock *s1 = new StockImp(100, "s1");
    Stock *s2 = new StockImp(10, "s2");

    vector<Flow*>flow;

    Flow *logistic = new FlowLogistic();
    logistic->setName("Logistic");
    logistic->setSource(s1);
    logistic->setTarget(s2);
    flow.push_back(logistic);

    Model *mod1 = new ModelImp(flow);
    assert(mod1!=NULL);

    mod1->execute(0, 100);
    cout << "Valor Stock 1:" << s1->getValue() << endl;
    cout << "Valor Stock 2:"<< s2->getValue()<<endl;
    assert((s1->getValue() - 88.2167) < 0.0001);
    assert((s2->getValue() - 21.7834) < 0.0001);

}*/

/*void testCase3() {

    Stock *s1 = new StockImp(100, "s1");
    Stock *s2 = new StockImp(0, "s2");
    Stock *s3 = new StockImp(100, "s3");
    Stock *s4 = new StockImp(0, "s4");
    Stock *s5 = new StockImp(0, "s5");

    vector<Flow*> flows;

    Flow *f = new FlowExponential();
    f->setName("G");
    f->setSource(s1);
    f->setTarget(s2);
    flows.push_back(f);

    f = new FlowExponential();
    f->setName("V");
    f->setSource(s4);
    f->setTarget(s1);
    flows.push_back(f);

    f = new FlowExponential();
    f->setName("F");
    f->setSource(s1);
    f->setTarget(s3);
    flows.push_back(f);

    f = new FlowExponential();
    f->setName("R");
    f->setSource(s2);
    f->setTarget(s3);
    flows.push_back(f);

    f = new FlowExponential();
    f->setName("T");
    f->setSource(s2);
    f->setTarget(s5);
    flows.push_back(f);

    f = new FlowExponential();
    f->setName("U");
    f->setSource(s3);
    f->setTarget(s4);
    flows.push_back(f);

    Model *m1 = new ModelImp(flows);

    m1->execute(0, 100);

    cout <<"Valor stock 1: "<< s1->getValue() << endl;
    cout <<"Valor stock 2: "<< s2->getValue() << endl;
    cout <<"Valor stock 3: "<< s3->getValue() << endl;
    cout <<"Valor stock 4: "<< s4->getValue() << endl;

    assert((s1->getValue() - 31.8513) < 0.0001);
    assert((s2->getValue() - 18.4003) < 0.0001);
    assert((s3->getValue() - 77.1143) < 0.0001);
    assert((s4->getValue() - 56.1728) < 0.0001);
    assert((s5->getValue() - 16.4612) < 0.0001);

}*/

/*void testCase4(){

    Stock *s1 = new StockImp(100, "s1");
    Stock *s2 = new StockImp(0, "s2");

    Flow *exponential = new FlowExponential();
    exponential->setName("Exponential");
    exponential->setSource(s1);
    exponential->setTarget(s2);

    Model *mod1 = new ModelImp();
    mod1->setFlows(exponential);
    mod1->setStocks(s1);
    mod1->setStocks(s2);

    Model *test = new ModelImp();

    *test=*mod1;

    test->execute(0, 100);

    cout << "Valor do stock 1:"<< test->getFlowPos(0)->getSource()->getValue()<<endl;
    cout << "Valor do stock 2:"<< test->getFlowPos(0)->getTarget()->getValue()<<endl;

    assert((test->getFlowPos(0)->getSource()->getValue() - 36.6032) < 0.0001);
    assert((test->getFlowPos(0)->getTarget()->getValue() - 63.3968) < 0.0001);

}*/

void testCase5(){

    Model *mod = Model::newModel();

    Model *m1 = mod->newModel();

    Stock *s1 = mod->newStock(100,"s1");
    Stock *s2 = mod->newStock(0,"s2");

    Flow *f1 = mod->newFlow<FlowExponential>();
    f1->setName("Exponential");
    f1->setSource(s1);
    f1->setTarget(s2);

    m1->setStocks(s1);
    m1->setStocks(s2);
    m1->setFlows(f1);

    m1->execute(0,100);

    cout << "Valor do stock 1:"<< s1->getValue() <<endl;
    cout << "Valor do stock 2:"<< s2->getValue() <<endl;

    assert((s1->getValue() - 36.6032) < 0.0001);
    assert((s2->getValue() - 63.3968) < 0.0001);


}

void testCase6(){

    numHandleCreated=0;
    numHandleDeleted=0;
    numBodyCreated=0;
    numBodyDeleted=0;


    Model *mod = Model::newModel();

    Stock *s1 = mod->newStock(100, "s1");
    Stock *s2 = mod->newStock(0, "s2");
    Stock *s3 = mod->newStock(100, "s3");
    Stock *s4 = mod->newStock(0, "s4");
    Stock *s5 = mod->newStock(0, "s5");

    //vector<Flow*> flows;

    Model *m1 = mod->newModel();

    Flow *f = mod->newFlow<FlowExponential>();
    f->setName("G");
    f->setSource(s1);
    f->setTarget(s2);

    m1->setFlows(f);

    f = mod->newFlow<FlowExponential>();
    f->setName("V");
    f->setSource(s4);
    f->setTarget(s1);

    m1->setFlows(f);

    f = mod->newFlow<FlowExponential>();
    f->setName("F");
    f->setSource(s1);
    f->setTarget(s3);

    m1->setFlows(f);

    f = mod->newFlow<FlowExponential>();
    f->setName("R");
    f->setSource(s2);
    f->setTarget(s3);

    m1->setFlows(f);

    f = mod->newFlow<FlowExponential>();
    f->setName("T");
    f->setSource(s2);
    f->setTarget(s5);

    m1->setFlows(f);

    f = mod->newFlow<FlowExponential>();
    f->setName("U");
    f->setSource(s3);
    f->setTarget(s4);

    m1->setFlows(f);


    m1->execute(0, 100);

    cout <<"Valor stock 1: "<< s1->getValue() << endl;
    cout <<"Valor stock 2: "<< s2->getValue() << endl;
    cout <<"Valor stock 3: "<< s3->getValue() << endl;
    cout <<"Valor stock 4: "<< s4->getValue() << endl;

    assert((s1->getValue() - 31.8513) < 0.0001);
    assert((s2->getValue() - 18.4003) < 0.0001);
    assert((s3->getValue() - 77.1143) < 0.0001);
    assert((s4->getValue() - 56.1728) < 0.0001);
    assert((s5->getValue() - 16.4612) < 0.0001);


}

void testCase7(){

    numHandleCreated=0;
    numHandleDeleted=0;
    numBodyCreated=0;
    numBodyDeleted=0;


   // Model* mod = Model::newModel();

    //Stock* s1 = mod->newStock(100,"s1");
    //Stock* s2 = mod->newStock(100,"s2");

    StockHandle* s1 = new StockHandle();
    s1->setName("s1");
    StockHandle* s2 = new StockHandle();
    s2->setName("s2");

    cout << "1 Handle criada: " << numHandleCreated << "  Handle deletada: " << numHandleDeleted << endl;
    cout << "  Body criado: " << numBodyCreated << "  Body deletado: " << numBodyDeleted << endl;

    assert(numHandleCreated==2);
    assert(numBodyCreated==2);

    *s1=*s2;

    cout << "2 Handle criada: " << numHandleCreated << "  Handle deletada: " << numHandleDeleted << endl;
    cout << "  Body criado: " << numBodyCreated << "  Body deletado: " << numBodyDeleted << endl;

    assert(numBodyDeleted==1);

    FlowHandle<FlowExponential>* f1 = new FlowHandle<FlowExponential>();
    f1->setName("primeiro");
    FlowHandle<FlowExponential>* f2 = new FlowHandle<FlowExponential>();
    f2->setName("segundo");

    cout << "3 Handle criada: " << numHandleCreated << "  Handle deletada: " << numHandleDeleted << endl;
    cout << "  Body criado: " << numBodyCreated << "  Body deletado: " << numBodyDeleted << endl;

    assert(numHandleCreated==4);
    assert(numBodyCreated==4);

    *f1=*f2;

    cout << "4 Handle criada: " << numHandleCreated << "  Handle deletada: " << numHandleDeleted << endl;
    cout << "  Body criado: " << numBodyCreated << "  Body deletado: " << numBodyDeleted << endl;

    assert(numBodyDeleted==2);
    assert(f1->getName()==f2->getName());


}
