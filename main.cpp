#include "include.h"
#include "oneNueron.h"

int main(int argc, char const *argv[])
{
    double km = 100;
    double miles = 62.1371;
    //double usd = 1;
    //double rub = 75.76;

    oneNueron neuron(0,"kmmiles");

    if(neuron.getNeedTrain())
    {
        neuron.setWeight(0.5);
        neuron.setSmooth(0.00001l);
        unsigned long long i = 0;
        do
        {
            i++;
            //neuron.trainNeuron(usd, rub);
            neuron.trainNeuron(km, miles);
            if(i%10000 == 0)
            {
                cout << "Iteration #" << i << " Error:" << neuron.getError() << endl;
            }
        } 
        while (neuron.getError() > neuron.getSmooth() || neuron.getError() < -neuron.getSmooth());
        neuron.saveWeightandSmoothInFile();
    }


    printf("in 500 km %f miles\n", neuron.workWithInput(500));
    printf("in 10 km %f miles\n", neuron.workWithInput(10));
    printf("in 53 km %f miles\n", neuron.workWithInput(53));

    //printf("in 500 usd %f rub\n", neuron.workWithInput(500));
    //printf("in 10 usd %f rub\n", neuron.workWithInput(10));
    //printf("in 53 usd %f rub\n", neuron.workWithInput(53));

    return 0;
}
