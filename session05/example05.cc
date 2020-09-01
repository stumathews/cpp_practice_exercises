#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
void print_vec_index( const vector<T> & v ) {
  cout << '<';
  for (int sz = v.size(), i = 0; i < sz; ++i)
    cout << ' ' << v[i];
  cout << " >";
}

template <typename T>
void print_vec_iterator1( const vector<T> & v ) { // Old C++
  cout << '<';
    // UNCOMMENT the different for loops to see the errors you get.
  // WRONG: Need typename before template type since vector<T> doesn't exist!!!
  // for (vector<T>::const_iterator i = begin(v); i != end(v); ++i)
  // WRONG: Need a constant iterator, as v is a const reference
  // for (typename vector<T>::iterator i = begin(v); i != end(v); ++i)
  for (typename vector<T>::const_iterator i = begin(v); i != end(v); ++i)
    cout << ' ' << *i;
  cout << " >";
}

template <typename T>
void print_vec_iterator2( const vector<T> & v ) { // New C++ (C++11)
  cout << '<';
  for (auto i = begin(v); i != end(v); ++i)
    cout << ' ' << *i;
  cout << " >";
}

template <typename T>
void print_list_old(const list<T> &l)
{
	for(typename list<T>::const_iterator b = begin(l); b != end(l);b++){
		cout << *b << endl;
	}
}

template <typename T>
void print_list_new(const list<T> &l)
{
	for(auto b = begin(l); b != end(l);b++) {
		cout << *b << endl;
	}
}

int main() {
  vector<int> vi;
  vi.push_back(1);
  vi.push_back(2);
  vi.push_back(3);
  print_vec_index(vi); cout << endl;
  print_vec_iterator1(vi); cout << endl;
  print_vec_iterator2(vi); cout << endl;

  list<string> names;
  names.push_back("Stuart");
  names.push_back("Jenny");
  names.push_back("Bruce");

  print_list_old(names);
  print_list_new(names);


  return 0;
}
