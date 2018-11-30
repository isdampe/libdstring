#include <string.h>
#include <stdlib.h>
#include "dstring.h"

string string_create(const char *src)
{
	string result = malloc(sizeof(struct dstring));

	result->append = &dstring_append;
	result->append_c_str = &dstring_append_c_str;
	result->set = &dstring_set;
	result->set_c_str = &dstring_set_c_str;
	result->c_str = &dstring_c_str;
	result->match = &dstring_match;
	result->match_c_str = &dstring_match_c_str;

	result->length = strlen(src);
	result->data = malloc(dstring_alloc_str_size(result));
	strcpy(result->data, src);

	return result;
}

string string_clone(const string src)
{
	return string_create(src->data);
}

void string_destroy(string src)
{
	free(src->data);
	free(src);
}

static void dstring_set(string dest, const string src)
{
	dstring_set_c_str(dest, src->data);
}

static void dstring_set_c_str(string dest, const char *src)
{
	dest->length = strlen(src);
	dest->data = realloc(dest->data, dstring_alloc_str_size(dest));
	strcpy(dest->data, src);
}

static void dstring_append(string dest, const string src)
{
	dstring_append_c_str(dest, src->data);
}

static void dstring_append_c_str(string dest, const char *src)
{
	dest->length = strlen(src);
	dest->data = realloc(dest->data, dstring_alloc_str_size(dest));
	strcat(dest->data, src);
}

static char *dstring_c_str(const string src)
{
	return src->data;
}

static int dstring_match(const string str1, const string str2)
{
	return dstring_match_c_str(str1, str2->data);
}

static int dstring_match_c_str(const string str1, const char *str2)
{
	return (strcmp(str1->data, str2) == 0 ? 1 : 0);
}
