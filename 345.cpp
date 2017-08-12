#include <iostream>
#include <vector>
using namespace std;

bool ifexist(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
		return true;
	}
	return false;
}

string reverseVowels(string s){
   vector<int> index;
   string result = s;
   for (int i = 0; i < s.length(); ++i)
   {
   	if (ifexist(s[i]))
   	{
   		index.push_back(i);
   	}
   }
   for (int i = 0; i < index.size(); ++i)
   {
   	result[index[i]] = s[index[index.size()-1-i]];
   }
   return result;
}

int main(){
	string s("A man, a plan, a canal: Panama");	
    s = reverseVowels(s);
    cout<<s<<endl;
	return 0;
}
