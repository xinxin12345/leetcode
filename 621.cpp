#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n){
	int len = tasks.size();
	vector<int> res(26,0);
	for (int i = 0; i < tasks.size(); ++i)
	{
       	res[tasks[i]-'A']++;
	}
	sort(res.begin(),res.end());
	int i = 25;
	while(i>=0 && res[25] == res[i]){
		i--;
	}
	return max((res[25]-1)*(n+1)+25-i,len);
}

int main(){
	int n = 2;
    char a[6] = {'A','A','A','B','B','B'};
    vector<char> tasks(a,a+6);
    cout<<leastInterval(tasks, n)<<endl;
	return 0;
}
