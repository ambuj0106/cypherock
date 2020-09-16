#include<stdio.h>
#include "bip39.h"
#include "bip32.h"
int main()
{
	const char passphrase[]="",c[]="client power maple tonight gossip apart kite seed rebuild museum ankle cheese coil note property account aware monkey spread brief follow normal unit inside";
    uint8_t seed[64];
    uint32_t current=0,total=0;
   
    
     HDNode *master_node=(HDNode *)malloc(sizeof(HDNode));
      
      mnemonic_to_seed(c, passphrase,seed,(current,total));

      hdnode_from_seed(seed,64,"secp256k1",master_node);
      
    
      //filling public key
       hdnode_fill_public_key(master_node);
    

    //master node-> purpose node
	int pn=hdnode_private_ckd(master_node, (uint32_t)44); 
	//printf("%d\n",master_node->depth);
   //purpose node-> coin node	
   int cn=hdnode_private_ckd(master_node, (uint32_t)1);
   //coin node-> account  node
   int accn=hdnode_private_ckd(master_node, (uint32_t)0);
   //acc node -> chain node
   int chainn=hdnode_private_ckd(master_node, (uint32_t)0);
   //chain node-> address node
   //printf("%d\n",master_node->depth);
   
   int addn=hdnode_private_ckd(master_node, (uint32_t)0);
// filling address node public key 
   hdnode_fill_public_key(master_node);
   
   //printing public key
   for(int i=0;i<32;i++)
   {
   	printf("%x",master_node->private_key[i]);
   }
    printf("\n");
    

    
     
	return 0;
}
