#include "cfie.h"
#include <iostream>

cfie::cfie()
{
}

cfie::cfie(const vector<vector<float>> &factorE, const vector<float> &factorH, const float &alpha)
{
    this->factorE = factorE;
    this->factorH = factorH;
    this->alpha = alpha;
}

cfie::~cfie()
{
}

void cfie::setRwgFilePath(const string &path)
{
    this->rwgFilePath = path;
}

void cfie::initCFIEValue(const float& alpha, const float& r_epsilon, const float& r_mu)
{
    if (alpha < 0.0 || alpha > 1.0)
    {
        std::cerr << "系数alpha错误" << '\n';
    }
    if (alpha == 0.0)
    {
        this->equation = MFIE;
    } else if (alpha == 1.0)
    {
        this->equation = EFIE;
    } else
    {
        this->equation = CFIE;
    }
    if (r_epsilon != -1.0)
    {
        this->equation = PMCHWT;
    }
    
    this->alpha = alpha;
    vector<float> instantValue = mMesh.readRwgFile(rwgFilePath);
    mConstantValue.setSystemFreq(instantValue[0]);
    mConstantValue.setRelativeMediumParms(r_epsilon, r_mu);
    mSourceValue.setEfieldSource(instantValue[1], instantValue[2], instantValue[3]);
}

void cfie::outputInfo()
{
    mSourceValue.outputSourceInfo();
    mConstantValue.outputMediaInfo();
    mMesh.outputMeshInfo();
    switch (this->equation)
    {
    case EFIE:
        std::cout << "采用EFIE方程求解" << '\n';
        break;
    case MFIE:
        std::cout << "采用MFIE方程求解" << '\n';
        break;
    case CFIE:
        std::cout << "采用CFIE方程求解" << '\n';
        break;
    case PMCHWT:
        std::cout << "采用PMCHWT方程求解" << '\n';
        break;
    default:
        std::cerr << "选择求解方程出错" << '\n';
        break;
    }
}
