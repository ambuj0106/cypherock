#include<stdio.h>
#include "crypto/bip39.h"
int main()
{
 char mnemonic[]="garden reject beauty inch scissors rifle amazing couch bacon multiply swim poverty impose spray ugly term stamp prevent nothing mutual awful project wrist movie";
 
 uint8_t entropy[32];
int ent= mnemonic_to_entropy(mnemonic,entropy);
printf("%d",ent);
	return 0;

}
