#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(),nums2.end());
	int len1 = nums1.size();
	int len2 = nums2.size();
	vector<int> result;
	if (len1 == 0 || len2 == 0)
	{
		return result;
	}

   int num = 0;
   int i = 0,j = 0;
   while(i != len1 && j!= len2){
   	if (nums1[i] == nums2[j])
   	{
   		result.push_back(nums1[i]);
   		i++;
   		j++;
   	}
   	else if(nums1[i] < nums2[j]){
        i++;
   	}
   	else{
       j++;
   	}
   }
   return result; 	
}

int main(){
	int a[4] = {1,2,2,1};
	int b[2] = {2,2};
	vector<int> nums1(a,a+4);
	vector<int> nums2(b,b+2);
	vector<int> result = intersect(nums1,nums2);
	for (int i = 0; i < result.size(); ++i)
	{
	cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
