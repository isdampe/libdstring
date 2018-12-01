#include <stdio.h>
#include "../src/dstring.h"

int main(int argc, char **argv)
{
	string name = string_create("is");
	name->append_c_str(name, "dampe");

	string name_copy = string_clone(name);

	string welcome = string_create("Thank you testing libdstring.\n\n-- ");
	welcome->append(welcome, name);
	printf("%s\n", welcome->c_str(welcome));

	welcome->set_c_str(welcome, "It really works.");
	printf("%s\n", welcome->c_str(welcome));

	welcome->set(welcome, name);
	printf("%s\n", welcome->c_str(welcome));

	string test1 = string_create("Hello world.");
	string test2 = string_create("Hello world.");
	if (test1->matches(test1, test2))
		printf("The strings match!\n");

	string strip = string_create("  It works .  ");
	printf("'%s'\n", strip->c_str(strip));
	strip->strip(strip);
	printf("'%s'\n", strip->c_str(strip));

	string strip2 = string_create("");
	printf("'%s'\n", strip2->c_str(strip2));
	strip->strip(strip2);
	printf("'%s'\n", strip2->c_str(strip2));


	string_destroy(welcome);
	string_destroy(name);
	string_destroy(name_copy);
	string_destroy(test1);
	string_destroy(test2);

	return 0;
}
