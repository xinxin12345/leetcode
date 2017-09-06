#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int,int> data_map;
vector<int> data;
/** Initialize your data structure here. */
RandomizedSet() {

}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool insert(int val) {
	if (data_map.count(val) != 0)
	{
		return false;
	}
	else{
		data.push_back(val);
		data_map[val] = data.size()-1;
		return true;
	}
}

    /** Removes a value from the set. Returns true if the set contained the specified element. */
bool remove(int val) {
	if (data_map.count(val) == 0)
	{
		return false;
	}
	else{
		int tail = data[data.size()-1];
		int pos1 = data_map[val];
		int pos2 = data.size()-1;
		data_map[val] = pos1;
		data_map[tail] = pos2;
		data[pos1] = tail;
		data_map.erase(val);
		data.pop_back();
		return true;
	}

}

    /** Get a random element from the set. */
int getRandom() {
    int t = data.size();
    int random_num = rand()%t;
    return data[random_num];
}