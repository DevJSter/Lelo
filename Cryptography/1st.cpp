#include <iostream>
#include <map>

using namespace std;

string substitutionEncrypt(const string& input, int key) {
    string result;
    string all_letrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN"
                       "OPQRSTUVWXYZ";

    map<char, char> dict;
    for (int i = 0; i < all_letrs.length(); i++) {
        dict[all_letrs[i]] = all_letrs[(i + key) % all_letrs.length()];
    }

    for (char c : input) {
        if (all_letrs.find(c) != string::npos) {
            result += dict[c];
        } else {
            result += c;
        }
    }

    return result;
}

string substitutionDecrypt(const string& input, int key) {
    string result;
    string all_letrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN"
                       "OPQRSTUVWXYZ";

    map<char, char> dict;
    for (int i = 0; i < all_letrs.length(); i++) {
        dict[all_letrs[i]] = all_letrs[(i - key + all_letrs.length()) % all_letrs.length()];
    }

    for (char c : input) {
        if (all_letrs.find(c) != string::npos) {
            result += dict[c];
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
