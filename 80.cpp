#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
	int index = 0;
   for (int i = 1; i < nums.size(); ++i)
   { 
   	 if(nums[i] == nums[i-1] && ++index <= 1){
   	 	continue;
   	 }
   	 else if(nums[i] != nums[i-1]){
       index = 0;
   	 }
   	 else{
   	 	nums.erase(nums.begin() + i);
   	    i--;
   	 }
   }
   return nums.size();
}

int main(){
	int a[6] = {1,1,1,2,2,3};
	vector<int> nums(a,a+6);
	cout<<removeDuplicates(nums)<<endl;
	return 0;
}
