#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

namespace test_calc
{
	class test_calc
	{
		int test()
		{
			string line;
			ifstream testfile;
			testfile.open("test.txt");

			while (getline(testfile, line))
			{
				cout << line << '\n';
			}

			testfile.close();
			return 0;
		}
	};
	}