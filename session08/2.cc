What special methods (constructors, destructors, assignment operators) will the compiler automatically generate for this class? Write explicit versions of these special methods that are equivalent to the ones the compiler would generate. Are these what you would want?

class Person {  
	string name;  
	int age;  
	public:  
	Person(string n, int a) : name(n), age(a) {}  

	string get_name() const { return name; }  
	int get_age() const { return age; }  

	//The compiler will generate:
	//1) a default constructor
	Person(){}
	//2) a copy constuctor and perform memberwise copy
	Person(const Person &other)
	{
		name = other.name;
		age = other.age;
	}
	//3) a assignment constructor which will also do memberwise copy
	Person& operator=(Person &other){
		name = other.name;
		age - other.age;
	}
	//4) a destructor which is empty
	~Person(){}


};


	 Yes these are reasonable generated special methods as no pointers are defined

