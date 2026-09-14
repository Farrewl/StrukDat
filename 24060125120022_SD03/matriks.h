#ifndef matriks_H
#define matriks_H 

/* Program   : matriks.h */
/* Deskripsi : file HEADER modul matriks integer */
/* NIM/Nama  : 24060125120022/Ibnu Farrel Athailah Firdaus */
/* Tanggal   : 7 September 2026 */
/***********************************/ 

#include "boolean.h"  //salin dari praktikum lalu

/* type Matriks = < cell: array[1…10] of array[1…10] of integer, 
				    nbaris: integer, 
					nkolom: integer > */
/* asumsi: indeks 0 tidak digunakan */
typedef	struct { int cell[11][11];
                 int nbaris;
				 int nkolom; } Matriks;

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M);

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M);

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M);

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M);

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M);

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int baris, int kolom);

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X);

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y);

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n);

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y);

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M);

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M);

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2);

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2);

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2);

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x);

/* OPERASI LAINNYA */

/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M);

/* function getTransposeMatriks(M: Matriks) -> Matriks
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M);

//buat header fungsi untuk beberapa operasi matriks dalam image processing berikut

/* function thresholding(M: Matriks, T: integer) -> Matriks
   {menghasilkan matriks hasil thresholding dengan nilai threshold T}
*/
Matriks thresholding(Matriks M, int T);

/* function citraNegatif(M: Matriks) -> Matriks
   {menghasilkan citra/matriks negatif}
*/
Matriks citraNegatif(Matriks M);

/* function brightness(M: Matriks, b: integer) -> Matriks
   {menghasilkan citra/matriks baru yang telah diubah kecerahannya sebasar b}
*/
Matriks brightness(Matriks M, int b);

/* function grayscale(R, G, B: Matriks) -> Matriks
   {menghasilkan citra/matriks grayscale dari citra R, G, B}
*/
Matriks grayscale(Matriks R, Matriks G, Matriks B);

/* function translasi(M: Matriks, dx: integer, dy: integer) -> Matriks
   {menghasilkan citra/matriks hasil translasi sebesar dx secara horizontal dan dx secara vertikal}
*/
Matriks translasi(Matriks M, int dx, int dy);

/* function flipHorizontal(M: Matriks) -> Matriks
   {menghasilkan citra/matriks hasil flip horizontal, kanan -> kiri, kir -> kanan}
*/
Matriks flipHorizontal(Matriks M);

/* function flipVertical(M: Matriks) -> Matriks
   {menghasilkan citra/matriks hasil flip vertical, atas -> bawah, bawah <- atas}
*/
Matriks flipVertical(Matriks M);

/* function addPadding(M: Matriks, input n:integer) -> Matriks
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks Padding(Matriks M, int n);

/* function maxPooling(M: Matriks, input size:integer) -> Matriks
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size);

/* function avgPooling(M: Matriks, input size:integer) -> Matriks
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size);

/* function conv(M: Matriks, K:Matriks) -> Matriks
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks konvolusi(Matriks M, Matriks K);

#endif