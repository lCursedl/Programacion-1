//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
	This file is known as calculator02buggy.cpp

	I have inserted 5 errors that should cause this not to compile
	I have inserted 3 logic errors that should cause the program to give wrong results

	First try to find an remove the bugs without looking in the book.
	If that gets tedious, compare the code to that in the book (or posted source code)

	Happy hunting!

*/

#include "Includes.h"
#include <ctime>

class Name_Value
{
public:
	string Name;
	int Value;
	Name_Value(string str, int val)
		:Name(str), Value(val)	{ }
};

//------------------------------------------------------------------------------

class Token{
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream():full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full)	// do we already have a Token ready?
	{       
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch)
	{
		case '=':    // for "print"
		case 'q':    // for "quit"
		case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}': case '!':
			return Token(ch);        // let each character represent itself
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);         // put digit back into the input stream
			double val;
			cin >> val;              // read a floating-point number
			return Token('8', val);   // let '8' represent "a number"
		}
		default:
			error("Bad token");
	}
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case '(':    // handle '(' expression ')'
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
				return d;
		}
		case '{':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != '}')
			{
				error("'}' expected");
				return d;
			}
		}
		case '8':            // we use '8' to represent a number
			return t.value;  // return the number's value
		default:
			error("primary expected");
	}
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = primary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '!':
		{
			if (left == 0)
			{
				left = 1;
			}
			else
			{
				int fact = 1;
				for (int i = 1; i <= left; i++)
				{
					fact *= i;
				}
				left = fact;
			}
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}
//------------------------------------------------------------------------------
// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}
//------------------------------------------------------------------------------
int calculator()
{
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\nAvailable operators:\n\t +, - , * , /\n";
	try
	{
		double val = 0;
		while (cin) {
			Token t = ts.get();

			if (t.kind == 'q') break; // 'x' for quit
			if (t.kind == '=')        // '=' for "print now"
				cout << "=" << val << '\n';
			else
				ts.putback(t);
			val = expression();
		}
		keep_window_open();
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}

void Ejercicio4()
{
	vector<Name_Value>NV;
	string TempName;
	int TempScore;
	bool RunProgram = true;

	while (RunProgram)
	{
		cout << "Introduzca un nombre: ";
		cin >> TempName;
		cout << "Introduzca un puntaje: ";
		cin >> TempScore;
		if (TempName != "NoName" && TempScore != 0)
		{
			for (int i = 0; i < NV.size(); i++)
			{
				if (TempName == NV[i].Name)
				{
					cout << "Error. Nombre repetido\n";
					cin.ignore();
					cin.get();
					return;
				}
			}
			NV.push_back(Name_Value(TempName, TempScore));
		}
		else
		{
			RunProgram = false;
		}
	}
	for (int i = 0; i < NV.size(); i++)
	{
		cout << NV[i].Name << ", " << NV[i].Value << "\n";
	}
	cin.ignore();
}

void Ejercicio6()
{
	vector <char> Letters;
	vector <int> States(4, 0);
	int iBulls = 0;
	int iCows = 0;
	char L1, L2, L3, L4;
	bool bGuess = true;
	int r;
	char rl;
	srand((int)time(0));
	for (int i = 0; i < 4; i++)
	{
		r = rand() % 26;
		switch (r)
		{
		case 0:
			rl = 'A';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 1:
			rl = 'B';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 2:
			rl = 'C';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 3:
			rl = 'D';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 4:
			rl = 'E';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 5:
			rl = 'F';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 6:
			rl = 'G';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 7:
			rl = 'H';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 8:
			rl = 'I';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 9:
			rl = 'J';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 10:
			rl = 'K';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 11:
			rl = 'L';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 12:
			rl = 'M';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 13:
			rl = 'N';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 14:
			rl = 'O';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 15:
			rl = 'P';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 16:
			rl = 'Q';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 17:
			rl = 'R';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 18:
			rl = 'S';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 19:
			rl = 'T';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 20:
			rl = 'U';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 21:
			rl = 'V';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 22:
			rl = 'W';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 23:
			rl = 'X';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 24:
			rl = 'Y';
			Letters.push_back(rl);
			cout << rl;
			break;
		case 25:
			rl = 'Z';
			Letters.push_back(rl);
			cout << rl;
			break;
		default:
			break;
		}
	}
	cout << "\n";
	while (bGuess)
	{
		iBulls = 0;
		iCows = 0;
		cout << "Introduzca sus 4 letras en mayusculas: ";
		cin >> L1;
		cin >> L2;
		cin >> L3;
		cin >> L4;
		for (int i = 0; i < States.size(); i++)
		{
			States[i] = 0;
		}
		if (L1 == Letters[0])
		{
			iBulls++;
			States[0] = 2;
		}
		if (L2 == Letters[1])
		{
			iBulls++;
			States[1] = 2;
		}
		if (L3 == Letters[2])
		{
			iBulls++;
			States[2] = 2;
		}
		if (L4 == Letters[3])
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
				for (int i = 0; i < Letters.size(); i++)
				{
					if (i != 0)
					{
						if (Letters[i] == L1)
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
				for (int i = 0; i < Letters.size(); i++)
				{
					if (i != 1)
					{
						if (Letters[i] == L2)
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
				for (int i = 0; i < Letters.size(); i++)
				{
					if (i != 2)
					{
						if (Letters[i] == L3)
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
				for (int i = 0; i < Letters.size(); i++)
				{
					if (i != 3)
					{
						if (Letters[i] == L4)
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
	Ejercicio6();
	cin.get();
	return 0;
}
//------------------------------------------------------------------------------