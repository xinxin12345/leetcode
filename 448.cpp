#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums){
	int len = nums.size();
	vector<int> result;
	int index = 1;
	sort(nums.begin(),nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for (int i = 0; i < nums.size(); )
	{
		if (nums[i] != index)
		{
			result.push_back(index);
			index++;
		}
		else{
			i++;
			index++;
		}
    }
    if (index == len+1)
    {
    	return result;
    }
    else{
    	for (int i = index; i <= len; ++i)
    	{
    		result.push_back(i);
    	}
    	return result;
    }
    
}

int main(){
	int a[2] = {1,1};
	vector<int> nums(a,a+2);
	nums = findDisappearedNumbers(nums);
	for (int i = 0; i < nums.size(); ++i)
	 {
	 	cout<<nums[i]<<" ";
	 } 
	 cout<<endl;
	return 0;
}
