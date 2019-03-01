#include <iostream>
bool Palindrome(const char *MyArray)
{
	int array_iterator = 0;
	int copy_iterator = 0;
	while (MyArray[array_iterator] != '\0')
	{
		array_iterator++;
	}
	char* MyCopy = new char[array_iterator];
	for (int i = array_iterator - 1; i > -1; i--)
	{
		MyCopy[copy_iterator] = MyArray[i];
		copy_iterator++;
	}
	for (int i = 0; i < array_iterator; i++)
	{
		if (MyCopy[i] != MyArray[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	if (Palindrome("ana"))
	{
		std::cout << "La palabra es palindromo";
	}
	else
	{
		std::cout << "La palabra no es palindromo";
	}
	std::cin.get();
	return 0;
}