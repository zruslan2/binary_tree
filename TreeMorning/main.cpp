#include "map_.h"
#include <string>
//#include <map>
using namespace std;



//
//class human{};
//
//bool operator<(const human&h1, const human&h2) {
//	return 0;
//}


//bool check(const string &s1, const string &s2) {
//	return s1.size() < s2.size();
//}

void main() {

	//map<string, int>::key_compare k;


	//map<string, int> mp(k);
	//mp.co
	//mp.key_comp.

	//map_<human, string>  m;


	//human h,h2;
	//m.insert(h, "1");
	//m.insert(h2, "1");
	//while (1) {
	map_<int, string> m;
	m.insert(10, "Ten");
	m.insert(0, "Zero");
	m.insert(5, "Five");
	m.insert(1, "One");
	m.insert(777, "777");
	m.insert(-777, "-777");

	auto m2 = move(m);

	m.print();
	cout << "\n--\n";
	m2.print();
	m2.delNode(m2.getNode(), 10);
	cout << "----------\n";
	m2.print();
	//}
	/*

	string a = m.find(789);
	cout << a<<endl;*/

	system("pause");
	//матрица
	/*vector<vector<vector<vector<>>>> v;
	v.push_back(vector<vector<int>>());
	v[0].push_back(vector<int>());
	v[0][0].push_back(5);*/
}



//
//a<b
//a>=b   !(a<b)
//
//== !(a<b)&&!(b<a)
//!=	!(!(a<b) && !(b<a))
//>	b<a
//
//<= (a<b)|| !(a<b) && !(b<a)
//