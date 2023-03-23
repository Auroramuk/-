#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

struct books
{
	char name[50];
	char author[20];
	char pub[30];
	char date[10];
}book[50];
int len;
int read();
void write();
void search();
void remove();
void savefile();
void sort();

int main()
{
	len = read();
	int op;
	while (cin>>op)
	{
		switch (op)
		{
		case 1:
			write();
			break;
		case 2:
			search();
			break;
		case 3:
			remove();
			break;
		default:
			break;
		}
		if (op == 0)
		{
			break;
		}
	}
}


int read()
{
	int i = 0;
	ifstream infile;
	infile.open("books.txt", ios::in);
	while (!infile.eof())
	{

		infile >> book[i].name;
		infile >> book[i].author;
		infile >> book[i].pub;
		infile >> book[i].date;
		i++;
	}

	infile.close();
	return i;
}

void savefile()
{
	int i = 0;
	ofstream outfile;
	outfile.open("ordered.txt",ios::out);
	for(i=0;i<len;i++)
	{
		outfile << std::left<<setw(50) << book[i].name<<
			std::left<<setw(20)<<book[i].author <<
			std::left << setw(30)<<book[i].pub <<
			std::left << setw(10)<< book[i].date<<endl;
	}
	outfile.close();
}

void sort()
{
	for(int i=0;i<len;i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (strcmp(book[j].name, book[j+1].name) > 0)
			{
				swap(book[j], book[j+1]);
			}
		}
	}
	savefile();
}

void write()
{
	
	cin >> book[len].name;
	cin >> book[len].author;
	cin >> book[len].pub;
	cin>> book[len].date;
	len++;
	sort();
	savefile();
}

void search()
{
	char name[50];
	cin >> name;
	for (int i = 0; i < len; i++)
	{
		if (strstr(book[i].name, name) != NULL)
		{
			cout << std::left << setw(50) << book[i].name <<
				std::left << setw(20) << book[i].author <<
				std::left << setw(30) << book[i].pub <<
				std::left << setw(10) << book[i].date<<endl;
		}
	}
	savefile();
}

void remove()
{
	char name[50];
	cin >> name;
	for (int i = 0; i < len; i++)
	{
		if (strstr(book[i].name, name) != NULL)
		{
			for (int j = i; j < len; j++)
			{
				book[j] = book[j + 1];
			}
			len--;
			i--;
		}
	}
	savefile();
}

