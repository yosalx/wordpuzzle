# Tugas Kecil 1 Strategi Algoritma -  Word Puzzle

### Program Penyelesain Word Search Puzzle sebagai Tugas Kecil 1 IF2211 Strategi Algoritma

 Yoseph A.S. / K03/ 13520141

## Deskripsi Program
Program penyelesaian word search puzzle ini dibuat dengan memanfaatkan konsep algoritma brute force. Berdasarkan input dari file, puzzle dan keyword akan disimpan dalam matriks dan list lalu diselesaikan. Program lalu akan menampilkan matriks hasil dari tiap keyword, waktu eksekusi dari program untuk menyelesaikan puzzle dan jumlah perbandingan kata untuk menyelesaikan permainan.

## Requirements

Compiler untuk bahasa c

## Directory

```sh
wordpuzzle
├── src                     # Berisi source code program
├── bin                     # Berisi executable
├── test                    # Berisi test case dalam format txt 
├── doc                     # Berisi laporan dari Tugas Kecil 1 ini
```

## How to Run

1. Clone repository ini : `git clone git@github.com:yosalx/wordpuzzle.git`
2. Masuk ke directory tempat repo disimpan dan masuk ke folder src dengan `cd`
3. Lakukan command berikut 
`gcc -c main.c`;
`gcc main.c -o main`
`./main` 
4. Program akan berjalan, untuk input nama file - karena berada pada folder yang berbeda maka penulisan nama file dengan format `../test/{namafile}.txt`