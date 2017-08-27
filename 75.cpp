#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums){
    int len = nums.size();
    if (len < 2)
    {
    	return;
    }

	int num0 = 0;
	int num1 = 0;
	int num2 = 0;
    
	for (int i = 0; i < len; ++i)
	{
		if (nums[i] == 0)
		{
			num0++;
		}
		else if(nums[i] == 1){
			num1++;
		}
		else{
			num2++;
		}
	}
	for (int i = 0; i < num0; ++i)
	{
		nums[i] = 0;
	}
	for (int i = num0; i < num0+num1; ++i)
	{
		nums[i] = 1;
	}
	for (int i = num0+num1; i < len; ++i)
	{
		nums[i] = 2;
	}
}

int main(){
	int a[4] = {2,1,0,2};
	vector<int> nums(a,a+4);
	sortColors(nums);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	return 0;
}
