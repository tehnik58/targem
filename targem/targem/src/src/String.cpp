#include"../head/String.h"

String::String(const char* _mas) {
	lenght = strlen(_mas);
	capacity = lenght;

	line = new char[capacity + 1];
	line[lenght] = '\0';

	strcpy(line, _mas);
}

String::String(const String& other) : String(other.line)
{

}

String::String() {
	line = new char[1];
	line[0] = '\0';
}

String::~String()
{
	delete[] line;
}

String::String(String&& other) noexcept
{
	line = other.line;
	capacity = other.capacity;
	lenght = other.lenght;

	other.line = nullptr;
	other.capacity = 0;
	other.lenght = 0;
}

String& String::operator=(const String& other) {
	size_t count_other = strlen(other.line);
	size_t count_base = strlen(line);

	if (other.line != line) {
		if (count_other < count_base) {
			strcpy(line, other.line);

			lenght = count_other;
		}
		else
		{
			delete[] line;
			capacity = count_other;
			lenght = count_other;

			line = new char[count_other + 1];
			line[lenght] = '\0';

			strcpy(line, other.line);
		}
	}

	return *this;
}

String& String::operator=(const char* other) {
	size_t count_other = strlen(other);
	size_t count_base = strlen(line);

	if (other != line) {
		if (count_other < count_base) {
			strcpy(line, other);

			lenght = count_other;
		}
		else
		{
			delete[] line;
			capacity = count_other;
			lenght = count_other;

			line = new char[count_other + 1];
			line[lenght] = '\0';

			strcpy(line, other);	
		}
	}
	return *this;
}

String operator+(const char* left, const String& right)
{
	String p = String::concatenate(left, right.get_data());
	return p;
}

String operator+(const String& left, const String& right)
{
	String p = String::concatenate(left, right);
	return p;
}

String operator+(const String& left, const char* right)
{
	String p = String::concatenate(left.get_data(), right);
	return p;
}

String& String::operator+=(const char* right)
{
	*this = concatenate(this->line, right);
	return *this;
}

String& String::operator+=(String& right)
{
	*this = concatenate(*this, right);
	return *this;
}

String& String::operator>>(istream& stream)
{
	stream.get(*this->line);
	return *this;
}

String String::concatenate(const char* data, const char* other)
{
	size_t lenght_data = strlen(data);
	size_t lenght_other = strlen(other);
	size_t lenght = lenght_data + lenght_other;

	String result;

	result.line = new char[lenght+1];
	result.line[lenght] = '\0';

	strcpy(result.line, data);
	strcpy(result.line + lenght_data, other);

	result.capacity = lenght;
	result.lenght = lenght;

	return result;
}

String String::concatenate(String& data, String& other)
{
	String result;
	rsize_t lenght= data.get_lenght() + other.get_lenght();

	result.line = new char[ lenght + 1];
	result.line[lenght] = '\0';

	strcpy(result.line, data.line);
	strcpy(result.line + data.get_lenght(), other.line);

	result.capacity = lenght;
	result.lenght = lenght;

	return result;
}