#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums){
	int len = nums.size();
	int maxsum = 0;
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		if (nums[i] == 1)
		{
			sum++;
			
		}
		else{
			maxsum = max(sum,maxsum);
			sum = 0;
		}
	}
	maxsum = max(sum,maxsum);
	return maxsum;
}

int main(){
	int a[6] = {1,1,0,1,1,1};
	vector<int> nums(a,a+6);
	cout<<findMaxConsecutiveOnes(nums)<<endl;
	return 0;
}
