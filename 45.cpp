#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
	if (nums.size() == 1)
	{
		return 0;
	}
	int Maxreach = 0 + nums[0],i = 0,k = 0,step = 1;
	while(Maxreach < nums.size()-1){
		step++;
		for (int j = i + 1; j <= i + nums[i] ; ++j)
		{
			if (nums[j] + j > Maxreach)
			{
				Maxreach = nums[j] + j;
				k = j;
			}
		}
		i = k;
	}
	return step;
	    
    }

    int main(){
    	int a[5] = {2,3,1,1,4};
    	vector<int> nums(a,a+5);
    	cout<<jump(nums)<<endl;
    	return 0;
    	return 0;
    }


