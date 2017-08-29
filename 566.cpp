#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c){
	int height = nums.size();
	int width = nums[0].size();
	int rows = 0;
	vector<vector<int>> result;
	vector<int> lines;

	if (r*c > height*width)
	{
		return nums;
	}
	else{
       for (int i = 0; i < nums.size(); ++i)
       {
       	for (int j = 0; j < nums[i].size(); ++j)
       	{
       		if ((i*width+j)/c == rows)
       		{
       			rows = (i*width+j)/c;
       			lines.push_back(nums[i][j]);

       		}
       		else{
       			rows = (i*width+j)/c;
       			result.push_back(lines);
       			lines.clear();
       			lines.push_back(nums[i][j]);
       		}
       		
       	}
       }
       result.push_back(lines);
       return result;
	}
}

int main(){
	vector<vector<int>> nums;
	vector<vector<int>> result;
    vector<int> a;
    // vector<int> b;
    a.push_back(1);
    a.push_back(2);

    a.push_back(3);
    a.push_back(4);
    nums.push_back(a);
    // nums.push_back(b);

	int r = 2,c = 2;
	result = matrixReshape(nums,r,c);
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





