#include "line.h"
#include "neuron.h"

using namespace std;

double line:get_val(){
    return n1->get_val() * weight;
}

void line:set_neurons(neuron* a, neuron* b, double w){
    n1 = a;
    n2 = b;
    weight = w;
    b->add_line(this);
}