#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 0x7fffffff

//int maxProfit(vector<int>& prices){
//	int m = prices.size();
//	int maxvalue = 0;
//	for(int i = 0;i < m-1;i++){
//		for(int j = i+1;j < m;j++){
//			if(prices[j] - prices[i] > maxvalue){
//				maxvalue = prices[j] - prices[i];
//			}
//		}	
//	}
//	return maxvalue;
//}

int maxProfit(vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}

int main(){
	int a[6]={7, 1, 5, 3, 6, 4};

	vector<int> prices(a,a+6);
	cout<<maxProfit(prices)<<endl; 
	return 0;
}
