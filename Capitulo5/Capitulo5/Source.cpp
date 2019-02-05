#include "Includes.h"
#include <ctime>

double ctok(double c) // converts Celsius to Kelvin
{
	if (c < 273.15)
	{
		error("Valor introducido menor al minimo permitido.");
	}
	double k = c + 273.15;
	return k; // int k, funcion devuelve valor int cuando se supone es double
}

double ktoc(double k)
{
	if (k < 0)
	{
		error("Valor introducido menor al minimo permitido.");
	}
	double c = k - 273.15;
	return c;
}

double ctof(double c)
{
	if (c < -17.78)
	{
		error("Valor introducido menor al minimo permitido.");
	}
	double f = (c * (9.0 / 5.0)) + 32;
	return f;
}

double ftoc(double f)
{
	if (f < 32)
	{
		error("Valor introducido menor al minimo permitido.");
	}
	double c = (f - 32) * (5.0/9.0);
	return c;
}

void Ejercicio2()
{
	double c = 0; 
	cin >> c; // cin >> d , uso de variable no declarada
	double k = ctok(c); // ctok("c") , funcion recibe variable de tipo double, 
						  // se coloca de tipo string
	cout << k << '/n'; // Cout, llamada a metodo cout de manera incorrecta
	cin.ignore();
}

void Ejercicio3()
{
	double c = 0;
	cin >> c;
	if (c < 273.15)
	{
		error("Valor introducido menor al minimo permitido.");
	}
	double k = ctok(c);
	cout << k << '\n';
	cin.ignore();
}

void Ejercicio4()
{
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << '/n';
	cin.ignore();
}

void Ejercicio5()
{
	int Select;
	cout << "Seleccione el tipo de conversion que desea realizar.\n\t1.Celsius a Kelvin 2.Kelvin a Celsius\n";
	cin >> Select;
	if (Select == 1)
	{
		double c = 0;
		cin >> c;
		double k = ctok(c);
		cout << k << '/n';
	}
	else if (Select == 2)
	{
		double k = 0;
		cin >> k;
		double c = ktoc(k);
		cout << c << '\n';
	}
	cin.ignore();
}

void Ejercicio6()
{
	int Select;
	cout << "Seleccione el tipo de coversion.\n\t1. Celsius a Fanhrenheit. 2. Fahrenheit a Celsius.\n";
	cin >> Select;
	if (Select == 1)
	{
		double c = 0;
		cin >> c;
		double f = ctof(c);
		cout << f << '\n';
	}
	else if (Select == 2)
	{
		double f = 0;
		cin >> f;
		double c = ftoc(f);
		cout << c << '\n';
	}
	cin.ignore();
}

void Ejercicio7()
{

}

void Ejercicio8()
{
	int iAmount;
	vector <int> vNum;
	int input = 0;
	bool getInput = true;
	int numSum = 0;

	cout << "Introduzca el numero de valores a sumar: ";
	cin >> iAmount;
	cout << "Porfavor introduzca algunos numeros (introduzca \"|\" para parar).";
	while (getInput)
	{
		cin >> input;
		if (input != 0)
		{
			vNum.push_back(input);
		}
		else
		{
			getInput = false;
		}
	}
	if (iAmount >= vNum.size())
	{
		error("La cantidad de numeros solicitados es mayor a la existente.");
	}
	for (int i = 0; i < iAmount; i++)
	{
		numSum += vNum[i];
	}
	cout << "La suma de los " << iAmount <<" primeros numeros es " << numSum << ".";
	cin.ignore();
}

void Ejercicio11()
{
	int firstnum = 0;
	int secondnum = 1;
	int tempnum = secondnum;
	while (secondnum > 0)
	{
		secondnum = firstnum + secondnum;
		firstnum = tempnum;
		tempnum = secondnum;
	}
	cout << "El numero maximo imprimible de fibonacci es " << firstnum;
}

void Ejercicio12y13()
{
	vector <int> Nums;
	vector <int> States(4, 0);
	int iBulls = 0;
	int iCows = 0;
	int Num1, Num2, Num3, Num4;
	bool bGuess = true;
	int r;
	srand((int)time(0));
	for (int i = 0; i < 4; i++)
	{
		r = rand() % 10;
		Nums.push_back(r);
		cout << r;
	}
	while (bGuess)
	{
		iBulls = 0;
		iCows = 0;
		cout << "Introduzca el primer numero: ";
		cin >> Num1;
		cout << "Introduzca el segundo numero: ";
		cin >> Num2;
		cout << "Introduzca el tercer numero: ";
		cin >> Num3;
		cout << "Introduzca el cuarto numero: ";
		cin >> Num4;
		for (int i = 0; i < States.size(); i++)
		{
			States[i] = 0;
		}
		if (Num1 == Nums[0])
		{
			iBulls++;
			States[0] = 2;
		}
		if (Num2 == Nums[1])
		{
			iBulls++;
			States[1] = 2;
		}
		if (Num3 == Nums[2])
		{
			iBulls++;
			States[2] = 2;
		}
		if (Num4 == Nums[3])
		{
			iBulls++;
			States[3] = 2;
		}
		if (iBulls == 4)
		{
			cout << "\nFelicidades. Ha ganado la partida.";
			bGuess = false;
		}
		else
		{
			if (States[0] != 2)
			{
				for (int i = 0; i < Nums.size(); i++)
				{
					if (i != 0)
					{
						if (Nums[i] == Num1)
						{
							if (States[i] < 1)
							{
								States[i] = 1;
								iCows++;
								break;
							}
						}
					}
				}
			}
			if (States[1] != 2)
			{
				for (int i = 0; i < Nums.size(); i++)
				{
					if (i != 1)
					{
						if (Nums[i] == Num2)
						{
							if (States[i] < 1)
							{
								States[i] = 1;
								iCows++;
								break;
							}
						}
					}
				}
			}
			if (States[2] != 2)
			{
				for (int i = 0; i < Nums.size(); i++)
				{
					if (i != 2)
					{
						if (Nums[i] == Num3)
						{
							if (States[i] < 1)
							{
								States[i] = 1;
								iCows++;
								break;
							}
						}
					}
				}
			}
			if (States[3] != 2)
			{
				for (int i = 0; i < Nums.size(); i++)
				{
					if (i != 3)
					{
						if (Nums[i] == Num4)
						{
							if (States[i] < 1)
							{
								States[i] = 1;
								iCows++;
								break;
							}
						}
					}
				}
			}
			cout << "\nToros: " << iBulls << ". Vacas: " << iCows << "\n\n";
		}
	}
	cin.ignore();
}

int main()
{
	Ejercicio12y13();
	cin.get();
	return 0;
}