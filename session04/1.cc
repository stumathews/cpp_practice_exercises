#include <list>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Queue
{
	list<T> lst;
public:
	void enqueue(T el);
	T dequeue();
	T head() { return lst.front();}
	T tail() {return lst.back();}
	size_t size() { return lst.size();}
};

template <typename T>
void Queue<T>::enqueue(T el) {
	lst.push_back(el);
}

template <typename T>
T Queue<T>::dequeue() {
  	T tmp = head();
	lst.pop_front();
	return tmp;
}

int main(int argc, char** argv)
{
	Queue<string> q;
	q.enqueue("Stuart");
	q.enqueue("Bruce");
	q.enqueue("Jenny");

	assert(q.head() == "Stuart");
	assert(q.tail() == "Jenny");
	assert(q.size() == 3);

	assert(q.dequeue() == "Stuart");
	assert(q.size() == 2);
	assert(q.head() == "Bruce");

	return 0;
}
