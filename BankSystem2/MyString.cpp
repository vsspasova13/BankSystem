#include "MyString.h"
#pragma warning(disable: 4996)

static unsigned roundToPowerOfTwo(unsigned n)
{
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return n;
}
void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	allocatedDataSize = other.allocatedDataSize;
	data = new char[allocatedDataSize];
	std::strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	other.size = 0;

	allocatedDataSize = other.allocatedDataSize;
	other.allocatedDataSize = 0;
}

void MyString::free()
{
	delete[]data;
	data = nullptr;
	allocatedDataSize = 0;
	size = 0;
}

void MyString::resize(size_t newAllocatedDataSize)
{
	char* newData = new char[newAllocatedDataSize];
	std::strcpy(newData, data);
	delete[]data;
	data = newData;
	allocatedDataSize = newAllocatedDataSize;
}

size_t MyString::getCapacity() const
{
	return allocatedDataSize;
}

size_t MyString::getSize() const
{
	return size;
}
static unsigned getAllocatedNewSize(unsigned length)
{
	return std::max(roundToPowerOfTwo(length + 1), 16u);
}

const char* MyString::c_str() const
{
	return data;
}

MyString& MyString::operator+=(const MyString& other)
{
	if ((getSize() + other.getSize() + 1) > allocatedDataSize)
	{
		resize(getAllocatedNewSize(getSize() + other.getSize()));
	}

	std::strncat(data, other.data, other.getSize());
	size = getSize() + other.getSize();
	return *this;

}

char& MyString::operator[](size_t index)
{

	return data[index];
}

const char& MyString::operator[](size_t index) const
{

	return data[index];
}



MyString::MyString() : MyString("") {}

MyString::MyString(const char* _data)
{
	size = std::strlen(_data);
	allocatedDataSize = getAllocatedNewSize(size);
	data = new char[allocatedDataSize];
	std::strcpy(data, _data);
}

MyString::MyString(size_t length)
{
	allocatedDataSize = getAllocatedNewSize(length);
	data = new char[allocatedDataSize];
	size = 0;
	data[0] = '\0';
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::MyString(MyString&& other)noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

std::ostream& operator<<(std::ostream os, const MyString& obj)
{
	return os << obj.data;
}

std::istream& operator>>(std::istream is, MyString& ref)
{
	char buff[1024];
	is >> buff;
	size_t buffSize = std::strlen(buff);

	if (buffSize > ref.getCapacity())
		ref.resize(getAllocatedNewSize(buffSize));
	strcpy(ref.data, buff);
	ref.size = strlen(ref.c_str());
	return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString temp(lhs.getSize() + rhs.getSize());
	temp += lhs;
	temp += rhs;
	return temp;
}

bool operator==(const MyString& lhs, const MyString rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

bool operator!=(const MyString& lhs, const MyString rhs)
{
	return !(lhs == rhs);
}

bool operator>=(const MyString& lhs, const MyString rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) >= 0);
}

bool operator<=(const MyString& lhs, const MyString rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) <= 0);
}

bool operator>(const MyString& lhs, const MyString rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) > 0);
}

bool operator<(const MyString& lhs, const MyString rhs)
{
	return (std::strcmp(lhs.c_str(), rhs.c_str()) < 0);
}
