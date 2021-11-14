//
// Created by drayr on 14/11/2021.
//

#ifndef VIGENERECIPHER_VIGENERECIPHER_H
#define VIGENERECIPHER_VIGENERECIPHER_H

#define UPPER_CASE_START 'A'
#define LOWER_CASE_START 'a'

typedef struct VigenereCipher_s
{
    int curr;
    char * key;
}VigenereCipher;

VigenereCipher initVigenereCipher(char * key);
char encrypt(VigenereCipher * cipher, char c);
char decrypt(VigenereCipher * cipher, char c);
char * vigenereEncrypt(VigenereCipher * cipher, char * message);
char * vigenereDecrypt(VigenereCipher * cipher, char * message);
#endif //VIGENERECIPHER_VIGENERECIPHER_H
