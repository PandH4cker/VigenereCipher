//
// Created by drayr on 14/11/2021.
//

#ifndef VIGENERECIPHER_BABAGEATTACK_H
#define VIGENERECIPHER_BABAGEATTACK_H

#define FRENCH_COINCIDENCE .077
#define EQUIDISTRIBUTED_COINCIDENCE .0385

float coincidence(char * message);
int findKeyLength(char * message);

#endif //VIGENERECIPHER_BABAGEATTACK_H
