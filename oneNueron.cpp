#include "oneNueron.h"

oneNueron::oneNueron(int arg, string str)
{
    m_nameOfWork = str;
    switch (arg)
    {
    case 1:
        m_needTrain = false;
        loadWeightandSmoothFromFile();
        break;
    
    default:
        break;
    }
}

oneNueron::~oneNueron()
{

}

bool oneNueron::getNeedTrain()
{
    return m_needTrain;
}

double oneNueron::getError()
{
    return m_error;
}

long double oneNueron::getSmooth()
{
    return m_smooth;
}

double oneNueron::getWeight()
{
    return m_weight;
}

void oneNueron::setSmooth(long double newSmooth)
{
    m_smooth = newSmooth;
}

void oneNueron::setWeight(double newWeight)
{
    m_weight = newWeight;
}

double oneNueron::workWithInput(double input)
{
    return input * m_weight;
}

double oneNueron::restoreWorkWithInput(double output)
{
    return output / m_weight;
}

void oneNueron::trainNeuron(double input, double expectedResult)
{
    double realResult = input * m_weight;
    m_error = expectedResult - realResult;
    auto correction = (m_error/realResult) * m_smooth;
    m_weight += correction;
}

void oneNueron::loadWeightandSmoothFromFile()
{
    ifstream file;
    string nameFile = "settings" + m_nameOfWork + ".txt";
    file.open(nameFile);
    if(file.is_open())
    {
        cout << "Getting weight and smooth for neuron from file" << endl;
        file >> m_weight >> m_smooth;
    }
    else
    {
        cout << "Couldn`t open settings file, check the folder with programm" << endl;
    }
    file.close();
}

void oneNueron::saveWeightandSmoothInFile()
{
    ofstream file;
    string nameFile = "settings" + m_nameOfWork + ".txt";
    file.open("settings" + m_nameOfWork + ".txt");
    if(file.is_open())
    {
        cout << "Saving weight and smooth in file" << endl;
        file << m_weight << " " << m_smooth;
    }
    file.close();
}