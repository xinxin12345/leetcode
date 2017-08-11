#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums){
for (int i = 0; i < nums.size()-1; ++i)
{
	for (int j = i+1; j < nums.size(); ++j)
	{
		if (nums[i] == nums[j])
		{
			return nums[i];
		}
	}
}
}

int main(){
	int a[5] = {1,2,4,2,5};
	vector<int> nums(a,a+5);
	int b = findDuplicate(nums);
	cout<<b<<endl;
	return 0;
}
