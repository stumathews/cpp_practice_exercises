#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

class String {
	int len;
	char *chars;
        // Invariant: chars points to an array of len characters
	int current_len;

public:
	String(const char *s) : len(strlen(s)), chars(nullptr), current_len(len) {
		cout << "constructor called" << endl;
                chars = new char[len]; // len always has a valid value here.
		for (int i = 0; i < len; i++)
			chars[i] = s[i];
	}

	// default constructor - empty array to keep the invariant!
	String() : len(0), chars(new char[0]) {}

	// destructor
	virtual ~String() { 
		cout << "dtor for string object with contents:" << *chars << endl;
		delete[] chars; }

	// copy constructor
	String(const String &s) : len(s.len), chars(new char[s.len]) {
		for (int i = 0; i < len; i++)
			chars[i] = s.chars[i];
	}

	int length() { return len; }

	// assignment operator
	
	// Original, normal implementation
	String & operator= (const String &s) {
		if (&s != this) {   // don't copy onto self
			if(s.len > len)
			{
				cout << "Need bigger array. Current size=" << length() << " reallocating. New length:" << s.len << endl;
				delete[] chars;
				chars = new char[s.len];
			} else {
				cout << "reusing existing array" << endl;
			}
			len = s.len;
			for (int i = 0; i < len; i++)
				chars[i] = s.chars[i];
		}
		return *this;
	}
	

	void myswap(String &o) {
		swap(len, o.len);
		swap(chars, o.chars);
	}
	// implementation using call-by-value (copy) & swap
	/* String & operator= (String o) { */
	/* 	myswap(o); */
	/* 	return *this; */
	/* } */
	
	// print out a String
	ostream& print(ostream &o = cout) const {
		o << '"';
		for (int i = 0; i < len; i++)
			o << chars[i];
		o << '"';
		o << endl;
		return o;
	}
};

ostream &operator<< ( ostream &o, const String &s ) {
  return s.print(o);
}

int main(int argc, char *argv[]) {
	String s1;

	s1 = String("wheel");

	cout << s1 << endl;
	/*
	  A String object is constructed using a paramaterised constructor where the single parameter is of type char* (constructor called)
	  The resulting temporary object(space on the stack) is then assigned through S1's assignment operator to the variable s1, also of the same type
	  s1's assignment operator creates a new space in memory for the contents of the temporary's array contents, copies the content of the temporary objects underlying array to the newly allocated corresponding location(its own array) in the s1 object, element for element. It does not allocate a new space if the existing space is big enough to hold the incomming array. 
	temporary object's destructor is called.
	s1' destructor is called
	 * */

	return 0;
}
