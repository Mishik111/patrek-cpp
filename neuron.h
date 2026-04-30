#ifndef NEURON_H
#define NEURON_H

#include <vector>

class line;
using namespace std;

class neuron {
public:
  double val;
  vector<line*> last;

  double get_val();
  void add_line(line*);
};
#endif