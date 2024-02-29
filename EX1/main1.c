#include <stdio.h>
void printf_sp(int n){
    for (int j=n ;j>=1;j--){
       printf(" "); 
    }
}
void printf_num(int n){
    for(int j=1;j<=n;j++){
        printf("%d ",n);
    }
}
int main(){
    int rows = 6;
    int spc=rows;
    for (int i = 0 ; i<rows ; i++){
        printf_sp(spc);
        printf_num(i);
        printf("\n");
        spc--;
    }

    return 0;
}
