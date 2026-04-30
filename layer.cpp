#include "layer.h"

using namespace std;

void L::cr_n(int c){
    ns.resize(c);
}

void L::con(L* p, double w){
    for(int i=0;i<ns.size();i++){
        for(int j=0;j<p->ns.size();j++){
            ls.push_back(Ln());
            Ln* x=&ls.back();
            x->set_n(&(p->ns[j]), &(ns[i]), w);
        }
    }
}
