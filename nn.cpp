#include "nn.h"

using namespace std;

void nn:add_layer(int neuron_count){
    layers.push_back(layer());
    layers.back().create_neurons(neuron_count);
}

void nn:connect_layers(double weight){
    for(int i=1;i<layers.size();i++){
        layers[i].connect(&layers[i-1], weight);
    }
}

void nn:forward(vector<double> inputs){
    for(int i=0;i<inputs.size() && i<layers[0].neurons.size();i++){
        layers[0].neurons[i].val=inputs[i];
    }
    for(int i=1;i<layers.size();i++){
        for(int j=0;j<layers[i].neurons.size();j++){
            layers[i].neurons[j].get_val();
        }
    }
}

vector<double> nn:get_val(){
    vector<double> output;
    layer& last_layer=layers.back();
    for(int i=0;i<last_layer.neurons.size();i++){
        output.push_back(last_layer.neurons[i].val);
    }
    return output;
}
