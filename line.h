#ifndef LN_H
#define LN_H

#include "neuron.h"

using namespace std;

class Ln {
public:
  Nr* a;
  Nr* b;
  double w;
  
  void set_n(Nr*, Nr*, double);
  double gv();
};
#endif
