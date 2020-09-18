#include "include.h"

class oneNueron
{
private:
    double m_weight = 0.0;
    long double m_smooth = 0.0;
    double m_error = 0.0;
    string m_nameOfWork;
    bool m_needTrain = true;

public:
    oneNueron(int arg, string str);
    ~oneNueron();
    double getWeight();
    long double getSmooth();
    double getError();
    bool getNeedTrain();
    double workWithInput(double input);
    double restoreWorkWithInput(double output);
    void setWeight(double newWeight);
    void setSmooth(long double newSmooth);
    void loadWeightandSmoothFromFile();
    void saveWeightandSmoothInFile();
    void trainNeuron(double input, double expectedResult);    
    
};


