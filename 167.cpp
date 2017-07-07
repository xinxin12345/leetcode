#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
	int m = numbers.size();
	vector<int> result;
    
    if (m<2)
    {
    	return result;
    }

	int first = 0;
	int second = m-1;
	while(first != second){
        if (numbers[first] + numbers[second] < target)
        {
        	first++;
        }
        else if(numbers[first] + numbers[second] > target){
        	second--;
        } 
        else{
        	result.push_back(first+1);
        	result.push_back(second+1);
        	return result;
        }
	}
	return result;
}

int main(){
	int a[4] = {2, 7, 11, 15};
	vector<int> numbers(a,a+4);
	int target = 9;
    vector<int> result = twoSum(numbers,target);
    for (int i = 0; i < result.size(); ++i)
    {
    	cout<<result[i]<<" ";
    }
    cout<<endl;
	return 0;
}

