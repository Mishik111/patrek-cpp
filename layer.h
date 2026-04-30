#ifndef L_H
#define L_H

#include <vector>
#include "neuron.h"
#include "line.h"

using namespace std;

class L {
public:
  vector<Nr> ns;
  vector<Ln> ls;
  
  void cr_n(int c);
  void con(L* p, double w);
};
#endif
