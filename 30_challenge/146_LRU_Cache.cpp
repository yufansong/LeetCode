#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;

 
class LRUCache {
public:
	LRUCache(int capacity) : capacity(capacity) {}
	int get(int key) {
		if (pos.find(key) != pos.end()){
			put(key, pos[key]->second);
			return pos[key]->second;
		}
		return -1;
	}
	void put(int key, int value) {
		if (pos.find(key) != pos.end())
			recent.erase(pos[key]);
		else if (recent.size() >= capacity) {
			pos.erase(recent.back().first);
			recent.pop_back();
		}
		recent.push_front({ key, value });
		pos[key] = recent.begin();
	}
private:
	int capacity;
	list<pair<int, int>> recent;
	unordered_map<int, list<pair<int, int>>::iterator> pos;  //value存储的是一个迭代器
};