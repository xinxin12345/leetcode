#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string findLongestWord(string s, vector<string>& d){
   int len = d.size();
   int len1 = s.length();
   int len2;
   string temp;
   int exist = 0;
   string result;
   for (int i = 0; i < len; ++i)
   {
   	exist = 0;
   	temp = d[i];
    len2 = temp.length();
    int sindex = 0,tempindex = 0;
    while(sindex != len1 && tempindex != len2){
       if (s[sindex] == temp[tempindex])
       {
       	tempindex++;
       	sindex++;
       }
       else{
       	sindex++;
       }
    }
    if (tempindex == len2)
    {
    	if (result == "")
    	{
    		result = temp;
    	}
    	else if (temp.length() > result.length())
    	{
    		result = temp;
    	}
    	else if (temp.length() == result.length() && strcmp(temp.c_str(),result.c_str()) < 1)
    	{
    		result = temp;
    	}
    }
   }
   return result;
}

int main(){
	string s("abpcplea");
	vector<string> d = {"a","b","c"};
	string result = findLongestWord(s,d);
	cout<<result<<endl;
	return 0;
}


