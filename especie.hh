/** @file especie.hh
    @brief Especificación de la clase especie
*/

#ifndef _ESPECIE_HH
#define _ESPECIE_HH

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#include <string>
using namespace std;
#endif

/** @class especie
    @brief Representa una especie.

    Cada especie consta d'un identificador i d'un string de gens
*/


class especie {
private:

    string gen; // gen sense modificar (no kmer)
    map<string,int> kgen; //numero d'aparicions del kgen i gen ja separat en k essims

    /** @brief Metode que calcula els kmers del kgen i l'afegeix al parametre implicit.

        \pre <em>k > 0</em>
        \post Calcula el kgen i l'afegeix al parametre implicit.
    */
     void generar_kgen(int k); //Metode privat opcional

public:

    //CONSTRUCTORA

    /** @brief Constructora per defecte.

        \pre <em>Cert.</em>
        \post El resultat es una espacie sense identificador.
    */
    especie();

    /** @brief Constructora copiadora.

        \pre <em>gen no buit.</em>
        \post El resultat es una especie gen = gen
    */
    especie(string& gen);

    /** @brief Destructora,esborra automaticament els objectes locals en sortir d'un ambit de visibilitat*/
    ~especie();

    //MODIFICADORES

    /** @brief Afegeix el gen a una especie buida.

        \pre <em>el parametre implicit no te gen.I "gen" no buit</em>
        \post el gen del parametre implicit passa a ser el "gen"
    */
    void afegir_gen(string& gen, int k);


    //CONSULTORES

    /** @brief Retorna la distancia entre dos especies.

        \pre <em>esp1 i esp2 estan ben definides.</em>
        \post Retorna la distancia entre esp1 i esp2.
    */
    static double dist_esp(const especie& esp1,const especie& esp2);

   /** @brief Metode que consulta el gen del parametre implicit.

       \pre <em>Cert.</em>
       \post Retorna el gen del parametre implicit.
    */
   string consultar_gen() const; //Metode opcional

};
#endif
