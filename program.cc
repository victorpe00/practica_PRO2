#ifndef NO_DIAGRAM
#include <iostream>
#endif

#include "cjt_clusters.hh"

/** @mainpage Pràctica PRO2: Entrega de l'especificació

La documentació inclou l'especificació dels membres públics de totes les classes que componen el programa de la pràctica de PRO2.
*/

/** @file program.cc
    @brief Programa principal de la pràctica
*/

/** @brief Programa principal de la pràctica
*/
int main(){
    cjt_especies c_esp;
    cjt_clusters c_clust;
    int k;
    string s;
    cin >> k >> s; //No llegeixo dins del blucle per a que el programa no s'aturi en pulsar ctrl+l a la consola.
    while (s != "fin"){
        if (s == "crea_especie"){ //crea_especie
            string id,gen;
            cin >> id >> gen;
            cout << "# crea_especie " << id << " " << gen << endl;
            if (not c_esp.existe_especie(id)){
                c_esp.crea_especie(id,gen,k);
            }
            else cout <<"ERROR: La especie " << id <<" ya existe." << endl;
            cout << endl;
        }
        else if (s == "obtener_gen"){ //obtener_gen d'una especie inclosa a un cjt_especies
            string id;
            cin >> id;
            cout << "# obtener_gen " << id << endl; 
            if (c_esp.existe_especie(id)) cout << c_esp.obtener_gen(id) << endl;
            else cout << "ERROR: La especie " << id <<" no existe." << endl;
            cout << endl;
        }
        else if (s == "distancia"){ //distancia entre cjt_especies.
            string id1,id2;
            cin >> id1 >> id2;
            cout << "# distancia " << id1 << " " << id2 << endl;
            if (c_esp.existe_especie(id1) and c_esp.existe_especie(id2)) cout << c_esp.distancia_esp(id1,id2) << endl;
            else{
                if(not c_esp.existe_especie(id1) and not c_esp.existe_especie(id2)){
                     cout <<"ERROR: La especie " << id1 <<" y la especie "<< id2 << " no existen." << endl;
                }
                else if(not c_esp.existe_especie(id1)) cout <<"ERROR: La especie " << id1 << " no existe." << endl;
                else cout <<"ERROR: La especie " << id2 << " no existe." << endl; 
            }
            cout << endl; 
        }
        else if (s == "elimina_especie"){ //elimina d'especie amb id del parametre implicit si existeix.
            string id;
            cin >> id;
            cout << "# elimina_especie " << id << endl;
            if (c_esp.existe_especie(id)) c_esp.elimina_especie(id);
            else cout << "ERROR: La especie " << id << " no existe." << endl;
            cout << endl;
        }
        else if (s == "existe_especie"){ //Imprimeix cert si existeix una especie amb id al parametre implicit.
            string id;
            cin >> id;
            cout << "# existe_especie " << id << endl;
            if (c_esp.existe_especie(id)) cout <<"SI" << endl;
            else cout << "NO" << endl;
            cout << endl;
        }
        else if (s == "lee_cjt_especies"){ //llegeix pel canal estandard n especies i les afegeix al parametre implicit
            int n;
            cin >> n;
            cout << "# lee_cjt_especies" << endl;
            c_esp.lee_cjt_especies(n,k);
            cout << endl;
        }
        else if (s == "imprime_cjt_especies"){ //imprimeix el conjunt d'especies
            cout << "# imprime_cjt_especies" << endl;
            if (not c_esp.buit()) c_esp.imprime_cjt_especies();
            cout << endl;
        }
        else if (s == "tabla_distancias"){ //Imprimeix la taula de distancies entre cada parell d'especies del parametre implicit.
            cout << "# tabla_distancias" << endl;
            c_esp.imprime_t_cesp();
            cout << endl;
        }


        else if (s == "inicializa_clusters"){ //Inicialitza el conjunt de clusters
            cout << "# inicializa_clusters" << endl;
            c_clust.inicialitza_clusters(c_esp);
            cout << endl;
        }
        else if (s == "ejecuta_paso_wpgma"){ //Executa el pas wpgma 
            if (not c_clust.cjt_clust_buit()) c_clust.ejecuta_paso_wpgma();
            else cout << "El parametre implicit es un conjunt buit." << endl;
            cout << endl;
        }
        else if (s == "imprime_cluster"){ // Imprimeix l'estructura arborescent del cluster amb identificador = id del parametre implicit.
            string id;
            cin >> id;
            cout << "# imprime_cluster " << id << endl; 
            if (not c_clust.cjt_clust_buit() and c_clust.existe_cluster(id)) c_clust.imprime_cluster(id);
            else cout << "ERROR: El cluster " << id << " no existe." << endl;
            cout << endl;
        }
        else if (s == "imprime_arbol_filogenetico"){ //Imprimeix l'arbre filogenetic del parametre implicit.
            if (not c_clust.cjt_clust_buit()) c_clust.imprime_arbol_filogenetico();
            else cout << "parametre implicit buit" << endl;
            cout << endl;
        }
        cin >> s;
    }
}