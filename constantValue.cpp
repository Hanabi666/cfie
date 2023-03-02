#include "constantValue.h"
#include <iostream>
#include "mathUtils.h"

constantValue::constantValue()
{
    this->ve0 = 8.854185e-12;
    this->vu0 = 1.2566371e-6;
    this->c0 = 3.0e8;
    this->pi = 3.14159265359;
    this->j0 = {0, 1.0};
}

constantValue::~constantValue()
{
}

void constantValue::setSystemFreq(float freq)
{
    this->f0 = freq;
    this->w0 = 2.0 * pi * freq;
    this->k0 = w0 * sqrtf(ve0 * vu0);
    this->wavelength0 = 2.0 * pi / k0;
    this->eta0 = sqrtf(vu0/ve0);
}

void constantValue::setRelativeMediumParms(float r_epsilon, float r_mu)
{
    this->ve1 = r_epsilon * ve0;
    this->vu1 = r_mu * vu0;
    this->k1 = w0 * sqrtf(ve1 * vu1);
    this->wavelength0 = 2.0 * pi / k1;
    this->eta1 = sqrtf(vu1/ve1);
}

void constantValue::outputMediaInfo()
{
    std::cout<< "媒质1：\t"<< ve0<< '\t'<< vu0<< '\n'
            << "媒质2：\t"<< ve1<< '\t'<< vu1<< '\n'
            << "系统频率："<< f0<< '\n';
}

sourceValue::sourceValue()
{
}

sourceValue::~sourceValue()
{
}

void sourceValue::setEfieldSource(float theta, float phi, int polar)
{
    this->thetaInc = theta;
    this->phiInc = phi;
    this->iPolar = polar;
    float eTheta, ePhi;
    if (polar == 1)
    {
        eTheta = 1.0;
        ePhi = 0;
    } else if (polar == 2)
    {
        eTheta = 0;
        ePhi = 1.0;
    } else {
        std::cerr << "入射场方向错误" << '\n';
    }
    float r2d = 3.1415926536/180.0;
    float vst = sin(theta*r2d);
    float vct = cos(theta*r2d);
    float vsp = sin(phi*r2d);
    float vcp = cos(phi*r2d);
    this->vR = {vst*vcp, vst*vsp, vct};
    this->vE = {eTheta*vct*vcp-ePhi*vsp, eTheta*vct*vsp+ePhi*vcp, -eTheta*vst};
    this->vH = mCross_product3(vR, vE);
}

void sourceValue::outputSourceInfo()
{
    std::cout<< "入射电场："<< "\t(" << vE[0] << ',' << vE[1] << ','<< vE[2] << ")" << '\n'
            << "入射磁场:"<< "\t(" << vH[0] << ',' << vH[1] << ',' << vH[2] << ')' << '\n'
            << "传播方向:"<< "\t(" << vR[0] << ',' << vR[1] << ',' << vR[2] << ')' << '\n';
}
