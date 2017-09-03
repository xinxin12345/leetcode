#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
	int product = 1;
	int count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0)
		{
			product *= nums[i];
		}
		else{
			count++;	
		}
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (count >= 2)
		{
			nums[i] = 0;
		}
		else if (count == 1)
		{
			if (nums[i] == 0)
			{
				nums[i] = product;
			}
			else{
				nums[i] = 0;
			}
		}
		else
		{
			nums[i] = product/nums[i];
		}
	}
	return nums;
}

int main(){
	int a[4] = {0,1,2,3};
	vector<int> nums(a,a+4);
	nums = productExceptSelf(nums);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	return 0;
}

