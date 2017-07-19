#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumProduct(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	int n = nums.size();
	int result = 0;
	result = nums[n-1]*nums[n-2]*nums[n-3];
	result = max(result,nums[0]*nums[1]*nums[n-1]);
	return result;
}

int main(){
	int a[5] = {-4,-3,-2,-1,60};
	vector<int> nums(a,a+5);
	cout<<maximumProduct(nums)<<endl;
	return 0;
}
