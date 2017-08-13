#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle){
  int len1 = haystack.length();
  int len2 = needle.length();
  int index = 0;
  if (len1 < len2)
  {
  	return -1;
  }
  if (len2 == 0)
  {
  	return 0;
  }
  int i = 0,j = 0;
  while(i != len1 && j != len2){
       if (haystack[i] == needle[j])
       {
       	index++;
       	if (index == len2)
       	{
       		return i-len2+1;
       	}
       	i++;
       	j++;
       }
       else{
       	index = 0;
       	if(j == 0){
       		i++;
       	}
       	else{
       	i = i - j + 1;
       	j = 0;
       	} 	
       }
  }
  return -1;
}

int main(){
	string haystack("mississippi");
	string needle("issipi");
	cout<<strStr(haystack,needle)<<endl;
	return 0;
}


