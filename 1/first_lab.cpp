// first_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/////////////////////////////////////////////////////////////////

//Russian alphabet: абвгдеёжзийклмнопрстуфхцчшщъыьэюя

//Russian alphabet in frequency order: оеанитслвркдмупяьыгбчзжйшхюэщцфъё

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <Windows.h> 
#include <cmath>
#include <iomanip>
#include <ctime>

#define _type  unsigned int

using namespace std;


struct alphabet
{
	char symbols;
	long  int value;
};

alphabet* freuquency_of_symbols(alphabet* language, _type size, string text)
{
	
	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";

	for (_type i = 0; i < text.length(); i++)
	{
		for (_type j = 0; j < size; j++)
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

string filtration_the_text(string text)
{
	string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ";
	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";

	for (_type i = 0; i < text.length(); i++)
	{
		for (_type j = 0; j < 34; j++)
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
			if (j == 33 && text[i] != lower_alphabet[j] && text[i] != lower_alphabet[j])
			{
				text[i] = ' ';
				break;
			}

		}

	}

	for (_type i = 0; i < text.length(); i++)
	{
		if (text[i] == ' '&&text[i + 1] == ' ')
		{
			text.erase(i, 1);
			i = i - 2;
		}
	}


	return text;
}

string upper_alphabet_()
{
	return "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_";
}

alphabet* null(alphabet* language, string upper_alphabet, _type size)
{
	for (_type i = 0; i < size; i++)
	{
		language[i].symbols = upper_alphabet[i]; language[i].value = 0;
	}

	return language;
}

void bubbleSort(alphabet* language_, _type length_array)
{
	_type temp_ = 0;
	char _temp = 0;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (_type int_counter = 0; int_counter < (length_array - 1); int_counter++)

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

long double** matrix_frequancy_with_step_one(long double** matrix, _type row, _type column, string text)
{
	
	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";

	for (_type t = 0; t < text.length() - 1; t++)
	{
		_type temp_i = 0;

		_type temp_j = 0;

		for (_type i = 0; i < row; i++)
		{
			if (text[t] == lower_alphabet[i])
			{
				temp_i = i;
				break;
			}
		}

		for (_type j = 0; j < column; j++)
		{
			if (text[t+1] == lower_alphabet[j])
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

long double** matrix_frequancy_with_step_two(long double** matrix, _type row, _type column, string text)
{

	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";

	for (_type t = 0; t < text.length() - 1; t=t+2)
	{
		_type temp_i = 0;

		_type temp_j = 0;

		for (_type i = 0; i < row; i++)
		{
			if (text[t] == lower_alphabet[i])
			{
				temp_i = i;
				break;
			}
		}

		for (_type j = 0; j < column; j++)
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

long double entrophy_of_alphabet(alphabet* language,_type length,_type size)
{
	long double result = 0;

	for (_type i=0;i<size;i++)
	{
		if (language[i].value!=0)
		{
			long double temp = 0;

			temp = ((long double)language[i].value / length);

			result = -temp * log2(temp) + result;
		}

	}

	return result;
}

long double entrophy_of_alphabet_without_struck(alphabet* language, _type length, _type size)
{
	long double result = 0;

	for (_type i = 0; i < size; i++)
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

long double entrophy_of_alphabet_bigram(long double**matrix, _type length, _type size)
{
	long double result = 0;

	for (_type i = 0; i < size; i++)
	{
		for (_type j = 0; j < size; j++)
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


int main()
{
	

	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	
	string path_;    cout << endl << "Input path to text-file: ";      cin >> path_;       ifstream fin;       fin.open(path_);

	
	if (!fin.is_open())
	{
		cout << endl << "Error of open file!" << endl;
	}
	else
	{
		long double entrophy_alphubet, entrophy_alphubet_without_struck;

		string upper_alphabet = upper_alphabet_();

		cout << endl << "File open seccsesfull and we may to work with file." << endl;

		fstream fout;          fout.open("in_file.xls", ios::out);

		string  text =" ";     string one_string;
		

		while (!fin.eof())
		{
			one_string = " ";  getline(fin, one_string);  text = text + one_string + " ";
		}

		cout << endl << "Check of the output of russian symbols:" << endl;      cout << endl << text << endl;

		cout << endl << "Process of filtration source text..." << endl;         text = filtration_the_text(text);      cout << endl << text << endl;


		//Work program start////////////////////////////////////////////////

		unsigned int start_time = clock();


		alphabet  language[34];   null(language, upper_alphabet, 34);    freuquency_of_symbols(language, 34, text);     int temp = language[33].value;


		fout << endl << "Freaquency analise:" << endl << endl;


		fout << endl << "-ordinary order of symbols:" << endl;

		fout << endl << "\t" << "Symbols" << "\t" << "Count" << "\t" << "Frequancy"<< endl << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << "\t" << language[i].symbols << "\t" << language[i].value << "\t" << (long double)(language[i].value) / text.length() << endl;
		}


		fout << endl << "-ordinary order of symbols without struck:" << endl;

		fout << endl << "\t" << "Symbols" << "\t" << "Count" << "\t" << "Frequancy" << endl << endl;

		for (_type i = 0; i < 34; i++)
		{
			if (language[i].symbols != '_')
			{
				fout << "\t" << language[i].symbols << "\t" << language[i].value << "\t" << (long double)(language[i].value) / (text.length() - temp) << endl;
			}
		}


		entrophy_alphubet = entrophy_of_alphabet(language, text.length(), 34);
		entrophy_alphubet_without_struck = entrophy_of_alphabet_without_struck(language, text.length() - temp, 33);
		

		bubbleSort(language, 34); 


		fout << endl << "-sorting order of symbols:" << endl;

		fout << endl << "\t" << "Symbols" << "\t" << "Count" << "\t" << "Frequancy" << endl << endl;

		for (_type i = 0; i < 34; i++)
		{
			
				fout << "\t" << language[i].symbols << "\t" << language[i].value << "\t" << (long double)(language[i].value) / (text.length())<< endl;
			
		}


		fout << endl << "-sorting order of symbols without struck:" << endl;

		fout << endl << "\t" << "Symbols" << "\t" << "Count" << "\t" << "Frequancy" << endl << endl;

		for (_type i = 0; i < 34; i++)
		{
			if (language[i].symbols != '_')
			{
				fout << "\t" << language[i].symbols << "\t" << language[i].value << "\t" << (long double)(language[i].value) / ((text.length()) - temp) << endl;
			}
		}


		fout << endl << "Entrophy of symbols of alphabet with struck: " << entrophy_alphubet << " ;" << endl;


		fout << endl << "Entrophy of symbols of alphabet without struck: " << entrophy_alphubet_without_struck << " ;" << endl;

		/////////////////////////////////////////////////////////////////

	
		//create matrix start

		long  double** matrix = new long double*[34];

		for (_type i = 0; i < 34; i++)
		{
			matrix[i] = new long double[34];
		}

		for (_type i = 0; i < 34; i++)
		{
			for (_type j = 0; j < 34; j++)
			{
				matrix[i][j] = 0;
			}
		}


		//create matrix end

		matrix_frequancy_with_step_one(matrix, 34, 34, text);


		fout << endl << "Bigram statistic data for step one:" << endl << endl;


		fout << endl << "-bigram count with step one:" << endl << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << "\t \t" << upper_alphabet[i];
		}

		fout << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << upper_alphabet[i] << "\t";

			for (_type j = 0; j < 34; j++)
			{
				fout << "\t" << matrix[i][j]  << "\t";
			}
			fout << endl;

		}


		int bigram_universume = 0;

		for (_type i = 0; i < 34; i++)
		{
			for (_type j = 0; j < 34; j++)
			{
				bigram_universume = bigram_universume + matrix[i][j];
			}
		}



		fout << endl << "-bigram frequency with step one:" << endl << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << "\t \t" << upper_alphabet[i];
		}

		fout << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << upper_alphabet[i] << "\t";

			for (_type j = 0; j < 34; j++)
			{
				fout << "\t" << (long double)matrix[i][j] / bigram_universume << "\t";
			}
			fout << endl;

		}



		int bigram_universume_without_struck = 0;

		for (_type i = 0; i < 33; i++)
		{
			for (_type j = 0; j < 33; j++)
			{
				bigram_universume_without_struck = bigram_universume_without_struck + matrix[i][j];
			}
		}

		fout << endl << "-bigram frequency with step one without struck:" << endl << endl;

		for (_type i = 0; i < 33; i++)
		{
			fout << "\t \t" << upper_alphabet[i];
		}

		fout << endl;

		for (_type i = 0; i < 33; i++)
		{
			fout << upper_alphabet[i] << "\t";

			for (_type j = 0; j < 33; j++)
			{
				fout << "\t" << (long double)matrix[i][j] / bigram_universume_without_struck << "\t";
			}
			fout << endl;

		}


		fout << endl << "Specific entrophy bigram of alphabet with struck: " << entrophy_of_alphabet_bigram(matrix, bigram_universume, 34) << " ;" << endl;

		fout << endl << "Entrophy on symbol of bigram with struck: " << entrophy_of_alphabet_bigram(matrix, bigram_universume, 34)/2 << " ;" << endl;

		fout << endl << "Specific entrophy of bigram of alphabet without struck: " << entrophy_of_alphabet_bigram(matrix, bigram_universume_without_struck, 33) << " ;" << endl;

		fout << endl << "Entrophy on symbol of bigram without struck: " << entrophy_of_alphabet_bigram(matrix, bigram_universume_without_struck, 33)/2 << " ;" << endl;


		for (_type i = 0; i < 34; i++)
		{
			for (_type j = 0; j < 34; j++)
			{
				matrix[i][j] = 0;
			}
		}

		matrix_frequancy_with_step_two(matrix, 34, 34, text);


		fout << endl << "Bigram statistic data with step two:" << endl << endl;


		fout << endl << "-bigram count with step two:" << endl << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << "\t \t" << upper_alphabet[i];
		}

		fout << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << upper_alphabet[i] << "\t";

			for (_type j = 0; j < 34; j++)
			{
				fout << "\t" << matrix[i][j] << "\t";
			}
			fout << endl;

		}


		int _bigram_universume = 0;

		for (_type i = 0; i < 34; i++)
		{
			for (_type j = 0; j < 34; j++)
			{
				_bigram_universume = _bigram_universume + matrix[i][j];
			}
		}



		fout << endl << "-bigram frequency with step two:" << endl << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << "\t \t" << upper_alphabet[i];
		}

		fout << endl;

		for (_type i = 0; i < 34; i++)
		{
			fout << upper_alphabet[i] << "\t";

			for (_type j = 0; j < 34; j++)
			{
				fout << "\t" << (long double)matrix[i][j] / _bigram_universume << "\t";
			}
			fout << endl;

		}



		int _bigram_universume_without_struck = 0;

		for (_type i = 0; i < 33; i++)
		{
			for (_type j = 0; j < 33; j++)
			{
				_bigram_universume_without_struck = _bigram_universume_without_struck + matrix[i][j];
			}
		}

		fout << endl << "-bigram frequency with step two without struck:" << endl << endl;

		for (_type i = 0; i < 33; i++)
		{
			fout << "\t \t" << upper_alphabet[i];
		}

		fout << endl;

		for (_type i = 0; i < 33; i++)
		{
			fout << upper_alphabet[i] << "\t";

			for (_type j = 0; j < 33; j++)
			{
				fout << "\t" << (long double)matrix[i][j] / _bigram_universume_without_struck << "\t";
			}
			fout << endl;

		}


		fout << endl << "Specific entrophy bigram of alphabet with struck: " << entrophy_of_alphabet_bigram(matrix, _bigram_universume, 34) << " ;" << endl;

		fout << endl << "Entrophy on symbol of bigram with struck: " << entrophy_of_alphabet_bigram(matrix, _bigram_universume, 34) / 2 << " ;" << endl;

		fout << endl << "Specific entrophy of bigram of alphabet without struck: " << entrophy_of_alphabet_bigram(matrix, _bigram_universume_without_struck, 33) << " ;" << endl;

		fout << endl << "Entrophy on symbol of bigram without struck: " << entrophy_of_alphabet_bigram(matrix, _bigram_universume_without_struck, 33) / 2 << " ;" << endl;


		//delite matrix start

		for (_type i = 0; i < 34; i++)
		{
			delete matrix[i];
		}

		delete[] matrix;

		//delite matrix end


		/////////////////////////////////////////////////////////////////


		unsigned int end_time = clock(); 

		unsigned int search_time = end_time - start_time; 

		cout << endl << "Time of work: " << search_time << " miliseconds;" << endl;

		//Work program end////////////////////////////////////////////////


		fout.close();

		
	}

	fin.close();

	return 0;

}

/////////////////////////////////////////////////////////////////

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

//void bubbleSort(int* arrayPtr, int length_array)
//{
//	int temp = 0;
//	bool exit = false;
//
//	while (!exit)
//	{
//		exit = true;
//		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
//
//			if (arrayPtr[int_counter] < arrayPtr[int_counter + 1])
//			{
//
//				temp = arrayPtr[int_counter];
//				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
//				arrayPtr[int_counter + 1] = temp;
//				exit = false;
//			}
//	}
//}

//using namespace std;
//
//#define line cout<<endl<<"__________________________________________________________________________________________________________________________________________________________"<<endl;
//
//
//struct alphabet
//{
//	char symbols;
//	int value;
//};
//
//alphabet null(alphabet language, int size);
//
//int* freuquency_of_symbols(int* array, int size, string text);
//void bubbleSort(int* arrayPtr, int length_array);
//double** matrix_frequancy(double** matrix, int row, int column, string text);
//
//string filtration_the_text(string text);
//
//
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	string path_ = "out_file.txt";
//
//	ifstream fin;
//
//	fin.open(path_);
//
//	if (!fin.is_open())
//	{
//		cout << endl << "Error of open file!" << endl;
//	}
//	else
//	{
//		line
//
//			cout << endl << "File open seccsesfull and we may to work with file." << endl;
//
//
//		string  text;
//
//		string one_string;
//
//		while (!fin.eof())
//		{
//			one_string = "";
//			getline(fin, one_string);
//			text = text + one_string;
//		}
//
//		line
//
//			cout << endl << "Check of the output of russian symbols:" << endl;
//
//		cout << endl << text << endl;
//
//
//		line
//
//			cout << endl << "Process of filtration source text..." << endl;
//
//		text = filtration_the_text(text);
//
//		cout << endl << text << endl;
//
//		line
//
//			int* alphabet_frequency = new int[34];
//
//		cout << endl << "Freaquency analise:" << endl;
//
//		string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_";
//
//		alphabet  language[34];
//
//		for (int i = 0; i < 34; i++)
//		{
//			language[i].symbols = upper_alphabet[i];
//
//		}
//
//		//ordunary order-start
//		cout << endl << "-count of each symbol in alphabet order:" << endl; null(language, 34);
//
//		cout << endl << "А\tБ\tВ\tГ\tД\tЕ\tЁ\tЖ\tЗ\tИ\tЙ\tК\tЛ\tМ\tН\tО\tП\tР\tС\tТ\tУ\tФ\tХ\tЦ\tЧ\tШ\tЩ\tЪ\tЫ\tЬ\tЭ\tЮ\tЯ\t_\t" << endl;
//
//		freuquency_of_symbols(alphabet_frequency, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << alphabet_frequency[i] << "\t";
//		}
//
//		cout << endl << "-frequancy of each symbol in alphabet order:" << endl;
//
//		cout << endl << "А\tБ\tВ\tГ\tД\tЕ\tЁ\tЖ\tЗ\tИ\tЙ\tК\tЛ\tМ\tН\tО\tП\tР\tС\tТ\tУ\tФ\tХ\tЦ\tЧ\tШ\tЩ\tЪ\tЫ\tЬ\tЭ\tЮ\tЯ\t_\t" << endl;
//
//
//		freuquency_of_symbols(alphabet_frequency, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << (double)alphabet_frequency[i] / text.length() << "\t";
//		}
//		//ordunary order-end
//
//		//sorting order-start
//		cout << endl << "-count of each symbol in sorting order:" << endl;
//
//		null(alphabet_frequency, 34);
//
//		freuquency_of_symbols(alphabet_frequency, 34, text);
//
//		bubbleSort(alphabet_frequency, 34);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << (double)alphabet_frequency[i] << "\t";
//		}
//
//		cout << endl << "-frequancy of each symbol in sorting order:" << endl;
//
//		null(alphabet_frequency, 34);
//		freuquency_of_symbols(alphabet_frequency, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << (double)alphabet_frequency[i] / text.length() << "\t";
//		}
//		//sorting order-end
//
//		delete[]  alphabet_frequency;
//
//
//		//bigram frequancy-start
//
//
//		cout << endl << "-bigram frequency:" << endl;
//
//		double** matrix = new double*[34];
//
//		for (int i = 0; i < 34; i++)
//		{
//			matrix[i] = new double[34];
//		}
//
//		for (int i = 0; i < 34; i++)
//		{
//			for (int j = 0; j < 34; j++)
//			{
//				matrix[i][j] = 0;
//			}
//		}
//
//
//		//_______________________________________________________
//
//		string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_";
//
//		matrix_frequancy(matrix, 34, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << " \t" << upper_alphabet[i];
//		}
//
//		cout << endl;
//
//		for (int i = 0; i < 34; i++)
//		{
//			for (int j = 0; j < 34; j++)
//			{
//				cout << matrix[i][j] << "\t";
//			}
//			cout << endl;
//
//		}
//
//		//_______________________________________________________
//
//		for (int i = 0; i < 34; i++)
//		{
//			delete matrix[i];
//		}
//
//		delete[] matrix;
//
//		//bigram frequancy-end
//
//
//
//		line
//
//			/*cout << endl << "Process of saving data in in_file.txt ..." << endl;
//
//			string _path = "in_file.txt";
//
//			ofstream fout;
//
//			fout.open(_path);
//
//			if (!fout.is_open())
//			{
//				cout << endl << "Error of saving in file!" << endl;
//			}
//			else
//			{
//				cout << endl << "File saved seccsesfull." << endl;
//
//				fout << text;
//			}
//
//			fout.close();
//
//			line*/
//
//	}
//
//	fin.close();
//
//	return 0;
//
//}
//
//alphabet* null(alphabet* language, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		language[i].value = 0;
//	}
//
//	return language;
//}
//
//int* freuquency_of_symbols(int* array, int size, string text)
//{
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		for (int j = 0; j < 34; j++)
//		{
//
//			if (text[i] == lower_alphabet[j])
//			{
//				array[j] = array[j] + 1;
//				break;
//			}
//		}
//
//	}
//
//	return array;
//}
//
//void bubbleSort(int* arrayPtr, int length_array)
//{
//	int temp = 0;
//	bool exit = false;
//
//	while (!exit)
//	{
//		exit = true;
//		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
//
//			if (arrayPtr[int_counter] < arrayPtr[int_counter + 1])
//			{
//
//				temp = arrayPtr[int_counter];
//				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
//				arrayPtr[int_counter + 1] = temp;
//				exit = false;
//			}
//	}
//}
//
//double** matrix_frequancy(double** matrix, int row, int column, string text)
//{
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int t = 0; t < text.length() - 1; t++)
//	{
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < column; j++)
//			{
//				if (text[t] == lower_alphabet[i] && text[t + 1] == lower_alphabet[j])
//				{
//					matrix[i][j] = matrix[i][j] + 1;
//				}
//
//			}
//		}
//	}
//
//
//	return matrix;
//}
//
//string filtration_the_text(string text)
//{
//	string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ";
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		for (int j = 0; j < 34; j++)
//		{
//
//			if (text[i] == lower_alphabet[j])
//			{
//				text[i] = lower_alphabet[j];
//				break;
//			}
//			if (text[i] == upper_alphabet[j])
//			{
//				text[i] = lower_alphabet[j];
//				break;
//			}
//			if (j == 33 && text[i] != lower_alphabet[j] && text[i] != lower_alphabet[j])
//			{
//				text[i] = ' ';
//				break;
//			}
//
//		}
//
//	}
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		if (text[i] == ' '&&text[i + 1] == ' ')
//		{
//			text.erase(i, 1);
//			i = i - 1;
//		}
//	}
//
//
//	return text;
//}

//
//char instrument_for_filtration_symbols(char symbols)
//{
//
//		switch (symbols)
//		{
//
//
//		case 'а' || 'б' || 'в' || 'г' || 'д' || 'е' || 'ё' || 'ж' || 'з' || 'и' || 'й' || 'к' || 'л' || 'м' || 'н' || 'о' || 'п' || 'р' || 'с' || 'т' || 'у' || 'ф' || 'х' || 'ц' || 'ч' || 'ш' || 'щ' || 'ъ' || 'ы' || 'ь' || 'э' || 'ю' || 'я':
//		{
//			return symbols;
//			break;
//		}
//
//		case 'А':
//		{
//			symbols = 'а';
//			return symbols;
//			break;
//		}
//
//		case 'Б':
//		{
//			symbols = 'б';
//			return symbols;
//			break;
//		}
//
//		case 'В':
//		{
//			symbols = 'в';
//			return symbols;
//			break;
//		}
//
//		case 'Г':
//		{
//			symbols = 'г';
//			return symbols;
//			break;
//		}
//		case 'Д':
//		{
//			symbols = 'д';
//			return symbols;
//			break;
//		}
//		case 'Е':
//		{
//			symbols = 'е';
//			return symbols;
//			break;
//		}
//		case 'Ё':
//		{
//			symbols = 'ё';
//			return symbols;
//			break;
//		}
//		case 'Ж':
//		{
//			symbols = 'ж';
//			return symbols;
//			break;
//		}
//		case 'З':
//		{
//			symbols = 'з';
//			return symbols;
//			break;
//		}
//		case 'И':
//		{
//			symbols = 'и';
//			return symbols;
//			break;
//		}
//		case 'Й':
//		{
//			symbols = 'й';
//			return symbols;
//			break;
//		}
//		case 'К':
//		{
//			symbols = 'к';
//			return symbols;
//			break;
//		}
//		case 'Л':
//		{
//			symbols = 'л';
//			return symbols;
//			break;
//		}
//		case 'М':
//		{
//			symbols = 'м';
//			return symbols;
//			break;
//		}
//		case 'Н':
//		{
//			symbols = 'н';
//			return symbols;
//			break;
//		}
//		case 'О':
//		{
//			symbols = 'о';
//			return symbols;
//			break;
//		}
//		case 'П':
//		{
//			symbols = 'п';
//			return symbols;
//			break;
//		}
//		case 'Р':
//		{
//			symbols = 'р';
//			return symbols;
//			break;
//		}
//		case 'С':
//		{
//			symbols = 'с';
//			return symbols;
//			break;
//		}
//		case 'Т':
//		{
//			symbols = 'т';
//			return symbols;
//			break;
//		}
//		case 'У':
//		{
//			symbols = 'у';
//			return symbols;
//			break;
//		}
//		case 'Ф':
//		{
//			symbols = 'ф';
//			return symbols;
//			break;
//		}
//		case 'Х':
//		{
//			symbols = 'х';
//			return symbols;
//			break;
//		}
//		case 'Ц':
//		{
//			symbols = 'ц';
//			return symbols;
//			break;
//		}
//		case 'Ч':
//		{
//			symbols = 'ч';
//			return symbols;
//			break;
//		}
//		case 'Ш':
//		{
//			symbols = 'ш';
//			return symbols;
//			break;
//		}
//		case 'Щ':
//		{
//			symbols = 'щ';
//			return symbols;
//			break;
//		}
//		case 'Ъ':
//		{
//			symbols = 'ъ';
//			return symbols;
//			break;
//		}
//		case 'Ы':
//		{
//			symbols = 'ы';
//			return symbols;
//			break;
//		}
//		case 'Ь':
//		{
//			symbols = 'ь';
//			return symbols;
//			break;
//		}
//		case 'Э':
//		{
//			symbols = 'э';
//			return symbols;
//			break;
//		}
//		case 'Ю':
//		{
//			symbols = 'ю';
//			return symbols;
//			break;
//		}
//		case 'Я':
//		{
//			symbols = 'я';
//			return symbols;
//			break;
//		}
//		default:
//		{
//			symbols = '_';
//			return symbols;
//			break;
//		}
//
//		}
//
//
//}
//char instrument_for_filtration(char symbols)
//{
//	switch (symbols)
//	{
//
//	case 'А':
//	{
//		symbols = 'а';
//		return symbols;
//		break;
//	}
//
//	case 'Б':
//	{
//		symbols = 'б';
//		return symbols;
//		break;
//	}
//
//	case 'В':
//	{
//		symbols = 'в';
//		return symbols;
//		break;
//	}
//
//	case 'Г':
//	{
//		symbols = 'г';
//		return symbols;
//		break;
//	}
//	case 'Д':
//	{
//		symbols = 'д';
//		return symbols;
//		break;
//	}
//	case 'Е':
//	{
//		symbols = 'е';
//		return symbols;
//		break;
//	}
//	case 'Ё':
//	{
//		symbols = 'ё';
//		return symbols;
//		break;
//	}
//	case 'Ж':
//	{
//		symbols = 'ж';
//		return symbols;
//		break;
//	}
//	case 'З':
//	{
//		symbols = 'з';
//		return symbols;
//		break;
//	}
//	case 'И':
//	{
//		symbols = 'и';
//		return symbols;
//		break;
//	}
//	case 'Й':
//	{
//		symbols = 'й';
//		return symbols;
//		break;
//	}
//	case 'К':
//	{
//		symbols = 'к';
//		return symbols;
//		break;
//	}
//	case 'Л':
//	{
//		symbols = 'л';
//		return symbols;
//		break;
//	}
//	case 'М':
//	{
//		symbols = 'м';
//		return symbols;
//		break;
//	}
//	case 'Н':
//	{
//		symbols = 'н';
//		return symbols;
//		break;
//	}
//	case 'О':
//	{
//		symbols = 'о';
//		return symbols;
//		break;
//	}
//	case 'П':
//	{
//		symbols = 'п';
//		return symbols;
//		break;
//	}
//	case 'Р':
//	{
//		symbols = 'р';
//		return symbols;
//		break;
//	}
//	case 'С':
//	{
//		symbols = 'с';
//		return symbols;
//		break;
//	}
//	case 'Т':
//	{
//		symbols = 'т';
//		return symbols;
//		break;
//	}
//	case 'У':
//	{
//		symbols = 'у';
//		return symbols;
//		break;
//	}
//	case 'Ф':
//	{
//		symbols = 'ф';
//		return symbols;
//		break;
//	}
//	case 'Х':
//	{
//		symbols = 'х';
//		return symbols;
//		break;
//	}
//	case 'Ц':
//	{
//		symbols = 'ц';
//		return symbols;
//		break;
//	}
//	case 'Ч':
//	{
//		symbols = 'ч';
//		return symbols;
//		break;
//	}
//	case 'Ш':
//	{
//		symbols = 'ш';
//		return symbols;
//		break;
//	}
//	case 'Щ':
//	{
//		symbols = 'щ';
//		return symbols;
//		break;
//	}
//	case 'Ъ':
//	{
//		symbols = 'ъ';
//		return symbols;
//		break;
//	}
//	case 'Ы':
//	{
//		symbols = 'ы';
//		return symbols;
//		break;
//	}
//	case 'Ь':
//	{
//		symbols = 'ь';
//		return symbols;
//		break;
//	}
//	case 'Э':
//	{
//		symbols = 'э';
//		return symbols;
//		break;
//	}
//	case 'Ю':
//	{
//		symbols = 'ю';
//		return symbols;
//		break;
//	}
//	case 'Я':
//	{
//		symbols = 'я';
//		return symbols;
//		break;
//	}
//	default:
//	{
//		symbols = '_';
//		return symbols;
//		break;
//	}
//
//	}
//
//
//}
//

//
////////////////
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <algorithm>
//#include <Windows.h> 
//
//using namespace std;
//
//#define line cout<<endl<<"__________________________________________________________________________________________________________________________________________________________"<<endl;
//
//
//struct alphabet
//{
//	char symbols;
//	int value;
//};
//
//string filtration_the_text(string text);
//alphabet* freuquency_of_symbols(alphabet* array, int size, string text);
//
//void bubbleSort(alphabet* arrayPtr, int length_array);
//double** matrix_frequancy(double** matrix, int row, int column, string text);
//
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	string path_ = "out_file.txt";
//
//	ifstream fin;
//
//	fin.open(path_);
//
//	if (!fin.is_open())
//	{
//		cout << endl << "Error of open file!" << endl;
//	}
//	else
//	{
//		line
//
//			cout << endl << "File open seccsesfull and we may to work with file." << endl;
//
//
//		string  text;
//
//		string one_string;
//
//		while (!fin.eof())
//		{
//			one_string = "";
//			getline(fin, one_string);
//			text = text + one_string;
//		}
//
//		line
//
//			cout << endl << "Check of the output of russian symbols:" << endl;
//
//		cout << endl << text << endl;
//
//
//		line
//
//			cout << endl << "Process of filtration source text..." << endl;
//
//		text = filtration_the_text(text);
//
//		cout << endl << text << endl;
//
//		line
//
//			int* alphabet_frequency = new int[34];
//
//		cout << endl << "Freaquency analise:" << endl;
//
//		string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_";
//
//		alphabet  language[34];
//
//		for (int i = 0; i < 34; i++)
//		{
//			language[i].symbols = upper_alphabet[i];
//			language[i].value = 0;
//		}
//
//		freuquency_of_symbols(language, 34, text);
//
//		bubbleSort(language, 34);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << language[i].symbols << "\t";
//		}
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << (double)alphabet_frequency[i] / text.length() << "\t";
//		}
//
//		delete[]  alphabet_frequency;
//
//
//		line
//
//
//			cout << endl << "-bigram frequency:" << endl;
//
//		double** matrix = new double*[34];
//
//		for (int i = 0; i < 34; i++)
//		{
//			matrix[i] = new double[34];
//		}
//
//		for (int i = 0; i < 34; i++)
//		{
//			for (int j = 0; j < 34; j++)
//			{
//				matrix[i][j] = 0;
//			}
//		}
//
//
//		matrix_frequancy(matrix, 34, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << " \t" << upper_alphabet[i];
//		}
//
//		cout << endl;
//
//		for (int i = 0; i < 34; i++)
//		{
//			for (int j = 0; j < 34; j++)
//			{
//				cout << matrix[i][j] << "\t";
//			}
//			cout << endl;
//
//		}
//
//
//
//		for (int i = 0; i < 34; i++)
//		{
//			delete matrix[i];
//		}
//
//		delete[] matrix;
//
//
//
//
//
//		line
//
//			/*cout << endl << "Process of saving data in in_file.txt ..." << endl;
//
//			string _path = "in_file.txt";
//
//			ofstream fout;
//
//			fout.open(_path);
//
//			if (!fout.is_open())
//			{
//				cout << endl << "Error of saving in file!" << endl;
//			}
//			else
//			{
//				cout << endl << "File saved seccsesfull." << endl;
//
//				fout << text;
//			}
//
//			fout.close();
//
//			line*/
//
//	}
//
//	fin.close();
//
//	return 0;
//
//}
//
//
//alphabet* freuquency_of_symbols(alphabet* array, int size, string text)
//{
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		for (int j = 0; j < 34; j++)
//		{
//
//			if (text[i] == lower_alphabet[j])
//			{
//				array[j].value = array[j].value + 1;
//				break;
//			}
//		}
//
//	}
//
//	return array;
//}
//
//void bubbleSort(alphabet* arrayPtr, int length_array)
//{
//	int temp_ = 0;
//	char _temp = 0;
//	bool exit = false;
//
//	while (!exit)
//	{
//		exit = true;
//		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
//
//			if (arrayPtr[int_counter].value < arrayPtr[int_counter + 1].value)
//			{
//
//				temp_ = arrayPtr[int_counter].value;
//				arrayPtr[int_counter].value = arrayPtr[int_counter + 1].value;
//				arrayPtr[int_counter + 1].value = temp_;
//
//				_temp = arrayPtr[int_counter].symbols;
//				arrayPtr[int_counter].symbols = arrayPtr[int_counter + 1].symbols;
//				arrayPtr[int_counter + 1].symbols = _temp;
//
//				exit = false;
//			}
//	}
//}
//
////void bubbleSort(int* arrayPtr, int length_array)
////{
////	int temp = 0;
////	bool exit = false;
////
////	while (!exit)
////	{
////		exit = true;
////		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
////
////			if (arrayPtr[int_counter] < arrayPtr[int_counter + 1])
////			{
////
////				temp = arrayPtr[int_counter];
////				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
////				arrayPtr[int_counter + 1] = temp;
////				exit = false;
////			}
////	}
////}
//
//double** matrix_frequancy(double** matrix, int row, int column, string text)
//{
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int t = 0; t < text.length() - 1; t++)
//	{
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < column; j++)
//			{
//				if (text[t] == lower_alphabet[i] && text[t + 1] == lower_alphabet[j])
//				{
//					matrix[i][j] = matrix[i][j] + 1;
//				}
//
//			}
//		}
//	}
//
//
//	return matrix;
//}
//
//string filtration_the_text(string text)
//{
//	string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ";
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		for (int j = 0; j < 34; j++)
//		{
//
//			if (text[i] == lower_alphabet[j])
//			{
//				text[i] = lower_alphabet[j];
//				break;
//			}
//			if (text[i] == upper_alphabet[j])
//			{
//				text[i] = lower_alphabet[j];
//				break;
//			}
//			if (j == 33 && text[i] != lower_alphabet[j] && text[i] != lower_alphabet[j])
//			{
//				text[i] = ' ';
//				break;
//			}
//
//		}
//
//	}
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		if (text[i] == ' '&&text[i + 1] == ' ')
//		{
//			text.erase(i, 1);
//			i = i - 1;
//		}
//	}
//
//
//	return text;
//}

//#include <iostream>
//#include <string>
//#include <fstream>
//#include <algorithm>
//#include <Windows.h> 
//
//using namespace std;
//
//#define line cout<<endl<<"_________________________________________________________"<<endl;
//
//
//struct alphabet
//{
//	char symbols;
//	int value;
//};
//
//alphabet null(alphabet language, int size);
//
//int* freuquency_of_symbols(int* array, int size, string text);
//void bubbleSort(int* arrayPtr, int length_array);
//double** matrix_frequancy(double** matrix, int row, int column, string text);
//
//string filtration_the_text(string text);
//
//
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	string path_ = "out_file.txt";
//
//	ifstream fin;
//
//	fin.open(path_);
//
//	if (!fin.is_open())
//	{
//		cout << endl << "Error of open file!" << endl;
//	}
//	else
//	{
//		line
//
//			cout << endl << "File open seccsesfull and we may to work with file." << endl;
//
//
//		string  text;
//
//		string one_string;
//
//		while (!fin.eof())
//		{
//			one_string = "";
//			getline(fin, one_string);
//			text = text + one_string;
//		}
//
//		line
//
//			cout << endl << "Check of the output of russian symbols:" << endl;
//
//		cout << endl << text << endl;
//
//
//		line
//
//			cout << endl << "Process of filtration source text..." << endl;
//
//		text = filtration_the_text(text);
//
//		cout << endl << text << endl;
//
//		line
//
//			int* alphabet_frequency = new int[34];
//
//		cout << endl << "Freaquency analise:" << endl;
//
//		string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_";
//
//		alphabet  language[34];
//
//		for (int i = 0; i < 34; i++)
//		{
//			language[i].symbols = upper_alphabet[i];
//
//		}
//
//		//ordunary order-start
//		cout << endl << "-count of each symbol in alphabet order:" << endl; null(language, 34);
//
//		cout << endl << "А\tБ\tВ\tГ\tД\tЕ\tЁ\tЖ\tЗ\tИ\tЙ\tК\tЛ\tМ\tН\tО\tП\tР\tС\tТ\tУ\tФ\tХ\tЦ\tЧ\tШ\tЩ\tЪ\tЫ\tЬ\tЭ\tЮ\tЯ\t_\t" << endl;
//
//		freuquency_of_symbols(alphabet_frequency, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << alphabet_frequency[i] << "\t";
//		}
//
//		cout << endl << "-frequancy of each symbol in alphabet order:" << endl;
//
//		cout << endl << "А\tБ\tВ\tГ\tД\tЕ\tЁ\tЖ\tЗ\tИ\tЙ\tК\tЛ\tМ\tН\tО\tП\tР\tС\tТ\tУ\tФ\tХ\tЦ\tЧ\tШ\tЩ\tЪ\tЫ\tЬ\tЭ\tЮ\tЯ\t_\t" << endl;
//
//
//		freuquency_of_symbols(alphabet_frequency, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << (double)alphabet_frequency[i] / text.length() << "\t";
//		}
//		//ordunary order-end
//
//		//sorting order-start
//		cout << endl << "-count of each symbol in sorting order:" << endl;
//
//		null(alphabet_frequency, 34);
//
//		freuquency_of_symbols(alphabet_frequency, 34, text);
//
//		bubbleSort(alphabet_frequency, 34);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << (double)alphabet_frequency[i] << "\t";
//		}
//
//		cout << endl << "-frequancy of each symbol in sorting order:" << endl;
//
//		null(alphabet_frequency, 34);
//		freuquency_of_symbols(alphabet_frequency, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << (double)alphabet_frequency[i] / text.length() << "\t";
//		}
//		//sorting order-end
//
//		delete[]  alphabet_frequency;
//
//
//		//bigram frequancy-start
//
//
//		cout << endl << "-bigram frequency:" << endl;
//
//		double** matrix = new double*[34];
//
//		for (int i = 0; i < 34; i++)
//		{
//			matrix[i] = new double[34];
//		}
//
//		for (int i = 0; i < 34; i++)
//		{
//			for (int j = 0; j < 34; j++)
//			{
//				matrix[i][j] = 0;
//			}
//		}
//
//
//		//_______________________________________________________
//
//		string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ_";
//
//		matrix_frequancy(matrix, 34, 34, text);
//
//		for (int i = 0; i < 34; i++)
//		{
//			cout << " \t" << upper_alphabet[i];
//		}
//
//		cout << endl;
//
//		for (int i = 0; i < 34; i++)
//		{
//			for (int j = 0; j < 34; j++)
//			{
//				cout << matrix[i][j] << "\t";
//			}
//			cout << endl;
//
//		}
//
//		//_______________________________________________________
//
//		for (int i = 0; i < 34; i++)
//		{
//			delete matrix[i];
//		}
//
//		delete[] matrix;
//
//		//bigram frequancy-end
//
//
//
//		line
//
//			/*cout << endl << "Process of saving data in in_file.txt ..." << endl;
//
//			string _path = "in_file.txt";
//
//			ofstream fout;
//
//			fout.open(_path);
//
//			if (!fout.is_open())
//			{
//				cout << endl << "Error of saving in file!" << endl;
//			}
//			else
//			{
//				cout << endl << "File saved seccsesfull." << endl;
//
//				fout << text;
//			}
//
//			fout.close();
//
//			line*/
//
//	}
//
//	fin.close();
//
//	return 0;
//
//}
//
//alphabet* null(alphabet* language, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		language[i].value = 0;
//	}
//
//	return language;
//}
//
//int* freuquency_of_symbols(int* array, int size, string text)
//{
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		for (int j = 0; j < 34; j++)
//		{
//
//			if (text[i] == lower_alphabet[j])
//			{
//				array[j] = array[j] + 1;
//				break;
//			}
//		}
//
//	}
//
//	return array;
//}
//
//void bubbleSort(int* arrayPtr, int length_array)
//{
//	int temp = 0;
//	bool exit = false;
//
//	while (!exit)
//	{
//		exit = true;
//		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
//
//			if (arrayPtr[int_counter] < arrayPtr[int_counter + 1])
//			{
//
//				temp = arrayPtr[int_counter];
//				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
//				arrayPtr[int_counter + 1] = temp;
//				exit = false;
//			}
//	}
//}
//
//double** matrix_frequancy(double** matrix, int row, int column, string text)
//{
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int t = 0; t < text.length() - 1; t++)
//	{
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < column; j++)
//			{
//				if (text[t] == lower_alphabet[i] && text[t + 1] == lower_alphabet[j])
//				{
//					matrix[i][j] = matrix[i][j] + 1;
//				}
//
//			}
//		}
//	}
//
//
//	return matrix;
//}
//
//string filtration_the_text(string text)
//{
//	string upper_alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ";
//	string lower_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		for (int j = 0; j < 34; j++)
//		{
//
//			if (text[i] == lower_alphabet[j])
//			{
//				text[i] = lower_alphabet[j];
//				break;
//			}
//			if (text[i] == upper_alphabet[j])
//			{
//				text[i] = lower_alphabet[j];
//				break;
//			}
//			if (j == 33 && text[i] != lower_alphabet[j] && text[i] != lower_alphabet[j])
//			{
//				text[i] = ' ';
//				break;
//			}
//
//		}
//
//	}
//
//	for (int i = 0; i < text.length(); i++)
//	{
//		if (text[i] == ' '&&text[i + 1] == ' ')
//		{
//			text.erase(i, 1);
//			i = i - 1;
//		}
//	}
//
//
//	return text;
//}

/*cout << endl << "Process of saving data in in_file.txt ..." << endl;

			string _path = "in_file.txt";

			ofstream fout;

			fout.open(_path);

			if (!fout.is_open())
			{
				cout << endl << "Error of saving in file!" << endl;
			}
			else
			{
				cout << endl << "File saved seccsesfull." << endl;

				fout << text;
			}

			fout.close();

			line*/
