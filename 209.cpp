#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 0x7fffffff

int minSubArrayLen(int s, vector<int>& nums){
   int len = nums.size();
   int result = 0;
   int minvalue = INT_MAX;
   int sum = 0;
   int count = 1;
   int i = 0;
   if (len == 0)
   {
   	return result;
   }
   if (len == 1 && nums[0] == s)
   {
   	return len;
   }

   while(i < len)
   {
   	sum += nums[i];
   	if (sum < s)
   	{
   		count++;
   		i++;
   	}
   	else 
   	{
   		minvalue = min(minvalue,count);
   		i = i - count + 2;
   		count = 1;
   		sum = 0;
   	}
   }
   if (minvalue == INT_MAX)
   {
   	return 0;
   }
   return minvalue;
}

int main(){
	int s = 80;
	int a[14] = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
	vector<int> nums(a,a+14);
	cout<<minSubArrayLen(s,nums);
	return 0;
}


