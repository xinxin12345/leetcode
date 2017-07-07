#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums){
    if (nums.size()==1)
    {
    	return nums[0];
    }

	sort(nums.begin(),nums.end());
	int majority = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[i-1])
		{
			majority++;
			if (majority>nums.size()/2)
			{
				return nums[i];
			}
		}
		else{
			majority = 1;
		}
	}
}

int main(){
	int a[8] = {2,3,2,2,1,2,2};
	vector<int> nums(a,a+8);
	cout<<majorityElement(nums)<<endl;
	return 0;
}

