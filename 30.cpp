#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
  vector<int> res;
  map<string,int> traits;

  if (L.empty() || S.empty())
  {
    return res;
  }

  for (int i = 0; i < L.size(); ++i)
  {
    traits[L[i]]++;
  }
  int len = L[0].length();

  for (int i = 0; i < len; ++i)
  {
    map<string,int> window;

    int left = i;
    int right = i;
    while(right < S.length()){
      while(right < S.length()){
        string word = S.substr(right,len);
        right += len;

        if (traits.find(word) == traits.end())
        {
          window.clear();
          left = right;
        }
        else{
           window[word]++;
           if (window[word] >= traits[word])
           {
             break;
           }
        }
      }
      while(left < right){
        string head = S.substr(left,len);
        string tail = S.substr(right - len,len);
        if (window[tail] == traits[tail])
        {
          break;
        }
        left += len;
        window[head]--;

      }
      if (right - left == len*L.size())
      {
        res.push_back(left);
      }
    }
  }
  return res;
}

int main(){
	vector<int> result;
	string s = "ababaab";
	vector<string> words;
	words.push_back("ab");
	words.push_back("ba");
	words.push_back("ba");
	result = findSubstring(s,words);
	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}


