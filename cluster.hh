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

    BinTree<pair<string,double>> clust_tree; 

public:
    //CONSTRUCTORES

    /** @brief Constructora per defecte.

        \pre <em>Cert.</em>
        \post El resultat es un cluster sense especies.
    */
    cluster();
    
    /** @brief Constructora copiadora.
        \pre <em>Cert.</em>
        \post El reesultat es un cluster amb un clust_tree = tree
    */
    cluster(const BinTree<pair<string,double>>& tree);

    /** @brief Destructora,esborra automaticament els objectes locals en sortir d'un ambit de visibilitat.*/
    ~cluster();
    

    /** @brief Metode de cració d'un cluster.

       \pre <em>Cert.</em>
       \post Crea un cluster.
    */
    void consultar_clust_dist() const;

    /** @brief Metode que retorna cert si el parametre implicit es una fulla
     *  \pre <em>Parametre implicit
    */
    bool clust_unic();

    //LECTURA I ESCRIPTURA

    /** @brief Metode de cració d'un cluster.

       \pre <em>Cert.</em>
       \post Crea un cluster.
    */
    void inici_clust(const string& id);

    /** @brief Metode d'escriptura d'un cluster no unic.

       \pre <em>Parametre implicit no buit.</em>
       \post Imprimeix pel canal estandard de sortida el parametre implicit.
    */
    void escriure_clust();
    
    /** @brief Metode d'escriptura d'un cluster unic.

       \pre <em>Parametre implicit no buit.</em>
       \post Imprimeix pel canal estandard de sortida el parametre implicit.
    
    void escriure_clust_unic();*/
};
#endif