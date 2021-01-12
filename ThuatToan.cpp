#include<conio.h>
#include <fstream>
#include <iostream>
using namespace std;

struct Node
{
	int index;  // so thu tu
	int g;      // khoang cach tu dinh ban dau den dinh hien ta
	int f;      // f = h + g;
	int h;      // duong di ngan nhat
	int color;  // danh dau dinh di qua
	int parent;    // dinh cha
};

int a[100][100];
Node p[100];
Node Open[100];
Node Close[100];

void ReadInputFile1(int *b, int &n)
{
	fstream fs1("Input1.txt");

	if (!fs1.is_open())
	{
		cout << "Khong the mo duoc file!";
	}
	else
	{
		fs1 >> n;

		for (int i = 0; i < n; i++)
		{
			fs1 >> b[i];
		}
	}
    fs1.close();
}

void ReadInputFile2(int a[100][100], int &n, int &start, int &finsh)
{
	fstream fs2("Input2.txt");

	if (!fs2.is_open())
	{
		cout << "Khong the mo duoc file!";
	}
	else
	{
		fs2 >> n >> start >> finsh;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				fs2 >> a[i][j];
		}
	}
	fs2.close();
}
void RhowMatrix(int a[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
}

int Count(int n, Node *Open)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (Open[i].color == 1)
			count++;
	}
	return count;
}
int Find(int n, Node *Open)
{

	for (int i = 0; i < n; i++)
		if (Open[i].color == 1)
			return i;
    return -1;
}

int FindMin(int n, Node *Open)
{
	int minIndex = Find(n, Open);
	int min = Open[minIndex].f;
	for (int i = 0; i < n; i++)
	{
		if (Open[i].f < min && Open[i].color == 1)
		{
			minIndex = i;
			min = Open[i].f;
		}
	}
	return minIndex;
}
void Init(int n, int *b)
{
	for (int i = 0; i < n; i++)
	{
		p[i].index = i;
		p[i].color = 0;
		p[i].g = b[i];
		p[i].parent = 0;
		p[i].f = p[i].g;
		p[i].h = 0;
	}
}

int FindPoint(int n, Node *q, int o)
{
	for (int i = 0; i < n; i++)
		if (q[i].index == o)
			return  i;
    return -1;
}
