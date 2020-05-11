/** @file taula_distancies.hh
    @brief Especificació de la clase taula_distancies.
*/

#ifndef _TAULA_DISTANCIES_HH
#define _TAULA_DISTANCIES_HH

using namespace std;

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

/** @class taula_distancies
    @brief Classe per calcular les  distancies i taules de distancia.
*/
class taula_distancies{

private: 

    map<pair<string,string>,double> t_dist; 

public:
    //CONSTRUCTORES I DESTRUCTORES
    
    /** @brief Constructora per defecte.
    
        \pre <em>Cert.</em>
        \post Crea una taula de distancies buida;
    */
    taula_distancies();

    /** @brief Destructora,esborra automaticament els objectes locals en sortir d'un ambit de visibilitat.*/
    ~taula_distancies();



    //MODIFICADORES
    
    /** @brief Afegeix una distancia entre dos clusters/especies.
     
        \pre <em>Distancia no buida > 0</em>
        \post Afegeix al parametre implicit la distancia entre els cjt_especies/cjt_clusters.
    */
    void afegir_distancia(const string& id1,const string& id2,const double& dist); //Afegir distancia entre dos clusters/cjt_especies.

     /** @brief Elimina una distancia entre dos clusters/especies.
     
        \pre <em>Existeixen al parametre implicit una especie amb id1 i una altra amb id2 </em>
        \post Elimina del parametre implicit la distancia entre els cjt_especies/cjt_clusters.
    */
    void eliminar_distancia(const string& id1,const string& id2);


    /** @brief Elimina el cjt_cluster amb id1 i id2 del parametre implicit.
     
        \pre <em>id1 i id2 pertanyen a un cjt_cluster del parametre implicit.</em>
        \post ELimina del parametre implicit el cjt_cluster amb id1 i id2.
    */
    void eliminar_cluster(string& id1,string& id2); //Elimina la distancia de la taula de distancies del cjt_cluster amb id1 i id2.

    void neteja();

    void taula_dist();
    //ESCRIPTURA

    /** @brief Imprimeix la taula de distancies.

        \pre <em>taula de distancies no buida</em>
        \post Imprimeix la taula de distancies del parametre implicit
    */
    void imprimir_t_dist(string id) const;

};
#endif