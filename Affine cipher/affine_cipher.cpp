// affine_cipher.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


/*

Help information:

 - Russian alphabet with big symbol: АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ
 - Russian alphabet with little symbol: абвгдеёжзийклмнопрстуфхцчшщъыьэюя
 - Russian alphabet in frequency order: оеаинтсрвлкмдпуяыьгзбчйхжшюцщэфъ
 - power of Russion alphabet:33

 - We use in labs: абвгдежзийклмнопрстуфхцчшщыьэюя
 - power alphabet in labs: 31

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

#define type unsigned long int


/// function for work with bigrams block start

struct bigram_tools //ok
{
	string bigram;
	type value;
};

struct possible_key //ok
{
	type first_key;
	type second_key;
};

struct possible_permutation
{
	bigram_tools first_;
	bigram_tools second_;
	
};

string remove_all_spaces(string str) //ok
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

string filtration_the_text_without_space(string text) //ok
{
	string upper_alphabet = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЫЬЭЮЯ";
	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	for (type i = 0; i < text.length(); i++)
	{
		for (type j = 0; j < 31; j++)
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
			if (text[i] == 'Ё' || text[i] == 'ё')
			{
				text[i] = 'е';
				break;
			}
			if (text[i] == 'Ъ' || text[i] == 'ъ')
			{
				text[i] = 'ь';
				break;
			}
			if (j == 30 && text[i] != lower_alphabet[j])
			{
				text[i] = ' ';
				break;
			}
		}

	}

	return remove_all_spaces(text);
}

type** matrix_frequancy_with_step_two(type** matrix, type row, type column, string text) //ok
{
	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

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

string get_all_text_in_one_string(ifstream &text_link, string text, string text_string) //ok
{

	text_link.seekg(0, std::ios::beg);

	text = " ";

	while (!text_link.eof())
	{
		getline(text_link, text_string);

		text_string = filtration_the_text_without_space(text_string);

		text = text + text_string;
	}

	text = remove_all_spaces(text);

	return text;
}

string we_make_the_text_of_even_length(string text)//ok
{

	if (text.length() % 2 != 0)
	{
		text = text.substr(0, text.size() - 1);
	}

	return text;
}

type* copy_vector(type* vector_first, type* vector_second, type size) //ok
{
	for (type i = 0; i < size; i++)
	{
		vector_second[i] = vector_first[i];
	}

	return vector_second;
}

type** copy_matrix(type** matrix_first, type** matrix_second, type size) //ok
{
	for (type i = 0; i < size; i++)
	{
		for (type j = 0; j < size; j++)
		{
			matrix_second[i][j] = matrix_first[i][j];
		}
	}

	return matrix_second;
}

type* null_vector(type* vector, type size)//ok
{
	for (type i = 0; i < size; i++)
	{
		vector[i] = 0;
	}

	return vector;
}

type** null_matrix(type** matrix, type size)//ok
{
	for (type i = 0; i < size; i++)
	{
		for (type j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void bubbleSort(bigram_tools* bigrams_statistics_sorting, type length_array)//ok
{
	type temp_ = 0;
	string _temp;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (type int_counter = 0; int_counter < (length_array - 1); int_counter++)

			if (bigrams_statistics_sorting[int_counter].value < bigrams_statistics_sorting[int_counter + 1].value)
			{

				temp_ = bigrams_statistics_sorting[int_counter].value;
				bigrams_statistics_sorting[int_counter].value = bigrams_statistics_sorting[int_counter + 1].value;
				bigrams_statistics_sorting[int_counter + 1].value = temp_;

				_temp = bigrams_statistics_sorting[int_counter].bigram;
				bigrams_statistics_sorting[int_counter].bigram = bigrams_statistics_sorting[int_counter + 1].bigram;
				bigrams_statistics_sorting[int_counter + 1].bigram = _temp;

				exit = false;
			}
	}
}

bigram_tools* statistics_start_initil(bigram_tools* array_sorting_bigram)//ok
{
	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	type count = 0;

	for (type i = 0; i < lower_alphabet.length(); i++)
	{
		for (type j = 0; j < lower_alphabet.length(); j++)
		{
			string temp = " ";

			temp = temp + lower_alphabet[i] + lower_alphabet[j];
			temp = remove_all_spaces(temp);

			array_sorting_bigram[count].bigram = temp;
			array_sorting_bigram[count].value = 0;

			count++;
		}
	}

	return array_sorting_bigram;
}

void output_statistics_bigram(bigram_tools* array_sorting_bigram) //ok
{
	cout << endl;

	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	for (type i = 0; i < pow(lower_alphabet.length(), 2); i++)
	{
		cout << " \t Bigram: " << array_sorting_bigram[i].bigram << " equel " << array_sorting_bigram[i].value << ";" << endl;
	}
}

bigram_tools* sorting_matrix_in_descending(bigram_tools* array_sorting_bigram,string text)//ok
{
	type count = 0;

	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";


	type** matrix = new type*[lower_alphabet.length()];

	for (type i = 0; i < lower_alphabet.length(); i++)
	{
			matrix[i] = new type[lower_alphabet.length()];
	}

	null_matrix(matrix, lower_alphabet.length());


	matrix=matrix_frequancy_with_step_two(matrix, lower_alphabet.length(), lower_alphabet.length(), text);


	for (type i = 0; i < lower_alphabet.length(); i++)
	{
	    for (type j = 0; j < lower_alphabet.length(); j++)
	    {
	    		string temp = " ";
				temp=temp+lower_alphabet[i] + lower_alphabet[j]; 
				temp = remove_all_spaces(temp);
	
				array_sorting_bigram[count].bigram = temp;
				array_sorting_bigram[count].value = matrix[i][j];

				count++;
		}
	}
	
	bubbleSort(array_sorting_bigram, pow(lower_alphabet.length(), 2));


	for (type i = 0; i < lower_alphabet.length(); i++)
	{
		delete matrix[i];
	}

	delete[] matrix;

	return array_sorting_bigram;
}

/// function for work with bigrams block end


///algorithmic part block start

//.............................insert invers element block...........................// 

int number_by_module(int number, int module)
{
	int numb_by_module;
	if (number < 0)
	{
		if (number / module != 0)
		{
			numb_by_module = module - (abs(number) - module * (abs(number) / module));
		}
		else {
			numb_by_module = module - abs(number);
		}
		//numb_by_module = module - abs(number);
	}
	else if (number / module != 0) {
		numb_by_module = number - module * (number / module);
	}
	else {
		numb_by_module = number;
	}
	//numb_by_module = number;
	return numb_by_module;
}

int gcd(int first_num, int second_num)
{
	int gcd_value;
	int r_1 = first_num;
	int r_2 = second_num;

	int q_1;
	int q_2 = -1;

	while (q_2 != 0)
	{
		if (r_1 < r_2)
		{
			int temp;
			temp = r_1;
			r_1 = r_2;
			r_2 = temp;
			gcd(r_1, r_2);
		}
		else {
			q_1 = r_1 / r_2;
			q_2 = r_1 - (q_1 * r_2);
			r_1 = r_2;
			r_2 = q_2;
		}
	}
	gcd_value = r_1;
	return gcd_value;
}

int choose_bigger_num(int first_num, int second_num)
{
	if (first_num < second_num)
	{
		return second_num;
	}
	else
	{
		return first_num;
	}
}

int choose_smaller_num(int first_num, int second_num)
{
	if (first_num < second_num)
	{
		return first_num;
	}
	else {
		return second_num;
	}
}

int index_of_first_nonzero_el_of_array(int* array, int size_of_arr)
{
	int index = size_of_arr - 1;
	while (array[index] == 0)
	{
		index--;
	}
	return index;
}

int inverted_element(int first_num, int second_num)
{
	int which_el_be_inversed = first_num;
	int inv_el = 0;
	int Q_1_array[32];
	int R_1_array[32];
	int Q_2_array[32];
	int R_2_array[32];
	for (int i = 0; i < 32; i++)
	{
		Q_1_array[i] = 0;
		Q_2_array[i] = 0;
		R_1_array[i] = 0;
		R_1_array[i] = 0;
	}
	int gcd_value = gcd(first_num, second_num);
	if (gcd_value != 1)
	{
		cout << "There is no inversed elements!" << endl;
	}
	else {								//Euclidean algorithm
		int position = 0;
		R_1_array[position] = choose_bigger_num(first_num, second_num);
		R_2_array[position] = choose_smaller_num(first_num, second_num);
		Q_1_array[position] = R_1_array[position] / R_2_array[position];
		Q_2_array[position] = R_1_array[position] - (Q_1_array[position] * R_2_array[position]);
		position++;
		R_1_array[position] = R_2_array[position - 1];
		R_2_array[position] = Q_2_array[position - 1];
		while (R_2_array[position] != 0)
		{
			Q_1_array[position] = R_1_array[position] / R_2_array[position];
			Q_2_array[position] = R_1_array[position] - (Q_1_array[position] * R_2_array[position]);
			position++;
			R_1_array[position] = R_2_array[position - 1];
			R_2_array[position] = Q_2_array[position - 1];
		}
		/*cout << "Array of R_1:" << endl;
		for (int i = 0; i < index_of_first_nonzero_el_of_array(R_1_array, 32); i++)
		{
			cout << R_1_array[i] << "  ";
		}
		cout << endl;
		cout << "Array of R_2:" << endl;
		for (int i = 0; i < index_of_first_nonzero_el_of_array(R_1_array, 32); i++)
		{
			cout << R_2_array[i] << "  ";
		}
		cout << endl;
		cout << "Array of Q_1:" << endl;
		for (int i = 0; i < index_of_first_nonzero_el_of_array(R_1_array, 32); i++)
		{
			cout << Q_1_array[i] << "  ";
		}
		cout << endl;
		cout << "Array of Q_2:" << endl;
		for (int i = 0; i < index_of_first_nonzero_el_of_array(R_1_array, 32); i++)
		{
			cout << Q_2_array[i] << "  ";
		}
		cout << endl;*/
		int index = index_of_first_nonzero_el_of_array(R_1_array, 32);

		//find inverted element (using recursive formula)
		int* U_i_array = new int[index + 1];
		int* V_i_array = new int[index + 1];
		U_i_array[0] = R_2_array[index - 1];
		V_i_array[0] = 0;
		for (int i = 1; i < (index + 1); i++)
		{
			U_i_array[i] = V_i_array[i - 1];
			V_i_array[i] = U_i_array[i - 1] - (V_i_array[i - 1] * (R_1_array[index - i] / R_2_array[index - i]));
		}
		/*cout << "Coeficients U_i:" << endl;
		for (int i = 0; i < index + 1; i++)
		{
			cout << U_i_array[i] << " ";
		}
		cout << endl;*/

		/*cout << "Coeficients V_i:" << endl;
		for (int i = 0; i < index + 1; i++)
		{
			cout << V_i_array[i] << " ";
		}
		cout << endl;*/
		if (R_1_array[0] != which_el_be_inversed)
		{
			inv_el = number_by_module(V_i_array[index], second_num);
		}
		else {
			inv_el = number_by_module(U_i_array[index], second_num);
		}
	}
	return inv_el;
}

//...................................................................................//

type search_number_representation_of_bigram(char first, char second) //ok
{
	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	type temp_first, temp_second;


	for (type i = 0; i < lower_alphabet.length(); i++)
	{
		if (first == lower_alphabet[i])
		{
			temp_first = i;
			break;
		}

	}
	for (type j = 0; j < lower_alphabet.length(); j++)
	{
		if (second == lower_alphabet[j])
		{
			temp_second = j;
			break;
		}

	}

	return  temp_first * lower_alphabet.length() + temp_second;
}

string search_symbols_representation_of_bigram(type number_representation_bigrams) //ok
{
	string search_bigram = " ";

	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	for (type i = 0; i < lower_alphabet.length(); i++)
	{

		for (type j = 0; j < lower_alphabet.length(); j++)
		{
			if (number_representation_bigrams == i * lower_alphabet.length()+ j)
			{
				search_bigram = search_bigram + lower_alphabet[i] + lower_alphabet[j];
				search_bigram = remove_all_spaces(search_bigram);
				break;
			}

		}

	}


	return search_bigram;
}

type* convert_number_representation_of_bigram(string text_in_symbols, type* text_in_number)// ok
{
	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	for (type t = 0; t < (text_in_symbols.length() / 2); t++)
	{
		text_in_number[t] = search_number_representation_of_bigram(text_in_symbols[2 * t], text_in_symbols[2 * t + 1]);
	}

	return text_in_number;
}

string convert_string_representation_of_bigram(type* text_in_number, string text_in_symbols, type size_text_in_number)//ok
{
	text_in_symbols = " ";

	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	for (type i = 0; i < size_text_in_number; i++)
	{
		text_in_symbols = text_in_symbols + search_symbols_representation_of_bigram(text_in_number[i]);
	}

	text_in_symbols = remove_all_spaces(text_in_symbols);

	return text_in_symbols;
}

string affine_encryption(string text, type* key)//ok
{
	string cipher_text = " ";

	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	type* cipher_text_number_representation = new type[text.length() / 2];    null_vector(cipher_text_number_representation, text.length() / 2);
	type* text_number_representation = new type[text.length() / 2];           null_vector(text_number_representation, text.length() / 2);

	text_number_representation = convert_number_representation_of_bigram(text, text_number_representation);

	for (type i = 0; i < text.length() / 2; i++)
	{
		type moduls = pow(lower_alphabet.length(), 2);
		cipher_text_number_representation[i] = (key[0] * text_number_representation[i] + key[1]) % moduls;
	}

	cipher_text = remove_all_spaces(convert_string_representation_of_bigram(cipher_text_number_representation, cipher_text, text.length() / 2));

	delete[] text_number_representation;
	delete[] cipher_text_number_representation;

	return cipher_text;
}

string affine_decryption(string cipher_text, type* key)//ok
{
	string text = " ";

	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	type* cipher_text_number_representation = new type[cipher_text.length() / 2];     null_vector(cipher_text_number_representation, cipher_text.length() / 2);
	type* text_number_representation = new type[cipher_text.length() / 2];            null_vector(text_number_representation, cipher_text.length() / 2);

	cipher_text_number_representation = convert_number_representation_of_bigram(cipher_text, cipher_text_number_representation);

	type moduls = pow(lower_alphabet.length(), 2);
	type invert = inverted_element(key[0], moduls);

	for (type i = 0; i < cipher_text.length() / 2; i++)
	{
		if ((cipher_text_number_representation[i] - key[1]) < 0)
		{
			type temp = (moduls - (key[1] - cipher_text_number_representation[i])) % moduls;
			text_number_representation[i] = (invert * temp) % moduls;
		}
		else 
		{
			text_number_representation[i] = (invert*(cipher_text_number_representation[i] - key[1])) % moduls;
		}
	}

	text = remove_all_spaces(convert_string_representation_of_bigram(text_number_representation, text, cipher_text.length()/2));

	delete[] text_number_representation;
	delete[] cipher_text_number_representation;

	return text;

}


//..................................crack key block.....................................//

bool check_the_content_of_the_text(string text)
{

	bool verification = false;

	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

	string set_of_forbidden_bigram[70] = 
	 {  "ыы","ьы","ыь","ьь","щщ",
		"аы","бй","вй","гй","гц",
		"гщ","еы","жй","жф","жх",
		"жщ","жы","жю","зй","зщ",
		"иы","иь","йй","кй","кы",
		"кь","лй","мй","нй","оы",
		"оь","пф","пэ","рй","сй",
		"фж","фз","фй","фх","фц",
		"фш","фщ","фэ","фю","хй",
		"хы","хь","цй","цф","цш",
		"цщ","ць","цю","чй","чф",
		"чщ","чы","чю","шд","шж",
		"шщ","щб","щж","эо","эе",
		"уы","уь","фг","фд","юы"  };

	

	type count_errors_combination_in_text = 0;

	for (type i = 0; i < 70; i++)
	{
		if (text.find(set_of_forbidden_bigram[i]) != std::string::npos)
		{
			count_errors_combination_in_text++;
		}
	}

	if (count_errors_combination_in_text==0)
	{
		verification = true;
	}


	return verification;
}


void solving_system(type* X``, type* X`, type* Y``, type* Y`, type* A, type* B, type* moduls)
{

}

void crack_key(bigram_tools* array_sorting_bigram, string cipher_text, type* key)
{

	string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";     

	type* cipher_text_number_representation = new type[cipher_text.length() / 2];     
	null_vector(cipher_text_number_representation, cipher_text.length() / 2);
	
	cipher_text_number_representation = convert_number_representation_of_bigram(cipher_text, cipher_text_number_representation);

	//////////////////////////////////////all possible combination of bigram realisation//////////////////////////////////////
	
	type size_frequent_bigram = 5;
		
	string* symbol_theoretical = new symbol_theoretical[size_frequent_bigram];

	string* symbol_1 = "ст";                         string _symbol_1 = array_sorting_bigram[0].bigram;
	string* symbol_2 = "но";                         string _symbol_2 = array_sorting_bigram[1].bigram;
	string* symbol_3 = "то";                         string _symbol_3 = array_sorting_bigram[2].bigram;
	string* symbol_4 = "на";                         string _symbol_4 = array_sorting_bigram[3].bigram;
	string symbol_5 = "ен";                         string _symbol_5 = array_sorting_bigram[4].bigram;

	

	possible_permutation* possible_bigram = new possible_permutation[size_frequent_bigram*size_frequent_bigram];

	for (type i=0;i< size_frequent_bigram;i++)
	{
		for (type j = 0; j < size_frequent_bigram; j++)
		{
			possible_bigram[i].first_.bigram=
				possible_bigram[i].second_ = j;
		}
	}

	delete[] possible_bigram;



	//with the first and second block need to get two bigrams? all possible variants, can count if use A_n_k: number_possible_variants=A_5_2*A_5_2=400

	type number_possible_permutation_bigram_in_two_pair = 400;

	/////////////////////////////////////////////searching the key and varification/////////////////////////////////////////////
	


	possible_key* keys = new possible_key[5];


	//count all keys
	
	for (type i = 0; i < count_key; i++)
	{
		keys[i]=search_all_keys();
	}

	//cheak all keys
	for (type i = 0; i < count_key; i++)
	{
		if (verify_the_key_on_the_content())
		{
			count_key_verufied++;
		}
	}
	
	type count_key_verufied = 0;

	

	/////////////////////////////////////////////we must to chack the text visuality/////////////////////////////////////////////

	//see on all solution

	for (type i=0;i<count_key_verufied;i++)
	{

		    key[0] = keys[i].first_key;   key[1] = keys[i].second_key;
		    
			cout<<endl<<"Text: "<<affine_decryption(cipher_text, key)<<endl;

			cout<<endl<<"The text is normal?(yes/no)"<<endl;

			string answer; cin >> answer;
		    
			if (answer=="yes")
			{
				break;
			}
			else
			{
				continue;
            }
		
	}


	delete[] cipher_text_number_representation;

}

//...................................................................................//

///algorithmic part block end

int main()
{
	SetConsoleCP(1251);                      SetConsoleOutputCP(1251);


	ifstream fin_for_encryption_text;      string path_for_encryption_text = "text_for_encryption.txt";     fin_for_encryption_text.open(path_for_encryption_text);
	ifstream fin_for_decryption_text;      string path_for_decryption_text = "text_for_decryption.txt";     fin_for_decryption_text.open(path_for_decryption_text);

	fstream fout_for_encryption_text;      string _path_for_encryption_text = "encrypted.txt";             fout_for_encryption_text.open(_path_for_encryption_text, ios::out);
	fstream fout_for_decryption_text;      string _path_for_decryption_text = "decrypted.txt";             fout_for_decryption_text.open(_path_for_decryption_text, ios::out);



	if (!fin_for_encryption_text.is_open() && !fin_for_decryption_text.is_open())
	{
		cout << endl << "Error of open files!" << endl;
	}
	else
	{

		cout << endl << "File open seccsesfull." << endl;

		unsigned int start_time = clock();

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		/// common variables block start

		string lower_alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";

		string one_string_encryption_text;     string encryption_text;
		string one_string_decryption_text;     string decryption_text;

		/// vommon variables block end 

		/// text block encryption and decryption using conformity index start

		cout << endl << "Start program..." << endl;

		{   // block with text encypted process and decryption

			type test_key[2];    test_key[0] = 13;  test_key[1] = 151;

			bigram_tools* array_sorting_bigram = new bigram_tools[pow(lower_alphabet.length(),2)];      statistics_start_initil(array_sorting_bigram);
			

			encryption_text = we_make_the_text_of_even_length(get_all_text_in_one_string(fin_for_encryption_text, encryption_text, one_string_encryption_text));

			/*cout << endl << "Text: " << encryption_text << endl;
*/
/*
			string temp_ = affine_encryption(encryption_text, test_key);*/

			/*cout << endl << "Encryption text: " << temp_ << endl;
*/

			cout << endl << "Process sorting statistics bigram: " << endl; 

			/*cout << endl <<"Text comformity:"<<conformity_index_for_text(encryption_text)<<endl;
			cout << endl << "Cipher text comformity:" <<conformity_index_for_text(temp_) << endl;*/

			sorting_matrix_in_descending(array_sorting_bigram, encryption_text);
			output_statistics_bigram(array_sorting_bigram);

/*
			string _temp = affine_decryption(temp_, test_key);

			cout << endl << "Decrypted text: " << _temp << endl;*/

			delete[]  array_sorting_bigram;
		}

		cout << endl << "End program..." << endl;

		/// text block encryption and decryption using conformity index end


		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		unsigned int end_time = clock();

		unsigned int search_time = end_time - start_time;

		cout << endl << "Time of work: " << search_time << " miliseconds;" << endl;

	}


	fout_for_decryption_text.close();
	fout_for_encryption_text.close();

	fin_for_decryption_text.close();
	fin_for_encryption_text.close();


	return 0;

}

//void output_matrix(type** matrix, type size)
//{
//	cout << endl << "Matrix start:" << endl;
//
//	for (type i = 0; i < size; i++)
//	{
//		for (type j = 0; j < size; j++)
//		{
//			cout<<matrix[i][j]<<" ";
//		}
//		cout << endl;
//	}
//
//	cout << endl << "Matrix end:" << endl;
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
