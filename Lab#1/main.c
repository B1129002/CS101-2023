#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp;
    int arr_write[5] = {1, 2, 3, 4, 5};
    int arr_read[5];
    fp = fopen("a.bin","wb+");
    fwrite(arr_write,sizeof(int),5,fp);
    fseek(fp,0,SEEK_SET);
    fread(arr_read,sizeof(arr_read),5,fp);
    for(int i=0;i<5;i++){
        printf("%d",arr_read[i]);
    }
    return 0;
}
