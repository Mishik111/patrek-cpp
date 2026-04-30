#include "neuron.h"
#include "line.h"

using namespace std;

double neuron:get_val(){
    if(last.size()==0){
        return val;
    }
    val=0;
    for(int i=0;i<last.size();i++){
        val+=last[i]->get_val();
    }
    return val;
}

void neuron:add_line(line* l){
    last.push_back(l);
}