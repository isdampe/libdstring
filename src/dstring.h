#ifndef DSTRING_H
#define DSTRING_H
#include <stdbool.h>

#define dstring_alloc_str_size(string) (string->length + 1) * sizeof(char)

struct dstring {
	size_t length;
	char *str;
};

typedef struct dstring *string;

// Class functions.
string dstring_create(const char *src);
string dstring_clone(const string src);
void dstring_destroy(string src);
void dstring_append(string dest, const string src);
void dstring_append_c_str(string dest, const char *src);
void dstring_set(string dest, const string src);
void dstring_set_c_str(string dest, const char *src);
bool dstring_matches(const string str1, const string str2);
bool dstring_matches_c_str(const string str1, const char *str2);
void dstring_strip(string src);
void dstring_ltrim(string src);
void dstring_rtrim(string src);
void dstring_to_upper(string src);
void dstring_to_lower(string src);

#endif
