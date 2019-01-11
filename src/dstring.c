#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "dstring.h"

string dstring_create(const char *src)
{
	string result = malloc(sizeof(struct dstring));

	result->length = strlen(src);
	result->str = malloc(dstring_alloc_str_size(result));
	strcpy(result->str, src);

	return result;
}

string dstring_clone(const string src)
{
	return dstring_create(src->str);
}

void dstring_destroy(string src)
{
	free(src->str);
	free(src);
}

void dstring_set(string dest, const string src)
{
	dstring_set_c_str(dest, src->str);
}

void dstring_set_c_str(string dest, const char *src)
{
	dest->length = strlen(src);
	dest->str = realloc(dest->str, dstring_alloc_str_size(dest));
	strcpy(dest->str, src);
}

void dstring_append(string dest, const string src)
{
	dstring_append_c_str(dest, src->str);
}

void dstring_append_c_str(string dest, const char *src)
{
	dest->length = strlen(src) + dest->length;
	dest->str = realloc(dest->str, dstring_alloc_str_size(dest));
	strcat(dest->str, src);
}

bool dstring_matches(const string str1, const string str2)
{
	return dstring_matches_c_str(str1, str2->str);
}

bool dstring_matches_c_str(const string str1, const char *str2)
{
	return (strcmp(str1->str, str2) == 0 ? true : false);
}

void dstring_strip(string src)
{
	if (src->length == 0)
		return;

	size_t li = 0, ri = src->length -1;

	for (; li<src->length; ++li) {
		if (! isspace(src->str[li]))
			break;
	}

	for (; ri>0; --ri) {
		if (! isspace(src->str[ri]))
			break;
	}

	size_t diff = src->length - li - (src->length - ri) + 2;
	char *buffer = malloc((diff + 1) * sizeof(char));
	memcpy(buffer, (src->str + (li * sizeof(char))), diff);
	buffer[diff -1] = '\0';

	dstring_set_c_str(src, buffer);

	free(buffer);
}

void dstring_ltrim(string src)
{
	if (src->length == 0)
		return;

	size_t li = 0;
	for (; li<src->length; ++li) {
		if (! isspace(src->str[li]))
			break;
	}

	if (li == 0)
		return;

	size_t diff = src->length - li;
	char *buffer = malloc((diff + 1) * sizeof(char));
	memcpy(buffer, (src->str + (li * sizeof(char))), diff);
	buffer[diff] = '\0';
	dstring_set_c_str(src, buffer);
	free(buffer);
}

void dstring_rtrim(string src)
{
	if (src->length == 0)
		return;

	int ri = src->length -1;
	for (; ri >= 0; --ri) {
		if (! isspace(src->str[ri]))
			break;
	}

	size_t diff = src->length - ri;
	if (diff == src->length)
		return;

	char *buffer = malloc((ri +2) * sizeof(char));
	memcpy(buffer, src->str, ri +1);
	buffer[ri +1] = '\0';
	dstring_set_c_str(src, buffer);
	free(buffer);
}

void dstring_to_upper(string src)
{
	for(size_t i = 0; i<src->length; i++)
		src->str[i] = toupper(src->str[i]);
}

void dstring_to_lower(string src)
{
	for(size_t i = 0; i<src->length; i++)
		src->str[i] = tolower(src->str[i]);
}
