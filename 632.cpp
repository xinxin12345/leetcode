#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define INT_MAX 0x7fffffff

vector<int> smallestRange(vector<vector<int>>& nums){
	vector<int> res;
	vector<pair<int,int>> v;
	unordered_map<int,int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums[i].size(); ++j)
		{
			v.push_back({nums[i][j],i});
		}
	}
	sort(v.begin(),v.end());
	int left = 0,diff = INT_MAX,cnt = 0;
	for (int right = 0; right < v.size(); ++right)
	{
		if (m[v[right].second] == 0)
		{
			cnt++;
		}
		++m[v[right].second];
		while(cnt == nums.size() && left <= right){
			if (diff > v[right].first - v[left].first)
			{
			   diff =  v[right].first - v[left].first;
			   res.clear();
			   res.push_back(v[left].first);
			   res.push_back(v[right].first);
			}
			if(--m[v[left].second] == 0){
               cnt--;
			}
			left++;
		}
	}
	return res;
}

int main(){
	vector<vector<int>> nums;
	vector<int> line;
	line.push_back(4);
	line.push_back(10);
	line.push_back(15);
	line.push_back(24);
	line.push_back(26);
	nums.push_back(line);

	line.clear();

	line.push_back(0);
	line.push_back(9);
	line.push_back(12);
	line.push_back(20);
	nums.push_back(line);

	line.clear();
	
	line.push_back(5);
	line.push_back(18);
    line.push_back(22);
    line.push_back(30);
    nums.push_back(line);

    vector<int> result;

    result = smallestRange(nums);
    for (int i = 0; i < result.size(); ++i)
    {
    	cout<<result[i]<<" ";
    }
    cout<<endl;
	return 0;
}


