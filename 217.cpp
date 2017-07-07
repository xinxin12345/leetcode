#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 bool containsDuplicate(vector<int>& nums){
 	sort(nums.begin(),nums.end());
 	for (int i = 1; i < nums.size(); ++i)
 	{
 		if (nums[i] == nums[i-1])
 		{
 			return true;
 		}
 	}
 	return false;
 }

int main(){
	int a[7] = {1,4,2,4,6,7,8};
	vector<int> nums(a,a+7);
	cout<<containsDuplicate(nums)<<endl;
	return 0;
}
