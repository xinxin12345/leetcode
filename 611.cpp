#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool iftriplets(int a,int b,int c){
	if (a+b>c && a+c>b && b+c>a)
	{
		return true;
	}
	return false;
}

int triangleNumber(vector<int>& nums){
	int res = 0;
	int len = nums.size();
	if (len <= 2)
	{
		return res;
	}
	sort(nums.begin(),nums.end());
	int left = 0;
	int right = 1;
	int temp = 2;
	for (left = 0; left < len-2; ++left)
	{
		for (right = left+1; right < len-1; ++right)
		{
			for (temp = right+1; temp < len; ++temp)
			{
				if (iftriplets(nums[left],nums[right],nums[temp]))
				{
					res++;
				}
			}
		}
	}
	return res;

}

int main(){
	int a[4] = {2,2,3,4};
	vector<int> nums(a,a+4);
	cout<<triangleNumber(nums)<<endl;
	return 0;
}


