#include "cluster.hh"

cluster::cluster(){
    this->clust_tree = BinTree< pair<string,double>>();
}

cluster::cluster(const BinTree<pair<string,double>>& tree){
    this->clust_tree = tree;
}

cluster::~cluster(){}

void cluster::consultar_clust_dist() const{}

void cluster::inici_clust(const string& id){
    pair<string,double> p_aux;
    p_aux.first = id;
    p_aux.second = 0; //No se quina disnatcia posar a la primera iteracio del clust.
    BinTree <pair<string,double>> aux(p_aux);
    clust_tree = aux;
}

bool cluster::clust_unic(){
    if (not clust_tree.empty() and clust_tree.left().empty() and clust_tree.right().empty() ) return true;
    else return false;
}

void cluster::escriure_clust(){
    if(not clust_tree.empty()){

        if (clust_unic()) cout << "[" << clust_tree.value().first << "]" << endl;
        else {//AL EXEMPLE NO HI HA CAP EXEMPLE SENSE EXECUTAR EL WPGMA (NO PROVAT)
            cout << "[(" << clust_tree.value().first <<", "<< clust_tree.value().second << ") ";
            BinTree<pair<string,double>> tree_esq = clust_tree.left();
            cluster esq (tree_esq);
            esq.escriure_clust();
            cout << "] " << "[";
            BinTree<pair<string,double>> tree_dre = clust_tree.right();
            cluster dre (tree_dre);
            dre.escriure_clust();
            cout << "]" << endl;
        }
    }
}