#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n){
	vector<vector<int>> res(n,vector<int>(n,0));
	int i = 0;
	int j = 0;
	int value = 1;
	
	if(n == 1){
		vector<int> line;
		line.push_back(n);
		res.clear();
		res.push_back(line);
		return res;
	}
		
	
	while(value != n*n+1){
		while(res[i][j] == 0 && j < n){
			res[i][j] = value++;
			j++;
			if(j == n) break;
		}
		j--;
		i++;
		while(res[i][j] == 0 && i < n){
			res[i][j] = value++;
			i++;
			if(i == n)  break;
		}
		i--;
		j--;
		while(res[i][j] == 0 && j >= 0){
			res[i][j] = value++;
			j--;
		}
		j++;
		i--;
		while(res[i][j] == 0 && i >= 0){
			res[i][j] = value++;
			i--;
		}
		i++;
		j++;
	}
	return res;
}

int main(){
	int n = 1;
	vector<vector<int>> res;
	res = generateMatrix(n);
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

