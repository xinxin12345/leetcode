#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> constructArray(int n, int k){
	vector<int> temp;
	vector<int> res;
	int ktemp = k;
	for (int i = 0; i < n; ++i)
	{
		temp.push_back(i+1);
	}
	if (k == 1)
	{
		return temp;
	}

	res.push_back(1);
	temp.erase(temp.begin() + 0);

	while(ktemp){
        for (int i = 0; i < temp.size(); )
        {
        	if (abs(temp[i] - res[res.size()-1]) == ktemp)
        	{
        		res.push_back(temp[i]);
        		temp.erase(temp.begin() + i);
        		ktemp--;
        		if(ktemp == 0){
        			break;
        		}
        		i = 0;
        	}
        	else{
        		++i;
        	}
        }
	}
	while(res.size() < n){
       for (int i = 0; i < temp.size(); )
       {
       	if (abs(temp[i] - res[res.size()-1]) <= k)
       	{
       		res.push_back(temp[i]);
       		temp.erase(temp.begin() + i);
       		i = 0;
       	}
       	else{
       		++i;
       	}
       }
	}

	return res;
}

int main(){
	vector<int> res;
	int n = 5;
	int k = 4;
	res = constructArray(n,k);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}
