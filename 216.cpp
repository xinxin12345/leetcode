#include <iostream>
#include <vector>
using namespace std;

void helper(int k,int n,int sum,int pos,vector<int>& line,vector<vector<int>>& res){
	if (k == 0 && sum == n)
	{
		res.push_back(line);
		return;
	}
	if (k < 0 || sum > n)
	{
		return;
	}
	for (int i = pos; i <= 9; ++i)
	{
		line.push_back(i);
		helper(k-1,n,sum+i,i+1,line,res);
		line.pop_back();
	}
}

vector<vector<int>> combinationSum3(int k, int n){
	vector<vector<int>> res;
	vector<int> line;
	helper(k,n,0,1,line,res);
	return res;
}

int main(){
	vector<vector<int>> res;
	int k = 3;
	int n = 9;
	res = combinationSum3(k, n);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout<<res[i][j]<<" ";
		}
			cout<<endl;
	}
	return 0;
}

