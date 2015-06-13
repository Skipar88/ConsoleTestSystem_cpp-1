#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

#include "vars.h"

using namespace std;

int userAnswers[numberOfQuestions] = {};

int result = 0;

string fromDos(string dosString)
{
	char buf[1000000];
	OemToCharA(dosString.c_str(), buf);
	return buf;
}

int test()
{
	bool answered = false;
	int c = 0;

	for (int i = 0; i < numberOfQuestions; i++)
	{
		int rightanswer = 0;

		cout << questions[i] << endl;
		for (int j = 0; j < numberOfQuestions * 4; j++)
		{
			if (stoi(answers[1][j]) == i)
			{
				cout << answers[0][j] << endl;
			}
		}

		cout << "Отговор(а, б, в, г):" << endl;

		while (!answered)
		{
			switch ((c = _getch()))
			{
			case ANS_a:
				rightanswer = 0;
				answered = true;
				break;
			case ANS_b:
				rightanswer = 1;
				answered = true;
				break;
			case ANS_c:
				rightanswer = 2;
				answered = true;
				break;
			case ANS_d:
				rightanswer = 3;
				answered = true;
				break;
			default:
				break;
			}
		}

		answered = false;
		
		for (int j = 0; j < numberOfQuestions * 4; j++)
		{

			if (stoi(answers[1][j]) == i)
			{
				if (answers[2][ i * 4 + rightanswer] == to_string(1))
				{
					userAnswers[i] = 1;
				}
				else
				{
					userAnswers[i] = 0;
				}
			}
		}
	}

	for each (int item in userAnswers)
	{
		if (item == 1)
		{
			result++;
		}
	}

	return result;
}

string mark(int result)
{
	string finalMessage = "";
	switch (result)
	{
	case 5:
		finalMessage = "Вашата оценка е Среден, брой точки " + to_string(result);
		break;
	case 6:
		finalMessage = "Вашата оценка е Добър, брой точки " + to_string(result);
		break;
	case 7:
		finalMessage = "Вашата оценка е Добър, брой точки " + to_string(result);
		break;
	case 8:
		finalMessage = "Вашата оценка е Много добър, брой точки " + to_string(result);
		break;
	case 9:
		finalMessage = "Вашата оценка е Много добър, брой точки " + to_string(result);
		break;
	case 10:
		finalMessage = "Вашата оценка е Отличен, брой точки " + to_string(result);
		break;
	default:
		finalMessage = "Вашата оценка е Слаб, брой точки " + to_string(result);
		break;
	}

	return finalMessage;
}

int main()
{

	setlocale(LC_ALL, "bulgarian");

	string name = "";
	bool finished = false;

	cout << "Вашето име:";

	cin >> name;


	name = fromDos(name);

	cout << name << endl << "Искате ли да започнете теста?(y/n)" << endl;


	int c = 0;
	while (!finished)
	{
		c = 0;

		switch ((c = _getch())) {
		case KEY_Y:
			result = test();
			finished = true;
			break;
		case KEY_N:
			return 0;
			break;
		case KEY_y:
			result = test();
			finished = true;
			break;
		case KEY_n:
			return 0;
			break;
		case KEY_y_bg:
			result = test();
			finished = true;
			break;
		case KEY_n_bg:
			return 0;
			break;
		case KEY_Y_bg:
			result = test();
			finished = true;
			break;
		case KEY_N_bg:
			return 0;
			break;
		default:
			//cout << endl << _getch() << endl;  // key left
			break;
		}

	}

	cout << mark(result) << endl;

	system("pause");

	return 0;
}
