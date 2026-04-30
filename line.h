#ifndef LINE_H
#define LINE_H

class neuron;
using namespace std;

class line {
public:
  neuron* n1;
  neuron* n2;
  double weight;
  
  void set_neurons(neuron*, neuron*, double);
  double get_val();
};
#endif