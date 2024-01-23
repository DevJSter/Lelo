// Substituation Cipher

#include <iostream>

using namespace std;

string substitutionEncrypt(const string& input, int key) {
    string result;
    string all_letrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (char c : input) {
        size_t pos = all_letrs.find(c);
        if (pos != string::npos) {
            result += all_letrs[(pos + key) % all_letrs.length()];
        } else {
            result += c;
        }
    }

    return result;
}

string substitutionDecrypt(const string& input, int key) {
    string result;
    string all_letrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (char c : input) {
        size_t pos = all_letrs.find(c);
        if (pos != string::npos) {
            result += all_letrs[(pos - key + all_letrs.length()) % all_letrs.length()];
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    int encryptKey, decryptKey;

    cout << "Enter the string: ";
    string plain_txt;
    getline(cin, plain_txt);

    cout << "Enter the encryption key: ";
    cin >> encryptKey;

    // Encryption
    string cipher_txt = substitutionEncrypt(plain_txt, encryptKey);
    cout << "Cipher Text is: " << cipher_txt << endl;

    cout << "Enter the decryption key: ";       
    cin >> decryptKey;

    string decrypted_txt = substitutionDecrypt(cipher_txt, decryptKey);
    cout << "Recovered plain text: " << decrypted_txt << endl;

    return 0;
}


// Transposition Cipher
#include<bits/stdc++.h>
using namespace std;

string const key = "HACK"; 
map<int, int> keyMap;

void setPermutationOrder()
{			 
	for(int i=0; i < key.length(); i++)
	{
		keyMap[key[i]] = i;
	}
}

string encryptMessage(string msg)
{
	int row, col, j;
	string cipher = "";
	
	col = key.length(); 
	row = msg.length()/col; 
	
	if (msg.length() % col)
		row += 1;

	char matrix[row][col];

	for (int i=0, k=0; i < row; i++)
	{
		for (int j=0; j < col; )
		{
			if(msg[k] == '\0')
			{
				matrix[i][j] = '_';	 
				j++;
			}
			
			if(isalpha(msg[k]) || msg[k]==' ')
			{ 
				matrix[i][j] = msg[k];
				j++;
			}
			k++;
		}
	}

	for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
	{
		j = ii->second;
		
		for (int i=0; i < row; i++)
		{
			if(isalpha(matrix[i][j]) || matrix[i][j]==' ' || matrix[i][j]=='_')
				cipher += matrix[i][j];
		}
	}

	return cipher;
}

string decryptMessage(string cipher)
{
	int col = key.length();
	int row = cipher.length()/col;
	char cipherMat[row][col];

	for (int j=0, k=0; j < col; j++)
		for (int i=0; i < row; i++)
			cipherMat[i][j] = cipher[k++];

	int index = 0;
	for(map<int, int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
		ii->second = index++;

	char decCipher[row][col];
	map<int, int>::iterator ii=keyMap.begin();
	int k = 0;
	for (int l=0, j; key[l]!='\0'; k++)
	{
		j = keyMap[key[l++]];
		for (int i=0; i < row; i++)
		{
			decCipher[i][k] = cipherMat[i][j];
		}
	}

	string msg = "";
	for (int i=0; i < row; i++)
	{
		for(int j=0; j < col; j++)
		{
			if(decCipher[i][j] != '_')
				msg += decCipher[i][j];
		}
	}
	return msg;
}

int main(void)
{
	cout << "Enter the message: ";
	string msg;
	getline(cin, msg);

	setPermutationOrder();
	
	string cipher = encryptMessage(msg);
	cout << "Encrypted Message: " << cipher << endl;
	
	cout << "Decrypted Message: " << decryptMessage(cipher) << endl;

	return 0;
}
