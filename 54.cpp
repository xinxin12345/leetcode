#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
	vector<int> res;
	if(matrix.size()==0)  return res;
	int index = 0;
	int i = 0;
	int j = 0;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> matrixcopy(m,vector<int>(n,1));
	if(m==1 && n==1){
		res.push_back(matrix[i][j]);
		return res;
	} 
	
	while(index != m*n){
      while(matrixcopy[i][j] != NULL && j < n){
			res.push_back(matrix[i][j]);
			matrixcopy[i][j] = NULL;
			j++;
			index++;
			if(j == n) break;
		}
		j--;
		i++;
		if(i == m){
			break;
		}
		
		while(matrixcopy[i][j] != NULL && i < m){
			res.push_back(matrix[i][j]);
			matrixcopy[i][j] = NULL;
			i++;
			index++;
			if(i == m)  break;
		}
		i--;
		j--;
		if(j < 0){
			break;
		}
		while(matrixcopy[i][j] != NULL && j >= 0){
			res.push_back(matrix[i][j]);
			matrixcopy[i][j] = NULL;
			j--;
			index++;
		}
		j++;
		i--;
		if(i < 0){
		  break;	
		}
		while(matrixcopy[i][j] != NULL && i >= 0){
			res.push_back(matrix[i][j]);
			matrixcopy[i][j] = NULL;
			i--;
			index++;
		}
		i++;
		j++;
		if(j == n){
			break;
		}
	}
	return res;

}

int main(){
	vector<vector<int>> matrix;
	vector<int> line;
//	line.push_back(1);
	line.push_back(2);
	line.push_back(5);
	matrix.push_back(line);
	line.clear();
	line.push_back(8);
	line.push_back(4);
//	line.push_back(6);
	matrix.push_back(line);
	line.clear();
	line.push_back(0);
	line.push_back(-1);
//	line.push_back(9);
	matrix.push_back(line);
	line.clear();
	line = spiralOrder(matrix);
	for (int i = 0; i < line.size(); ++i)
	{
		cout<<line[i]<<" ";
	}
	cout<<endl;
	return 0;
}
