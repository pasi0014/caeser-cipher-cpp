// caesar-cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>

using namespace std;

// Encrypt function
string encrypt(string text, int shift) {

	string result = "";

	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i]))
			result += char(int(text[i] + shift - 65) % 26 + 65);
		else
			result += char(int(text[i] + shift - 97) % 26 + 97);
	}
	return result;

}

// Decrypt function
string decrypt(string cipher, int shift) {

	string result = "";

	for (int i = 0; i < cipher.length(); i++) {
		if (isupper(cipher[i]))
			result += char(int(cipher[i] + shift - 65) % 26 + 65);
		else
			result += char(int(cipher[i] + shift - 97) % 26 + 97);
	}
	return result;
}
int main()
{
	//initialize variables
	string text;
	int shift;

	// Loop variable
	bool validate = true;

	cout << "Enter a shift key for Caesar Cipher \n(it should be integer and 0-25)" << endl;
	cin >> shift;
	while (validate) {
		//check if entered shift is in range of 25
		if (shift <= 0 || shift > 25) {
			cout << "Your key should be 0 - 25" << endl;
			cin >> shift;
		}
		else if (shift != 0 && shift < 25) {
			cout << "Enter your message (just a string)" << endl;
			cin >> text;
			if (text != "") {
				// encrypt the entered message
				string cipher = encrypt(text, shift);
				cout << "\nThe cipher text of message: " << "'" << text << "'" << " is : " << cipher;
				// decrypt the cipher message
				string recoveredMessage = decrypt(cipher, 26 - shift);
				//display the message
				cout << "\nThe recovered plain text is: " << recoveredMessage;
				cout << "\n\n";
				validate = false;
			}
		}
	}

}

