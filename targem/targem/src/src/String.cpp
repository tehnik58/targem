#include"../head/String.h"

String::String(const char* _mas) {
	lenght = strlen(_mas);
	capacity = lenght;

	BaseChar = new char[capacity + 1];
	BaseChar[lenght] = '\0';

	strcpy(BaseChar, _mas);
}

String::String(const String& other) : String(other.BaseChar)
{

}

String::String() {
	BaseChar = new char[1];
	BaseChar[0] = '\0';
}

String::~String()
{
	delete[] BaseChar;
}

String::String(String&& other) noexcept
{
	BaseChar = other.BaseChar;
	capacity = other.capacity;
	lenght = other.lenght;

	other.BaseChar = nullptr;
	other.capacity = 0;
	other.lenght = 0;
}

String& String::operator=(const String& other) {
	size_t count_other = strlen(other.BaseChar);
	size_t count_base = strlen(BaseChar);

	if (other.BaseChar != BaseChar) {
		if (count_other < count_base) {
			strcpy(BaseChar, other.BaseChar);

			lenght = count_other;
		}
		else
		{
			delete[] BaseChar;
			capacity = count_other;
			lenght = count_other;

			BaseChar = new char[count_other + 1];
			BaseChar[lenght] = '\0';

			strcpy(BaseChar, other.BaseChar);
		}
	}

	return *this;
}

String& String::operator=(const char* other) {
	size_t count_other = strlen(other);
	size_t count_base = strlen(BaseChar);

	if (other != BaseChar) {
		if (count_other < count_base) {
			strcpy(BaseChar, other);

			lenght = count_other;
		}
		else
		{
			delete[] BaseChar;
			capacity = count_other;
			lenght = count_other;

			BaseChar = new char[count_other + 1];
			BaseChar[lenght] = '\0';

			strcpy(BaseChar, other);	
		}
	}
	return *this;
}

String String::operator+(const char* right)
{
	String p = concatenate(BaseChar, right);
	return p;
}

String String::operator+(String& right)
{
	String p = concatenate(*this, right);
	return p;
}

String& String::operator+=(const char* right)
{
	*this = concatenate(this->BaseChar, right);
	return *this;
}

String& String::operator+=(String& right)
{
	*this = concatenate(*this, right);
	return *this;
}

String& String::operator>>(istream& stream)
{
	stream.get(*this->BaseChar);
	return *this;
}



String String::concatenate(const char* date, const char* other)
{
	size_t lenght_date = strlen(date);
	size_t lenght_other = strlen(other);
	size_t lenght = lenght_date + lenght_other;

	String result;

	result.BaseChar = new char[lenght+1];
	result.BaseChar[lenght] = '\0';

	strcpy(result.BaseChar, date);
	strcpy(result.BaseChar + lenght_date, other);

	result.capacity = lenght;
	result.lenght = lenght;

	return result;
}

String String::concatenate(String& date, String& other)
{
	String result;
	rsize_t lenght= date.get_lenght() + other.get_lenght();

	result.BaseChar = new char[ lenght + 1];
	result.BaseChar[lenght] = '\0';

	strcpy(result.BaseChar, date.BaseChar);
	strcpy(result.BaseChar + date.get_lenght(), other.BaseChar);

	result.capacity = lenght;
	result.lenght = lenght;

	return result;
}
