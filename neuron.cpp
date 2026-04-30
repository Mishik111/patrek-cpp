#include "neuron.h"
#include "line.h"

using namespace std;

double Neuron:get_val(){
    val=0;
    for(int i=0;i<last.size();i++){
        val+=last[i].get_val();
    }
    return val;
}

void Neuron:set_lines(vector<Line> l){
    last=l;
}