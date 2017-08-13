#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2){
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 > len2)
	{
		return false;
	}
    
    vector<int> maps1(26),maps2(26);
    for (int i = 0; i < len1; ++i)
    {
    	maps1[s1[i] - 'a']++;
    	maps2[s2[i] - 'a']++;
    }
    if (maps1 == maps2)
    {
    	return true;
    }

    for (int i = 0; i + len1 < len2; ++i)
    {
    	maps2[s2[i] - 'a']--;
    	maps2[s2[i + len1] - 'a']++;
    	if (maps1 == maps2)
    	{
    		return true;
    	}
    }
    return false;
}

int main(){
	string s1("ab");
	string s2("eidbaooo");
	cout<<checkInclusion(s1,s2)<<endl;
	return 0;
}
