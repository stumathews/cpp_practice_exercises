#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

class String {
	int len;
	char *chars;
        // Invariant: chars points to an array of len characters

public:
	String(const char *s) : len(strlen(s)), chars(nullptr) {
                chars = new char[len]; // len always has a valid value here.
		for (int i = 0; i < len; i++)
			chars[i] = s[i];
	}

	// default constructor - empty array to keep the invariant!
	String() : len(0), chars(new char[0]) {}

	// destructor
	virtual ~String() { delete[] chars; }

	// copy constructor
	String(const String &s) : len(s.len), chars(new char[s.len]) {
		for (int i = 0; i < len; i++)
			chars[i] = s.chars[i];
	}

	// assignment operator
	/*
	// Original, normal implementation
	String & operator= (const String &s) {
		if (&s != this) {   // don't copy onto self
			delete[] chars;
			len = s.len;
			chars = new char[len];
			for (int i = 0; i < len; i++)
				chars[i] = s.chars[i];
		}
		return *this;
	}
	*/

	void myswap(String &o) {
		swap(len, o.len);
		swap(chars, o.chars);
	}
	// implementation using call-by-value (copy) & swap
	String & operator= (String o) {
		myswap(o);
		return *this;
	}
	
	// print out a String
	ostream& print(ostream &o = cout) const {
		o << '"';
		for (int i = 0; i < len; i++)
			o << chars[i];
		o << '"';
		o << endl;
	}
};

ostream &operator<< ( ostream &o, const String &s ) {
  return s.print(o);
}

int main(int argc, char *argv[]) {
	String s1;
	String s2 = s1;
	String s3 = "fred";
	s2 = s3;
	s2 = s2;	// nothing happens

	s1.print();
	s2.print();
	s3.print();

	return 0;
}
