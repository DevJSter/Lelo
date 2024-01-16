const readline = require('readline');

// Function to perform substitution cipher encryption
function substitutionEncrypt(plaintext, key) {
    let ciphertext = '';
    for (let i = 0; i < plaintext.length; i++) {
        let char = plaintext.charAt(i);
        if (char.match(/[a-z]/i)) {
            let isUpperCase = char === char.toUpperCase();
            char = char.toLowerCase();
            let index = (char.charCodeAt(0) - 97 + key) % 26;
            if (index < 0) {
                index += 26;
            }
            char = String.fromCharCode(index + 97);
            if (isUpperCase) {
                char = char.toUpperCase();
            }
        }
        ciphertext += char;
    }
    return ciphertext;
}

// Function to perform product cipher encryption
function productCipherEncrypt(plaintext, key1, key2) {
    let intermediateResult = substitutionEncrypt(plaintext, key1);
    let ciphertext = substitutionEncrypt(intermediateResult, key2);
    return ciphertext;
}

// Create interface for reading input
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Get user input
rl.question('Enter the string: ', (plaintext) => {
    let key1 = 3;
    let key2 = 7;

    let encryptedText = productCipherEncrypt(plaintext, key1, key2);

    console.log("Plaintext:", plaintext);
    console.log("Encrypted Text:", encryptedText);

    // Close the interface
    rl.close();
});
