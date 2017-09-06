#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string itos(int i){
	stringstream s;
	s << i;
	return s.str();
}

int findindex(string str,int n){
	for (int i = str.length()-1; i >= 0; --i)
	{
		if (str[i] - '0' == n)
		{
			return i;
		}
	}
}

int maximumSwap(int num){
	int res = 0;
	vector<int> sortarray;
	string str = itos(num);

	while(num){
      sortarray.push_back(num%10);
      num /= 10;
	}

	sort(sortarray.begin(),sortarray.end(),greater<int>());
    
    for (int i = 0; i < str.length(); ++i)
    {
    	if (str[i] - '0' != sortarray[i])
    	{
    		str[findindex(str.substr(i,str.length()-i),sortarray[i])+i] = str[i];
    		str[i] = sortarray[i] + '0';
    		break;
    	}
    }

    for (int i = 0; i < str.length() ; ++i)
    {
    	res = res*10 + str[i] - '0';
    }
    return res;

}

int main(){
	int num = 1993;
	cout<<maximumSwap(num)<<endl;
	return 0;
}

