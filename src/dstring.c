#include <string.h>
#include <stdlib.h>
#include "dstring.h"

string string_create(const char *src)
{
	string result = malloc(sizeof(struct dstring));
	result->append = &dstring_append;
	result->append_c_str = &dstring_append_c_str;
	result->c_str = &dstring_c_str;
	result->length = strlen(src);
	result->data = malloc(dstring_alloc_str_size(result));
	strcpy(result->data, src);

	return result;
}

void string_destroy(string src)
{
	free(src->data);
	free(src);
}

static void dstring_append(string dest, string src)
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
