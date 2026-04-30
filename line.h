#ifndef LINE_H
#define LINE_H

#include "neuron.h"
using namespace std;

class Line {
public:
  neuron n1, n2;
  
  void set_neurons(neuron, neuron);
  double get_val();
};
#endif