#include "nn.h"

using namespace std;

bool N::save(const string& filename){
    ofstream f(filename, ios::binary);
    if(!f) return false;
    
    const char magic[4] = {'P','A','T','R'};
    int version = 1;
    f.write(magic, 4);
    f.write((char*)&version, sizeof(version));
    
    int nl = ls.size();
    f.write((char*)&nl, sizeof(nl));
    for(int i=0;i<nl;i++){
        int nc = ls[i].ns.size();
        f.write((char*)&nc, sizeof(nc));
    }
    
    for(int i=1;i<nl;i++){
        L& l = ls[i];
        for(int j=0;j<l.ls.size();j++){
            double w = l.ls[j].w;
            f.write((char*)&w, sizeof(w));
        }
    }
    
    f.close();
    return true;
}

bool N::load(const string& filename){
    ifstream f(filename, ios::binary);
    if(!f) return false;
    
    char magic[4];
    f.read(magic, 4);
    if(magic[0]!='P'||magic[1]!='A'||magic[2]!='T'||magic[3]!='R') return false;
    int version;
    f.read((char*)&version, sizeof(version));
    if(version!=1) return false;
    
    int nl;
    f.read((char*)&nl, sizeof(nl));
    ls.clear();
    ls.resize(nl);
    for(int i=0;i<nl;i++){
        int nc;
        f.read((char*)&nc, sizeof(nc));
        ls[i].cr_n(nc);
    }
    
    for(int i=1;i<nl;i++){
        L& prev = ls[i-1];
        L& cur = ls[i];
        int total = cur.ns.size() * prev.ns.size();
        cur.ls.resize(total);
        int idx = 0;
        for(int ni=0;ni<cur.ns.size();ni++){
            for(int pi=0;pi<prev.ns.size();pi++){
                Ln& ln = cur.ls[idx];
                ln.a = &(prev.ns[pi]);
                ln.b = &(cur.ns[ni]);
                ln.b->add_l(&ln);
                f.read((char*)&ln.w, sizeof(double));
                idx++;
            }
        }
    }
    
    f.close();
    return true;
}

void N::add_l(int c){
    ls.push_back(L());
    ls.back().cr_n(c);
}

void N::con_l(double w){
    for(int i=1;i<ls.size();i++){
        ls[i].con(&ls[i-1], w);
    }
}

void N::fwd(vector<double> in){
    for(int i=0;i<in.size() && i<ls[0].ns.size();i++){
        ls[0].ns[i].v=in[i];
    }
    for(int i=1;i<ls.size();i++){
        for(int j=0;j<ls[i].ns.size();j++){
            ls[i].ns[j].gv();
        }
    }
}

vector<double> N::gv(){
    vector<double> o;
    L& l=ls.back();
    for(int i=0;i<l.ns.size();i++){
        o.push_back(l.ns[i].v);
    }
    return o;
}
