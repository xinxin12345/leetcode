#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums) {
   if (nums.size() == 0)
   {
   	return 0;
   }
   
   int sum = 0;

   sort(nums.begin(),nums.end());

   for (int i = 0; i < nums.size()-1; i = i+2)
   {
   	sum += min(nums[i],nums[i+1]);
   }

   return sum;
}

int main(){
	int a[4] = {1,4,3,2};
	vector<int> nums(a,a+4);
	int sum = arrayPairSum(nums);
	cout<<sum<<endl;
	return 0;
}

