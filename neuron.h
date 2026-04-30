#ifndef NR_H
#define NR_H

#include <vector>

class Ln;
using namespace std;

class Nr {
public:
  double v;
  vector<Ln*> lst;

  double gv();
  void add_l(Ln*);
};
#endif
