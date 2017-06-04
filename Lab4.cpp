#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree
{
	vector<int> tree1;
	int value;
};
tree massive[10];

int getTop(int* arr, int size)
{
	int t;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == -1)
		{
			t = i;
		}
	}
	return t;
}

void match_tree(int* arr, int size, int base, int pos)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == pos)
		{
			massive[i].value = i;
			if (pos >= 0)
			{
				massive[base].tree1.push_back(i);
			}
			match_tree(arr, size, i, i);
		}
	}
}
void message1(const tree& A, int a = 0)
{
	cout << " ";
	cout << A.value << endl;
	for (vector<int>::const_iterator iter = A.tree1.begin(); iter != A.tree1.end(); ++iter)
	{
		message1(massive[*iter], (a + 1));
	}
}
void message2(const tree& A, int a = 0)
{
	for (vector<int>::const_iterator iter = A.tree1.begin(); iter != A.tree1.end(); ++iter)
	{
		message2(massive[*iter], (a + 1));
	}
	cout << " ";
	cout << A.value << endl;
}

void message3(const tree& A, int a = 0)
{
	vector<int>::const_iterator iter = A.tree1.begin();
	if (iter != A.tree1.end())
		message3(massive[*iter++], (a + 1));
	cout << " ";
	cout << A.value << endl;
	for (; iter != A.tree1.end(); ++iter)
	{
		message3(massive[*iter], (a + 1));
	}
}
int main()
{
	int mass[] = { -1, 0, 0, 0, 1, 2, 3, 1, 2 };
	int m = sizeof(mass) / sizeof(int);
	int top = getTop(mass, m);

	match_tree(mass, m, top, -1);

	message1(massive[top]);
	cout << endl;
	message2(massive[top]);
	cout << endl;
	message3(massive[top]);

	system("pause");
	return 0;
}