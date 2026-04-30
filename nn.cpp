#include "nn.h"

using namespace std;

void N::add_l(int c){
    ls.push_back(L());
    ls.back().cr_n(c);
}

void N::con_l(double w){
    for(int i=1;i<ls.size();i++){
        ls[i].con(&ls[i-1], w);
    }
}

void N::fwd(vector<double> in){
    for(int i=0;i<in.size() && i<ls[0].ns.size();i++){
        ls[0].ns[i].v=in[i];
    }
    for(int i=1;i<ls.size();i++){
        for(int j=0;j<ls[i].ns.size();j++){
            ls[i].ns[j].gv();
        }
    }
}

vector<double> N::gv(){
    vector<double> o;
    L& l=ls.back();
    for(int i=0;i<l.ns.size();i++){
        o.push_back(l.ns[i].v);
    }
    return o;
}
