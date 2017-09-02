#include <iostream>
#include <string>
#include <string.h>
#include <map>
using namespace std;

#define INT_MAX 0x7fffffff

string minWindow(string s,string t){
	string res = "";
	int slen = s.size();
	int tlen = t.size();
	if (slen < 1 || tlen < 1 || slen < tlen)
	{
		return res;
	}
	map<char,int> a;
	for (int i = 0; i < tlen; ++i)
	{
		a[t[i]]++;
	}

    int left = 0;
    int cnt = 0;
    int diff = INT_MAX;

	for (int right = 0; right < slen; ++right)
	{
		if (a.find(s[right]) != a.end())
		{
			if (--a[s[right]] >= 0)
			{
				cnt++;
			}
			while(cnt == tlen){
				if (right - left + 1 < diff)
				{
					diff = right - left + 1 ;
					res = s.substr(left,diff);
				}
				if (a.find(s[left]) != a.end())
				{
					if (++a[s[left]] > 0)
					{
						cnt--;
					}
				}
				left++;
			}
		}
	}
	return res;
}

int main(){
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout<<minWindow(s,t)<<endl;
	return 0;
}
