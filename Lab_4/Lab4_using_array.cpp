#include <iostream>
#include <fstream>
#include <string>


using namespace std;


struct register_result
{
	int res[1024];
};

register_result L1(int start_x[], int size);
register_result L2(int start_y[], int size);
register_result L3(int start_s[], int size);
register_result Giffy(register_result X, register_result Y, register_result S);
register_result short_L1(int start_x[], int size);

//For Jiffy generator

register_result L1(int start_x[], int size)
{
	register_result X;
	for (int i = 0; i < 25; i++)
	{
		X.res[i] = start_x[i];
	}
	for (int i = 0; i < size - 25; i++)
	{
		X.res[i+25] = X.res[i] xor X.res[i+3];
	}
	return X;
}

register_result short_L1(int start_x[], int size)
{
	register_result X;
	for (int i = 0; i < 4; i++)
	{
		X.res[i] = start_x[i];
	}
	for (int i = 0; i < size - 4 ; i++)
	{
		X.res[i + 4] = X.res[i] xor X.res[i + 3];
	}
	return X;
}

register_result L2(int start_y[], int size)
{
	register_result Y;
	for (int i = 0; i < 26; i++)
	{
		Y.res[i] = start_y[i];
	}
	for (int i = 0; i < size - 26; i++)
	{
		Y.res[i + 26] = Y.res[i] xor Y.res[i+1] xor Y.res[i+2] xor Y.res[i+6];
	}
	return Y;
}

register_result L3(int start_s[], int size)
{
	register_result S;
	for (int i = 0; i < 27; i++)
	{
		S.res[i] = start_s[i];
	}
	for (int i = 0; i < size - 27; i++)
	{
		S.res[i + 27] = S.res[i] xor S.res[i+1] xor S.res[i+2] xor S.res[i+5];
	}
	return S;
}

register_result Giffy(register_result X, register_result Y, register_result S)
{
	register_result Gif;
	for (int i = 0; i < 1024; i++)
	{
		Gif.res[i] = (S.res[i] * X.res[i]) xor ((1 xor S.res[i]) * Y.res[i]);
	}
	return Gif;
}


int statistic_R(register_result x, int z[], int size)
{
	int R = 0;
	for (int i = 0; i < size; i++)
	{
		R = R + (x.res[i] xor z[i]);
	}
	return R;
}

//for sorting out all possible variants

int* sort_out(int arr[], int size_of_vector, int num_in_decimal)
{
	for (int i = size_of_vector-1; num_in_decimal > 0; i--)
	{
		arr[i] = num_in_decimal % 2;
		num_in_decimal = num_in_decimal / 2;
	}
	return arr;
}


int main()
{
	register_result X_for_L1;
	register_result Y_for_L2;
	register_result Z_for_L3;
	//var 3
	//string sequence_of_z = "01010100000100011110010000111010011110110010111111010101111100100000110000011100001001010000000110011100000011001110100110000100011011101000111010001010011100110001011111101010111001011001101001011001110001010101010001111110011001001100110000101000011111011001010101110011010001000000010001010000111100100000001100100001001101000110010100000101001001011000111011110010101110001000000010111110111101110000001010010010011111100000101001011100010001110010010011010111110101011000111000010111010000100000001001010100001111101000010011111011101010011111010111110110111011011000010100010000101001000110001000010100101010111010100100101001110010110011100100011111110000101101110001111111001000010000010001100101111001001101000001011001101001000110101100000000100101100011000010000100100010111111111001011011010010110001011101000001001111011101001110101100011000101101000100000011100100101110011011001101101011101100000001111001010010001001000111110001000001011010110110101010100011000101000111111110001011110001000101100101110101010101010000010010101110110110010110000101100111000111111010100110110101100110001010010011101101101101111100000110000110110101111110011110101001101101100000111110101100000111101101000100001000010001001000001111100011110010101110101010100010100110101001010110100111111110010100110010010111011100001000000001110000000001011111001111101000001001001110111000000001010101010100100000011111100110000011100001011111101001110011100000100111110010001010101100101110110000101111111011101101011000111111000101000010010011110001110010001011011101110010010011011101111000100100111110111110001110010001010101010110000110100010111000111110010010110001101011101010110010011001001111011001001011010001010111001111010000110111111111010001110010000011001110101011110101000100011111011110101100010011111000111100111011110100011101110101000101110111111010101110001110100010111111001110110111010100011001111100000111010100001111111010001010110010111101000110110001011110011100111011000011000000000011011001101100100110010111010110100100011100001100";
	//var 19
	string sequence_of_z = "11001100101000110110001111010000010110010101101011101101000011110001011001100111111111001001110000000110001101011011110011100110010010010001010011101010100100001111110001101100000001001000111011110001011111010011100000110001011010110101110101011011110111011111110100011110110101111000101010000100110110101000110111111010100000110010110011110101001011001101110011010010000101101101000100110111110100111100000010100101011010000000111011100000011000001001011001010110010010010001101011110100001010001001101010110011001011010001001011110000101100000011111000101010111011111111000101111110110010011110101111001100010101010110001010111111100101111111111110001001000101110111010101000000110001110111011011110101100110011110110000101101011101111110111010001011111000100101101011101011011110111000011000110100101100111101001100011100001101100000110100001110110000111101111110010101001101111111111011001011110010000010110010000110110101110011011000011101011100101101111111101101010110101001000000110001011000011101011000001110111110010110001001010000010010000111010100000011110011011111000010111001000101000011111011101110100111111101001101001101011101101000101011100001011110001100001101101100110100011010111110101110011001100000001101100010101110110100110000001001111101011001000010101011000111101000110001110100111001110110001000011001111111100001110101101001110011101111011000110000001110100100010101011000100100000010111001100110000010101110010000101101001010100111001000011111000001001111100011100111101101001010100001110111011010000110001101100011101110111101011000000111110001010000111100101010110001100011011110111111000110110110110100000111110100101111010100011110000100001110000001110110000101101000100111101111011100000001111111010100111110010011000111111111000001011101101000100011000101101000110111111110100110001101010111100110101010110101110010010010100100000010010011010110101111101011001110101011001110001001000011110100111011110101111110111011111100101000100000011111011010110001101101000100010010111010001111101101000110100101011101010110";
	//var 4
	//string sequence_of_z = "00010011110011101100000001111011100101001011110110011011100110010000001010100011101011001001101101011111100010010100000100011011011000100000110001100001000010100100100100110100010100000000000010010101010100111101101100100000101101100000100010110001010110100010000001111000111011001011001101011011010101000101111100100110101110100010100001101111101111111111100111101001000011011100101001001001101110111100010001000000000111011110110010111111011000001001110010110001101000111001101110011110100101010110111001110110010010010101111100000010100101001011110001101000001000001111101111010010100010111010000010101011111011111101001011101101100110101000000010001110011011110011101101110110101010000001000001110011111000100000110110110100001010111000001010111100111111111000100000010011111110110110011011111010011101101111001011111000011100001001011010011001001011101100011010101010100101110101100000011101111011101110110011001001101100100001000010101000110011000100101101101001111010111000111010011000011000100100011101000000111010011000100100111000010100111111110110111101010110101100000111101000000001010000011011001101010000001010100011010100101000001111110101100111011110000111111100000010111101110100100100111110011001001000011101100011100010011101000000101001010010101010100010101110110101100100011001000011100111110010101001011001101011101001101011111011011001010110011111000011101101111011100110110001010010111001111000000010011110000011011111000100100000110101111100100010111010011111011111101010110100001101001110011011110000011101101110000101000111100000001101000110111111000110111111100100101010111000010110011101111100110100000001100101110110101100011011110110010100101101101011110000010000011101000110110001110011111111100110001001001110011110100110000110101101100111011111101101110101000101100001000000010110000110110101101110011010010001100000111101101101001111110011101011100011110001110111011001111001010001010100110011000001010001000110111111000100010110001000001101101011011000100011111011110000101110111001011100011010001001010101011001";
	int z[2048];
	for (int i = 0; i < 2048; i++)
	{
		z[i] = int(sequence_of_z.at(i) - '0');
	}
	int start_x[25];
	int start_y[26];
	int start_s[27];
	for (int i = 0; i < 25; i++)
	{
		start_x[i] = 0;
		start_y[i] = 0;
		start_s[i] = 0;
	}
	start_s[25] = start_s[26] = 0;
	start_y[25] = 0;
	double Betta1;
	int M1 = pow(2, 25);
	Betta1 = (double)1 / M1;
	cout << "Betta1: " << Betta1 << endl;
	cout << "1-Betta1: " << (double)1 - Betta1 << endl;
	double Kvantil_1_betta1 = 5.42;
	double Kvantil_1_alfa = 2.33;
	int N1_ = 222;
	int C1 = 66;
	cout << "Number N1*:  " << N1_ << endl;
	cout << "Constant C1:  " << C1 << endl << endl;

	double Betta2;
	int M2 = pow(2, 26);
	Betta2 = (double)1 / M2;
	cout << "Betta2: " << Betta2 << endl;
	cout << "1-Betta2: " << (double)1 - Betta2 << endl;
	double Kvantil_1_betta2 = 5.54;
	int N2_ = 229;
	int C2 = 68; 
	cout << "Number N2*:  " << N2_ << endl;
	cout << "Constant C2:  " << C2 << endl << endl;

	double Betta3;
	int M3 = pow(2, 27);
	Betta3 = (double)1 / M3;
	cout << "Betta3: " << Betta3 << endl;
	cout << "1-Betta3: " << (double)1 - Betta3 << endl;
	double Kvantil_1_betta3 = 5.66;
	int N3_ = 236;
	int C3 = 70; 
	cout << "Number N3*:  " << N3_ << endl;
	cout << "Constant C3:  " << C3 << endl << endl;
	cout << "//////////////////////////////////////////////////////////////////" << endl;

	ofstream L1_reg;
	L1_reg.open("L1 gen.txt");
	ofstream L2_reg;
	L2_reg.open("L2 gen.txt");

	int R = 0;
	int* sequence_of_x;
	int* sequence_of_y;
	int candidates_for_L1 = 0;
	int candidates_for_L2 = 0;
	int candidates_for_L3 = 0;

	//finding true initial candidats for L1 and L2
	cout << "Begin finding true initial candidats for L1 and L2" << endl;
	
	for (int i = 1; i < 33554432; i++)
	{
		sort_out(start_x, 25, i);
		X_for_L1 = L1(start_x, N1_);
		R = statistic_R(X_for_L1, z, N1_);
		if (R < C1)
		{
			candidates_for_L1++;
			for (int j = 0; j < 25; j++)
			{
				L1_reg << to_string(start_x[j]);
			}
			L1_reg << endl;
		}
		
	}

	cout << "End of finding true initial candidats for L1" << endl;
	cout << "Begin finding true initial candidats for L2" << endl;
	for (int i = 0; i < 25; i++)
	{
		start_x[i] = 0;
	}
	//finding true initial filling for L2
	for (int i = 1; i < 67108864; i++)
	{
		sort_out(start_y, 26, i);
		Y_for_L2 = L2(start_y, N2_);
		R = statistic_R(Y_for_L2, z, N2_);
		if (R < C2)
		{
			candidates_for_L2++;
			for (int j = 0; j < 26; j++)
			{
				L2_reg << to_string(start_y[j]);
			}
			L2_reg << endl;
		}
			
	}
	cout << "End of finding true initial candidats for L2" << endl;
	cout << "Candidats for L1: " << candidates_for_L1 << endl;
	cout << "Candidats for L2: " << candidates_for_L2 << endl;
	L1_reg.close();
	L2_reg.close();


	//finding true initial candidats for L3 
	string x = "";
	string y = "";
	int correct = 0;
	int that_var_of_input_is_wrong = 0;
	ofstream L3_reg;
	L3_reg.open("L3 gen.txt");
	ifstream L1_for_check;
	L1_for_check.open("L1 gen.txt");
	ifstream L2_for_check;
	L2_for_check.open("L2 gen.txt");
	int **Candidates_x;
	Candidates_x = new int* [25];
	for (int i = 0; i < 25; i++)
	{
		Candidates_x[i] = new int[candidates_for_L1];
	}
	int** Candidates_y;
	Candidates_y = new int* [26];
	for (int i = 0; i < 26; i++)
	{
		Candidates_y[i] = new int[candidates_for_L2];
	}
	int j = 0;
	if (L1_for_check.is_open())
	{
		while (getline(L1_for_check, x))
		{
			for (int k = 0; k < 25; k++)
			{
				Candidates_x[k][j] = int(x[k] - '0');
			}
			j = j + 1;
		}
	}
	j = 0;
	if (L2_for_check.is_open())
	{
		while (getline(L2_for_check, y))
		{
			for (int k = 0; k < 26; k++)
			{
				Candidates_y[k][j] = int(y[k] - '0');
			}
			j = j + 1;
		}
	}

	cout << "Right candidates for L1:" << endl;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < candidates_for_L1; j++)
		{
			cout << Candidates_x[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Right candidates for L2:" << endl; 
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < candidates_for_L2; j++)
		{
			cout << Candidates_y[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	register_result* x_seq = new register_result[candidates_for_L1];
	register_result* y_seq = new register_result[candidates_for_L2];
	for (int i = 0; i < candidates_for_L1; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			start_x[j] = Candidates_x[j][i];
		}
		x_seq[i] = L1(start_x, 1024);
	}
	for (int i = 0; i < candidates_for_L2; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			start_y[j] = Candidates_y[j][i];
		}
		y_seq[i] = L2(start_y, 1024);
	}

	int x_check_num = 0;
	int y_check_num = 0;
	int for_no_writing_same = 0;
	cout << "Begin finding true initial candidats for L3" << endl;
	for (int i = 1; i < 134217728; i++)
	{
		for_no_writing_same = 1;
		sort_out(start_s, 27, i);
		x_check_num = 0;
		while (x_check_num < candidates_for_L1)
		{
			y_check_num = 0;
			while (y_check_num < candidates_for_L2)
			{
				that_var_of_input_is_wrong = 0;
				correct = 0;
				for (int p = 0; p < 27; p++)
				{
					if (that_var_of_input_is_wrong > 0)
					{
						break;
					}
					if (x_seq[x_check_num].res[p] != y_seq[y_check_num].res[p])
					{
						if (z[p] == x_seq[x_check_num].res[p])
						{
							if (start_s[p] == 1)
							{
								correct = correct + 1;
							}
							else {
								correct = 0; 
								that_var_of_input_is_wrong++;
								break;
							}
						}
						else {
							if (z[p] == y_seq[y_check_num].res[p]) {
								if (start_s[p] == 0)
								{
									correct = correct + 1;
								}
								else {
									correct = 0;
									that_var_of_input_is_wrong++;
									break;
								}
							}
						}
					}
				}
				if (correct > 0 && for_no_writing_same ==1)
				{
					candidates_for_L3++;
					for (int t = 0; t < 27; t++)
					{
						L3_reg << to_string(start_s[t]);
					}
					L3_reg << endl;
					for_no_writing_same++;
				}
				correct = 0;
				y_check_num++;
			}
			x_check_num++;
		}
	}

	L1_for_check.close();
	L2_for_check.close();
	L3_reg.close();
	cout << "End of finding true initial filling for L3" << endl;

	correct = 0;
	string s;
	string text;
	register_result* s_seq = new register_result[candidates_for_L3];
	register_result L1_seq;
	register_result L2_seq;
	register_result L3_seq;
	ifstream L3_reg_read;
	cout << "Begin finding initial fillings for L1, L2, L3 so that we will get Z, that is io our variant" << endl;
	L3_reg_read.open("L3 gen.txt");
	ofstream Fin;
	Fin.open("Final result.txt");
	int l = 0;
	while (getline(L3_reg_read, s))
	{
		for (int i = 0; i < 27; i++)
		{
			start_s[i] = int(s[i] - '0');
		}
		s_seq[l] = L3(start_s, 1024);
		l = l + 1;
	}
	for (int i = 0; i < candidates_for_L3; i++)
	{
		for (int j = 0; j < candidates_for_L2; j++)
		{
			for (int m = 0; m < candidates_for_L1; m++)
			{
				correct = 0;
				Z_for_L3 = Giffy(x_seq[m], y_seq[j], s_seq[i]);
				for (int p = 0; p < N3_; p++)
				{
					if (z[p] != Z_for_L3.res[p])
					{
						correct = 0;
						break;
					}
					else {
						correct += 1;
					}
				}
				if (correct !=0 && correct!=1)
				{
					text = "L1 register:";
					Fin << text;
					Fin << endl;
					for (int q = 0; q < 25; q++)
					{
						Fin << to_string(x_seq[m].res[q]);
					}
					Fin << endl;

					L1_seq = x_seq[m];
					L2_seq = y_seq[j];
					L3_seq = s_seq[i];

					text = "L2 register:";
					Fin << text;
					Fin << endl;
					for (int q = 0; q < 26; q++)
					{
						Fin << to_string(y_seq[j].res[q]);
					}
					Fin << endl;

					text = "L3 register:";
					Fin << text;
					Fin << endl;
					for (int q = 0; q < 27; q++)
					{
						Fin << to_string(s_seq[i].res[q]);
					}
					Fin << endl;
					break;
				}
			}
		}
	}

	L3_reg_read.close();
	Fin.close();
	cout << "End of finding initial fillings for L1, L2, L3 so that we will get Z, that is io our variant" << endl;

	Z_for_L3 = Giffy(L1_seq, L2_seq, L3_seq);
	cout << "Z in variant:" << endl;
	for (int i = 0; i < 1024; i++)
	{
		cout << z[i] <<" ";
	}
	cout << endl;
	cout << "Z we got:" << endl;
	for (int i = 0; i < 1024; i++)
	{
		cout << Z_for_L3.res[i] << " ";
	}
	cout << endl;

	cout << "L1:" << endl;
	for (int i = 0; i < 25; i++)
	{
		cout << L1_seq.res[i] << " ";
	}
	cout << endl;
	cout << "L2:" << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << L2_seq.res[i] << " ";
	}
	cout << endl;
	cout << "L3:" << endl;
	for (int i = 0; i < 27; i++)
	{
		cout << L3_seq.res[i] << " ";
	}
	cout << endl;


	for (int i = 0; i < candidates_for_L1; i++)
	{
		delete Candidates_x[i];
	}
	delete [] Candidates_x;
	for (int i = 0; i < candidates_for_L2; i++)
	{
		delete Candidates_y[i];
	}
	delete[] Candidates_y;

	return 0;
}