#include <stdio.h>
#include <stdlib.h>

#include "../includes/vigenereCipher.h"
#include "../includes/babageAttack.h"
#include "../includes/utils.h"

int main() {
    char s[] = "PandAlcohol";
    char ** splitted = splitInParts(s, 2);
    for (int i = 0; i < 2; ++i)
        printf("splitted[%d]: %s\n", i, splitted[i]);

    for (int i = 0; i < 2; ++i)
        free(splitted[i]);
    free(splitted);
    /*char s[] = "Panda Warriors";
    char key[] = "PandaAttackers";

    printf("Original Message: %s\n", s);
    printf("Encryption Key: %s\n", key);

    VigenereCipher cipher = initVigenereCipher(key);

    char * encryptedMessage = vigenereEncrypt(&cipher, s);
    printf("Encrypted Message: %s\n", encryptedMessage);

    char * decryptedMessage = vigenereDecrypt(&cipher, encryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);
    free(cipher.key);*/

    return EXIT_SUCCESS;
}
