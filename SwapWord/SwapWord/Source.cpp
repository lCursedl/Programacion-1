#include <iostream>
int main()
{
	char * Word = new char[15];
	char C;
	int wsize;
	int l_iterator = 0;
	int r_iterator;
	std::cout << "Introduzca una palabra: ";	
	for (wsize = 0; std::cin >> C; wsize++)		//Se almacena la palabra registrada por letra en el arreglo
	{		
		if (C != ';' && wsize < 15)
		{
			Word[wsize] = C;
		}
		else
		{
			break;
		}
	}
	r_iterator = wsize - 1;
	if ((wsize%2) == 0)
	{
		while (l_iterator < (wsize / 2))
		{
			C = Word[l_iterator];
			Word[l_iterator] = Word[r_iterator];
			Word[r_iterator] = C;
			l_iterator++;
			r_iterator--;
		}
	}
	else
	{
		while (l_iterator != r_iterator)
		{
			C = Word[l_iterator];
			Word[l_iterator] = Word[r_iterator];
			Word[r_iterator] = C;
			l_iterator++;
			r_iterator--;
		}
	}
	for (int i = 0; i < wsize; i++)
	{
		std::cout << Word[i];
	}
	std::cin.ignore();
	std::cin.get();
	return 0;
}