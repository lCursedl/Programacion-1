#include "Includes.h"

bool CheckPrime(int num, vector<int> VecNum)
{
	for (int i = 0; i < VecNum.size(); i++)
	{
		if (num % VecNum[i] == 0)
		{
			return false;
		}
	}
	return true;
}

int CheckText(string s)
{
	if (s == "Cero" || s == "cero" || s == "0")
	{
		return 0;
	}
	else if (s == "Uno" || s == "uno" || s == "1")
	{
		return 1;
	}
	else if (s == "Dos" || s == "dos"|| s == "2")
	{
		return 2;
	}
	else if (s == "Tres" || s == "tres" || s == "3")
	{
		return 3;
	}
	else if (s == "Cuatro" || s == "cuatro" || s == "4")
	{
		return 4;
	}
	else if (s == "Cinco" || s == "cinco" || s == "5")
	{
		return 5;
	}
	else if (s == "Seis" || s == "seis" || s == "6")
	{
		return 6;
	}
	else if (s == "Siete" || s == "siete" || s == "7")
	{
		return 7;
	}
	else if (s == "Ocho" || s == "ocho" || s == "8")
	{
		return 8;
	}
	else if (s == "Nueve" || s == "nueve" || s == "9")
	{
		return 9;
	}
	else
	{
		return -1;
	}
}

void Ejercicio3()
{
	vector <double> Distances;
	double mydistance;
	double SumDistances = 0;
	double MinDistance;
	double MaxDistance;
	bool selection = true;
	while (selection)
	{
		cout << "Introduzca la distancia en KM entre 2 ciudades\n";
		cin >> mydistance;
		Distances.push_back(mydistance);
		cout << "Desea seguir introduciendo distancias?\n\t0: No. 1: Si\n";
		cin >> selection;
	}
	MinDistance = Distances[0];
	MaxDistance = Distances[0];
	//Ciclo para obtener sumatoria de distancias
	for (int i = 0; i < Distances.size(); i++)
	{
		SumDistances += Distances[i];
	}
	//Ciclo para obtener distancia menor
	for (int i = 1; i < Distances.size(); i++)
	{
		if (MinDistance > Distances[i])
		{
			MinDistance = Distances[i];
		}
	}
	//Ciclo para obtener distancia mayor
	for (int i = 1; i < Distances.size(); i++)
	{
		if (MaxDistance < Distances[i])
		{
			MaxDistance = Distances[i];
		}
	}
	cout << "La sumatoria de distancias es: " << SumDistances << " KM.\n";
	cout << "La distancia menor es: " << MinDistance << " KM.\n";
	cout << "La distancia mayor es: " << MaxDistance << " KM.\n";
	cin.ignore();
}

void Ejercicio4()
{
	bool selection;
	cout << "Pienza en un numero del 1 al 100.\n";
	cout << "Es un numero menor o igual a 51?\n\tNo: 0. Si: 1.";
	cin >> selection;
	if (selection == 0)//No, 51 - 100
	{
	}
	else//Si, 1 - 50
	{
		cout << "Es un numero menor o igual a 26?\n\tNo: 0. Si: 1.";
		if (selection == 0)//No, 26 - 50
		{

		}
		else
		{

		}
	}

}

void Ejercicio5()
{
	double num1;
	double num2;
	char operation;
	cout << "Introduzca un numero\n";
	cin >> num1;
	cout << "Introduzca otro numero.\n";
	cin >> num2;
	cout << "Introduzca la operacion a realizar (+, -, *, /)\n";
	cin >> operation;
	if (operation == '+')
	{
		cout << "La suma de " << num1 << " y " << num2 << " es " << num1 + num2 << ".\n";
	}
	else if (operation == '-')
	{
		cout << "La resta de " << num1 << " menos " << num2 << " es " << num1 - num2 << ".\n";
	}
	else if (operation == '*')
	{
		cout << "La mulriplicacion de " << num1 << " por " << num2 << " es " << num1 * num2 << ".\n";
	}
	else if (operation == '/')
	{
		cout << "La division de " << num1 << " entre " << num2 << " es " << num1 / num2 << ".\n";
	}
	cin.ignore();
}

void Ejercicio6()
{
	vector<string>MyNumbers;
	int DigitNumber;
	string LetterNumber;
	MyNumbers.push_back("Cero");
	MyNumbers.push_back("Uno");
	MyNumbers.push_back("Dos");
	MyNumbers.push_back("Tres");
	MyNumbers.push_back("Cuatro");
	MyNumbers.push_back("Cinco");
	MyNumbers.push_back("Seis");
	MyNumbers.push_back("Siete");
	MyNumbers.push_back("Ocho");
	MyNumbers.push_back("Nueve");
	cout << "Introduzca un numero en digito del 0 al 9: ";
	cin >> DigitNumber;
	cout << MyNumbers[DigitNumber];
	cout << "\nIntroduzca un numero en letra del 0 al 9: ";
	cin >> LetterNumber;
	if (LetterNumber == "Cero" || LetterNumber == "cero")
	{
		cout << "0\n";
	}
	else if (LetterNumber == "Uno" || LetterNumber == "uno")
	{
		cout << "1\n";
	}
	else if (LetterNumber == "Dos" || LetterNumber == "dos")
	{
		cout << "2\n";
	}
	else if (LetterNumber == "Tres" || LetterNumber == "tres")
	{
		cout << "3\n";
	}
	else if (LetterNumber == "Cuatro" || LetterNumber == "cuatro")
	{
		cout << "4\n";
	}
	else if (LetterNumber == "Cinco" || LetterNumber == "cinco")
	{
		cout << "5\n";
	}
	else if (LetterNumber == "Seis" || LetterNumber == "seis")
	{
		cout << "6\n";
	}
	else if (LetterNumber == "Siete" || LetterNumber == "siete")
	{
		cout << "7\n";
	}
	else if (LetterNumber == "Ocho" || LetterNumber == "ocho")
	{
		cout << "8\n";
	}
	else if (LetterNumber == "Nueve" || LetterNumber == "nueve")
	{
		cout << "9\n";
	}
	cin.ignore();
}

void Ejercicio7()
{
	int num1;
	int num2;
	string LetterNumber;
	char operation;
	cout << "Introduzca un numero\n";
	cin >> LetterNumber;
	num1 = CheckText(LetterNumber);
	cout << "Introduzca otro numero.\n";
	cin >> LetterNumber;
	num2 = CheckText(LetterNumber);
	cout << "Introduzca la operacion a realizar (+, -, *, /)\n";
	cin >> operation;
	if (num1 != -1 && num2 != -1)
	{
		if (operation == '+')
		{
			cout << "La suma de " << num1 << " y " << num2 << " es " << num1 + num2 << ".\n";
		}
		else if (operation == '-')
		{
			cout << "La resta de " << num1 << " menos " << num2 << " es " << num1 - num2 << ".\n";
		}
		else if (operation == '*')
		{
			cout << "La mulriplicacion de " << num1 << " por " << num2 << " es " << num1 * num2 << ".\n";
		}
		else if (operation == '/')
		{
			cout << "La division de " << num1 << " entre " << num2 << " es " << num1 / num2 << ".\n";
		}
	}
	else
	{
		cout << "Se introdujo un valor no valido.\n";
	}	
	cin.ignore();
}

void Ejercicio8()
{
	unsigned int CurrRice = 1;
	unsigned int Square = 0;
	for (CurrRice = 1; CurrRice < 1000; CurrRice *= 2)
	{
		Square += 1;
	}
	cout << "Se requieren " <<Square << " cuadros para obtener minimo de 1000 granos de arroz. Total: " << CurrRice << ".\n";
	Square = 0;
	for (CurrRice = 1; CurrRice < 1000000; CurrRice *= 2)
	{
		Square += 1;
	}
	cout << "Se requieren " << Square << " cuadros para obtener minimo de 1,000,000 granos de arroz. Total: " << CurrRice << ".\n";
	Square = 0;
	for (CurrRice = 1; CurrRice < 1000000000; CurrRice *= 2)
	{
		Square += 1;
	}
	cout << "Se requieren " << Square << " cuadros para obtener minimo de 1,000,000,000 granos de arroz. Total: " << CurrRice << ".\n";
	cin.ignore();
}

void Ejercicio9()
{
	int iRice = 1;
	double dRice = 1.;
	for (int i = 1; i < 64; i++)
	{
		iRice *= 2;
		dRice *= (double)2.;
	}
	cout << "Cantidad de granos en variable int: " << iRice << ".\n";
	cout << "Cantidad de granos en variable double: " << dRice << ".\n";
	cout << "Cantidad total verdadera: 18,446,744,073,709,551,616.\n";
	cin.ignore();
}

void Ejercicio10()
{
	vector <int> PCChoice;
	PCChoice.push_back(2);
	PCChoice.push_back(3);
	PCChoice.push_back(1);
	int Player = 0;
	cout << "Juego a 3 rondas.\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "\nIntroduce la jugada que quieras hacer:\n\tPiedra: 1. Papel: 2. Tijeras:3.\n";
		cin >> Player;
		switch (Player)
		{
		case 1:
			if (PCChoice[i] == 1)
			{
				cout << "\nJugador: Piedra.\nPC: Piedra.\nEmpate.\n";
			}
			else if (PCChoice[i] == 2)
			{
				cout << "\nJugador: Piedra.\nComputadora: Papel.\nComputadora gana.\n";
			}
			else if (PCChoice[i] == 3)
			{
				cout << "\nJugador: Piedra.\nComputadora: Tijera.\nJugador gana.\n";
			}
			break;
		case 2:
			if (PCChoice[i] == 1)
			{
				cout << "\nJugador: Papel.\nPC: Piedra.\nJugador gana.\n";
			}
			else if (PCChoice[i] == 2)
			{
				cout << "\nJugador: Papel.\nComputadora: Papel.\Empate.\n";
			}
			else if (PCChoice[i] == 3)
			{
				cout << "\nJugador: Papel.\nComputadora: Tijera.\nComputadora gana.\n";
			}
			break;
		case 3:
			if (PCChoice[i] == 1)
			{
				cout << "\nJugador: Tijera.\nPC: Piedra.\nComputadora gana.\n";
			}
			else if (PCChoice[i] == 2)
			{
				cout << "\nJugador: Tijera.\nComputadora: Papel.\nJugador gana.\n";
			}
			else if (PCChoice[i] == 3)
			{
				cout << "\nJugador: Tijera.\nComputadora: Tijera.\nEmpate.\n";
			}
			break;
		default:
			break;
		}
	}
	cin.ignore();
}

void Ejercicio11()
{
	vector<int>PrimeNums;
	for (int i = 2; i <= 100; i++)
	{
		if (CheckPrime(i, PrimeNums))
		{
			PrimeNums.push_back(i);
		}
	}
	cout << "Numeros primos del 2 al 100:\n\n";
	for (int i = 0; i < PrimeNums.size(); i++)
	{
		cout << PrimeNums[i] << "\n";
	}
	cin.ignore();
}

void Ejercicio12()
{
	vector<int>PrimeNums;
	int PrimMax;
	cout << "Introduzca el numero maximo postivo a calcular de numeros primos: ";
	cin >> PrimMax;
	for (int i = 2; i <= PrimMax; i++)
	{
		if (CheckPrime(i, PrimeNums))
		{
			PrimeNums.push_back(i);
		}
	}
	cout << "Numeros primos del 2 al "<< PrimMax <<":\n\n";
	for (int i = 0; i < PrimeNums.size(); i++)
	{
		cout << PrimeNums[i] << "\n";
	}
	cin.ignore();
}

void Ejercicio15()
{
	vector<int>PrimeNums;
	int PrimeAmount;
	int CurrAmount = 0;
	int PrimeNum = 2;
	cout << "Introduzca cantidad de numeros primos a calcular\n";
	cin >> PrimeAmount;
	while (CurrAmount != PrimeAmount)
	{
		if (CheckPrime(PrimeNum, PrimeNums))
		{
			PrimeNums.push_back(PrimeNum);
			CurrAmount++;
		}
		PrimeNum++;
	}
	for (int i = 0; i < PrimeNums.size(); i++)
	{
		cout << PrimeNums[i] << "\n";
	}
	cin.ignore();
}

void Ejercicio18()
{
	double a;
	double b;
	double c;
	double x1;
	double x2;
	cout << "Resolucion de ecuaciones de segundo grado (ax^2 + bx + c = 0)\n";
	cout << "Introuzca el valor de a: ";
	cin >> a;
	cout << "Introduzca el valor de b: ";
	cin >> b;
	cout << "Introduzca el valor de c: ";
	cin >> c;
	x1 = pow(b, 2);
	x2 = pow(b, 2);
	x1 = x1 - (4 * a * c);
	x2 = x2 - (4 * a * c);
	x1 = sqrt(x1);
	x2 = sqrt(x2);
	x1 = -b + x1;
	x2 = -b - x2;
	x1 /= (2 * a);
	x2 /= (2 * a);
	cout << x1 << " " << x2;
	cin.ignore();
}

void Ejercicio19()
{
	vector<string>Names;
	vector<int>Scores;
	string TempName;
	int TempScore;
	
	bool RunProgram = true;
	do
	{
		cout << "Introduzca un nombre: ";
		cin >> TempName;
		cout << "Introduzca un puntaje: ";
		cin >> TempScore;
		if (TempName != "NoName" && TempScore != 0)
		{
			for (int i = 0; i < Names.size(); i++)
			{
				if (TempName == Names[i])
				{
					cout << "Error. Nombre repetido\n";
					cin.ignore();
					cin.get();
					return;
				}
			}
			Names.push_back(TempName);
			Scores.push_back(TempScore);
		}
		else
		{
			RunProgram = false;
		}
	} while (RunProgram);
	for (int i = 0; i < Names.size(); i++)
	{
		cout << Names[i] << ", " << Scores[i] << "\n";
	}
	cin.ignore();
}

void Ejercicio20()
{
	vector<string>Names;
	vector<int>Scores;
	string TempName;
	int TempScore;

	bool RunProgram = true;
	bool SearchName = false;
	bool FoundName = false;

	do
	{
		cout << "Introduzca un nombre: ";
		cin >> TempName;
		cout << "Introduzca un puntaje: ";
		cin >> TempScore;
		if (TempName != "NoName" && TempScore != 0)
		{
			for (int i = 0; i < Names.size(); i++)
			{
				if (TempName == Names[i])
				{
					cout << "Error. Nombre repetido\n";
					cin.ignore();
					cin.get();
					return;
				}
			}
			Names.push_back(TempName);
			Scores.push_back(TempScore);
		}
		else
		{
			RunProgram = false;
			SearchName = true;
		}
	} while (RunProgram);
	
	while (SearchName)
	{
		cout << "Introduzca un nombre para buscar su puntaje: ";
		cin >> TempName;
		for (int i = 0; i < Names.size(); i++)
		{
			if (Names[i] == TempName)
			{
				cout << Names[i] << ", " << Scores[i] << "\n";
				FoundName = true;
			}
		}
		if (!FoundName)
		{
			cout << "Nombre no encontrado\n";
		}
		else
		{
			FoundName = false;
		}
		cout << "Desea seguir buscando nombres?\n\tNo:0 Si:1\n\tSeleccion: ";
		cin >> SearchName;
	}
	cin.ignore();
}

void Ejercicio21()
{
	vector<string>Names;
	vector<int>Scores;
	string TempName;
	int TempScore;

	bool RunProgram = true;
	bool SearchScore = false;
	bool FoundScore = false;

	do
	{
		cout << "Introduzca un nombre: ";
		cin >> TempName;
		cout << "Introduzca un puntaje: ";
		cin >> TempScore;
		if (TempName != "NoName" && TempScore != 0)
		{
			for (int i = 0; i < Names.size(); i++)
			{
				if (TempName == Names[i])
				{
					cout << "Error. Nombre repetido\n";
					cin.ignore();
					cin.get();
					return;
				}
			}
			Names.push_back(TempName);
			Scores.push_back(TempScore);
		}
		else
		{
			RunProgram = false;
			SearchScore = true;
		}
	} while (RunProgram);

	while (SearchScore)
	{
		cout << "Introduzca un puntaje para buscar todos los nombres correspondientes: ";
		cin >> TempScore;
		for (int i = 0; i < Scores.size(); i++)
		{
			if (Scores[i] == TempScore)
			{
				cout << Names[i] << "\n";
				FoundScore = true;
			}
		}
		if (!FoundScore)
		{
			cout << "Puntaje no encontrado\n";
		}
		else
		{
			FoundScore = false;
		}
		cout << "Desea seguir buscando puntajes?\n\tNo:0 Si:1\n\tSeleccion: ";
		cin >> SearchScore;
	}
	cin.ignore();
}

int main()
{
	Ejercicio20();
	cin.get();
	return 0;
}