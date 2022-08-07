#pragma once

/*

Help information:

 -Russian alphabet with little symbol: אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ
 -Russian alphabet with big symbol: ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞ‗
 -Russian alphabet in frequency order: מואטםעסנגכךלהןףÿûüדחבקיץזר‏צש‎פת
 -power of Russion alphabet:33

 */

 /// standart include start///

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

#define type  int

/// standart include end///

///labs function block start


struct frequency_statistics
{
	char symbols;
	type value;
};

string remove_all_spaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

string filtration_the_text_without_space_modified(string text)
{
	// incurrent string of text 32 symbols

	string upper_alphabet = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞ‗";
	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

	for (type i = 0; i < text.length(); i++)
	{
		for (type j = 0; j < 32; j++)
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
			if (text[i] == '¨' || text[i] == '¸')
			{
				text[i] = 'ו';
				break;
			}
			if (j == 31 && text[i] != lower_alphabet[j])
			{
				text[i] = ' ';
				break;
			}
		}

	}

	return remove_all_spaces(text);
}

frequency_statistics* freuquency_of_symbols(frequency_statistics* language,string text,type size)
{

	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

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

frequency_statistics* start_frequency_table(frequency_statistics* language, string lower_alphabet, type size)
{
	for (type i = 0; i < size; i++)
	{
		language[i].symbols = lower_alphabet[i]; language[i].value = 0;
	}
	return language;
}

void sorting(frequency_statistics* language_, type length_array)
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

string text_with_specific_position(string text, type start, type end)
{
	string temp = " ";

	for (type i = start; i < end; i++)
	{
		temp = temp + text[i];
	}

	temp = remove_all_spaces(temp);

	return temp;
}

string get_all_text_in_one_string(ifstream &text_link, string text, string text_string)
{

	text_link.seekg(0, std::ios::beg);

	text = " ";

	while (!text_link.eof())
	{
		getline(text_link, text_string);

		text_string = filtration_the_text_without_space_modified(text_string);

		text = text + text_string;
	}

	text = remove_all_spaces(text);

	return text;
}

type* null(type* array_numbers, type size)
{
	for (type i = 0; i < size; i++)
	{
		array_numbers[i] = 0;
	}

	return array_numbers;
}

type* addition_of_array_by_module(type* array_first, type* array_second, type* result, type module, type size)
{
	null(result, size);

	for (type i = 0; i < size; i++)
	{
		result[i] = (array_first[i] + array_second[i]) % module;
	}

	return  result;
}

type* substraction_of_array_by_module(type* array_first, type* array_second, type* result, type module, type size)
{
	null(result, size);

	for (type i = 0; i < size; i++)
	{
		if (array_first[i] >= array_second[i])
		{
			result[i] = (array_first[i] - array_second[i]) % module;
		}
		else
		{
			type temp = (array_second[i] - array_first[i]) % module;
			result[i] = (module - temp) % module;
		}

	}

	return  result;
}

type* convert_text_to_number_of_ring(string text_in_symbol_representation, type* text_in_number_representation, type size_text)
{
	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

	for (int i = 0; i < size_text; i++)
	{
		for (int j = 0; j < lower_alphabet.length(); j++)
		{
			if (text_in_symbol_representation[i] == lower_alphabet[j])
			{
				text_in_number_representation[i] = j;
				break;
			}
		}

	}

	return text_in_number_representation;
}

string convert_number_of_ring_to_text(type* text_in_number_representation, string text_in_symbol_representation, type size_text)
{
	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

	string temp = " ";

	for (int i = 0; i < size_text; i++)
	{
		int index = text_in_number_representation[i];

		temp = temp + lower_alphabet[index];
	}

	text_in_symbol_representation = remove_all_spaces(temp);

	return text_in_symbol_representation;
}

string wiegener_cipher_encryption_part(string text, string chipher, string key)
{
	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

	type* text_ = new type[key.length()];  type* cipher_ = new type[key.length()];  type* key_ = new type[key.length()];

	text_ = convert_text_to_number_of_ring(text, text_, key.length());
	key_ = convert_text_to_number_of_ring(key, key_, key.length());

	cipher_ = addition_of_array_by_module(text_, key_, cipher_, lower_alphabet.length(), key.length());

	chipher = convert_number_of_ring_to_text(cipher_, chipher, key.length());

	delete[] key_;  delete[] cipher_; delete[] text_;

	return chipher;
}

string wiegener_cipher_decryption_part(string cipher, string text, string key)
{
	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

	type* text_ = new type[key.length()];  type* cipher_ = new type[key.length()];  type* key_ = new type[key.length()];

	cipher_ = convert_text_to_number_of_ring(cipher, cipher_, key.length());

	key_ = convert_text_to_number_of_ring(key, key_, key.length());

	text_ = substraction_of_array_by_module(cipher_, key_, text_, lower_alphabet.length(), key.length());

	text = convert_number_of_ring_to_text(text_, text, key.length());

	delete[] key_;  delete[] cipher_; delete[] text_;

	return text;
}

string encryption(string text, string key)
{
	string encrypted_text=" ";
	string one_string;

	type integer = (type)(text.length() / key.length());  type frequency = (type)(text.length() % key.length());


	for (type i = 0; i < text.length() - frequency; i = i + key.length())
	{
		
		string part_text_which_encrypted = text_with_specific_position(text, i, i + key.length());
	
		one_string = wiegener_cipher_encryption_part(part_text_which_encrypted, one_string, key);

		encrypted_text = encrypted_text + one_string;
	}

	encrypted_text = remove_all_spaces(encrypted_text);

	string text_in_the_end = text_with_specific_position(text, text.length() - frequency, text.length());

	string first_part_of_the_key_for_end_text = text_with_specific_position(key, 0, frequency);

	one_string = wiegener_cipher_encryption_part(text_in_the_end, one_string, first_part_of_the_key_for_end_text);
	encrypted_text = encrypted_text + one_string;

	encrypted_text = remove_all_spaces(encrypted_text);

	return encrypted_text;
}

string decryption(string text, string key)
{
	string decrypted_text = " ";

	string one_string;

	type integer = (type)(text.length() / key.length());  type frequency = (type)(text.length() % key.length());


	for (type i = 0; i < text.length() - frequency; i = i + key.length())
	{

		string part_text_which_decrypted = text_with_specific_position(text, i, i + key.length());

		one_string = wiegener_cipher_decryption_part(part_text_which_decrypted, one_string, key);

		decrypted_text = decrypted_text + one_string;
	}

	decrypted_text = remove_all_spaces(decrypted_text);

	string text_in_the_end = text_with_specific_position(text, text.length() - frequency, text.length());

	string first_part_of_the_key_for_end_text = text_with_specific_position(key, 0, frequency);

	one_string = wiegener_cipher_decryption_part(text_in_the_end, one_string, first_part_of_the_key_for_end_text);

	decrypted_text = decrypted_text + one_string;

	decrypted_text = remove_all_spaces(decrypted_text);

	return decrypted_text;
}

long double error_in_percent(long double data_experiment, long double theoretical_data)
{
	return (abs(data_experiment - theoretical_data) / theoretical_data) * 100;
}

long  double conformity_index_for_text(string text)
{
	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

	frequency_statistics table_frequency[32];     start_frequency_table(table_frequency, lower_alphabet, lower_alphabet.length());

	freuquency_of_symbols(table_frequency, text, lower_alphabet.length());

	long double N, n = text.length(), index = 0.0;

	for (int i = 0; i < lower_alphabet.length(); i++)
	{
		N = table_frequency[i].value;
		index += N * (N - 1);
	}

	index /= (n * (n - 1));

	return index;
}

bool find_key_size(string text,type key_size,long double* index_conformity_cipher_text)
{
	long double index_conformity_russian_language = 0.056;

	bool key_verification=false;

	long double* index_conformity = new long double[key_size];

	for (type i=0;i< key_size;i++)
	{
		index_conformity[i] = 0.0;
	}

	for (type i = 0; i<key_size; i++)
	{
		string block = " ";

		type h = 0;

		for (int j = i;j<(text.length()- text.length()%key_size);j=i+h*key_size)
		{	
			block = block + text[j];
			h++;
		}

		block=remove_all_spaces(block);

		index_conformity[i] = conformity_index_for_text(block);
	}

	long double approximation = 0.0;

	for (type i = 0; i < key_size; i++)
	{
		approximation += index_conformity[i];
	}

	approximation /= key_size;

	if (error_in_percent(approximation, index_conformity_russian_language)<4)
	{
		/*cout <<endl<<"Conformity index cipher text:"<<approximation << endl; */
		key_verification = true;
		*index_conformity_cipher_text = approximation;
	}

	delete[] index_conformity;

	return key_verification;
}

string find_original_key_representation(string text, type key_size)
{
	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
	string sorting_order = "מאוטםענסכגךןלףהÿûüחבדיק‏ץזרצשפ‎ת";


	string key=" ";

	for (type i = 0; i < key_size; i++)
	{
		string block = " ";

		type h = 0;

		for (int j = i; j < (text.length() - text.length() % key_size); j = i + h * key_size)
		{
			block = block + text[j];
			h++;
		}

		block = remove_all_spaces(block);

		frequency_statistics letter[32];                            start_frequency_table(letter, lower_alphabet, lower_alphabet.length());
		freuquency_of_symbols(letter, block, block.length());  		sorting(letter, lower_alphabet.length());

		key = key + letter[0].symbols;

	}

	key = remove_all_spaces(key);
	
	type* key_number = new type[key_size];

	convert_text_to_number_of_ring(key, key_number, key_size);

	for (int i=0;i<key_size;i++)
	{
		if (key_number[i] - 14 >= 0)
		{
			key_number[i] = key_number[i] - 14;
		}
		else
		{
			key_number[i] = lower_alphabet .length()+key_number[i] - 14;

		}
			
	}

	key=convert_number_of_ring_to_text(key_number, key, key_size);

	delete[] key_number; 
	

	return key;
}

string hacking_the_key(string text, long double* index_conformity)
{
	type key_size;

	string key;
	
	for (type i = 2; i < text.length(); i++)
	{
		if (find_key_size(text, i, index_conformity)==true)
		{
			key_size = i;
			break;
		}
		if(find_key_size(text,i, index_conformity) != true)
		{
			continue;
		}
		
	}

	key=find_original_key_representation(text,key_size);

	return key;
}

long double maximum_element(long double* array,type size_array)
{
	long double max = 0.0;

	for (type i=0;i<size_array;i++)
	{
		if (max< array[i])
		{
			max = array[i];
		}
		if (max > array[i])
		{
			continue;
		}
	}

	return max;
}

char function_on_current_symbols(long double* theoretical_frequency, frequency_statistics* experimental_frequency,string lower_alphabet)
{
	char symbol_searched;

	long double* array_coeffitient = new long double[lower_alphabet.length()];

	

	for (type i = 0; i < lower_alphabet.length(); i++)
	{
		long double temp=0.0;

		for (type j = 0; j < lower_alphabet.length(); j++)
		{
			temp = temp + (theoretical_frequency[j])*(experimental_frequency[(j+i)% lower_alphabet.length()].value);
		}

		array_coeffitient[i] = temp;
	}

	

	long double searched_coeffitient=maximum_element(array_coeffitient, lower_alphabet.length());

	for (type i = 0; i < lower_alphabet.length(); i++)
	{
		if (array_coeffitient[i] == searched_coeffitient)
		{
			symbol_searched = lower_alphabet[i];
			break;
		}
	}


	delete[]  array_coeffitient;

	return symbol_searched;
}

string exact_location_of_the_key(string text,type key_size)
{
	string lower_alphabet = "אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
	string sorting_order = "מאוטםענסכגךןלףהÿûüחבדיק‏ץזרצשפ‎ת";

	long double theoretical_frequency[32];   
	
	theoretical_frequency[0] = 0.0751407;
	theoretical_frequency[1] = 0.0161419;
	theoretical_frequency[2] = 0.0419454;
	theoretical_frequency[3] = 0.0167463;
	theoretical_frequency[4] = 0.0266498;
	theoretical_frequency[5] = 0.0817477;
	theoretical_frequency[6] = 0.0106988;
	theoretical_frequency[7] = 0.0151354;
	theoretical_frequency[8] = 0.0606082;
	theoretical_frequency[9] = 0.00961956;
	theoretical_frequency[10] = 0.0305416;
	theoretical_frequency[11] = 0.0458484;
	theoretical_frequency[12] = 0.0260868;
	theoretical_frequency[13] = 0.0628269;
	theoretical_frequency[14] = 0.105807;
	theoretical_frequency[15] = 0.0215354;
	theoretical_frequency[16] = 0.036561;
	theoretical_frequency[17] = 0.0479824;
	theoretical_frequency[18] = 0.055228;
	theoretical_frequency[19] = 0.0252873;
	theoretical_frequency[20] = 0.000844238;
	theoretical_frequency[21] = 0.00706586;
	theoretical_frequency[22] = 0.00241451;
	theoretical_frequency[23] = 0.0155992;
	theoretical_frequency[24] = 0.00806888;
	theoretical_frequency[25] = 0.00260056;
	theoretical_frequency[26] = 0.000276283;
	theoretical_frequency[27] = 0.0173324;
	theoretical_frequency[28] = 0.0187292;
	theoretical_frequency[29] = 0.00299995;
	theoretical_frequency[30] = 0.00588659;
	theoretical_frequency[31] = 0.019428;


	string key = " ";

	for (type i = 0; i < key_size; i++)
	{
	
		char symbols;

		string block = " ";

		type h = 0;

		for (int j = i; j < (text.length() - text.length() % key_size); j = i + h * key_size)
		{
			block = block + text[j];
			h++;
		}

		block = remove_all_spaces(block);

		frequency_statistics experiment_data[32];    start_frequency_table(experiment_data, lower_alphabet, lower_alphabet.length());
		
		freuquency_of_symbols(experiment_data, block, block.length());

		symbols=function_on_current_symbols(theoretical_frequency,experiment_data,lower_alphabet);

		key = key + symbols;
	
	}

	key = remove_all_spaces(key);


	return key;
}

string hacking_the_key_modified(string text, long double* index_conformity)
{
	type key_size;

	string key;

	for (type i = 2; i < text.length(); i++)
	{
		if (find_key_size(text, i, index_conformity) == true)
		{
			key_size = i;
			break;
		}
		if (find_key_size(text, i, index_conformity) != true)
		{
			continue;
		}

	}

	key = exact_location_of_the_key(text, key_size);

	return key;
}

///labs function block start