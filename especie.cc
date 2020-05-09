#include "especie.hh"

especie::especie(){
    this->gen = string();
    this->kgen = map<string,int>();
}

especie::especie(string& gen){
    this->gen = gen;
}

especie::~especie(){}

void especie::afegir_gen(string& gen,int k){
    this->gen = gen;
    generar_kgen(k);
}

double especie::dist_esp(const especie& esp1,const especie& esp2){
    double inter,total;
    inter = total = 0;
    map<string,int>::const_iterator it_e1 = esp1.kgen.begin();
    map<string,int>::const_iterator it_e2 = esp2.kgen.begin();
    while(it_e1 != esp1.kgen.end() and it_e2 != esp2.kgen.end()){

        if((*it_e1).first == (*it_e2).first){
            inter += min((*it_e1).second,(*it_e2).second);
            total += (*it_e1).second + (*it_e2).second;
            ++it_e1;
            ++it_e2;
        }
        else if ((*it_e1).first < (*it_e2).first){
            total += (*it_e1).second;
            ++it_e1;
        }
        else{
            total += (*it_e2).second;
            ++it_e2;
        }
    }
    while(it_e1 != esp1.kgen.end()){
        total += (*it_e1).second;
        ++it_e1;
    }
    while(it_e2 != esp2.kgen.end()){
        total += (*it_e2).second;
        ++it_e2;
    }
//    cout << "Interseccio: " << inter << " Unio: " << total-inter << endl;
    double dist = (1-(inter/(total-inter)))*100;
    return dist;
}

string especie::consultar_gen() const{
    return gen;
}

void especie::generar_kgen(int k){
    
    for(int i = 0; i <= gen.length()-k; ++i ){
        string kmer =  gen.substr(i,k);
        if (kgen.empty()){
            kgen.insert({kmer,1});
        }
        else{
            map<string,int>::iterator it;
            it = kgen.find(kmer);
            if (it != kgen.end()){
                (*it).second += 1;
            }
            else {
                kgen.insert({kmer,1});
            }
        }
    }
}