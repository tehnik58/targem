#pragma once
#include <stdio.h>
#include <string.h>
#include <istream>

using namespace std;

class String {
private:
	size_t lenght;
	size_t capacity;
	char* line;

	static String concatenate(const char* date, const char* other);
	static String concatenate(String& date, String& other);
	
public:

	String(const char*);
	String(const String& other);
	String();
	~String();

	String(String&& other) noexcept;

	String& operator=(const String&);
	String& operator=(const char*);
	friend String operator+(const String&, const char*);
	friend String operator+(const char*, const String&);
	friend String operator+(const String&, const String&);
	String& operator+=(const char*);
	String& operator+=(String&);
	String& operator>>(istream&);

	explicit operator const char* () { return line; };
	operator char* () const { return line; };

	const char* get_data() const { return line; }
	rsize_t get_lenght() const { return lenght; }
	rsize_t get_capacity() const { return capacity; }
};

String operator+(const String&, const char*);
String operator+(const char*, const String&);
String operator+(const String&, const String&);