#include "stdafx.h"
#include <iostream>	 
#include <fstream>
#include <cstring>
	
using namespace std;
	
int main()
{
	setlocale(LC_ALL, "rus");
	ifstream fileexample1,fileexample2;
	fileexample1.open("/filelaba/fileexample1.txt",ios::binary);
	fileexample2.open("/filelaba/fileexample2.txt",ios::binary);
	
	int sum1, sum2; //Посчитаем кол-во строк у обоих файлов
	sum1 = 0; 
        sum2 = 0;
	string str;
	while(!fileexample1.eof())
	{
            getline(fileexample1, str);
	    sum1++;
	}
	   
	fileexample1.clear();
	fileexample1.seekg(0,ios::beg);

	while(!fileexample2.eof())
	{
	    getline(fileexample2, str);
	    sum2++;
	}
	fileexample2.clear();
	fileexample2.seekg(0, ios::beg);
	
	if(sum1 != sum2) // Cравниваем кол-во строк
	{
	    cout << "Отличия в кол-ве строк" << "\n";
	    cout << "У 1 файла " << sum1 << " строки, а у 2 "<< sum2 << " строки" << "\n";
	}

	char string1[256], string2[256]; 
	int n = 0;
	while(!fileexample1.eof())
	{
		fileexample1.getline(string1, 256);
		fileexample2.getline(string2, 256);
	    n++;
	    if(strcmp(string1, string2) != 0)
	    {
	    	cout << n << " строка отличается" << "\n";
	        cout << "   " << string1 << " - в первом файле \n";
	        cout << "   " << string2 << " - во втором файле\n";
	    }
	}
	return 0;
}