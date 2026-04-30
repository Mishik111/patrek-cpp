#include <iostream>
#include "nn.h"

using namespace std;

int main(){
    N n;
    n.add_l(2);
    n.add_l(3);
    n.add_l(1);
    n.con_l(0.5);
    
    vector<double> in = {1.0, 2.0};
    n.fwd(in);
    
    vector<double> out = n.gv();
    for(int i=0;i<out.size();i++){
        cout << out[i] << " ";
    }
    cout << endl;
    
    n.save("ai.patr");
    
    N n2;
    n2.load("ai.patr");
    n2.fwd(in);
    vector<double> out2 = n2.gv();
    for(int i=0;i<out2.size();i++){
        cout << out2[i] << " ";
    }
    cout << endl;
    
    return 0;
}
