#include "neuron.h"
#include "line.h"

using namespace std;

double Nr::gv(){
    if(lst.size()==0){
        return v;
    }
    v=0;
    for(int i=0;i<lst.size();i++){
        v+=lst[i]->gv();
    }
    return v;
}

void Nr::add_l(Ln* x){
    lst.push_back(x);
}
