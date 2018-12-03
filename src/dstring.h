#ifndef DSTRING_H
#define DSTRING_H

#define dstring_alloc_str_size(string) (string->length + 1) * sizeof(char)

struct dstring {
	size_t length;
	char *data;
	void (*append)(struct dstring *self, struct dstring *src);
	void (*append_c_str)(struct dstring *self, const char *src);
	void (*set)(struct dstring *self, struct dstring *src);
	void (*set_c_str)(struct dstring *self, const char *src);
	char *(*c_str)(struct dstring *self);
	int (*matches)(struct dstring *self, struct dstring *str2);
	int (*matches_c_str)(struct dstring *self, const char *str2);
	void (*strip)(struct dstring *self);
	void (*ltrim)(struct dstring *self);
	void (*rtrim)(struct dstring *self);
};

typedef struct dstring *string;

// Class functions.
string string_create(const char *src);
string string_clone(const string src);
void string_destroy(string src);
static void dstring_append(string dest, const string src);
static void dstring_append_c_str(string dest, const char *src);
static void dstring_set(string dest, const string src);
static void dstring_set_c_str(string dest, const char *src);
static char *dstring_c_str(const string src);
static int dstring_matches(const string str1, const string str2);
static int dstring_matches_c_str(const string str1, const char *str2);
static void dstring_strip(string src);
static void dstring_ltrim(string src);
static void dstring_rtrim(string src);

#endif
