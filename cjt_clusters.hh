/** @file cjt_clusters.hh
    @brief Especificació de la classe cjt_clusters
*/

#ifndef _CJT_CLUSTERS_HH_
#define _CJT_CLUSTERS_HH_

#include "cluster.hh"


#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class cjt_clusters
    @brief Representa un coinjunt de clusters. 
*/
class cjt_clusters{

private:
    map<string,cluster> cjt_clust;
    taula_distancies t_clust; //Taula distancia c_clust.
public:

    //CONSTRUCTORES I DESTRUCTORES

    /** @brief Constructora per defecte.
 
       \pre <em>Cert.</em>
       \post El resultat es un cjt_clusters buit.
    */
    cjt_clusters();

    /** @brief Destructora,esborra automaticament els objectes locals en sortir d'un ambit de visibilitat.*/
    ~cjt_clusters();


    //MODIFICADORES

    /** @brief Inicialitza el conjunt de clusters i imprimeix els clusters resultants,aixi com la taula de distancies entre aquests.

        \pre <em>cjt_espscies no buit.</em>
        \post imprimeix els clusters resultamts aixi com la taula de distancies d'aquests.
    */
    void inicialitza_clusters(cjt_especies& esp); //Treballem sobre el parametre implicit

    /** @brief Executa un pas del algoritme wpgma e imprimeix la taula de disancies entre els clusters resultants.

        \pre <em>cjt_clusters no buit.</em>
        \post imprimeix la taula de distancies reultant despres d'aplicar l'algoritme WPGMA.
    */
    void ejecuta_paso_wpgma();


    //CONSULTORES

    /** @brief Funció per saber si un cluster es troba al conjunt de clusters o no.

        \pre <em>Cert.</em>
        \post Retorna cert, si el cluster amb l'id passat per referencia es troba al cjt_clusters.Retorna false altrament.
    */
    bool existe_cluster(const string& id_clust) const;

    /** @brief Retorna true si el parametre implicit esta buit.
     
        \pre <em>Cert.</em>
        \post Retorna cert si el parametre implicit es un conjunt buit.Fals altrament.
    */
    bool cjt_clust_buit();

    /** @brief Retorna true si el parametre implicit nomes hi ha un cluster.
     
        \pre <em>Cert.</em>
        \post Retorna cert si el parametre implicit es un conjunt buit.Fals altrament.
    */
    bool cjt_clust_unic();


    //ESCRIPTURA

    /** @brief Imprimeix el cluster amb l'identificador donat, si existerix al cjt_cluster . Si no imprimeix un missatge de error.

        \pre <em>Cert.</em>
        \post si al cjt_cluster hi ha un cluster amb identifiador = id, s'imprimeix . Si no hi es imprimeix un missatge d'error</em>
    */
    void imprime_cluster(const string& id_clust);

    /** @brief Imprimeix l'arbre filogenetic pel conjunt d'especies actual.El contingut previ del conjunt de clusters s'esborra.

        \pre <em>Parametre implicit no buit.</em>
        \post S'imprimeix l'estructura arborescent del clusters amb id = node , la distancia entre cada cluster i les seves fulles.
    */
    void imprime_arbol_filogenetico();

};
#endif