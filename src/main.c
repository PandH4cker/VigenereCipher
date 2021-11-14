#include <stdio.h>
#include <stdlib.h>

#include "../includes/vigenereCipher.h"
#include "../includes/babageAttack.h"
#include "../includes/utils.h"

int main(int argc, char ** argv) {
    char s[] = "Aoehm xpfxm soyrr hig dmtt, prnhepweiue ddxpvvcxnt hlxt. Qrntc fxsriclt sinp ntc shlxs frlaipltjdvq, ai mnwtxs ahqje suicgvolp. Qhlsfur paaefxasa prmboqr fpcvoihif. Ves iawegdhp ej dboog gedvxdn iejgvdt. Cuyoab vrkiruyd pgeglub ahjut, nbq htnquegig oaruf sohurue cep. Ln eoewtxtbu mpgad vxtnh vtlvw dxgalshiz, qer shvcxpvw njnp dlxqhdm. Jt chlaeawehqhh egag dnie, fhd vrnyisa nucj cbpmddb hu. Xn fhd bagwih qhdm, coa wiccvguct nxgje. Vq hpc udbxtnvst pydtta qlciuzvt. Kefwiquyxm p phovxnnu vtlvw. Ic hnf hpbvwahsr slptrd dxcgxmht. Axnr mbolxs zdgca fhm, hig dmtt prmboqr tjrcls keulcjln qer. Dbqer apfubsnq jjsgr is snsitn glnriqxni, qhls tfslcxthu em eyhiueag. Ptlyhnieftut hneiiaaw mdrol.";

    int potentialKeyLength = findKeyLength(s);

    printf("Potential Key Length: %d\n", potentialKeyLength);

    /*char s[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec suscipit diam nec felis sollicitudin, at mattis neque fringilla. Quisque malesuada commodo facilisis. Sed interdum eu dolor gravida feugiat. Nullam vehicula pretium augue, non hendrerit lacus posuere nec. In porttitor magna vitae velit dignissim, nec suscipit nunc aliquam. Ut pellentesque erat ante, sed gravida arcu commodo eu. In sed mattis quam, non tincidunt augue. In hac habitasse platea dictumst. Vestibulum a pulvinar velit. In hac habitasse platea dictumst. Nunc mollis magna sem, sit amet commodo turpis vehicula nec. Donec accumsan justo id sapien tincidunt, quis efficitur ex eleifend. Pellentesque habitant morbi.";
    char key[] = "Panda";

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
