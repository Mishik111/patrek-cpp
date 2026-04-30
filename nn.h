#ifndef NN_H
#define NN_H

#include <vector>
#include "layer.h"

using namespace std;

class nn {
public:
  vector<layer> layers;
  
  void add_layer(int neuron_count);
  void connect_layers(double weight);
  void forward(vector<double> inputs);
  vector<double> get_output();
};
#endif
