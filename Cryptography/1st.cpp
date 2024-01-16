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
