// Labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "addition_functional.h"

int main()
{
	SetConsoleCP(1251);                    SetConsoleOutputCP(1251);

	ifstream fin_for_encryption_text;      string path_for_encryption_text = "text_for_encryption.txt";           fin_for_encryption_text.open(path_for_encryption_text);
	ifstream fin_for_decryption_text;      string path_for_decryption_text = "text_for_decryption.txt";           fin_for_decryption_text.open(path_for_decryption_text);


	if (!fin_for_encryption_text.is_open() && !fin_for_decryption_text.is_open())
	{
		cout << endl << "Error of open files!" << endl;
	}
	else
	{
		line

		cout << endl << "File open seccsesfull." << endl;

		unsigned int start_time = clock();

		line

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		/// common variables block start

		string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщъыьэюя";

		string temp;

		string one_string_encryption_text;     string encryption_text;
		string one_string_decryption_text;     string decryption_text;

		/// vommon variables block end 


		///algorythm block start

		encryption_text=get_all_text_in_one_string(fin_for_encryption_text, encryption_text, one_string_encryption_text);

		temp = encryption(encryption_text, "леонардейлер");

		cout <<endl<< "Text:" << endl;               cout << endl << encryption_text << endl;
		cout <<endl<< "Encrypted text:" << endl;     cout << endl << temp << endl;
		
		line

		string key=hacking_the_key(temp);

		line

			/*decryption_text = get_all_text_in_one_string(fin_for_decryption_text, decryption_text, one_string_decryption_text);*/

		decryption_text = temp;

		temp = decryption(decryption_text, key);

		cout <<endl<< "Text:" << endl;               cout << endl << decryption_text << endl;
		cout <<endl<< "Decrypted text:" << endl;     cout << endl << temp;

		///algorythm block end

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		line

		unsigned int end_time = clock();

		unsigned int search_time = end_time - start_time;

		cout << endl << "Time of work: " << search_time << " miliseconds;" << endl;

		line
	}

	fin_for_decryption_text.close();
	fin_for_encryption_text.close();

	return 0;

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
