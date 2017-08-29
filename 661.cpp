#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M){
	vector<vector<int>> result;
	vector<int> lines;
	int count = 0;
	int height = M.size();
	int width = M[0].size();
	int sum = 0;

	for (int i = 0; i < M.size(); ++i)
	{
		for (int j = 0; j < M[i].size(); ++j)
		{
			count = 0;
			sum = 0;
			for (int p = -1; p < 2; ++p)
			{
				for (int q = -1; q < 2; ++q)
				{
					if ((i + p >= 0 && i + p < height) && (j + q >= 0 && j + q < width))
					{
						count++;
                        sum += M[i+p][j+q];
					}
				}
			}
			lines.push_back(sum/count);
		}
		result.push_back(lines);
		lines.clear();
	}
	return result;
}

int main(){
	vector<vector<int>> result;
    vector<int> a;
    vector<vector<int>> M;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    M.push_back(a);
    a.clear();
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    M.push_back(a);
    a.clear();
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    M.push_back(a);
    result = imageSmoother(M);

    for (int i = 0; i < result.size(); ++i)
    {
    	for (int j = 0; j < result[i].size(); ++j)
    	{
    	     cout<<result[i][j]<<" ";
    	}
    	cout<<endl;
    }
	return 0;
}
