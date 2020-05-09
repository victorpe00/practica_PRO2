#include "taula_distancies.hh"

taula_distancies::taula_distancies(){
    this->t_dist = map<pair<string,string>,double>();
}

taula_distancies::~taula_distancies(){}


void taula_distancies::afegir_distancia(const string& id1,const string& id2,const double& dist){
    pair<string,string> cord;
    cord.first = min(id1,id2);
    cord.second = max(id1,id2);

    auto test = t_dist.find(cord);

    t_dist.insert({cord,dist});
}

void taula_distancies::eliminar_distancia(const string& id1,const string& id2){
    map<pair<string,string>,double>::iterator it;
    pair<string,string> cord;
    cord.first = min(id1,id2);
    cord.second = max(id1,id2);
    it = t_dist.find(cord);
    t_dist.erase(it);
}

void taula_distancies::eliminar_cluster(string& id1,string& id2){}

void taula_distancies::imprimir_t_dist(string id) const{
    map<pair<string,string>,double>::const_iterator it = t_dist.begin();
   
    while (it != t_dist.end()){
        if (((*it).first).first == id){  
            cout << " " << ((*it).first).second << " (" << (*it).second << ")";
        }
        ++it;
    }

    cout << endl;
}

void taula_distancies::neteja(){
    t_dist.clear();
}