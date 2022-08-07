#pragma once

/*

Help information:

 -Russian alphabet with little symbol: àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ
 -Russian alphabet with big symbol: ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß
 -Russian alphabet in frequency order: îåàíèòñëâğêäìóïÿüûãá÷çæéøõşıùöôú¸
 -power of Russion alphabet:33

 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <Windows.h> 
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cctype>

using namespace std;

#define type  unsigned int


struct alphabet
{
	char symbols;
	long  int value;
};

string upper_alphabet()
{
	return "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß_";
}

string remove_all_spaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

string remove_extra_space(string text)
{
	int i, j;

	int len = text.length();

	for (i = 0; i < len; i++)
	{
		if (text[0] == ' ')
		{
			for (i = 0; i < (len - 1); i++)
				text[i] = text[i + 1];
			text[i] = '\0';
			len--;
			i = -1;
			continue;
		}
		if (text[i] == ' ' && text[i + 1] == ' ')
		{
			for (j = i; j < (len - 1); j++)
			{
				text[j] = text[j + 1];
			}
			text[j] = '\0';
			len--;
			i--;
		}
	}

	return text;
}

string filtration_the_text_without_space(string text)
{
	// incurrent string of text 34 symbols

	string upper_alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß ";
	string lower_alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ ";

	for (type i = 0; i < text.length(); i++)
	{
		for (type j = 0; j < 34; j++)
		{
			if (text[i] == lower_alphabet[j])
			{
				text[i] = lower_alphabet[j];
				break;
			}
			if (text[i] == upper_alphabet[j])
			{
				text[i] = lower_alphabet[j];
				break;
			}
			if (j == 33 && text[i] != lower_alphabet[j])
			{
				text[i] = ' ';
				break;
			}
		}

	}



	return remove_all_spaces(text);
}

string filtration_the_text_with_space(string text)
{
	// incurrent string of text 34 symbols

	string upper_alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß ";
	string lower_alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ ";

	for (type i = 0; i < text.length(); i++)
	{
		for (type j = 0; j < 34; j++)
		{
			if (text[i] == lower_alphabet[j])
			{
				text[i] = lower_alphabet[j];
				break;
			}
			if (text[i] == upper_alphabet[j])
			{
				text[i] = lower_alphabet[j];
				break;
			}
			if (j == 33 && text[i] != lower_alphabet[j])
			{
				text[i] = ' ';
				break;
			}
		}

	}

	return remove_extra_space(text);
}

alphabet* freuquency_of_symbols(alphabet* language, type size, string text)
{

	string lower_alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ ";

	for (type i = 0; i < text.length(); i++)
	{
		for (type j = 0; j < size; j++)
		{

			if (text[i] == lower_alphabet[j])
			{
				language[j].value = language[j].value + 1;
				break;
			}
		}
	}

	return language;
}

alphabet* null(alphabet* language, string upper_alphabet, type size)
{
	for (type i = 0; i < size; i++)
	{
		language[i].symbols = upper_alphabet[i]; language[i].value = 0;
	}
	return language;
}

void bubbleSort(alphabet* language_, type length_array)
{
	type temp_ = 0;
	char _temp = 0;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (type int_counter = 0; int_counter < (length_array - 1); int_counter++)

			if (language_[int_counter].value < language_[int_counter + 1].value)
			{

				temp_ = language_[int_counter].value;
				language_[int_counter].value = language_[int_counter + 1].value;
				language_[int_counter + 1].value = temp_;

				_temp = language_[int_counter].symbols;
				language_[int_counter].symbols = language_[int_counter + 1].symbols;
				language_[int_counter + 1].symbols = _temp;

				exit = false;
			}
	}
}

long double** null_matrix(long double** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (type j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}

	return matrix;
}

long double** matrix_frequancy_with_step_one(long double** matrix, type row, type column, string text)
{

	string lower_alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ ";

	for (type t = 0; t < text.length() - 1; t++)
	{
		type temp_i = 0;

		type temp_j = 0;

		for (type i = 0; i < row; i++)
		{
			if (text[t] == lower_alphabet[i])
			{
				temp_i = i;
				break;
			}
		}

		for (type j = 0; j < column; j++)
		{
			if (text[t + 1] == lower_alphabet[j])
			{
				temp_j = j;
				break;
			}
		}

		matrix[temp_i][temp_j] = matrix[temp_i][temp_j] + 1;

		temp_i = 0;

		temp_j = 0;

	}


	return matrix;
}

long double** matrix_frequancy_with_step_two(long double** matrix, type row, type column, string text)
{

	string lower_alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ ";

	for (type t = 0; t < text.length() - 1; t = t + 2)
	{
		type temp_i = 0;

		type temp_j = 0;

		for (type i = 0; i < row; i++)
		{
			if (text[t] == lower_alphabet[i])
			{
				temp_i = i;
				break;
			}
		}

		for (type j = 0; j < column; j++)
		{
			if (text[t + 1] == lower_alphabet[j])
			{
				temp_j = j;
				break;
			}
		}

		matrix[temp_i][temp_j] = matrix[temp_i][temp_j] + 1;

		temp_i = 0;

		temp_j = 0;


	}


	return matrix;
}

long double entrophy_of_alphabet(alphabet* language, type length, type size)
{
	long double result = 0;

	for (type i = 0; i < size; i++)
	{
		if (language[i].value != 0)
		{
			long double temp = 0;

			temp = ((long double)language[i].value / length);

			result = -temp * log2(temp) + result;
		}

	}

	return result;
}

long double entrophy_of_alphabet_without_struck(alphabet* language, type length, type size)
{
	long double result = 0;

	for (type i = 0; i < size; i++)
	{
		if (language[i].value != 0 && language[i].symbols != ' ')
		{
			long double temp = 0;

			temp = ((long double)language[i].value / length);

			result = -temp * log2(temp) + result;

		}

	}

	return result;
}

long double entrophy_of_alphabet_bigram(long double**matrix, type length, type size)
{
	long double result = 0;

	for (type i = 0; i < size; i++)
	{
		for (type j = 0; j < size; j++)
		{
			if (matrix[i][j] != 0)
			{
				long double temp = 0;

				temp = ((long double)matrix[i][j] / length);

				result = -temp * log2(temp) + result;
			}
		}
	}

	return result;
}

