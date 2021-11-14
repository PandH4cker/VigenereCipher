//
// Created by drayr on 14/11/2021.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../includes/vigenereCipher.h"

VigenereCipher initVigenereCipher(char * key)
{
    return (VigenereCipher) {
        .curr = 0,
        .key = strdup(key)
    };
}

char encrypt(VigenereCipher * cipher, char c)
{
    if (isupper(c) || islower(c) || isdigit(c))
    {
        char keyC = cipher->key[cipher->curr++];
        if (cipher->curr == strlen(cipher->key)) cipher->curr = 0;

        return isupper(c) ?
                    (char) ((c + toupper(keyC) - 2 * UPPER_CASE_START) % 26 + UPPER_CASE_START) :
               islower(c) ?
                    (char) ((c + tolower(keyC) - 2 * LOWER_CASE_START) % 26 + LOWER_CASE_START) :
                    (char) ((c + keyC) % 10);
    }
    return c;
}

char decrypt(VigenereCipher * cipher, char c)
{
    if (isupper(c) || islower(c) || isdigit(c))
    {
        char keyC = cipher->key[cipher->curr++];
        if (cipher->curr == strlen(cipher->key)) cipher->curr = 0;
        int off = c - (isupper(c) ? toupper(keyC) : tolower(keyC));
        return isupper(c) ? (
                    off >= 0 ? off % 26 + UPPER_CASE_START : off + 26 + UPPER_CASE_START
               ) :
               islower(c) ? (
                    off >= 0 ? off % 26 + LOWER_CASE_START : off + 26 + LOWER_CASE_START
               ) : (char) ((c - keyC) % 10);
    }
    return c;
}

char * vigenereEncrypt(VigenereCipher * cipher, char * message)
{
    cipher->curr = 0;
    char * encryptedMessage = malloc(strlen(message) + 1);

    for (int i = 0; message[i] != '\0'; ++i)
        encryptedMessage[i] = encrypt(cipher, message[i]);

    encryptedMessage[strlen(message)] = '\0';
    return encryptedMessage;
}

char * vigenereDecrypt(VigenereCipher * cipher, char * message)
{
    cipher->curr = 0;
    char * decryptedMessage = malloc(strlen(message) + 1);

    for (int i = 0; message[i] != '\0'; ++i)
        decryptedMessage[i] = decrypt(cipher, message[i]);

    decryptedMessage[strlen(message)] = '\0';
    return decryptedMessage;
}
