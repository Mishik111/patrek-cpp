#ifndef N_H
#define N_H

#include <vector>
#include "layer.h"

using namespace std;

class N {
public:
  vector<L> ls;
  
  void add_l(int c);
  void con_l(double w);
  void fwd(vector<double> in);
  vector<double> gv();
};
#endif
