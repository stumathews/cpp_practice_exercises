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
	cout << "construct s2 from s1 - copy constructor. s1 length is " << s1.length() << endl;
	String s2 = s1;
	cout << "length of s2 is " << s2.length() << endl;
	cout << "construct new s3..." << endl;;
	String s3 = "fred";
	cout << "s3 is initialized to '"<< s3 <<"' and length:" << s3.length() << endl;
	cout << "assigning s3 to s2" << endl;
	s2 = s3;
	cout << "assigning s2 to s2" << endl;
	s2 = s2;	// nothing happens

	cout << "s1:";
	s1.print();
	cout << endl;
	cout << "s2:";
	s2.print();
	cout << endl;
	cout << "s3:";
	s3.print();
	cout << endl;

	cout << "assigning single char s3" << endl;
	s3 = "a";
	cout << "s3 length is :" << s3.length() << " content: " << s3 << endl;
	cout << "assignign bigger than array to s3" << endl;
	s3 = "Absolutely long";
	cout << "s3 length is :" << s3.length() << " content: " << s3 << endl;

	return 0;
}
