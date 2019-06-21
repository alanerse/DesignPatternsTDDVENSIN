/*!
 * \file flowstypes.h
 * Arquivo contendo a Definição da equação a ser utilizada em cada fluxo.
 */

#ifndef FLOWSTYPES_HPP
#define FLOWSTYPES_HPP

#include "flowimp.hpp"


/*!
 * \class FlowExponential
 * \brief Implementação da classe FlowExponential
 */
class FlowExponential :public FlowImp{

    public:

        /*!
        * \brief Contrutor da classe FlowExponential
        */
        FlowExponential(){}

        /*!
         * \brief Método que executa a equação do fluxo
         */
        double test();
};

/*!
 * \class FlowLogistic
 * \brief Implementação da classe FlowLogistic
 */
class FlowLogistic :public FlowImp
{

    public:

        /*!
        * \brief Contrutor da classe FlowExponential
        */
        FlowLogistic(){}

        /*!
        * \brief Método que executa a equação do fluxo
        */
        double test();
};


#endif // FLOWSTYPES_HPP
