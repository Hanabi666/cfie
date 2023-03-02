#include "triangle.h"
#include <vector>
#include <math.h>

triangle::triangle()
{
}

triangle::triangle(vector<float> p1, vector<float> p2, vector<float> p3, vector<float> length, float area, vector<float> vn)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->l1 = {p2[0]-p3[0],p2[1]-p3[1],p2[2]-p3[2]};
    this->l2 = {p3[0]-p1[0],p3[1]-p1[1],p3[2]-p1[2]};
    this->l3 = {p1[0]-p2[0],p1[1]-p2[1],p1[2]-p2[2]};
    this->length1 = length[0];
    this->length2 = length[1];
    this->length3 = length[3];
    this->area = area;
    this->vn = vn;
}

void triangle::setLengthValueByPoint()
{
    this->l1 = {p2[0]-p3[0],p2[1]-p3[1],p2[2]-p3[2]};
    this->l2 = {p3[0]-p1[0],p3[1]-p1[1],p3[2]-p1[2]};
    this->l3 = {p1[0]-p2[0],p1[1]-p2[1],p1[2]-p2[2]};
    length1 = sqrtf(powf(l1[0],2)+powl(l1[1],2)+powf(l1[2],2));
    length2 = sqrtf(powf(l2[0],2)+powl(l2[1],2)+powf(l2[2],2));
    length3 = sqrtf(powf(l3[0],2)+powl(l3[1],2)+powf(l3[2],2));
}

triangle::~triangle()
{
}
