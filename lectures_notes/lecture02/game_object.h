#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <string>
class game_object
{
	protected:
	int _x, _y;
	bool is_active = false; // default values since C++ 11 (not allowed in c++ 98) 
	const game_object *_pchild = nullptr;
	public:
	game_object(); 
	game_object(int x, int y);
	game_object(const game_object& other); // copy constructor
	~game_object(); // destructor
	const game_object& operator=(const game_object &other); // assignmet operator
	void print_position() const; // wont change this object
	inline int get_x() const { return _x;} // inline becasue simple function
	inline int get_y() const { return _y;}
	virtual std::string get_position_string() const;
	void add_child(const game_object* child);
};
#endif
