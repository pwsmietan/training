#include <cstring>
#include <iostream>
#include <string>

unsigned int digit_sum(unsigned int num);
void show_odds(unsigned long long int num);
bool is_palindrome(unsigned long long int num);
void sayAgeByPtr(int *a);
void sayAgeByRef(int &a);
void print_sum(int *param1, int *param2);

enum class DayOfWeek
{
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

int main()
{
	char *result = new char[50]{' '};
	const char src1[]{"will old space the replace"};
	const char src2[]{"sense sky  hit has"};
	const char src3[]{"hello went is get"};
	const char src4[]{"red blue yellow orange"};

	const char *stest{"will old space the replace"};

	// copy "the sky is blue" (one word) from each char array 1..4:
	std::cout << "*stest: " << *stest << "; &stest: " << &stest << std::endl;

	std::cout << "source: " << src1 << std::endl;
	char *idx1 = std::strstr(src1, "the");
	int offset1 = idx1 - src1;
	std::cout << "idx1: " << *idx1 << "; &idx1: " << &idx1 << "; offset diff: " << offset1 << std::endl;

	// char * result from strncpy returns junk :-(
	char *val1 = std::strncpy(result, src1 + offset1, 4);
	std::cout << "result: " << result << "; length of result: " << std::strlen(result) << std::endl;

	std::cout << "***" << std::endl;

	std::cout << "source2: " << src2 << std::endl;
	char *idx2 = std::strstr(src2, "sky");
	int offset2 = idx2 - src2;
	std::cout << "idx2: " << *idx2 << "; &idx2: " << &idx2 << "; offset diff: " << offset2 << std::endl;

	int startIdx2 = std::strlen(result);
	std::strncpy(result + startIdx2, src2 + offset2, 4);
	std::cout << "start Idx: " << startIdx2 << "; result: " << result << "; length of result: " << std::strlen(result) << std::endl;

	std::cout << "***" << std::endl;

	std::cout << "source3: " << src3 << std::endl;
	char *idx3 = std::strstr(src3, "is");
	int offset3 = idx3 - src3;
	std::cout << "idx3: " << *idx3 << "; &idx3: " << &idx3 << "; offset diff: " << offset3 << std::endl;

	int startIdx3 = std::strlen(result);
	std::strncpy(result + startIdx3, src3 + offset3, 3);
	std::cout << "start Idx: " << startIdx3 << "; result: " << result << "; length of result: " << std::strlen(result) << std::endl;

	std::cout << "***" << std::endl;

	std::cout << "source4: " << src4 << std::endl;
	char *idx4 = std::strstr(src4, "blue");
	int offset4 = idx4 - src4;
	std::cout << "idx4: " << *idx4 << "; &idx4: " << &idx4 << "; offset diff: " << offset4 << std::endl;

	int startIdx4 = std::strlen(result);
	std::strncpy(result + startIdx4, src4 + offset4, 4);
	result[strlen(result)] = '\0';
	std::cout << "start Idx: " << startIdx4 << "; result: " << result << "; length of result: " << std::strlen(result) << std::endl;

	std::cout << "***" << std::endl;

	std::string str[]{"geeksforgeeks", "a", "computer", "geek", "science", "geekin"};
	const char *str1 = "geek";
	size_t strsize = str->length();
	std::string outputStr[]{};

	char word[]{"dog"};
	std::string_view sv1 = word;
	std::cout << "word: " << word << std::endl;
	word[2] = 'f';
	std::cout << "word: " << sv1 << std::endl;
	sv1.remove_prefix(1);
	std::cout << "sv1 mod: " << sv1 << std::endl;

	std::cout << "sv1: " << sv1 << std::endl;
	std::cout << "sv1.data: " << sv1.data() << std::endl;

	std::cout << "digit sum of 1234: " << digit_sum(1234) << std::endl;
	std::cout << "show odds of 98723713: " << std::endl;
	show_odds(98723713);

	std::cout << "Is Palindrome? 16461: " << is_palindrome(16461) << std::endl;

	int age = 62;
	int *agePtr = &age;
	std::cout << "Age is " << age << " and &age=" << &age << std::endl;
	sayAgeByPtr(agePtr);
	std::cout << "Age after call is " << age << " and &age=" << &age << std::endl;

	std::cout << "---\n";

	age = 44;
	std::cout << "Age is " << age << " and &age=" << &age << std::endl;
	sayAgeByRef(age);
	std::cout << "Age after call is " << age << " and &age=" << &age << std::endl;

	// for(int z = 0; z < 20; ++z){
	// 	std::cout << "z: " << z << " ";
	// }

	int a{3};
	int b{12};
	print_sum(&a, &b);

	DayOfWeek day{DayOfWeek::Sunday};
	//std::cout << day << std::endl;
}

void sayAgeByRef(int &a)
{
	++a;
	std::cout << "age in method passing reference address of int: " << a << " and it's address: &a=" << &a << std::endl;
}

void sayAgeByPtr(int *a)
{
	++(*a);
	std::cout << "age in method passing pointer to int: " << *a << " and it's address: &a=" << &a << std::endl;
}

unsigned int digit_sum(unsigned int num)
{
	unsigned int digit = 0;
	unsigned int rightmostNumber = num;
	unsigned int sum = 0;

	while (rightmostNumber > 0)
	{
		digit = rightmostNumber % 10;
		sum += digit;
		rightmostNumber = rightmostNumber / 10;
	}

	return sum;
}

void show_odds(unsigned long long int num)
{

	unsigned int digit = 0;
	unsigned long long int rightmostNumber = num;

	while (rightmostNumber > 0)
	{
		digit = rightmostNumber % 10;
		if (digit % 2 != 0)
		{
			std::cout << digit;
		}
		rightmostNumber = rightmostNumber / 10;
	}
}

bool is_palindrome(unsigned long long int num)
{
	int temp;
	int remainder;
	unsigned long long int reversed = 0;
	temp = num;
	while (temp > 0)
	{
		remainder = temp % 10;
		reversed = (reversed * 10) + remainder;
		temp = temp / 10;
	}

	return (reversed == num);
}

void print_sum(int *param1, int *param2)
{
	std::cout << "sum : " << (*param1 + *param2) << std::endl;
}