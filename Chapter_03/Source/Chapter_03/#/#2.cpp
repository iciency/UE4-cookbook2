#include <stdio.h>

class Object
{
public:
	Object()
	{
		puts("object constructed");
	}
	~Object()
	{
		puts("object destructed");
	}
};

int main()
{
	Object * object = new Object();

	delete object;

	object = 0;
}


