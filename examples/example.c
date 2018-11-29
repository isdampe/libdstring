#include <stdio.h>
#include "../src/dstring.h"

int main(int argc, char **argv)
{
	string name = string_create("is");
	name->append_c_str(name, "dampe");

	string welcome = string_create("Thank you testing libdstring.\n\n-- ");
	welcome->append(welcome, name);
	printf("%s\n", welcome->c_str(welcome));

	welcome->set_c_str(welcome, "It really works.");
	printf("%s\n", welcome->c_str(welcome));

	string_destroy(welcome);
	string_destroy(name);

	return 0;
}
