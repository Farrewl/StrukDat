/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait ganda */
/* NIM & Nama : 24060125120022 - Ibnu Farrel Athaillah Firdaus */
/* Tanggal : 9 November 2026 */
#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/* ================= PROSEDUR BANTU (khusus driver) ================= */

/* Menampilkan judul bagian pengujian */
void Judul(const char *teks) {
    printf("\n=== %s ===\n", teks);
}

/* Menampilkan isi list beserta jumlah elemennya */
void Tampil(const char *label, List3 L) {
    printf("%-30s: ", label);
    if (IsEmptyList(L)) {
        printf("(kosong) ");
    } else {
        PrintList(L);
    }
    printf("[jumlah=%d]\n", NbElm(L));
}

/* Mengosongkan list (mengembalikan semua elemen ke sistem) */
void Kosongkan(List3 *L) {
    infotype V;
    while (!IsEmptyList(*L)) {
        DeleteVFirst(L, &V);
    }
}

/* Mengisi list dengan karakter-karakter dari string s (isi lama dibuang) */
void Isi(List3 *L, const char *s) {
    Kosongkan(L);
    while (*s != '\0') {
        InsertVLast(L, *s);
        s++;
    }
}

/* ============================ PROGRAM UTAMA ============================ */
int main() {
    /* Kamus */
    List3 L, L1, L2, L3;
    address P;
    infotype V;

    /* ---------- 1. CreateList, IsEmptyList, PrintList, NbElm ---------- */
    Judul("1. CreateList, IsEmptyList, NbElm (list kosong)");
    CreateList(&L);
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L3);
    printf("IsEmptyList(L) : %s\n", IsEmptyList(L) ? "true" : "false");
    Tampil("L", L);

    /* ---------- 2. Alokasi & Dealokasi ---------- */
    Judul("2. Alokasi & Dealokasi");
    P = Alokasi('Q');
    if (P != NIL) {
        printf("info(P)=%c, prev(P)=NIL? %s, next(P)=NIL? %s\n",
               info(P),
               (prev(P) == NIL) ? "ya" : "tidak",
               (next(P) == NIL) ? "ya" : "tidak");
        Dealokasi(&P);
        printf("Setelah Dealokasi, P=NIL? %s\n", (P == NIL) ? "ya" : "tidak");
    }

    /* ---------- 3. InsertVFirst ---------- */
    Judul("3. InsertVFirst");
    InsertVFirst(&L, 'C');
    Tampil("Insert 'C' (list kosong)", L);
    InsertVFirst(&L, 'B');
    Tampil("Insert 'B' di awal", L);
    InsertVFirst(&L, 'A');
    Tampil("Insert 'A' di awal", L);

    /* ---------- 4. InsertVLast ---------- */
    Judul("4. InsertVLast");
    InsertVLast(&L, 'D');
    Tampil("Insert 'D' di akhir", L);
    InsertVLast(&L, 'E');
    Tampil("Insert 'E' di akhir", L);
    InsertVLast(&L1, 'Z');
    Tampil("Insert 'Z' ke list kosong L1", L1);
    Kosongkan(&L1);

    /* ---------- 5. DeleteVFirst & DeleteVLast ---------- */
    Judul("5. DeleteVFirst & DeleteVLast");
    DeleteVFirst(&L, &V);
    printf("DeleteVFirst, V = %c\n", V);
    Tampil("L", L);
    DeleteVLast(&L, &V);
    printf("DeleteVLast, V = %c\n", V);
    Tampil("L", L);

    Isi(&L1, "K");
    DeleteVLast(&L1, &V);
    printf("DeleteVLast pada 1 elemen, V = %c\n", V);
    Tampil("L1", L1);
    DeleteVFirst(&L1, &V);
    printf("DeleteVFirst pada list kosong, V = %c (default '#')\n", V);
    DeleteVLast(&L1, &V);
    printf("DeleteVLast pada list kosong, V = %c (default '#')\n", V);

    /* ---------- 6. SearchX ---------- */
    Judul("6. SearchX");
    Tampil("L", L);
    SearchX(L, 'C', &P);
    if (P != NIL) {
        printf("SearchX 'C' ketemu : info=%c, prev=%c, next=%c\n",
               info(P), info(prev(P)), info(next(P)));
    }
    SearchX(L, 'Z', &P);
    printf("SearchX 'Z' tidak ada : P=NIL? %s\n", (P == NIL) ? "ya" : "tidak");

    /* ---------- 7. UpdateX ---------- */
    Judul("7. UpdateX");
    UpdateX(&L, 'C', 'X');
    Tampil("UpdateX C -> X", L);
    UpdateX(&L, 'Z', 'Y');
    Tampil("UpdateX Z -> Y (tdk ada)", L);

    /* ---------- 8. DeleteX ---------- */
    Judul("8. DeleteX");
    Isi(&L, "ABCDE");
    Tampil("L awal", L);
    DeleteX(&L, 'C');
    Tampil("DeleteX 'C' (tengah)", L);
    DeleteX(&L, 'A');
    Tampil("DeleteX 'A' (awal)", L);
    DeleteX(&L, 'E');
    Tampil("DeleteX 'E' (akhir)", L);
    DeleteX(&L, 'Z');
    Tampil("DeleteX 'Z' (tdk ada)", L);
    DeleteX(&L, 'B');
    DeleteX(&L, 'D');
    Tampil("DeleteX 'B' lalu 'D'", L);
    DeleteX(&L, 'A');
    Tampil("DeleteX pada list kosong", L);

    /* ---------- 9. Invers ---------- */
    Judul("9. Invers");
    Isi(&L, "ABCDE");
    Tampil("Sebelum Invers", L);
    Invers(&L);
    Tampil("Sesudah Invers", L);
    Invers(&L);
    Tampil("Invers lagi (kembali)", L);
    Kosongkan(&L);
    Invers(&L);
    Tampil("Invers list kosong", L);
    Isi(&L, "A");
    Invers(&L);
    Tampil("Invers 1 elemen", L);

    /* ---------- 10. InsertVAfterX & InsertVBeforeX ---------- */
    Judul("10. InsertVAfterX & InsertVBeforeX");
    Kosongkan(&L);
    Isi(&L, "ACE");
    Tampil("L awal", L);
    InsertVAfterX(&L, 'A', 'B');
    Tampil("After 'A' sisip 'B'", L);
    InsertVAfterX(&L, 'E', 'F');
    Tampil("After 'E' (akhir) sisip 'F'", L);
    InsertVBeforeX(&L, 'E', 'D');
    Tampil("Before 'E' sisip 'D'", L);
    InsertVBeforeX(&L, 'A', 'Z');
    Tampil("Before 'A' (awal) sisip 'Z'", L);
    InsertVAfterX(&L, 'Q', 'Y');
    InsertVBeforeX(&L, 'Q', 'Y');
    Tampil("X='Q' tdk ada (tetap)", L);

    /* ---------- 11. DeleteVAfterX & DeleteVBeforeX ---------- */
    Judul("11. DeleteVAfterX & DeleteVBeforeX");
    Tampil("L awal", L);
    DeleteVAfterX(&L, 'A', &V);
    printf("DeleteVAfterX 'A', V = %c\n", V);
    Tampil("L", L);
    DeleteVBeforeX(&L, 'D', &V);
    printf("DeleteVBeforeX 'D', V = %c\n", V);
    Tampil("L", L);
    DeleteVBeforeX(&L, 'Z', &V);
    printf("DeleteVBeforeX 'Z' (elemen pertama), V = %c (default '#')\n", V);
    Tampil("L", L);
    DeleteVAfterX(&L, 'F', &V);
    printf("DeleteVAfterX 'F' (elemen terakhir), V = %c (default '#')\n", V);
    Tampil("L", L);
    DeleteVBeforeX(&L, 'D', &V);
    printf("DeleteVBeforeX 'D', V = %c\n", V);
    Tampil("L", L);

    /* ---------- 12. CountX, FrekuensiX, MaxMember, Modus ---------- */
    Judul("12. CountX, FrekuensiX, MaxMember, Modus");
    Isi(&L, "MENGGENGGAM");
    Tampil("L", L);
    printf("CountX 'G'     : %d\n", CountX(L, 'G'));
    printf("CountX 'Z'     : %d\n", CountX(L, 'Z'));
    printf("FrekuensiX 'G' : %.2f\n", FrekuensiX(L, 'G'));
    printf("MaxMember      : %d\n", MaxMember(L));
    printf("Modus          : %c\n", Modus(L));
    Kosongkan(&L);
    printf("-- list kosong --\n");
    printf("CountX 'G'     : %d\n", CountX(L, 'G'));
    printf("FrekuensiX 'G' : %.2f\n", FrekuensiX(L, 'G'));
    printf("MaxMember      : %d\n", MaxMember(L));
    printf("Modus          : %c (default '#')\n", Modus(L));

    /* ---------- 13. CountVocal & CountNG ---------- */
    Judul("13. CountVocal & CountNG");
    Isi(&L, "MENGGENGGAM");
    Tampil("L", L);
    printf("CountVocal : %d\n", CountVocal(L));
    printf("CountNG    : %d\n", CountNG(L));
    Isi(&L1, "NGANGKUNG");
    Tampil("L1", L1);
    printf("CountVocal : %d\n", CountVocal(L1));
    printf("CountNG    : %d\n", CountNG(L1));
    Kosongkan(&L1);
    printf("-- list kosong --\n");
    printf("CountVocal : %d\n", CountVocal(L1));
    printf("CountNG    : %d\n", CountNG(L1));

    /* ---------- 14. SearchAllX ---------- */
    Judul("14. SearchAllX");
    Kosongkan(&L);
    Isi(&L, "MANDA");
    Tampil("L", L);
    printf("SearchAllX 'A' : "); SearchAllX(L, 'A'); printf("\n");
    printf("SearchAllX 'M' : "); SearchAllX(L, 'M'); printf("\n");
    printf("SearchAllX 'J' : "); SearchAllX(L, 'J'); printf("\n");

    /* ---------- 15. DeleteAllX ---------- */
    Judul("15. DeleteAllX");
    Kosongkan(&L);
    Isi(&L, "AABACAA");
    Tampil("L awal", L);
    DeleteAllX(&L, 'A');
    Tampil("DeleteAllX 'A'", L);
    DeleteAllX(&L, 'Z');
    Tampil("DeleteAllX 'Z' (tdk ada)", L);
    Kosongkan(&L);
    Isi(&L, "AAAA");
    DeleteAllX(&L, 'A');
    Tampil("DeleteAllX 'A' pada AAAA", L);
    DeleteAllX(&L, 'A');
    Tampil("DeleteAllX pada kosong", L);

    /* ---------- 16. ConcatList ---------- */
    Judul("16. ConcatList");
    Kosongkan(&L);
    Isi(&L1, "ABC");
    Isi(&L2, "XYZ");
    Tampil("L1", L1);
    Tampil("L2", L2);
    ConcatList(L1, L2, &L3);
    Tampil("L3 = L1 + L2", L3);
    Tampil("L1 (tidak berubah)", L1);
    Kosongkan(&L3);
    Kosongkan(&L2);
    ConcatList(L1, L2, &L3);
    Tampil("L1 + kosong", L3);
    Kosongkan(&L3);

    /* ---------- 17. SplitList ---------- */
    Judul("17. SplitList");
    Kosongkan(&L1);
    Isi(&L, "ABCDEF");
    SplitList(L, &L1, &L2);
    Tampil("L (6 elemen)", L);
    Tampil("L1", L1);
    Tampil("L2", L2);
    Kosongkan(&L1);
    Kosongkan(&L2);
    Kosongkan(&L);
    Isi(&L, "ABCDE");
    SplitList(L, &L1, &L2);
    Tampil("L (5 elemen)", L);
    Tampil("L1", L1);
    Tampil("L2", L2);
    Kosongkan(&L1);
    Kosongkan(&L2);
    Kosongkan(&L);
    SplitList(L, &L1, &L2);
    Tampil("L kosong -> L1", L1);
    Tampil("L kosong -> L2", L2);

    /* ---------- 18. CopyList ---------- */
    Judul("18. CopyList");
    Isi(&L, "HALO");
    CopyList(L, &L2);
    Tampil("L (asli)", L);
    Tampil("L2 (salinan)", L2);
    UpdateX(&L2, 'H', 'J');
    Tampil("L2 setelah H->J", L2);
    Tampil("L (asli, tdk berubah)", L);
    Kosongkan(&L2);
    CopyList(L2, &L1);
    Tampil("Salinan list kosong", L1);

    /* ---------- Bersihkan memori ---------- */
    Kosongkan(&L);
    Kosongkan(&L1);
    Kosongkan(&L2);
    Kosongkan(&L3);
    printf("\n=== Selesai. Semua list sudah dikosongkan. ===\n");

    return 0;
}