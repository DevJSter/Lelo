// design and implementation of product cipher text using substitution  cipher 

let words = "";
// let key = input("What would be the key ? ");

// A string containing all characters
const all_letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

const dict1 = {};
const key = 4;

for (let i = 0; i < all_letters.length; i++) {
dict1[all_letters[i]] = all_letters[(i + key) % all_letters.length];
}

const plain_txt = "I am studying Data Encryption";
let cipher_txt = "";

// loop to generate ciphertext
for (let i = 0; i < plain_txt.length; i++) {
const char = plain_txt[i];
if (all_letters.includes(char)) {
const temp = dict1[char];
cipher_txt += temp;
} else {
cipher_txt += char;
}
}

console.log("Cipher Text is: ", cipher_txt);

/*
Create a map to store the substitution for the given alphabet in the cipher text based on the key
*/
const dict2 = {};

for (let i = 0; i < all_letters.length; i++) {
dict2[all_letters[i]] = all_letters[(i - key + all_letters.length) % all_letters.length];
}

// loop to recover plain text
let decrypt_txt = "";

for (let i = 0; i < cipher_txt.length; i++) {
const char = cipher_txt[i];
if (all_letters.includes(char)) {
const temp = dict2[char];
decrypt_txt += temp;
} else {
decrypt_txt += char;
}
}

console.log("Recovered plain text :", decrypt_txt);
