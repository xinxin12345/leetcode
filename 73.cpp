#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix){
	int height = matrix.size();
	int width = matrix[0].size();
	int iindex = 0;
	int jindex = 0;
	for (int i = 0; i < height; ++i)
	{
		if (matrix[i][0] == 0)
		{
			jindex = 1;
			break;
		}
	}
	for (int i = 0; i < width; ++i)
	{
		if (matrix[0][i] == 0)
		{
			iindex = 1;
			break;
		}
	}
    for (int i = 1; i < height; ++i)
    {
    	for (int j = 1; j < width; ++j)
    	{
    		if (matrix[i][j] == 0)
    		{
    			matrix[0][j] = 0;
    			matrix[i][0] = 0;
    		}
    	}
    }

    for (int i = 1; i < height; ++i)
    {
    	if (matrix[i][0] == 0)
    	{
    		for (int j = 1; j < width; ++j)
    		{
    			matrix[i][j] = 0;
    		}
    	}
    }
    for (int i = 1; i < width; ++i)
    {
    	if (matrix[0][i] == 0)
    	{
    		for (int j = 1; j < height; ++j)
    		{
    			matrix[j][i] = 0;
    		}
    	}
    }
    if (iindex == 1)
    {
    	for (int i = 0; i < width; ++i)
    	{
    		matrix[0][i] = 0;
    	}
    }
    if (jindex == 1)
    {
    	for (int i = 0; i < height; ++i)
    	{
    		matrix[i][0] = 0;
    	}
    }
}

int main(){
    vector<vector<int>> matrix;
	int a[4] = {0,0,0,5};
	int b[4] = {4,3,1,4};
	int c[4] = {0,1,1,4};
	int d[4] = {1,2,1,3};
	int e[4] = {0,0,1,1};
	vector<int> line(a,a+4);
	matrix.push_back(line);
	vector<int> line1(b,b+4);
	matrix.push_back(line1);
	vector<int> line2(c,c+4);
	matrix.push_back(line2);
	vector<int> line3(d,d+4);
	matrix.push_back(line3);
	vector<int> line4(e,e+4);
	matrix.push_back(line4);
	
	setZeroes(matrix);
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
