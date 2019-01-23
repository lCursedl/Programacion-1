#include "Includes.h"

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

int main()
{
	Ejercicio6();
	cin.get();
	return 0;
}