#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& nums){
	sort(nums.begin(),nums.end());
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i]!=i)
		{
			return i;
		}
	}
	return nums[nums.size()-1]+1;
}

int main(){
	int a[3] = {1,2,3};
	vector<int> nums(a,a+3);
	cout<<missingNumber(nums)<<endl;
	return 0;
}



