#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums){
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
		{
			for (int j = i+1; j < nums.size(); ++j)
			{
				if (nums[j] != 0)
				{
					nums[i] = nums[j];
					nums[j] = 0;
					break;
				}
			}
			continue;
		}
	}
}

int main(){
	int a[5] = {0, 1, 0, 3, 12};
	vector<int> nums(a,a+5);
	moveZeroes(nums);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	return 0;
}
