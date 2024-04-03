#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int receipt_id;
    int receipt_price;
    int lotto_set[5][7];
}lotto_record_t;

void print_info(int lotto[]){
    printf("號碼：%02d %02d %02d %02d %02d %02d %02d\n", lotto[0], lotto[1], lotto[2], lotto[3], lotto[4], lotto[5], lotto[6]);
}

int main() {
    int n = 0;
    srand(time(NULL));
    printf("請問要買幾組樂透：");
    scanf("%d", &n);
    FILE* rc = fopen("record.bin", "ab+");;
    
    if (n == 0){
        int check_num[3] = {0}, m = 0, lotto_num = 1;
        printf("請輸入中獎號碼(最多三碼)：");
        do {
            scanf("%d", &check_num[m++]);
            if (m >= 3) break;
        } while (getchar() != '\n');
        
        printf("輸入中獎號碼為：");
        for(int i = 0; i < 3; i++){
            if(check_num[i] != '\0') printf("%02d ", check_num[i]);
        }
        printf("\n以下為中獎彩券：\n");
        fseek(rc, 0, SEEK_END);
        int total = ftell(rc)/sizeof(lotto_record_t);
        
        while(lotto_num <= total){
            int correct_arr[5] = {0};
            int c = 1;
            lotto_record_t lotto_record_read;
            fseek(rc, sizeof(lotto_record_t) * (lotto_num - 1), SEEK_SET);
            fread(&lotto_record_read, sizeof(lotto_record_t), 1, rc);
            
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 7; j ++){
                    for(int k = 0; k < 3; k++){
                        if(check_num[k] == 0){
                            continue;
                        }
                        else if (check_num[k] == lotto_record_read.lotto_set[i][j]){
                            correct_arr[i] = 1;
                        }
                    }
                }
                if(c == 1 && correct_arr[0] + correct_arr[1] + correct_arr[2] + correct_arr[3] + correct_arr[4] > 0){
                    printf("彩券No.[%d]\n", lotto_num);
                    c = 0;
                }
                for(int j = 0; j < 5; j++){
                    if(correct_arr[i] == 1){
                        print_info(lotto_record_read.lotto_set[i]);
                        break;
                    }
                }
            }
            lotto_num++;
        }
    }
    else {
        int num[7];
        char filename[20];
        lotto_record_t lotto_record;
        lotto_record.receipt_price = n * 100;
        
        if(fopen("record.bin", "rb") == NULL){
            lotto_record.receipt_id = 1;
        }
        else{
            fseek(rc, -sizeof(lotto_record_t), SEEK_END);
            fread(&lotto_record.receipt_id, sizeof(int), 1, rc);
        }
        sprintf(filename, "lotto%05d.txt", ++lotto_record.receipt_id);
        FILE* fp = fopen(filename, "w");

        fprintf(fp, "========= lotto649 =========\n");
        fprintf(fp, "========+ No.%05d +========\n", lotto_record.receipt_id);
        time_t curtime;
        time(&curtime);
        fprintf(fp, "%s\n",ctime(&curtime));
        for(int j = 1; j <= 5; j++){
            fprintf(fp, "[%d]: ", j);
            if (j > n){
                fprintf(fp, "__ __ __ __ __ __ __\n");
            }
            else{
                for(int i = 0; i < 7; i++){
                    num[i] = rand() % 69 + 1;
                    for (int k = 0; k < i; k++){
                        if(num[i] == num[k]) {
                            i--;
                            break;
                        }
                    }
                    lotto_record.lotto_set[j-1][i] = num[i];
                }
                fprintf(fp, "%02d %02d %02d %02d %02d %02d %02d\n", num[0], num[1], num[2], num[3], num[4], num[5], num[6]);
            }
        }
        fprintf(fp, "========= csie@CGU =========\n");
        fwrite(&lotto_record, sizeof(lotto_record_t), 1, rc);
    
        fclose(fp);
    }
    fclose(rc);
}
