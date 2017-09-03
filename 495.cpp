#include <iostream>
#include <vector>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration){
	int res = 0;
	if (timeSeries.size() == 0)
	{
		return res;
	}
	for (int i = 0; i < timeSeries.size() - 1; ++i)
	{
		if (timeSeries[i] + duration - 1 < timeSeries[i+1])
		{
			res += duration;
		}
		else{
			res += timeSeries[i+1] - timeSeries[i];
		}
	}
	res += duration;
	return res;
}

int main(){
    int a[2] = {1,2};
	vector<int> timeSeries(a,a+2);
	int duration = 2;
	cout<<findPoisonedDuration(timeSeries,duration)<<endl;
	return 0;
}

