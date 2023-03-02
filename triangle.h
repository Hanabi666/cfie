#include <vector>
using namespace std;

class triangle
{
public:
    /* data */
    vector<float> p1, p2, p3;
    vector<float> l1, l2, l3;
    float length1, length2, length3;
    float area;
    vector<float> vn;


    triangle(/* args */);
    triangle(vector<float> p1, vector<float> p2, vector<float> p3,
            vector<float> length, float area, vector<float> vn);
    void setLengthValueByPoint();
    ~triangle();
};
