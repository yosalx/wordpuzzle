#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "time.h"

typedef char ElType;

typedef struct {
    ElType contents[99][99];
    int neff;
} List;
#define NEFF(L) (L).neff
#define LIST(L, i) (L).contents[(i)]

typedef struct {
    ElType contents[99][99];
    int rowEff;
    int colEff;
} Matrix;
#define ROW(M) (M).rowEff
#define COL(M) (M).colEff
#define MTRX(M, i, j) (M).contents[(i)][(j)]

int main(){
    char filename[99];
    printf("Masukkan nama file yang akan diinput: ");
    gets(filename);

    FILE * fileinput;
    Matrix puzzle;
    Matrix result;
    int row = 0; 
    int col = 0;
    int count;
    char cc;
    char temp;
    ROW(puzzle) = 0;
    COL(puzzle) = 0;
    char *str;
    boolean newLine = false;

    fileinput=fopen(filename,"r");

    cc = fgetc(fileinput);

    while(!newLine){
        if(cc !=' ' && cc != '\n'){
            MTRX(puzzle, row, col) = cc;
            col++;
        }
        else if(cc == '\n'){
            ROW(puzzle)++;
            row++;
            COL(puzzle) = col;
            col = 0; 
        }            
        temp = cc;
        cc = fgetc(fileinput);
        if(cc =='\n' && temp =='\n'){
            newLine = true;
        }
    }

    List words;
    NEFF(words) = 0;
    
    char key[100];
    while (fgets(key, sizeof(key), fileinput)) {
        strcpy(LIST(words, NEFF(words)), key);
        NEFF(words)++;
    }

    for (int i = 0; i < NEFF(words)-1; i++) {
        LIST(words, i)[strlen(LIST(words, i))-1] = '\0';
    }
    
    fclose(fileinput);
    count = 0;

    clock_t beginpuzzle = clock();
    
    for (int n = 0; n < NEFF(words); n++){
        int wordsLen = strlen(LIST(words,n));
        for (int i = 0; i < ROW(puzzle); i ++){
            for (int j = 0; j< COL(puzzle); j++){
                count++;
                int m = 0; int o = 0; int p = 0; int q = 0;
                int r = 0; int s = 0; int t = 0; int u = 0;
                while ((m<wordsLen)&&(MTRX(puzzle,i,j+m)==LIST(words,n)[m])){
                    m++;
                    count++;
                }
                while ((o<wordsLen)&&(MTRX(puzzle,i+o,j)==LIST(words,n)[o])){
                    o++;
                    count++;
                }
                while ((p<wordsLen)&&(MTRX(puzzle,i,j-p)==LIST(words,n)[p])){
                    p++;
                    count++;
                }
                while ((q<wordsLen)&&(MTRX(puzzle,i-q,j)==LIST(words,n)[q])){
                    q++;
                    count++;
                }
                while ((r<wordsLen)&&(MTRX(puzzle,i+r,j+r)==LIST(words,n)[r])){
                    r++;
                    count++;
                }
                while ((s<wordsLen)&&(MTRX(puzzle,i+s,j-s)==LIST(words,n)[s])){
                    s++;
                    count++;
                }
                while ((t<wordsLen)&&(MTRX(puzzle,i-t,j-t)==LIST(words,n)[t])){
                    t++;
                    count++;
                }
                while ((u<wordsLen)&&(MTRX(puzzle,i-u,j+u)==LIST(words,n)[u])){
                    u++;
                    count++;
                }                
                if (m==wordsLen){
                    for (int y = 0; y < ROW(puzzle); y ++){
                        for (int z = 0; z< COL(puzzle); z++){
                            MTRX(result,y,z) = '=';
                        }
                    }

                    int limit = j + wordsLen;
                    for (j; j< limit ; j++){
                        MTRX(result,i,j) = MTRX(puzzle,i,j);
                    }

                    for (int a = 0; a < ROW(puzzle); a ++){
                        for (int b = 0; b< COL(puzzle); b++){
                            if(b == COL(puzzle) - 1){
                                printf("%c\n", MTRX(result, a, b));
                            }
                            else{
                                printf("%c ", MTRX(result, a, b));
                            }
                        }
                    }

                    printf("\n\n");
                }
                else if (o==wordsLen){
                    for (int y = 0; y < ROW(puzzle); y ++){
                        for (int z = 0; z< COL(puzzle); z++){
                            MTRX(result,y,z) = '=';
                        }
                    }

                    int limit = i + wordsLen;
                    for (i; i< limit ; i++){
                        MTRX(result,i,j) = MTRX(puzzle,i,j);
                    }

                    for (int a = 0; a < ROW(puzzle); a ++){
                        for (int b = 0; b< COL(puzzle); b++){
                            if(b == COL(puzzle) - 1){
                                printf("%c\n", MTRX(result, a, b));
                            }
                            else{
                                printf("%c ", MTRX(result, a, b));
                            }
                        }
                    }

                    printf("\n\n");
                }
                else if (p==wordsLen){
                    for (int y = 0; y < ROW(puzzle); y++){
                        for (int z = 0; z< COL(puzzle); z++){
                            MTRX(result,y,z) = '=';
                        }
                    }

                    int start = j - wordsLen + 1;
                    for (start; start <= j ; start++){
                        MTRX(result,i,start) = MTRX(puzzle,i,start);
                    }

                    for (int a = 0; a < ROW(puzzle); a ++){
                        for (int b = 0; b< COL(puzzle); b++){
                            if(b == COL(puzzle) - 1){
                                printf("%c\n", MTRX(result, a, b));
                            }
                            else{
                                printf("%c ", MTRX(result, a, b));
                            }
                        }
                    }
                    printf("\n\n");
                }
                else if (q==wordsLen){

                    for (int y = 0; y < ROW(puzzle); y++){
                        for (int z = 0; z< COL(puzzle); z++){
                            MTRX(result,y,z) = '=';
                        }
                    }

                    int start = i - wordsLen + 1;
                    for (start; start <= i ; start++){
                        MTRX(result,start,j) = MTRX(puzzle,start,j);
                    }

                    for (int a = 0; a < ROW(puzzle); a ++){
                        for (int b = 0; b< COL(puzzle); b++){
                            if(b == COL(puzzle) - 1){
                                printf("%c\n", MTRX(result, a, b));
                            }
                            else{
                                printf("%c ", MTRX(result, a, b));
                            }
                        }
                    }
                    printf("\n\n");
                }
                else if (r==wordsLen){
                    for (int y = 0; y < ROW(puzzle); y ++){
                        for (int z = 0; z< COL(puzzle); z++){
                            MTRX(result,y,z) = '=';
                        }
                    }
                    int limit= j + wordsLen;
                    int curr = i;
                    for (j; j< limit; j++){
                        MTRX(result,curr,j) = MTRX(puzzle,curr,j);
                        curr++;
                    }

                    for (int a = 0; a < ROW(puzzle); a ++){
                        for (int b = 0; b< COL(puzzle); b++){
                            if(b == COL(puzzle) - 1){
                                printf("%c\n", MTRX(result, a, b));
                            }
                            else{
                                printf("%c ", MTRX(result, a, b));
                            }
                        }
                    }

                    printf("\n\n");
                }
                else if (s==wordsLen){
                    for (int y = 0; y < ROW(puzzle); y ++){
                        for (int z = 0; z< COL(puzzle); z++){
                            MTRX(result,y,z) = '=';
                        }
                    }
                    int start = j - wordsLen + 1;
                    int curr = i + wordsLen - 1;
                    for (start; start<= j; start++){
                        MTRX(result,curr,start) = MTRX(puzzle,curr,start);
                        curr--;
                    }

                    for (int a = 0; a < ROW(puzzle); a ++){
                        for (int b = 0; b< COL(puzzle); b++){
                            if(b == COL(puzzle) - 1){
                                printf("%c\n", MTRX(result, a, b));
                            }
                            else{
                                printf("%c ", MTRX(result, a, b));
                            }
                        }
                    }

                    printf("\n\n");
                }
                else if (t==wordsLen){
                    for (int y = 0; y < ROW(puzzle); y ++){
                        for (int z = 0; z< COL(puzzle); z++){
                            MTRX(result,y,z) = '=';
                        }
                    }
                    int start = i - wordsLen + 1;
                    int curr = j - wordsLen + 1;
                    for (start; start<= i; start++){
                        MTRX(result,start,curr) = MTRX(puzzle,start,curr);
                        curr++;
                    }

                    for (int a = 0; a < ROW(puzzle); a ++){
                        for (int b = 0; b< COL(puzzle); b++){
                            if(b == COL(puzzle) - 1){
                                printf("%c\n", MTRX(result, a, b));
                            }
                            else{
                                printf("%c ", MTRX(result, a, b));
                            }
                        }
                    }

                    printf("\n\n");
                }
                else if (u==wordsLen){
                    for (int y = 0; y < ROW(puzzle); y ++){
                        for (int z = 0; z< COL(puzzle); z++){
                            MTRX(result,y,z) = '=';
                        }
                    }
                    int start = i - wordsLen + 1;
                    int curr = j + wordsLen - 1;
                    for (start; start<= i; start++){
                        MTRX(result,start,curr) = MTRX(puzzle,start,curr);
                        curr--;
                    }

                    for (int a = 0; a < ROW(puzzle); a ++){
                        for (int b = 0; b< COL(puzzle); b++){
                            if(b == COL(puzzle) - 1){
                                printf("%c\n", MTRX(result, a, b));
                            }
                            else{
                                printf("%c ", MTRX(result, a, b));
                            }
                        }
                    }

                    printf("\n\n");
                }
            }
        }
    }
    clock_t endpuzzle = clock();

    double duration = ((double) (endpuzzle - beginpuzzle))/(1000);

    printf("Waktu dari eksekusi program adalah : %.5f sekon\n", (float)duration);
    printf("Total perbandingan huruf yang dilakukan adalah sebanyak : %d kali", count);
}