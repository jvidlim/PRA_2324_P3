#ifndef DICT_H
#define DICT_H
#include <string>
using namespace std;

template <typename V> class Dict{

	public:
		void insert(string key, V value) = 0;
		V search(string key) = 0;
		V remove(string key) = 0;
		int rentries() = 0;

};



#endif
