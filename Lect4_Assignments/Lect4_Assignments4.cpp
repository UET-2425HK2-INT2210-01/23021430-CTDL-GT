#include <iostream>
#include <string>

using namespace std;

struct Student {
	int ID;
	string name;
	string Class;
};

Student student[100];
int studentCount = 0;

void Insert(int ID, string name, string Class)
{
	for (int i = 0; i < studentCount; i++)
	{
		if (student[i].ID == ID)
		{
			student[i].name = name;
			student[i].Class = Class;
			return;
		}
	}
	student[studentCount] = { ID, name, Class };
	studentCount++;
}

void Delete(int ID)
{
	for (int i = 0; i < studentCount; i++)
	{
		if (student[i].ID == ID)
		{
			for (int j = i; j < studentCount - 1; j++)
			{
				student[j] = student[j + 1];
			}
			studentCount--;
			return;
		}
	}
}

void Infor(int ID)
{
	for (int i = 0; i < studentCount; i++)
	{
		if (student[i].ID == ID)
		{
			cout << student[i].name << ',' << student[i].Class << endl;
			return;
		}
	}
	cout << "NA,NA" << endl;
}

int main()
{
	string str;
	int ID;
	string name;
	string Class;

	while (true)
	{
		cin >> str;
		if (str == "Insert")
		{
			cout << "ID: ";
			cin >> ID;
			cout << "Name: ";
			cin >> name;
			cout << "Class: ";
			cin >> Class;
			Insert(ID, name, Class);
		}
		if (str == "Delete")
		{
			cout << "ID: ";
			cin >> ID;
			Delete(ID);
		}
		if (str == "Infor")
		{
			cout << "ID: ";
			cin >> ID;
			Infor(ID);
		}
	}

	return 0;
}