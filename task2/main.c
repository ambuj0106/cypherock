#include<stdio.h>
#include "crypto/bip39.h"
int main()
{
 char mnemonic[2000];
 scanf("%s",&mnemonic); 
 uint8_t entropy[32];
int ent= mnemonic_to_entropy(mnemonic,entropy);
for(int i=0;i<32;i++)
{
printf("%x ",entropy[i]);
}
	return 0;

}
