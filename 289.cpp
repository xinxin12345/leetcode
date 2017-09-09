#include <iostream>
#include <vector>
using namespace std;

int getcount(vector<vector<int>>& board,int i,int j){
	int sum = 0;
	int iindex = 0;
	int jindex = 0;
	for (int p = -1; p < 2; ++p)
	{
		if (i+p>=0 && i+p<board.size())
		{
			iindex = i+p;
		}
		else{
			continue;
		}
		for (int q = -1; q < 2; ++q)
		{
			if (j+q>=0 && j+q<board[i].size())
			{
				jindex = j+q;
			}
			else{
				continue;
			}
			if(iindex==i && jindex==j){
				continue;
			}
			if (board[iindex][jindex] == 1 || board[iindex][jindex] == 3)
			{
				sum++;
			}
		}	
	}
	return sum;
}

void gameOfLife(vector<vector<int>>& board){
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			int count = getcount(board,i,j);
			if (board[i][j] == 0)
			{
				if (count == 3)
				{
					board[i][j] = 2;
				}
			}
			else{
				if (count<2 || count>3)
				{
					board[i][j] = 3;
				}
			}
		}
	}

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == 2)
			{
				board[i][j] = 1;
			}
			else if(board[i][j] == 3){
				board[i][j] = 0;
			}
		}
	}
}

int main(){
	int a[2] = {1,1};
//	int b[6] = {1,1,1,1,1,1};
	vector<int> line1(a,a+2);
//	vector<int> line2(b,b+6);
	vector<vector<int>> board;
	board.push_back(line1);
//	board.push_back(line2);
//	board.push_back(line1);
//	board.push_back(line2);
//	board.push_back(line1);
//	board.push_back(line2);
	gameOfLife(board);
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

