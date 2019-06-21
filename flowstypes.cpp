/*!
 * \file flowstypes.cpp
 * Arquivo contendo a implementação de tipos de fluxos
 */

#include "flowstypes.hpp"

/*!
 * \brief Este método realiza o cálculo da expressão atribuida
 * \return Valor pós equação
 */

double FlowExponential::test(){

    return (0.01*getSource()->getValue());

}

/*!
 * \brief Este método realiza o cálculo da expressão atribuida
 * \return Valor pós equação
 */
double FlowLogistic::test(){

    return 0.01*getTarget()->getValue()*(1 - getTarget()->getValue() / 70);

}
