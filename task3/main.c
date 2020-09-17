#include<stdio.h>
#include "bip39.h"
#include "bip32.h"
#include<string.h>
int main()
{
	const char passphrase[]="",c[]="client power maple tonight gossip apart kite seed rebuild museum ankle cheese coil note property account aware monkey spread brief follow normal unit inside";
    uint8_t seed[64];
    uint32_t current=0,total=0;
   
    
     HDNode *master_node=(HDNode *)malloc(sizeof(HDNode));
      
      mnemonic_to_seed(c, passphrase,seed,(current,total));
   
   //   for(int i=0;i<64;i++)
   // {
   // 	printf("%x",seed[i]);
   // }
   //  printf("\n");
 
      hdnode_from_seed(seed,64,"secp256k1",master_node);
      
    
      //filling public key
       hdnode_fill_public_key(master_node);
    

    //master node-> purpose node
	int pn=hdnode_private_ckd(master_node, 0x8000002c); 
	//printf("%d\n",master_node->depth);
   //purpose node-> coin node	
   int cn=hdnode_private_ckd(master_node, 0x80000001);
   //coin node-> account  node
   int accn=hdnode_private_ckd(master_node, 0x80000000);
   //acc node -> chain node
   int chainn=hdnode_private_ckd(master_node, 0x00000000);
   //chain node-> address node
   //printf("%d\n",master_node->depth);
   
   int addn=hdnode_private_ckd(master_node, 0x00000000);
// filling address node public key 
   hdnode_fill_public_key(master_node);
   
   //printing public key
   for(int i=0;i<32;i++)
   {
   	printf("%x",master_node->public_key[i]);
   }
    printf("\n");
    

    
     
	return 0;
}
