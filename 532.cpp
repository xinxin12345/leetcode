#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> isexist(vector<int>& nums,int n){
	vector<int> result;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == n)
		{
			result.push_back(i);
		}
	}
	return result;
}

int findPairs(vector<int>& nums, int k){
	if(k < 0){
       return 0;
	}
	sort(nums.begin(),nums.end());
	int num = 0;
	vector<int> result;
	for (int i = 0; i < nums.size(); )
	{
		result = isexist(nums,nums[i] + k);
		if ( k != 0)
		{
			if (result.size() != 0)
			{
				num++;
			}
			i++;
			while(nums[i] == nums[i-1]){
				i++;
			}
			continue;
		}
		else{
			if (result.size() > 1)
			num += 1;
			i += result.size();
			continue;
		}
	}
	return num;
}

int main(){
	int a[5] = {1, 2, 3, 4, 5};
	vector<int> nums(a,a+5);
	int k = -1;
	cout<<findPairs(nums,k)<<endl;
	return 0;
}


