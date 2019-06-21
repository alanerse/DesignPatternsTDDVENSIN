/*!
 * \file flow.h
 * Arquivo contendo a Declaração da Interface Flow
 */

#ifndef FLOW_H
#define FLOW_H
#include "stock.hpp"

/*!
 * \class Flow
 * \brief Classe para simular os fluxos existentes dentro do sistema
 */

class Flow
{
public:


    /*!
     * \brief Método que retorna o estoque de origem do fluxo
    */
    virtual Stock* getSource()=0;

    /*!
     * \brief Método que retorna o estoque de destino do fluxo
    */
    virtual Stock* getTarget()=0;

    /*!
     * \brief Método que retorna o nome atribuido ao fluxo
    */
    virtual string getName()=0;

    /*!
     * \brief Método para setar o estoque de origem do fluxo
     * \param Stock Objeto representando um estoque existente no sistema
    */
    virtual void setSource(Stock*)=0;

    /*!
     * \brief Método para setar o estoque de destino do fluxo
     * \param Stock Objeto representando um estoque existente no sistema
     */
    virtual void setTarget(Stock*)=0;

    /*!
     * \brief Método para atribuir um nome ao fluxo.
     * \param string Nome para atribuição
     */
    virtual void setName(string)=0;

    /*!
     * \brief Destrutor da classe Flow
    */
    virtual ~Flow(){}

    /*!
     * \brief Função que executa a operação do fluxo dado os estoques
    */
    virtual double test()=0;

    //virtual Flow &operator=(Flow &flow)=0;
};


#endif // FLOW_H
