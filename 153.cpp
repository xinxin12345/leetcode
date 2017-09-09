#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMin(vector<int>& nums){
	sort(nums.begin(),nums.end()); 
	return nums[0];
}

int main(){
	int a[7] = {0,1,2,4,5,6,7};
	vector<int> nums(a,a+7);
	cout<<findMin(nums)<<endl;
	return 0;
}
