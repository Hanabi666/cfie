#include <vector>
#include <string>
#include "triangle.h"
class mesh
{
public:
    /* data */
    int nodeNum, triangleNum, lineNum;
    float maxX, maxY, maxZ, minX, minY, minZ;
    vector<vector<int>> nodeInfo;
    vector<vector<int>> lineInfo;
    vector<triangle> Triangle;
    bool isCLose;

public:
    mesh(/* args */);
    vector<float> readRwgFile(const string& path);
    ~mesh();
    void outputMeshInfo();
};


