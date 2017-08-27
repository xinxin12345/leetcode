#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;

bool isPalindrome(string s) {
	int len = s.length();
	if (len == 0)
	{
		return true;
	}
	int i = 0,j = len-1;
	while(i < j){

		while(!isalnum(s[i]) && i < len){
			i++;
		}
		if ('A'<=s[i]&&s[i]<='Z')
		{
			s[i] = s[i]+32;
		}

		while(!isalnum(s[j]) && j >= 0){
			j--;
		}
		if ('A'<=s[j]&&s[j]<='Z')
		{
			s[j] = s[j]+32;
		}

		if(i == len && j == -1){
			return true;
		}

		if (s[i] != s[j])
		{
			return false;
		}
		else{
			i++;
			j--;
		}
	}
	return true;


}

int main(){
	string s(".,");
	cout<<isPalindrome(s)<<endl;
	return 0;
}


