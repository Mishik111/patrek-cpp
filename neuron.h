#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "line.h"

using namespace std;

class Neuron {
public:
  double val;
  vector<Line> last;

  double get_val();
  void set_lines(vector<Line>);
};
#endif