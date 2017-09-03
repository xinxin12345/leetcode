#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int>& nums){
   vector<int> res;
   sort(nums.begin(),nums.end());
   for (int i = 1; i < nums.size(); ++i)
   {
   	if (nums[i] == nums[i-1])
   	{
   		res.push_back(nums[i]);
   	}
   }
   return res;
}

int main(){
	int a[8] = {4,3,2,7,8,2,3,1};
	vector<int> nums(a,a+8);
	vector<int> res = findDuplicates(nums);
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}
