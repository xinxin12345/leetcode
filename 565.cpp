#include <iostream>
#include <vector>
using namespace std;

int arrayNesting(vector<int>& nums){
 int maxLength=-1;  
 for(int firstIndex=0;firstIndex<=nums.size()-1;firstIndex++){  
    int length=0;  
    while(nums[firstIndex]!=-1){  
        length++;  
        int firstTemp=nums[firstIndex];  
        nums[firstIndex]=-1;  
        firstIndex=firstTemp;  
    }  
    maxLength=maxLength>length?maxLength:length;  
}  
return maxLength;
}

int main(){
	int a[3] = {1,2,3};
	vector<int> nums(a,a+3);
	cout<<arrayNesting(nums)<<endl;
	return 0;
}


