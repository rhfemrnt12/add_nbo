#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if(argc!=3){
        printf("argc Error!\n");
        return 0;
    }

    FILE* fp1, *fp2;

    fp1=fopen(argv[1],"rb");
    fp2=fopen(argv[2],"rb");

    unsigned char a[4], b[4];
    uint32_t a1, b1;

    fread(a, 1, 4, fp1);
    fread(b, 1, 4, fp2);
    
    a1= (a[0]<<24) | (a[1]<<16) | (a[2]<<8) | (a[3]);
    b1= (b[0]<<24) | (b[1]<<16) | (b[2]<<8) | (b[3]);
    //a[3] and b[3] forms like 0xffffff__. why??? ==> signed=sign extension, unsigned=zero extension

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a1,a1,b1,b1,a1+b1,a1+b1);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
