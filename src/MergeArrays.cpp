//============================================================================
// Name        : MergeArrays.cpp
// Author      : Xin Liu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<vector<int>::iterator, vector<int>::iterator> Elem;

class Comp {
public:
	Comp(){}
	bool operator ()(Elem& a, Elem& b) {
		return *a.first > *b.first;
	}
};
class Iterator {
public:
	priority_queue<Elem, vector<Elem>, Comp> q_;

	Iterator(vector<vector<int>>& vecs) : q_(Comp()){
		for (auto& v : vecs)
			if (!v.empty())
				q_.push(make_pair(v.begin(), v.end()));
	}

	int get() {
		return *q_.top().first;
	}

	bool next() {
		auto e = q_.top();
		q_.pop();
		e.first ++;
		if (e.first != e.second) {
			q_.push(e);
		}
		return !q_.empty();
	}
};

int main() {
	vector<int> v1{0, 2, 4, 6, 8, 10};
	vector<int> v2{1, 3, 5};
	vector<vector<int>> vecs{v1, v2};
	Iterator it(vecs);
	do {
		cout << it.get() << ", " << endl;
	} while (it.next());
	return 0;
}
