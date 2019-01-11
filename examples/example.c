#include <stdio.h>
#include "../src/dstring.h"

int main(int argc, char **argv)
{
	string name = dstring_create("is");
	dstring_append_c_str(name, "dampe");

	string name_copy = dstring_clone(name);

	string welcome = dstring_create("Thank you testing libdstring.\n\n-- ");
	dstring_append(welcome, name);
	printf("%s\n", welcome->str);

	dstring_set_c_str(welcome, "It really works.");
	printf("%s\n", welcome->str);

	dstring_set(welcome, name);
	printf("%s\n", welcome->str);

	string test1 = dstring_create("Hello world.");
	string test2 = dstring_create("Hello world.");
	if (dstring_matches(test1, test2))
		printf("The strings match!\n");

	string strip = dstring_create("  It works .  ");
	printf("'%s'\n", strip->str);
	dstring_strip(strip);
	printf("'%s'\n", strip->str);


	string strip2 = dstring_create("");
	printf("'%s'\n", strip2->str);
	dstring_strip(strip2);
	printf("'%s'\n", strip2->str);

	string lstrip = dstring_create("   It's Richard.");
	printf("'%s'\n", lstrip->str);
	dstring_ltrim(lstrip);
	printf("'%s'\n", lstrip->str);

	string rstrip = dstring_create("It's Richard.       ");
	printf("'%s'\n", rstrip->str);
	dstring_rtrim(rstrip);
	printf("'%s'\n", rstrip->str);

	string cs = dstring_create("HELLo WorLd");
	printf("%s\n", cs->str);
	dstring_to_lower(cs);
	printf("%s\n", cs->str);
	dstring_to_upper(cs);
	printf("%s\n", cs->str);

	dstring_destroy(welcome);
	dstring_destroy(name);
	dstring_destroy(name_copy);
	dstring_destroy(test1);
	dstring_destroy(test2);
	dstring_destroy(lstrip);
	dstring_destroy(rstrip);
	dstring_destroy(cs);

	return 0;
}
