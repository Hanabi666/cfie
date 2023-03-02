#include <vector>
#include "mesh.h"
#include "constantValue.h"
#include <string>


enum INTEGRAL_EQUATION
{
    EFIE,
    MFIE,
    CFIE,
    PMCHWT
};

class cfie
{
private:
    string rwgFilePath;
    vector<vector<float>> factorE;
    vector<float> factorH;
    enum INTEGRAL_EQUATION equation;
    float alpha;
    mesh mMesh;
    constantValue mConstantValue;
    sourceValue mSourceValue;
public:
    cfie();
    cfie(const vector<vector<float>>& factorE, const vector<float>& factorH, const float& alpha);
    ~cfie();
    void setRwgFilePath(const string& path);
    void initCFIEValue(const float &alpha, const float &r_epsilon, const float &r_mu);
    void outputInfo();
};

