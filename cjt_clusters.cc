#include "cjt_clusters.hh"

cjt_clusters::cjt_clusters(){
    this->cjt_clust = map<string,cluster>();
    this->t_clust = taula_distancies();
}

cjt_clusters::~cjt_clusters(){}

void cjt_clusters::inicialitza_clusters(cjt_especies& esp){
    vector<string> ids;
    esp.ids_clusters(ids);
    for (int i = 0; i < ids.size(); ++i){
        cluster clust;
        clust.inici_clust(ids[i]);
        cjt_clust.insert({ids[i],clust});
    }
    
    //TODO: Falta q la taula dist sigui a del cjt esp
}

void cjt_clusters::ejecuta_paso_wpgma(){
    //TODO
}

bool cjt_clusters::existe_cluster(const string& id_clust) const{//FALTA
    map<string,cluster>::const_iterator it = cjt_clust.begin();
    it = cjt_clust.find(id_clust);
    if (it != cjt_clust.end()) return true;
    return false;
}

bool cjt_clusters::cjt_clust_buit(){
    if (cjt_clust.empty()) return true;
    return false;
}


void cjt_clusters::imprime_cluster(const string& id_clust) {
    map<string,cluster>::iterator it = cjt_clust.begin();
    it = cjt_clust.find(id_clust);
    (*it).second.escriure_clust();
}

void cjt_clusters::imprime_arbol_filogenetico(){};
