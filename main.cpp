/*!
 * \file main.cpp
 * Arquivo contendo a main e as chamadas dos testes
 */

#include <QCoreApplication>
#include "testes.hpp"
//#include "flow.hpp"
#include "model.hpp"
//#include "stock.hpp"

int main(int argc, char *argv[])
{

    //testCase1();
    cout <<"Passou primerio\n"<<endl;
    //testCase2();
    cout <<"Passou segundo\n"<<endl;
    //testCase3();
    cout <<"Passou terceiro\n"<<endl;

    //unitTest1();
    cout <<"Passou primerio unitario\n"<<endl;
    //unitTest2();
    cout <<"Passou segundo unitario\n"<<endl;

    //testCase4();
    cout <<"Passou quarto\n"<<endl;

    //testCase5();
    cout <<"Passou quinto\n"<<endl;

    testCase6();
    cout <<"Passou sexto\n"<<endl;

    testCase7();
    cout <<"Passou setimo\n"<<endl;

    return 0;
    //QCoreApplication a(argc, argv);
    //return a.exec();
}
