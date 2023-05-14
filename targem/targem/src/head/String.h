#pragma once
#include <stdio.h>
#include <string.h>
#include <istream>

using namespace std;

class String {
private:
	size_t lenght;
	size_t capacity;
	char* BaseChar;

	String concatenate(const char* date, const char* other);
	String concatenate(String& date, String& other);
	
public:

	String(const char*);
	String(const String& other);
	String();
	~String();

	String(String&& other) noexcept;

	String& operator=(const String&);
	String& operator=(const char*);
	String operator+(const char*);
	String operator+(String&);
	String& operator+=(const char*);
	String& operator+=(String&);
	String& operator>>(istream&);

	explicit operator const char* () { return BaseChar; };
	operator char* () const { return BaseChar; };

	char* get_chars() { return BaseChar; }
	rsize_t get_lenght() { return lenght; }
	rsize_t get_capacity() { return capacity; }
};