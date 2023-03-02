#include <complex>
#include <vector>

class constantValue
{
public:
    float ve0, vu0, c0, pi, k0, f0, w0, wavelength0, eta0;
    float ve1, vu1, k1, wavelength1, eta1;
    std::complex<float> j0;
public:
    constantValue(/* args */);
    ~constantValue();
    void setSystemFreq(float freq);
    void setRelativeMediumParms(float r_epsilon, float r_mu);
    void outputMediaInfo();
};

class sourceValue
{
private:
    float thetaInc, phiInc;
    int iPolar;
    std::vector<float> vE, vH, vR;
    
public:
    sourceValue(/* args */);
    ~sourceValue();
    void setEfieldSource(float theta, float phi, int polar);
    void outputSourceInfo();
};

