/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060125120022 - Ibnu Farrel Athaillah Firdaus*/
/* Tanggal : 28 Oktober 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.c"

int main(){ 
  //kamus
  address A; 
  address B;
  infotype V;
  List1 Senarai;
  List1 L1;
  List1 L2;
  List1 LHasil;
  List1 LSalin;
  //algoritma
  
  //aplikasi tipe address
  
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List1
  Senarai.First = B; //First(Senarai) = B;
  printf("Isi Senarai :");
  PrintList( Senarai );
  printf("\n");

  //dealokasi dua elemen contoh di atas
  next(B) = NIL;
  Dealokasi(A);
  Dealokasi(B);

  //aplikasi operasi-operasi ADT list1
  printf("\n== PEMAKAIAN OPERASI ADT LIST1 ==\n");
  CreateList(&Senarai);
  printf("Setelah CreateList, IsEmptyList = %d\n", IsEmptyList(Senarai));

  InsertVFirst(&Senarai, 'i');
  InsertVLast(&Senarai, 'b');
  InsertVLast(&Senarai, 'u');
  printf("Setelah InsertVFirst('i'), InsertVLast('b'), InsertVLast('u') :");
  PrintList(Senarai);
  printf("\nNbElm = %d\n", NbElm(Senarai));

  InsertVFirst(&Senarai, 'd');
  InsertVLast(&Senarai, 'a');
  printf("Setelah InsertVFirst('d') dan InsertVLast('a') :");
  PrintList(Senarai);
  printf("\n");

  //pencarian satu elemen
  SearchX(Senarai, 'b', &A);
  if (A != NIL) {
	  printf("SearchX('b') = ditemukan, info(A) = %c\n", info(A));
  } 
  else {
	  printf("SearchX('b') = tidak ditemukan\n");
  }

  //mengganti satu elemen
  UpdateX(&Senarai, 'b', 'B');
  printf("Setelah UpdateX('b','B') :");
  PrintList(Senarai);
  printf("\n");

  //menyisipkan setelah elemen tertentu
  InsertVAfter(&Senarai, 'u', 'k');
  printf("Setelah InsertVAfter('u','k') :");
  PrintList(Senarai);
  printf("\n");

  //menghitung kemunculan dan frekuensi
  printf("CountX('i') = %d\n", CountX(Senarai, 'i'));
  printf("FrekuensiX('i') = %.2f\n", FrekuensiX(Senarai, 'i'));

  //menampilkan semua posisi elemen
  printf("SearchAllX('i') :");
  SearchAllX(Senarai, 'i');
  printf("\n");

  //mengganti semua elemen
  UpdateAllX(&Senarai, 'i', 'I');
  printf("Setelah UpdateAllX('i','I') :");
  PrintList(Senarai);
  printf("\n");

  //menghapus elemen awal dan akhir
  DeleteVFirst(&Senarai, &V);
  printf("DeleteVFirst = %c\n", V);
  DeleteVLast(&Senarai, &V);
  printf("DeleteVLast = %c\n", V);
  printf("List setelah penghapusan :");
  PrintList(Senarai);
  printf("\n");

  //membalik urutan list
  Invers(&Senarai);
  printf("Setelah Invers :");
  PrintList(Senarai);
  printf("\n");

  //modus dan banyaknya
  printf("Modus = %c, NbModus = %d\n", Modus(Senarai), NbModus(Senarai));

  //menghitung huruf konsonan
  printf("CountKonsonan = %d\n", CountKonsonan(Senarai, '#'));

  //menggabungkan dua list
  CreateList(&L2);
  InsertVLast(&L2, 'n');
  InsertVLast(&L2, 'a');
  InsertVLast(&L2, 's');
  ConcatList(Senarai, L2, &LHasil);
  printf("List L2 :");
  PrintList(L2);
  printf("\nHasil ConcatList :");
  PrintList(LHasil);
  printf("\n");

  //memecah list menjadi dua
  SplitList(LHasil, &L1, &L2);
  printf("Hasil SplitList L1 :");
  PrintList(L1);
  printf("\nHasil SplitList L2 :");
  PrintList(L2);
  printf("\n");

  //menyalin list
  CopyList(LHasil, &LSalin);
  printf("Hasil CopyList :");
  PrintList(LSalin);
  printf("\nFirst LHasil dan First LSalin berbeda = %d\n",
		 First(LHasil) != First(LSalin));

  return 0;
}
