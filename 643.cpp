#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k){
	int len = nums.size();
	if (len == 0 || k == 0 || len < k)
	{
		return 0;
	}
	int sum = 0;
	int maxsum = 0;

	for (int i = 0; i < k; ++i)
	{
		maxsum += nums[i];
	}
	sum = maxsum;

	for (int i = 1; i <= len - k; ++i)
	{
		sum = sum + nums[i+k-1] - nums[i-1];
		maxsum = max(sum,maxsum);
	}
	return maxsum*1.0/k;
}

int main(){
	int a[5] = {0,1,1,3,3};
	vector<int> nums(a,a+5);
	int k = 4;
	cout<<findMaxAverage(nums,k)<<endl;
	return 0;
}

