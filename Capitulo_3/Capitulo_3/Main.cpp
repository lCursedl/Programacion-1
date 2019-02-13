#include "Includes.h"

void TryThis1()
{
	cout << "Please enter your first and second names.\n";
	string first;
	string second;
	double age;
	cin >> first >> second;
	cout << "Please enter your age.\n";
	cin >> age;
	age *= 12;
	cout << "Hello, " << first << " " << second << ".\nYou are " << age << " months old." << '\n';
	cin.ignore();
}

void TryThis2()
{
	cout << "Please enter a floating-point value: ";
	double n;
	cin >> n;
	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\nthree times n == " << 3 * n
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nsquare root of n == " << sqrt(n)
		<< '\n';
	cin.ignore();
}

void TryThis3()
{
	string previous = " ";
	string current;
	while (cin >> current)
	{
		if (previous == current)
		{
			cout << "Repeated word: " << current << '\n';
		}
		else if (current == "END")
		{
			break;
		}
		previous = current;
	}
	cin.ignore();
}

void TryThis4()
{
	cout << "Program with errors:\n" <<
		"\tSTRING s = \"Goodbye, cruel world!\"\n" <<
		"\tcOut << S << '\\n'\n";
	cout << "Program without errors:\n" <<
		"\tstring s = \"Goodbye, cruel world!\"\n" <<
		"\tcout << s << '\\n'\n";
	string s = "Goodbye, cruel world!";
	cout << s << '\n';
	cin.ignore();
}

void TryThis5()
{
	double d = 0;
	while (cin >> d) { // repeat the statements below
	// as long as we type in numbers
		int i = d; // try to squeeze a double into an int
		char c = i; // try to squeeze an int into a char
		int i2 = c; // get the integer value of the character
		cout << "d==" << d // the original double
			<< " i==" << i // converted to int
			<< " i2==" << i2 // int value of char
			<< " char(" << c << ")\n"; // the char
	}
	cin.ignore();
}

void Drill()
{
	string first_name;
	string friend_name;
	char friend_sex = 0;
	int age;
	cout << "Enter the name of the person you want to write to: ";
	cin >> first_name;
	cout << "\nEnter the age of the recipient: ";
	cin >> age;
	cout << "\nEnter the name of another friend: ";
	cin >> friend_name;
	cout << "\nEnter your friend gender (m = male, f = female): ";
	cin >> friend_sex;
	cout << "\nDear " << first_name << ",\n\tHow are you? I am fine. I miss you.";	
	cout << "\n\tHave you seen " << friend_name << " lately?";
	if (friend_sex == 'm')
	{
		cout << " If you see " << friend_name << " please ask him to call me.";
	}
	else if (friend_sex == 'f')
	{
		cout << " If you see " << friend_name << " please ask her to call me.";
	}
	
	cout << "\n\tI hear you just had a birthday and you are " << age << " years old. ";
	if (age <= 0 || age >= 110)
	{
		simple_error("You are kidding!");
	}
	else if (age < 12)
	{
		cout << "Next year you will be " << age + 1;
	}
	else if (age == 17)
	{
		cout << "Next year you will be able to vote.";
	}
	else if (age > 70)
	{
		cout << "I hope you are enjoying retirement.";
	}
	cout << "\n\tYours sincerely\n\t________\n\tGustavo.";
	cin.ignore();
}

void Ejercicio2()
{
	double Input;
	double Output;
	cout << "Introduzca una cantidad en millas para convertir a Km: ";
	cin >> Input;
	Output = 1.609 * Input;
	cout << "Km = " << Output;
	cin.ignore();
}

void Ejercicio4()
{
	int val1, val2;
	int suma, resta1, resta2, mul, div1, div2;
	cout << "Introduzca 2 numeros enteros para realizar operaciones.\n\tValor 1: ";
	cin >> val1;
	cout << "\n\tValor 2: ";
	cin >> val2;
	if (val1 >= val2)
	{
		cout << "Valor mayor: " << val1 << "\n";
		cout << "Valor menor: " << val2 << "\n";
	}
	else
	{
		cout << "Valor mayor: " << val2 << "\n";
		cout << "Valor menor: " << val1 << "\n";
	}
	suma = val1 + val2;
	resta1 = val1 - val2;
	resta2 = val2 - val1;
	mul = val1 * val2;
	div1 = val1 / val2;
	div2 = val2 / val1;

	cout << "Suma: " << suma << ".\nResta " << val1 << " - " << val2 << ": " << resta1 << ".\n";
	cout << "Multiplicacion: " << mul << ".\nDivision " << val1 << " / " << val2 << ": " << div1 << ".\n";
	cout << "Division " << val2 << " / " << val1 << ": " << div2 << ".\n";
	cin.ignore();
}

void Ejercicio5()
{
	double val1, val2;
	double suma, resta1, resta2, mul, div1, div2;
	cout << "Introduzca 2 numeros con punto flotante para realizar operaciones.\n\tValor 1: ";
	cin >> val1;
	cout << "\n\tValor 2: ";
	cin >> val2;
	if (val1 >= val2)
	{
		cout << "Valor mayor: " << val1 << "\n";
		cout << "Valor menor: " << val2 << "\n";
	}
	else
	{
		cout << "Valor mayor: " << val2 << "\n";
		cout << "Valor menor: " << val1 << "\n";
	}
	suma = val1 + val2;
	resta1 = val1 - val2;
	resta2 = val2 - val1;
	mul = val1 * val2;
	div1 = val1 / val2;
	div2 = val2 / val1;

	cout << "Suma: " << suma << ".\nResta " << val1 << " - " << val2 << ": " << resta1 << ".\n";
	cout << "Multiplicacion: " << mul << ".\nDivision " << val1 << " / " << val2 << ": " << div1 << ".\n";
	cout << "Division " << val2 << " / " << val1 << ": " << div2 << ".\n";
	cin.ignore();
}

void Ejercicio6()
{
	int val1, val2, val3;
	cout << "Introduzca 3 valores separados por espacios: ";
	cin >> val1 >> val2 >> val3;
	if (val1 >= val2)
	{
		if (val1 > val3)
		{

		}
		else if (val2 > val3)
		{

		}
	}
}

int main()
{
	Drill();
	cin.get();
	return 0;
}