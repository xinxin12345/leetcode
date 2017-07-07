#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 0x7fffffff

 int maxProfit(vector<int>& prices){
 	int maxprofit = 0;
 	int minindex = INT_MAX;
 	for (int i = 0; i < prices.size(); ++i)
 	{
 		minindex = min(minindex,prices[i]);
 		maxprofit = max(maxprofit,prices[i] - minindex);
 	}
 	return maxprofit;
 }

int main(){
	int a[6] = {7,1,5,3,6,4};
	vector<int> prices(a,a+6);
	cout<<maxProfit(prices)<<endl;
	return 0;
}
