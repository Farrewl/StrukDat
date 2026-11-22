/* File : main.c */
/* Deskripsi : driver pengujian ADT bintree berkait representasi fisik pointer */
/* NIM & Nama : 24060125120022 - Ibnu Farrel Athaillah Firdaus */
/* Tanggal : 16 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

/* ================= PROSEDUR BANTU (khusus driver) ================= */

/* Menampilkan judul bagian pengujian */
void Judul(const char *teks) {
    printf("\n=== %s ===\n", teks);
}

/* Menampilkan isi pohon secara prefix beserta jumlah elemen dan tingginya */
void Tampil(const char *label, bintree P) {
    printf("%-40s: ", label);
    if (IsEmptyTree(P)) {
        printf("(kosong)");
    } else {
        PrintPrefix(P);
    }
    printf(" [jumlah=%d, tinggi=%d]\n", NbElm(P), Tinggi(P));
}

/* Mengosongkan pohon (mengembalikan semua node ke sistem) secara postorder */
void Kosongkan(bintree *P) {
    if (*P != NIL) {
        Kosongkan(&(left(*P)));
        Kosongkan(&(right(*P)));
        DealokasiTree(P);
    }
}

/* Membuat pohon uji berisi huruf-huruf kata "TIRNIFORMATIKA" */
bintree BuatPohonUji(void) {
    return Tree('T',
                Tree('I',
                     Tree('N', NIL, NIL),
                     Tree('F',
                          Tree('O', NIL, NIL),
                          NIL)),
                Tree('R',
                     Tree('M',
                          Tree('A', NIL, NIL),
                          Tree('T', NIL, NIL)),
                     Tree('I',
                          NIL,
                          Tree('K',
                               NIL,
                               Tree('A', NIL, NIL)))));
}

/* ============================ PROGRAM UTAMA ============================ */
int main() {
    /* Kamus */
    bintree B, P, SL, SR;

    /* ---------- 1. AlokasiTree & Tree ---------- */
    Judul("1. AlokasiTree & Tree");
    B = BuatPohonUji();
    Tampil("Pohon uji B", B);

    P = AlokasiTree('Z');
    if (P != NIL) {
        printf("AlokasiTree('Z')      : info=%c, left=NIL? %s, right=NIL? %s\n",
               info(P),
               (left(P) == NIL) ? "ya" : "tidak",
               (right(P) == NIL) ? "ya" : "tidak");
        DealokasiTree(&P);
        printf("Setelah DealokasiTree : P=NIL? %s\n", (P == NIL) ? "ya" : "tidak");
    }

    /* ---------- 2. Selektor ---------- */
    Judul("2. Selektor");
    printf("akar(B)     = %c\n", akar(B));
    printf("GetLeft(B)  = %c\n", info(GetLeft(B)));
    printf("GetRight(B) = %c\n", info(GetRight(B)));

    /* ---------- 3. Predikat ---------- */
    Judul("3. Predikat");
    printf("IsEmptyTree(NIL)    = %d\n", IsEmptyTree(NIL));
    printf("IsEmptyTree(B)      = %d\n", IsEmptyTree(B));
    printf("IsDaun(B)           = %d\n", IsDaun(B));
    printf("IsDaun(daun 'N')    = %d\n", IsDaun(GetLeft(GetLeft(B))));
    printf("IsBiner(B)          = %d\n", IsBiner(B));
    SL = Tree('U', Tree('V', NIL, NIL), NIL);
    SR = Tree('U', NIL, Tree('V', NIL, NIL));
    printf("IsUnerLeft(pohon U kiri)  = %d\n", IsUnerLeft(SL));
    printf("IsUnerRight(pohon U kanan)= %d\n", IsUnerRight(SR));
    Kosongkan(&SL);
    Kosongkan(&SR);

    /* ---------- 4. Penelusuran & Cacah ---------- */
    Judul("4. Penelusuran & Cacah");
    Tampil("PrintPrefix(B)", B);
    printf("NbElm(B)   = %d\n", NbElm(B));
    printf("NbDaun(B)  = %d\n", NbDaun(B));
    printf("Tinggi(B)  = %d\n", Tinggi(B));
    P = Tree('A', NIL, NIL);
    printf("Tinggi(1 elemen) = %d\n", Tinggi(P));
    printf("Tinggi(pohon kosong) = %d\n", Tinggi(NIL));
    Kosongkan(&P);
    printf("max2(3,7)  = %d\n", max2(3, 7));

    /* ---------- 5. SearchX ---------- */
    Judul("5. SearchX");
    printf("SearchX(B,'K') = %d\n", SearchX(B, 'K'));
    printf("SearchX(B,'Z') = %d\n", SearchX(B, 'Z'));
    printf("SearchX(NIL,'A') = %d\n", SearchX(NIL, 'A'));

    /* ---------- 6. UpdateX ---------- */
    Judul("6. UpdateX");
    Tampil("Sebelum UpdateX", B);
    UpdateX(&B, 'O', 'Q');
    Tampil("Sesudah UpdateX O->Q", B);
    UpdateX(&B, 'Q', 'O');
    Tampil("Kembalikan UpdateX Q->O", B);
    UpdateX(&B, 'Z', 'Y');
    Tampil("UpdateX Z->Y (tdk ada)", B);

    /* ---------- 7. CountX ---------- */
    Judul("7. CountX");
    printf("CountX(B,'I') = %d\n", CountX(B, 'I'));
    printf("CountX(B,'A') = %d\n", CountX(B, 'A'));
    printf("CountX(B,'Z') = %d\n", CountX(B, 'Z'));

    /* ---------- 8. Pohon Condong ---------- */
    Judul("8. Pohon Condong");
    SL = Tree('A', Tree('B', Tree('C', NIL, NIL), NIL), NIL);
    SR = Tree('A', NIL, Tree('B', NIL, Tree('C', NIL, NIL)));
    Tampil("Pohon condong kiri  (SL)", SL);
    printf("IsSkewLeft(SL)  = %d\n", IsSkewLeft(SL));
    printf("IsSkewRight(SL) = %d\n", IsSkewRight(SL));
    Tampil("Pohon condong kanan (SR)", SR);
    printf("IsSkewRight(SR) = %d\n", IsSkewRight(SR));
    printf("IsSkewLeft(SR)  = %d\n", IsSkewLeft(SR));
    printf("IsSkewLeft(B)   = %d\n", IsSkewLeft(B));
    printf("IsSkewRight(B)  = %d\n", IsSkewRight(B));
    Kosongkan(&SL);
    Kosongkan(&SR);

    /* ---------- 9. PrintPrefixRingkas ---------- */
    Judul("9. PrintPrefixRingkas");
    printf("PrintPrefix(B)       = ");
    PrintPrefix(B);
    printf("\n");
    printf("PrintPrefixRingkas(B)= ");
    PrintPrefixRingkas(B);
    printf("\n");
    SL = Tree('A', Tree('B', Tree('C', NIL, NIL), NIL), NIL);
    printf("PrintPrefixRingkas(pohon condong kiri) = ");
    PrintPrefixRingkas(SL);
    printf("\n");
    Kosongkan(&SL);

    /* ---------- 10. LevelX ---------- */
    Judul("10. LevelX");
    printf("LevelX(B,'T') = %d (akar, level 1)\n", LevelX(B, 'T'));
    printf("LevelX(B,'N') = %d\n", LevelX(B, 'N'));
    printf("LevelX(B,'A') = %d\n", LevelX(B, 'A'));
    printf("LevelX(B,'Z') = %d (tdk ada -> -1)\n", LevelX(B, 'Z'));

    /* ---------- 11. CountLevel & PrintLevel ---------- */
    Judul("11. CountLevel & PrintLevel");
    printf("CountLevel(B,1) = %d\n", CountLevel(B, 1));
    printf("CountLevel(B,2) = %d\n", CountLevel(B, 2));
    printf("CountLevel(B,3) = %d\n", CountLevel(B, 3));
    printf("CountLevel(B,4) = %d\n", CountLevel(B, 4));
    printf("CountLevel(B,5) = %d\n", CountLevel(B, 5));
    printf("CountLevel(B,0) = %d (level tidak valid)\n", CountLevel(B, 0));
    printf("PrintLevel(B,1) = "); PrintLevel(B, 1); printf("\n");
    printf("PrintLevel(B,2) = "); PrintLevel(B, 2); printf("\n");
    printf("PrintLevel(B,3) = "); PrintLevel(B, 3); printf("\n");
    printf("PrintLevel(B,4) = "); PrintLevel(B, 4); printf("\n");

    /* ---------- 12. GetDaunTerkiri ---------- */
    Judul("12. GetDaunTerkiri");
    printf("GetDaunTerkiri(B)   = %c\n", GetDaunTerkiri(B));
    printf("GetDaunTerkiri(NIL) = %c (default '#')\n", GetDaunTerkiri(NIL));
    SR = Tree('A', NIL, Tree('B', NIL, Tree('C', NIL, NIL)));
    printf("GetDaunTerkiri(pohon condong kanan) = %c\n", GetDaunTerkiri(SR));
    Kosongkan(&SR);

    /* ---------- 13. FrekuensiX ---------- */
    Judul("13. FrekuensiX");
    printf("FrekuensiX(B,'I')   = %.4f\n", FrekuensiX(B, 'I'));
    printf("FrekuensiX(B,'A')   = %.4f\n", FrekuensiX(B, 'A'));
    printf("FrekuensiX(B,'Z')   = %.4f\n", FrekuensiX(B, 'Z'));
    printf("FrekuensiX(NIL,'A') = %.4f (pohon kosong)\n", FrekuensiX(NIL, 'A'));

    /* ---------- 14. Vokal & Konsonan ---------- */
    Judul("14. Vokal & Konsonan");
    printf("CountVocal(B)     = %d\n", CountVocal(B));
    printf("PrintVocal(B)     = "); PrintVocal(B); printf("\n");
    printf("CountConsonant(B) = %d\n", CountConsonant(B));
    printf("PrintConsonant(B) = "); PrintConsonant(B); printf("\n");

    /* ---------- 15. Modus ---------- */
    Judul("15. Modus");
    printf("Modus(B) = %c\n", Modus(B));
    printf("Modus(NIL) = %c (default '#')\n", Modus(NIL));
    P = Tree('A', Tree('B', NIL, NIL), NIL);
    printf("Modus(pohon A-B) = %c\n", Modus(P));
    Kosongkan(&P);

    /* ---------- 16. Dealokasi & Kosongkan ---------- */
    Judul("16. Dealokasi & Kosongkan");
    P = Tree('Z', NIL, NIL);
    printf("Sebelum dealokasi : P=%p\n", (void *) P);
    DealokasiTree(&P);
    printf("Sesudah dealokasi : P=%p (NIL)\n", (void *) P);
    Kosongkan(&B);
    Tampil("Setelah Kosongkan(B)", B);

    return 0;
}
