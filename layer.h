#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "neuron.h"
#include "line.h"

using namespace std;

class layer {
public:
  vector<neuron> neurons;
  vector<line> lines;
  
  void create_neurons(int count);
  void connect(layer* prev, double weight);
};
#endif
