#include "line.h"
#include "neuron.h"

using namespace std;

double Ln::gv(){
    return a->gv() * w;
}

void Ln::set_n(Nr* x, Nr* y, double w){
    a = x;
    b = y;
    this->w = w;
    y->add_l(this);
}
