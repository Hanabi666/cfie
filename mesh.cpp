#include "mesh.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

mesh::mesh()
{
}

vector<float> mesh::readRwgFile(const string& path)
{
    vector<float> instantValue;
    ifstream infile;
    string buff;
    float value;
    try
    {
        infile.open(path, ios::in);
        if (!infile.is_open())
        {
            std::cerr<< "读取文件错误" << "\n";
        }
        
        for (int i = 0; i < 9; i++)
        {
            getline(infile, buff);
            if (i == 2)
            {
                istringstream ss(buff);
                ss >> value;
                instantValue.push_back(value);
            }
            if (i == 4)
            {
                istringstream ss(buff);
                ss >> value;
                instantValue.push_back(value);
                ss >> value;
                instantValue.push_back(value);
                ss >> value;
                instantValue.push_back(value);
            }
            
            // std::cout<< buff << std::endl;
        }
        getline(infile, buff);
        istringstream ss(buff);
        ss >> this->nodeNum >> this->triangleNum >> this->lineNum;
        for (int i = 0; i < 4; i++)
        {
            getline(infile, buff);
        }
        for (int i = 0; i < this->triangleNum; i++)
        {
            getline(infile, buff);
            istringstream ss(buff);
            triangle tri;
            vector<int> node_temp(3), line_temp(3);
            ss >> value >> node_temp[0] >> node_temp[1] >> node_temp[2] >> line_temp[0]
                >> line_temp[1] >> line_temp[2];
            this->nodeInfo.push_back(node_temp);
            this->lineInfo.push_back(line_temp);
            float area, nx, ny, nz;
            ss >> area >> nx >> ny >> nz;
            tri.area = area;
            tri.vn = {nx, ny, nz};
            this->Triangle.push_back(tri);
        }
        for (int i = 0; i < 3; i++)
        {
            getline(infile, buff);
        }
        vector<vector<float>> ls;
        for (int i = 0; i < this->nodeNum; i++)
        {
            getline(infile, buff);
            istringstream ss(buff);
            float a, b, c;
            ss >> value >> a >> b >> c;
            ls.push_back({a, b, c});
        }
        for (int i = 0; i < this->triangleNum; i++)
        {
            Triangle[i].p1 = ls[this->nodeInfo[i][0]-1];
            Triangle[i].p2 = ls[this->nodeInfo[i][1]-1];
            Triangle[i].p3 = ls[this->nodeInfo[i][2]-1];
            Triangle[i].setLengthValueByPoint();
        }
        infile.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "**********read rwgfile completed**********" << std::endl;
    return instantValue;
}

mesh::~mesh()
{
}

void mesh::outputMeshInfo()
{
    std::cout<< "三角形个数："<< this->triangleNum << "节点个数：" << this->nodeNum << "边个数：" << this->lineNum << '\n';
    // for (int i = 0; i < this->triangleNum; i++)
    // {
    //     cout << i << '\t' << this->nodeInfo[i][0] << '\t' << this->nodeInfo[i][1] << '\t' << this->nodeInfo[i][2]
    //         << '\t' << this->Triangle[i].area << '\n';
    //     cout << '\t' << this->Triangle[i].p1[0] << '\t' << this->Triangle[i].p1[1] << '\t' << this->Triangle[i].p1[2]
    //         << '\t' << this->Triangle[i].p2[0] << '\t' << this->Triangle[i].p2[1] << '\t' << this->Triangle[i].p2[2]
    //         << '\t' << this->Triangle[i].p3[0] << '\t' << this->Triangle[i].p3[1] << '\t' << this->Triangle[i].p3[2] << '\n';
    //     cout << '\t' << this->Triangle[i].length1 << '\t' << this->Triangle[i].length2 << '\t' << this->Triangle[i].length3 << '\n';
    // }
}