#include "layer.h"

using namespace std;

void layer:create_neurons(int count){
    neurons.resize(count);
}

void layer:connect(layer* prev, double weight){
    for(int i=0;i<neurons.size();i++){
        for(int j=0;j<prev->neurons.size();j++){
            lines.push_back(line());
            line* l=&lines.back();
            l->set_neurons(&(prev->neurons[j]), &(neurons[i]), weight);
        }
    }
}
