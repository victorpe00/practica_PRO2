/** @file cjt_especies.hh
    @brief Especificació de la classe cjt_especies
*/

#ifndef _CJT_ESPECIES_HH
#define _CJT_ESPECIES_HH

#include "especie.hh"
#include "taula_distancies.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <vector>
using namespace std;
#endif


/** @class cjt_especies
    
    @brief Representa un conjunt de especies.
 */
class cjt_especies {

private:

    map<string, especie> cjt_esp; //conjunt d'especies string = id  
    taula_distancies t_esp; //Taula distancies del cjt_especies.
    
public:

    //CONSTRUCTORES I DESTRUCTORES

    /** @brief Constructora per defecte.
    
        \pre <em>Cert.</em>
        \post Crea un conjunt d'especies buit;
    */
    cjt_especies();


    /** @brief Destructora,esborra automaticament els objectes locals en sortir d'un ambit de visibilitat.*/
    ~cjt_especies();


    //CONSULTORES

    /** @brief Retorna el gen de asociat a la especie.
     
        \pre <em>Cert.</em>
        \post Retorna el gen asociat a la especie amb identificador = id que es troba a cjt_especies.
    */ 
    string obtener_gen(const string& id) const;

    /** @brief Retorna cert si existeix una especie amb la id que passem al parametre implicit.Retorna fals en qualsevol altre cas.

        \pre <em>Cert.</em>
        \post Retorna cert si hi ha una especie amb identificador = id al conjunt d'especies. Retorna fals en qualsevol altre cas.
    */
    bool existe_especie(const string& id);

    /** @brief Retorna true si el parametre implicit esta buit.
     
        \pre <em>Cert.</em>
        \post Retorna cert si el parametre implicit es un conjunt buit. Fals altrament.
    */
    bool buit() const;

    /** @brief Retorna l'especie amb identificador = id.
        \pre <em>Existeix una especie al parametre impliciat que te com a identificador = id.</em>
        \post Retorna l'especie amb identificador = id que es troba al parametre implicit.
    */
    especie consultar_especie(const string& id);

    /** @brief Retorna  la distancia entre les especies del cjt_espceies amb id1 i id2.Si no pertanyen al cjt_especies retorna false.
     
        \pre <em> els parametres id1 i id2 pertanyen a una especie al parametre implicit.</em>
        \post Retorna la distancia entre les especies del cjt_especies amb id1 i id2. Si les especies amb id1 i id2 retorna false.
    */
    double distancia_esp(const string& id1, const string& id2) const;

    void ids_clusters(vector<string>& ids);

    void consultar_taula(taula_distancies& taula);

    //MODIFICADORES
    
    /** @brief Crea una especie amb d'id i el gen donats i l'afegeix al cjt_especies.

        \pre <em>Cert.</em>
        \post Crea una especie i l'afegeix al parametre implicit.
    */
    void crea_especie(const string& id,string& gen, int k); //Treballem sobre el parametre implicit.


    /** @brief Elimina una especie del conjunt d'especies

        \pre <em>Cert.</em>
        \post si al cjt_especies hi ha una especie amb identifiador = id, s'eslimina del parametre imnplicit. Si no hi es,imprimeix un missatge d'error</em>
    */
    void elimina_especie(const string& id); //Treballem sobre el parametre implicit.


    //LECTRURA I ESCRIPTURA

    /** @brief Imprimeix la taula de distancies del parametre implicit.

        \pre <em>Cert.</em>
        \post Escriu la taula de distancies del parametre implicit.
    */
    void imprime_t_cesp() const;
    

    /** @brief Operacio d'escriptura

        \pre <em>El parametre implicit no esta buit.</em>
        \post Escriu el contingut del parametre implicit pel canal estandard de sortida.
    */
    void imprime_cjt_especies();

    /** @brief Operacio de lectura

        \pre <em>Cert.</em>
        \post Llegeix pel canal estandard una sequencia de n especies diferents entre si i les afegeix al conjunt esp.
    */
    void lee_cjt_especies(int n,int k); 

};
#endif