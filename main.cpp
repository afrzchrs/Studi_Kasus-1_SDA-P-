/*
Nama : Afriza Choirie Saputra
NIM  : 241524002
SDA PRAKTIK Studi Kasus 1
*/

#include "mahasiswa.h"

int main() {
    address L1 = NULL, L2 = NULL;
    
    //elemen List L1
    Ins_SortedByName(&L1, "Budi", 75);
    Ins_SortedByName(&L1, "Andi", 65);
    Ins_SortedByName(&L1, "Dina", 60);
    Ins_SortedByName(&L1, "Citra", 90);
    Ins_SortedByName(&L1, "Miles", 98);
    
    //elemen List L2
    Ins_SortedByName(&L2, "Jeriko", 81);
    Ins_SortedByName(&L2, "Nay", 83);
    Ins_SortedByName(&L2, "Maylene", 77);
    Ins_SortedByName(&L2, "Boby", 95);
    Ins_SortedByName(&L2, "Miles", 98);
    
    printf("\nList L1 (Ascending Nama):\n");
    Tampil_List(L1);
    
    printf("\nList L2 (Ascending Nama):\n");
    Tampil_List(L2);
    

    printf("\nList L1 (Descending Nilai):\n");
    TampilListDescending(L1);
    
    printf("\nList L2 (Descending Nilai):\n");
    TampilListDescending(L2);
    
    printf("\nJumlah Mahasiswa List L1: %d\n", hitungElements(L1));
    
    printf("\nJumlah Mahasiswa List L2: %d\n", hitungElements(L2));
    
    copydiatas70(L1, &L2);
    printf("\nList L2 setelah L1 difilter untuk Nilai > 70 :\n");
    Tampil_List(L2);
    
    hapusDuplikasi(&L2);
    printf("\nList baru L2 setelah duplikat dihapus:\n");
    Tampil_List(L2);
    
    printf("\n==== Menghapus List L1 ====\n");
    hapusList(&L1);
    
    printf("\n==== Menghapus List L2 ====\n");
    hapusList(&L2);
    return 0;
    
    return 0;
}
