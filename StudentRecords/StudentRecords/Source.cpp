#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using std::string;
using std::cout;
using std::cin;
using std::vector;

class CStudent
{
public:
	string m_Name;
	float m_Grade;
	string m_Group;

	CStudent(string Name, float Grade, string Group);
	CStudent();
	~CStudent();
	void PrintData();
	string GetData(bool jumpchar);
	string GetGroup();
};

CStudent::CStudent(string Name, float Grade, string Group)
{
	m_Name = Name;
	m_Grade = Grade;
	m_Group = Group;
}

CStudent::CStudent() {}

CStudent::~CStudent() {}

void CStudent::PrintData()
{
	cout << "\t" << m_Name << " " << m_Grade << " " << m_Group;
}

string CStudent::GetData(bool jumpchar)
{
	if (jumpchar)
	{
		return m_Name + ' ' + std::to_string(m_Grade) + ' ' + m_Group + '\n';
	}
	else
	{
		return m_Name + ' ' + std::to_string(m_Grade) + ' ' + m_Group;
	}
	
}

string CStudent::GetGroup()
{
	return m_Group;
}
/*----------------------------------------------------------------------------*/
class CGroup
{
public:
	string m_YearGroup;
	vector <CStudent> m_Students;

	CGroup(string YearGroup);
	~CGroup();
	void AddStudent(CStudent S);
	string GiveFName();
	void PrintStudents();
};

CGroup::CGroup(string YearGroup)
{
	m_YearGroup = YearGroup;
}

CGroup::~CGroup(){}

void CGroup::AddStudent(CStudent S)
{
	m_Students.push_back(S);
}

string CGroup::GiveFName()
{
	return m_YearGroup + ".txt";
}

void CGroup::PrintStudents()
{
	cout << m_YearGroup << '\n';
	for (int i = 0; i < m_Students.size(); i++)
	{
		m_Students[i].PrintData();
	}
}
/*-----------------------------------------------------------------------------*/

int SearchGroup(string GroupID, vector<CGroup>GroupList)
{
	for (int i = 0; i < GroupList.size(); i++)
	{
		if (GroupList[i].m_YearGroup == GroupID)
		{
			return i;
		}
	}
	return -1;
}

string InputName()
{
	string TempName;
	cin >> TempName;
	for (int i = 0; i < TempName.size(); i++)
	{
		if (!isalpha(TempName[i]))
		{
			cout << "Nombre invalido. Intente de nuevo.\n";
			return InputName();
		}
	}
	TempName[0] = toupper(TempName[0]);
	return TempName;
}

int InputNumber()
{
	string TempNum;
	cin >> TempNum;
	for (int i = 0; i < TempNum.size(); i++)
	{
		if (!isdigit(TempNum[0]))
		{
			cout << "Valor invalido, introduzca nuevo valor.\n";
			return InputNumber();
		}
	}
	return std::stoi(TempNum);
}

int InputMenu(int Min, int Max)
{
	int TempSelect;
	TempSelect = InputNumber();
	if (TempSelect < Min || TempSelect > Max)
	{
		cout << "Numero fuera del rango de seleccion. Intentelo de nuevo.\n";
		return InputMenu(Min, Max);
	}
	return TempSelect;
}

float InputGrade()
{
	float TempNum;
	cin >> TempNum;
	return TempNum;
}

string InputGroup()
{
	string TempGroup;
	cin >> TempGroup;
	for (int i = 0; i < TempGroup.size(); i++)
	{
		if (!isalnum(TempGroup[i]))
		{
			cout << "Grupo Invalido. Introduzca un nuevo grupo.\n";
			return InputGroup();
		}
		TempGroup[i] = toupper(TempGroup[i]);
	}
	return TempGroup;
}

void PrintGroups(vector<CGroup>GroupList)
{
	for (int i = 0; i < GroupList.size(); i++)
	{
		GroupList[i].PrintStudents();
	}
}

void PrintAGroup(vector<CGroup>GroupList)
{
	if (GroupList.size() > 0)
	{
		for (int i = 0; i < GroupList.size(); i++)
		{
			cout << GroupList[i].m_YearGroup << " : " << i << '\n' << "Seleccione el grupo a imprimir";
		}
		int SelectGroup = InputMenu(0, GroupList.size() - 1);
		GroupList[SelectGroup].PrintStudents();
	}
	else
	{
		cout << "Sin elementos a imprimir.\n";
	}	
}

void SortByGrade(vector<CStudent>&GroupList)
{
	int Movs = 0;
	int Pos = 0;
	CStudent CurrStudent = GroupList[Pos];
	CStudent NextStudent = GroupList[Pos + 1];
	int ListSize = GroupList.size();
	CStudent CopyS;
	int CheckIndex = 0;
	while (Pos != ListSize - 1)
	{
		if (CurrStudent.m_Grade < NextStudent.m_Grade)
		{
			CopyS = CurrStudent;
			GroupList[Pos] = NextStudent;
			GroupList[Pos + 1] = CopyS;
			Movs++;
		}
		if (Movs > 0)
		{
			Movs = 0;
			CurrStudent = GroupList[Pos];
			NextStudent = GroupList[Pos + 1];
		}
		else
		{
			if (Pos + 2 == ListSize)
			{
				Pos++;
				CurrStudent = GroupList[Pos];
				if (Pos != ListSize - 1)
				{
					NextStudent = GroupList[Pos + 1];
				}
			}
			else
			{
				NextStudent = GroupList[Pos + 1];
			}
		}
	}
}

void UserOperations(int SelectControl, vector<CGroup>GroupContainer, vector<CStudent>AllStudents, CStudent StudentVar)
{
	while (SelectControl != 0)
	{
		cout << "\nSeleccione que operacion desea relaizar:\n\tOrdenar alfabeticamente: 1\n\tOrdenar por promedio: 2\n\tImprimir todos los grupos: 3\n\tImprimir grupo especifico: 4\n\tIngresar alumno: 5\n\tSalir : 0\n";
		SelectControl = InputMenu(0, 5);
		switch (SelectControl)
		{
		case 1:
			for (int i = 0; i < GroupContainer.size(); i++)
			{
				
			}
			break;
		case 2:
			for (int i = 0; i < GroupContainer.size(); i++)
			{
				SortByGrade(GroupContainer[i].m_Students);
			}
			break;
		case 3:
			PrintGroups(GroupContainer);
			break;
		case 4:
			PrintAGroup(GroupContainer);
			break;
		case 5:
		{
			cout << "Introduzca el nombre del alumno: ";
			string StudentName = InputName();
			cout << "Introduzca el promedio del alumno: ";
			float StudentGrade = InputGrade();
			cout << "Introduzca el grupo del alumno: ";
			string StudentGroup = InputGroup();
			break;
		}
		case 0:
		{
			string FileName;
			for (int i = 0; i < GroupContainer.size(); i++)
			{
				FileName = GroupContainer[i].GiveFName();
				std::fstream File;
				File.open(FileName, std::ios_base::out | std::ios_base::trunc);
				for (int j = 0; j < GroupContainer[i].m_Students.size(); j++)
				{
					if (j != GroupContainer[i].m_Students.size() - 1)
					{
						File << GroupContainer[i].m_Students[j].GetData(true);
					}
					else
					{
						File << GroupContainer[i].m_Students[j].GetData(false);
					}
				}
				File.close();
			}
			std::fstream File;
			File.open("alumnos.txt", std::ios_base::out | std::ios_base::trunc);
			for (int i = 0; i < AllStudents.size(); i++)
			{
				if (i != AllStudents.size() - 1)
				{
					File << AllStudents[i].GetData(true);
				}
				else
				{
					File << AllStudents[i].GetData(false);
				}
			}
			break;
		}
		default:
			break;
		}
	}
}

vector<string> Split(string s)
{
	string buffer;
	std::stringstream ss(s);
	vector<string>tokens;
	while (ss >> buffer)
	{
		tokens.push_back(buffer);
	}
	return tokens;
}

int main()
{
	std::fstream MyFile;
	MyFile.open("alumnos.txt", std::ios_base::in);
	vector<CGroup>MyGroups;
	vector<CStudent>FileStudents;
	string Line;
	vector<string>SplitString;
	CStudent MyStudent;
	int Select = -1;
	int GIndex;
	if (MyFile.is_open())
	{
		cout << "Archivo encontrado.\n";
		while (!MyFile.eof())
		{
			std::getline(MyFile, Line);
			SplitString = Split(Line);
			MyStudent = CStudent(SplitString[0], std::stof(SplitString[1]), SplitString[2]);
			FileStudents.push_back(MyStudent);
			GIndex = SearchGroup(MyStudent.GetGroup(), MyGroups);
			if (GIndex != -1)
			{
				MyGroups[GIndex].AddStudent(MyStudent);
			}
			else
			{
				CGroup TmpGroup(MyStudent.GetGroup());
				TmpGroup.AddStudent(MyStudent);
				MyGroups.push_back(TmpGroup);
			}
		}
		MyFile.close();
		UserOperations(Select, MyGroups, FileStudents, MyStudent);
	}
	else
	{
		cout << "Archivo no encontrado.\n";
		UserOperations(Select, MyGroups, FileStudents, MyStudent);
	}
	return 0;
}