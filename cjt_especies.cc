#include "cjt_especies.hh"

cjt_especies::cjt_especies(){
    this->cjt_esp =  map<string, especie>();
    this->t_esp = taula_distancies();
}

cjt_especies::~cjt_especies(){}

string cjt_especies::obtener_gen(const string& id) const{
    map<string,especie>::const_iterator it;
    it = cjt_esp.find(id);
    return ((*it).second).consultar_gen();
}

bool cjt_especies::existe_especie(const string& id) {
    map<string,especie>::iterator it;
    it = cjt_esp.find(id);
    return it != cjt_esp.end();
}

bool cjt_especies::buit() const{
    if (cjt_esp.empty()) return true;
    else return false;
}

double cjt_especies::distancia_esp(const string& id1, const string& id2) const{ 
    map<string,especie>::const_iterator it;
    map<string,especie>::const_iterator it2;
    it = cjt_esp.find(id1);
    it2 = cjt_esp.find(id2);

    return especie::dist_esp((*it).second,(*it2).second);
}

/*void cjt_especies::crea_especie(const string& id,string& gen, int k){
    especie esp;
    map<string,especie>::iterator it = cjt_esp.begin(); 
    esp.afegir_gen(gen,k);
    while (it != cjt_esp.end()){
        double dist = distancia_esp((*it).first,id);
        t_esp.afegir_distancia((*it).first,id,dist);
        ++it;
    }
    cjt_esp.insert({id,esp});
}*/

void cjt_especies::crea_especie(const string& id, string& gen, int k)
{
    especie esp;
    map<string, especie>::iterator it = cjt_esp.begin();
    map<string, double> distancias;
    esp.afegir_gen(gen, k);
    cjt_esp.insert({id, esp});

    while(it != cjt_esp.end())
    {
        if((*it).first != id)
            distancias[it->first] = distancia_esp(it->first, id);

        ++it;
    }

    map<string, double>::iterator it2 = distancias.begin();

    while(it2 != distancias.end())
    {
        pair<string, string> coord;
        t_esp.afegir_distancia(it2->first, id, it2->second);
        ++it2;
    }
}

void cjt_especies::elimina_especie(const string& id){
    map<string,especie>::iterator it = cjt_esp.begin();
    while (it != cjt_esp.end())
    {
        if((*it).first != id)
            t_esp.eliminar_distancia((*it).first,id);

        ++it;
    }
    it = cjt_esp.find(id);
    cjt_esp.erase(it);
}

void cjt_especies::imprime_t_cesp() const{
    auto it = cjt_esp.begin();

    while(it != cjt_esp.end())
    {
        cout << (*it).first << ":";
        t_esp.imprimir_t_dist((*it).first);

        ++it;
    }
}

especie cjt_especies::consultar_especie(const string& id){
    map<string,especie>::iterator it = cjt_esp.begin();
    it = cjt_esp.find(id);
    return (*it).second;
}

void cjt_especies::imprime_cjt_especies() {
    map<string,especie>::iterator it = cjt_esp.begin();
    while(it != cjt_esp.end()){
        cout << (*it).first << " " << (*it).second.consultar_gen() << endl;
        ++it;
    }
}

void cjt_especies::lee_cjt_especies(int n,int k){
    cjt_esp.clear();
    t_esp.neteja();
    for (int i = 0; i < n; ++i){
        string gen,id;
        cin >> id >> gen;
        crea_especie(id,gen,k);
    }
}
