// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


//connected library block start

#include "my_function_library.h"

//connected library block end


//main function start

int main()
{

	//language configuration

	SetConsoleCP(1251); SetConsoleOutputCP(1251);


	//intput of path to text file

	string path_;    cout << endl << "Input path to text-file: ";      
	
	cin >> path_;       
	

	//open text file for analise of frequency

	ifstream fin;       fin.open(path_);


	if (!fin.is_open())
	{
		cout << endl << "Error of open file!" << endl;
	}
	else
	{
		//clock start

		unsigned int start_time = clock();


		// open file for writing the statistic

		cout << endl << "File open seccsesfull." << endl;  fstream fout;      fout.open("in_file.xls", ios::out);


		//creating of start data block start

		type text_size;
		type space_number;
		
		int bigram_universume_with_space_step_one;
		int bigram_universume_with_space_step_two;
		int bigram_universume_without_space_step_one;
		int bigram_universume_without_space_step_two;

		string one_string;                string _upper_alphabet_ = upper_alphabet(); 

		alphabet  table_frequency[34];    null(table_frequency, _upper_alphabet_, 34);

		long double entrophy_alphubet_without_space, entrophy_alphubet_with_space;

		//creating of start data block end


		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// frequency analize each symbols in text block start
		{

			fin.seekg(0, std::ios::beg);

			text_size = 0;

			while (!fin.eof())
			{
				getline(fin, one_string);

				one_string = filtration_the_text_with_space(one_string);

				freuquency_of_symbols(table_frequency, 34, one_string);

				text_size += one_string.length();
			}


			space_number = table_frequency[33].value;


			fout << endl << "Freaquency analise of text in general:" << endl << endl;


			fout << endl << "-ordinary order of symbols with space:" << endl;

			fout << endl << "\t" << "Symbols" << "\t" << "Count" << "\t" << "Frequancy" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << "\t" << table_frequency[i].symbols << "\t" << table_frequency[i].value << "\t" << (long double)(table_frequency[i].value) / text_size << endl;
			}


			fout << endl << "-ordinary order of symbols without space:" << endl;

			fout << endl << "\t" << "Symbols" << "\t" << "Count" << "\t" << "Frequancy" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				if (table_frequency[i].symbols != '_')
				{
					fout << "\t" << table_frequency[i].symbols << "\t" << table_frequency[i].value << "\t" << (long double)(table_frequency[i].value) / (text_size - space_number) << endl;
				}
			}

			bubbleSort(table_frequency, 34);


			fout << endl << "-sorting order of symbols with space:" << endl;

			fout << endl << "\t" << "Symbols" << "\t" << "Count" << "\t" << "Frequancy" << endl << endl;

			for (type i = 0; i < 34; i++)
			{

				fout << "\t" << table_frequency[i].symbols << "\t" << table_frequency[i].value << "\t" << ((long double)(table_frequency[i].value)) / text_size << endl;

			}

			fout << endl << "-sorting order of symbols without space:" << endl;

			fout << endl << "\t" << "Symbols" << "\t" << "Count" << "\t" << "Frequancy" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				if (table_frequency[i].symbols != '_')
				{
					fout << "\t" << table_frequency[i].symbols << "\t" << table_frequency[i].value << "\t" << ((long double)(table_frequency[i].value)) / (text_size - space_number) << endl;
				}
			}



			entrophy_alphubet_with_space = entrophy_of_alphabet(table_frequency, text_size, 34);
			fout << endl << "Entrophy of symbols of alphabet with struck: " << entrophy_alphubet_with_space << " ;" << endl;

			entrophy_alphubet_without_space = entrophy_of_alphabet_without_struck(table_frequency, text_size - space_number, 33);
			fout << endl << "Entrophy of symbols of alphabet without struck: " << entrophy_alphubet_without_space << " ;" << endl;

		}
		// frequency analize each symbols in text block end

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//create matrix start

		long  double** matrix = new long double*[34];

		for (type i = 0; i < 34; i++)
		{
			matrix[i] = new long double[34];
		}

		//create matrix end


		// bigram frequency with spaces block start

		{

			null_matrix(matrix, 34);

			fin.seekg(0, std::ios::beg);

			
			while (!fin.eof())
			{
				getline(fin, one_string);

				one_string = filtration_the_text_with_space(one_string);

				if (one_string.length() <= 1)
				{
					continue;
				}

				matrix_frequancy_with_step_one(matrix, 34, 34, one_string);
			}

			fout << endl << "Bigram statistic data for step one, with space:" << endl << endl;

			fout << endl << "-bigram count with step one, with space:" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << "\t \t" << _upper_alphabet_[i];
			}

			fout << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << _upper_alphabet_[i] << "\t";

				for (type j = 0; j < 34; j++)
				{
					fout << "\t" << matrix[i][j] << "\t";
				}
				fout << endl;

			}

			bigram_universume_with_space_step_one = 0;

			for (type i = 0; i < 34; i++)
			{
				for (type j = 0; j < 34; j++)
				{
					bigram_universume_with_space_step_one = bigram_universume_with_space_step_one + matrix[i][j];
				}
			}

			fout << endl << "-bigram frequency with step one, with space:" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
			fout << "\t \t" << _upper_alphabet_[i];
			}

			fout << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << _upper_alphabet_[i] << "\t";

				for (type j = 0; j < 34; j++)
				{
					fout << "\t" << (long double)matrix[i][j] / bigram_universume_with_space_step_one << "\t";
				}

				fout << endl;
			}

			fout << endl << "Entrophy on symbol of bigram with space and step one: " << entrophy_of_alphabet_bigram(matrix, bigram_universume_with_space_step_one, 34) / 2 << " ;" << endl;


			null_matrix(matrix, 34);

			fin.seekg(0, std::ios::beg);

			while (!fin.eof())
			{
				getline(fin, one_string);

				one_string = filtration_the_text_with_space(one_string);

				if (one_string.length() <= 1)
				{
					continue;
				}

				matrix_frequancy_with_step_two(matrix, 34, 34, one_string);
			}


			fout << endl << "Bigram statistic data with step two, with space:" << endl << endl;


			fout << endl << "-bigram count with step two, with space:" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << "\t \t" << _upper_alphabet_[i];
			}

			fout << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << _upper_alphabet_[i] << "\t";

				for (type j = 0; j < 34; j++)
				{
					fout << "\t" << matrix[i][j] << "\t";
				}
				fout << endl;

			}

			bigram_universume_with_space_step_two = 0;

			for (type i = 0; i < 34; i++)
			{
				for (type j = 0; j < 34; j++)
				{
					bigram_universume_with_space_step_two = bigram_universume_with_space_step_two + matrix[i][j];
				}
			}

			fout << endl << "-bigram frequency with step two, with space:" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << "\t \t" << _upper_alphabet_[i];
			}

			fout << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << _upper_alphabet_[i] << "\t";

				for (type j = 0; j < 34; j++)
				{
					fout << "\t" << (long double)matrix[i][j] / bigram_universume_with_space_step_two << "\t";
				}
				fout << endl;

			}

			fout << endl << "Entrophy on symbol of bigram with space and step two: " << entrophy_of_alphabet_bigram(matrix, bigram_universume_with_space_step_two, 34) / 2 << " ;" << endl;

		}

		// bigram frequency with spaces block end


		//bigram frequency without spaces block start

		{
			null_matrix(matrix, 34);

			fin.seekg(0, std::ios::beg);

			while (!fin.eof())
			{
				getline(fin, one_string);

				one_string = filtration_the_text_without_space(one_string);

				if (one_string.length() <= 1)
				{
					continue;
				}

				matrix_frequancy_with_step_one(matrix, 34, 34, one_string);
			}


			fout << endl << "Bigram statistic data for step one, without space:" << endl << endl;

			fout << endl << "-bigram count with step one, without space:" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << "\t \t" << _upper_alphabet_[i];
			}

			fout << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << _upper_alphabet_[i] << "\t";

				for (type j = 0; j < 34; j++)
				{
					fout << "\t" << matrix[i][j] << "\t";
				}
				fout << endl;

			}

			bigram_universume_without_space_step_one = 0;

			for (type i = 0; i < 34; i++)
			{
				for (type j = 0; j < 34; j++)
				{
					bigram_universume_without_space_step_one = bigram_universume_without_space_step_one + matrix[i][j];
				}
			}

			fout << endl << "-bigram frequency with step one, without space:" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << "\t \t" << _upper_alphabet_[i];
			}

			fout << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << _upper_alphabet_[i] << "\t";

				for (type j = 0; j < 34; j++)
				{
					fout << "\t" << (long double)matrix[i][j] / bigram_universume_without_space_step_one << "\t";
				}

				fout << endl;

			}

			fout << endl << "Entrophy on symbol of bigram without space and step one: " << entrophy_of_alphabet_bigram(matrix, bigram_universume_without_space_step_one, 33) / 2 << " ;" << endl;


			null_matrix(matrix, 34);

			fin.seekg(0, std::ios::beg);

			while (!fin.eof())
			{
				getline(fin, one_string);

				one_string = filtration_the_text_without_space(one_string);

				if (one_string.length() <= 1)
				{
					continue;
				}

				matrix_frequancy_with_step_two(matrix, 34, 34, one_string);

			}


			fout << endl << "Bigram statistic data with step two, without space:" << endl << endl;


			fout << endl << "-bigram count with step two, without space:" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << "\t \t" << _upper_alphabet_[i];
			}

			fout << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << _upper_alphabet_[i] << "\t";

				for (type j = 0; j < 34; j++)
				{
					fout << "\t" << matrix[i][j] << "\t";
				}
				fout << endl;

			}


			bigram_universume_without_space_step_two = 0;

			for (type i = 0; i < 34; i++)
			{
				for (type j = 0; j < 34; j++)
				{
					bigram_universume_without_space_step_two = bigram_universume_without_space_step_two + matrix[i][j];
				}
			}



			fout << endl << "-bigram frequency with step two, without space:" << endl << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << "\t \t" << _upper_alphabet_[i];
			}

			fout << endl;

			for (type i = 0; i < 34; i++)
			{
				fout << _upper_alphabet_[i] << "\t";

				for (type j = 0; j < 34; j++)
				{
					fout << "\t" << (long double)matrix[i][j] / bigram_universume_without_space_step_two << "\t";
				}
				fout << endl;


			}

			fout << endl << "Entrophy on symbol of bigram without space and step two: " << entrophy_of_alphabet_bigram(matrix, bigram_universume_without_space_step_two, 33) / 2 << " ;" << endl;


		}

		//bigram frequency without spaces block end


		//delite matrix start

		for (type i = 0; i < 34; i++)
		{
			delete matrix[i];
		}

		delete[] matrix;

		//delite matrix end

	
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		//clock end

		unsigned int end_time = clock(); unsigned int search_time = end_time - start_time;

		cout << endl << "Time of work: " << search_time << " miliseconds;" << endl;



	}

	//file close and exit with program

	fin.close();

	return 0;

}

//main function end

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
