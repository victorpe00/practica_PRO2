/** @file cluster.hh
    @brief Especificació de la classe cluster
*/

#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_


#include "cjt_especies.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/** @class cluster
    @brief Representa una cluster de especies. 
*/
class cluster{

private:

    BinTree<string> clust_tree; 

public:
    //CONSTRUCTORES

    /** @brief Constructora per defecte.

        \pre <em>Cert.</em>
        \post El resultat es un cluster sense especies.
    */
    cluster();

    /** @brief Destructora,esborra automaticament els objectes locals en sortir d'un ambit de visibilitat.*/
    ~cluster();
    
    //CONSTRUCTORES

    /** @brief Metode de cració d'un cluster.

       \pre <em>Cert.</em>
       \post Crea un cluster.
    */
    void consultar_clust_dist() const;

    //LECTURA I ESCRIPTURA

    /** @brief Metode de cració d'un cluster.

       \pre <em>Cert.</em>
       \post Crea un cluster.
    */
    void inicialitzar_clust(string& id) const;

    /** @brief Metode d'escriptura d'un cluster.

       \pre <em>Parametre implicit no buit.</em>
       \post Imprimeix pel canal estandard de sortida el parametre implicit.
    */
    void escriure_clust() const;
    
};
#endif