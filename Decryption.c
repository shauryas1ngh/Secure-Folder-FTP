#include"header.h"
#include<stdlib.h>
#include<stdio.h>
int Decrypt(){
    int num,code_ch,Flag = 1,Flag2 = 1,ch;
    char fname[20];
    FILE *fpts, *fptt, *fptu;
    
   (void) printf("\n\n Decrypt a text file :\n");
    (void)printf("--------------------------\n");
    
    (void)printf(" Input the name of file to decrypt : ");
    (void)scanf("%20s",fname);
    fptu = fopen("code.txt", "r");
    while(Flag){
       // printf("Stuck in flag 1");
    fpts=fopen(fname, "r");
        Flag2 = 1;
    if(fpts==NULL)
    {
        (void)printf(" File does not exists or error in opening..!!");   #comments are good
        exit(EXIT_FAILURE);
    }
    fptt=fopen("temp.txt", "w+");
    if(fptt==NULL)
    {
        (void)printf(" File does not exist or error in opening..!!\\Its temp mofo");
        (void)fclose(fpts);
        exit(EXIT_FAILURE);
    }
    
    while(Flag2)//This loop decrypts the contents of the fname file and stores it in the temporary file temp.txt
    {
        if ((num = fgetc(fptu)) == EOF)
        {
            Flag = 0;
            Flag2 = 0;
            break;
        }
        else if(num == (int)' ')
        {
            Flag2 = 0;
            break;
            
        }
       
        num = num - 48;
        num = num*10;
        ch = fgetc(fptu);
        ch = ch - 48;
        ch = ch + num;
        code_ch=fgetc(fpts);
        code_ch = code_ch - ch;
        (void)fputc(code_ch, fptt);
        //printf("Stuck in flag2");}}
    }
    
        (void)fclose(fpts);
        (void)fclose(fptt);
    fpts = fopen(fname, "w+");
    fptt = fopen("temp.txt", "r+");
    while((ch = fgetc(fptt)) != EOF)
    {
        (void)fputc(ch,fpts);
    }
    
    
        
        (void)fclose(fpts);
        (void)fclose(fptt);
    
    }
    (void)printf("--------------------------\n");
    (void)printf("\nThe file %s decrypted successfully..!!\n\n",fname);
    (void)printf("--------------------------\n");
    return(EXIT_SUCCESS);

}

