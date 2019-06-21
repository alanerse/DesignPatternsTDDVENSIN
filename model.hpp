/*!
 * \file model.hpp
 * Arquivo contendo a Declaração da Interface Model
 */

#ifndef MODEL_H
#define MODEL_H

#include<vector>
#include "flow.hpp"
#include "flowimp.hpp"
#include "stock.hpp"



class Model
{

protected:

    /*!
     * \brief Método para adicionar um estoque ao modelo
     * \param Stock Objeto para ser inserido
    */
    virtual void add(Stock*)=0;

    /*!
     * \brief Método para adicionar um fluxo ao modelo
     * \param Flow Objeto para ser inserido
    */
    virtual void add(Flow*)=0;

    /*!
     * \brief Método para adicionar um modelo ao conjunto de modelos
     * \param Model Objeto para ser inserido
    */
    virtual void add(Model*)=0;

public:

    /*!
     * \brief Definição do iterador para manipulação do container de Flow
    */
    typedef vector<Flow*>::iterator itFlow;

    /*!
     * \brief Definição do iterador para manipulação do container de Stock
    */
    typedef vector<Stock*>::iterator itStock;

    /*!
     * \brief Definição do iterador para manipulação do container de Models
    */
    typedef vector<Model*>::iterator itModel;

    /*!
     * \brief Destrutor da classe Model
    */
    virtual ~Model(){}

    /*!
     * \brief Método que retorna o início do container de Flow
    */
    virtual itFlow getBeginFlow()=0;

    /*!
     * \brief Método que retorna o fim do container de Flow
    */
    virtual itFlow getEndFlow()=0;

    /*!
     * \brief Método que retorna o início do container de Stock
    */
    virtual itStock getBeginStock()=0;

    /*!
     * \brief Método que retorna o fim do container de Stock
    */
    virtual itStock getEndStock()=0;

    /*!
     * \brief Método que retorna o início do container de Models
    */
    virtual itModel getBeginModel()=0;

    /*!
     * \brief Método que retorna o fim do container de Models
    */
    virtual itModel getEndModel()=0;

    /*!
     * \brief Método que executa a simulação dos estoques e fluxos presentes no modelo
    */
    virtual void execute(int,int)=0;

    /*!
     * \brief Método para atribuir um nome ao modelo
     * \param string Nome a ser atribuido
    */
    virtual void setName(string)=0;

    /*!
     * \brief Método para inserir um estoque no modelo
     * \param Stock Objeto a ser inserido
    */
    virtual void setStocks(Stock*)=0;

    /*!
     * \brief Método para inserir um fluxo ao modelo
     * \param Flow Objeto a ser inserido
    */
    virtual void setFlows(Flow*)=0;

    /*!
     * \brief Método que retorna um fluxo presente no container em uma posição específica
     * \param int Posição desejada no container
    */
    virtual Flow* getFlowPos(int)=0;

    /*!
     * \brief Método que retorna um estoque presente no container em uma posição específica
     * \param int Posição desejada no container
    */
    virtual Stock* getStockPos(int)=0;

    /*!
     * \brief Método que retorna o nome do modelo
    */
    virtual string getName()=0;

    /*!
     * \brief Método que retorna o tamanho do container de Flow
    */
    virtual int getsizeFlow()=0;

    /*!
     * \brief Método que retorna o tamanho do container de Stock
    */
    virtual int getsizeStock()=0;

    //virtual Model &operator=(Model &)=0;

    /*!
     * \brief Método estático que instancia a fábrica de objetos
    */
    static Model* newModel();

    /*!
     * \brief Método para a criação de um novo Stock
     * \param double Valor do estoque
     * \param string Nome do estoque
    */
    virtual Stock* newStock(double,string)=0;

    /*!
     * \brief Método para a criação de um novo fluxo
    */
    template<typename FLOW_TYPE>
    Flow* newFlow(){

        Flow* f = new FlowHandle<FLOW_TYPE>();

        add(f);

        return f;

    }

};

#endif // MODEL_H
