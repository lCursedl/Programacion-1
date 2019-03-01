#include "my.h"
#include "Includes.h"

int foo = 7;

namespace X
{
	int var;
	void print()
	{
		cout << var << "\n";
	}
}

namespace Y
{
	int var;
	void print()
	{
		cout << var << "\n";
	}
}

namespace Z
{
	int var;
	void print()
	{
		cout << var << "\n";
	}
}

void swap_v(int a, int b)
{
	int temp;
	temp = a, a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a, a = b;
	b = temp;
}

//void swap_cr(const int& a, const int& b)
//{
//	int temp;
//	temp = a, a = b;
//	b = temp;
//}

void Drill()
{	
	//1
	char cc;
	print_foo();
	print(99);
	//2
	int x = 7;
	int y = 9;
	swap_v(x, y); // replace by v, r, or cr
	swap_v(7, 9);
	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	swap_v(7.7, 9.9);
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	swap_v(7.7, 9.9);
	//3
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}
	cin >> cc;
}

void Ejercicio2(string str, vector<int> vec)
{
	cout << str << '\n';
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}
}

void Ejercicio3(int x, int y, vector<int>&fvec, int n)
{
	int firstnum = x;
	int secondnum = y;
	int tempnum = secondnum;
	fvec.push_back(firstnum);
	fvec.push_back(secondnum);
	for (int i = 0; i < n; i++)
	{
		secondnum = firstnum + secondnum;
		firstnum = tempnum;
		tempnum = secondnum;
		fvec.push_back(secondnum);
	}
	Ejercicio2("Secuencia Fibonacci:", fvec);
}

void Ejercicio4()
{
	vector<int>MyVec;
	Ejercicio3(1, 2, MyVec, 43);
}

vector<int>Ejercicio5A(vector<int>vInts)
{
	vector <int> Myvec;
	for (int i = (vInts.size() - 1); i > -1; i--)
	{
		Myvec.push_back(vInts[i]);
	}
	return Myvec;
}

void Ejercicio5B(vector<int>&vInts)
{
	int a_it = 0;
	int b_it = vInts.size() - 1;
	int buffer;
	if ((vInts.size()%2) == 0)
	{
		while (a_it < vInts.size()/2 && b_it > vInts.size()/2)
		{
			buffer = vInts[a_it];
			vInts[a_it] = vInts[b_it];
			vInts[b_it] = buffer;
			a_it++;
			b_it--;
		}
	}
	else
	{
		while (a_it != b_it)
		{
			buffer = vInts[a_it];
			vInts[a_it] = vInts[b_it];
			vInts[b_it] = buffer;
			a_it++;
			b_it--;
		}
	}
}

vector<string>Ejercicio6A(vector<string>vStrs)
{
	vector <string> Myvec;
	for (int i = (vStrs.size() - 1); i > -1; i--)
	{
		Myvec.push_back(vStrs[i]);
	}
	return Myvec;
}

void Ejercicio6B(vector<string>&vStrs)
{
	int a_it = 0;
	int b_it = vStrs.size() - 1;
	string buffer;
	if ((vStrs.size() % 2) == 0)
	{
		while (a_it < vStrs.size() / 2 && b_it > vStrs.size() / 2)
		{
			buffer = vStrs[a_it];
			vStrs[a_it] = vStrs[b_it];
			vStrs[b_it] = buffer;
			a_it++;
			b_it--;
		}
	}
	else
	{
		while (a_it != b_it)
		{
			buffer = vStrs[a_it];
			vStrs[a_it] = vStrs[b_it];
			vStrs[b_it] = buffer;
			a_it++;
			b_it--;
		}
	}
}

void Ejercicio7()
{
	vector<string>name;
	vector<double>age;
	string tmpstr;
	double tmpage;
	cout << "Introduzca 5 nombres:\n";
	for (int i = 0; i < 5; i++)
	{
		cin >> tmpstr;
		name.push_back(tmpstr);
	}
	cout << "Introduzca las edades de esas 5 personas:\n";
	for (int i = 0; i < 5; i++)
	{
		cin >> tmpage;
		age.push_back(tmpage);
	}
	for (int i = 0; i < name.size(); i++)
	{
		cout << "Nombre: " << name[i] << ", edad: " << age[i] << '\n';
	}
}

void Ejercicio9(vector<double>vprice, vector<double>vweight)
{
	if (vweight.size() == vprice.size())
	{
		double total = 0;
		for (int i = 0; i < vprice.size(); i++)
		{
			total += (vprice[i] * vweight[i]);
		}
	}
	else
	{
		cout << "Tamaño de los vectores incompatibles.\n";
	}
}

int main()
{
	cin.get();
	return 0;
}