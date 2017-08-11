#include <iostream>
#include <string>
using namespace std;

string reverseString(string s){
string str(s.rbegin(),s.rend());
return str;
}

int main(){
	string s("hello");
	cout<<reverseString(s)<<endl;
	return 0;
}
