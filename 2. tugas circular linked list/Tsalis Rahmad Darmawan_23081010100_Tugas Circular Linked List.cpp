#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================
// Nama  : Tsalis Rahmad Darmawan
// NPM   : 23081010100
// Kelas : Struktur Data E081

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Fungsi-fungsi untuk circular linked list
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void sumData(node *head);
void tranverse(node *head);

//========================================================

int main() {
    node *head;
    char pilih;

    head = NULL;
    do {
        system("cls");
        printf("masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir\n");
        printf("4. Cetak isi list\n");
        printf("5. Hapus data di awal\n");
        printf("6. Hapus data di tengah\n");
        printf("7. Hapus data di akhir\n");
        printf("8. Cari data\n");
        printf("9. Tampilkan jumlah data\n");
        printf("10. Tampilkan jumlahkan semua data\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);
        
        if (pilih == '1') tambahAwal(&head);
        else if (pilih == '2') tambahData(&head);
        else if (pilih == '3') tambahAkhir(&head);
        else if (pilih == '4') {
            tranverse(head);
            getch();
        } else if (pilih == '5') hapusAwal(&head);
        else if (pilih == '6') hapusTengah(&head);
        else if (pilih == '7') hapusAkhir(&head);
        else if (pilih == '8') cariData(head);
        else if (pilih == '9') jumlahData(head);
        else if (pilih == '10') sumData(head);
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew, *pLast;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head;
        } else {
            pLast = *head;
            while (pLast->next != *head) {
                pLast = pLast->next;
            }
            pNew->next = *head;
            *head = pNew;
            pLast->next = *head;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    do {
        if (pCur->data == pos) break;
        pCur = pCur->next;
    } while (pCur != *head);

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL || pCur->data != pos) {
        printf("\nnode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("\nalokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//========================================================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *head;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head) {
    node *pTemp, *pLast;

    system("cls");
    if (*head == NULL) {
        printf("List kosong");
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("Data awal berhasil dihapus");
    } else {
        pLast = *head;
        while (pLast->next != *head) {
            pLast = pLast->next;
        }
        pTemp = *head;
        *head = (*head)->next;
        pLast->next = *head;
        free(pTemp);
        printf("Data awal berhasil dihapus");
    }
    getch();
}

//========================================================

void hapusTengah(node **head) {
    int pos;
    node *pCur, *pPrev;

    system("cls");
    tranverse(*head);
    printf("\nData yang akan dihapus: ");
    fflush(stdin);
    scanf("%d", &pos);

    pCur = *head;
    pPrev = NULL;
    do {
        if (pCur->data == pos) break;
        pPrev = pCur;
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur == NULL || pCur->data != pos) {
        printf("Data tidak ditemukan");
    } else {
        if (pPrev != NULL) {
            pPrev->next = pCur->next;
        } else {
            node *pLast = *head;
            while (pLast->next != *head) {
                pLast = pLast->next;
            }
            *head = (*head)->next;
            pLast->next = *head;
        }
        free(pCur);
        printf("Data berhasil dihapus");
    }
    getch();
}

//========================================================

void hapusAkhir(node **head) {
    node *pCur, *pPrev;

    system("cls");
    if (*head == NULL) {
        printf("List kosong");
    } else if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        printf("Data akhir berhasil dihapus");
    } else {
        pCur = *head;
        while (pCur->next != *head) {
            pPrev = pCur;
            pCur = pCur->next;
        }
        pPrev->next = *head;
        free(pCur);
        printf("Data akhir berhasil dihapus");
    }
    getch();
}

//========================================================

void cariData(node *head) {
    int bil;
    node *pCur;

    system("cls");
    printf("Masukkan data yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = head;
    do {
        if (pCur->data == bil) break;
        pCur = pCur->next;
    } while (pCur != head);

    if (pCur == NULL || pCur->data != bil) {
        printf("Data tidak ditemukan");
    } else {
        printf("Data ditemukan: %d", pCur->data);
    }
    getch();
}

//========================================================

void jumlahData(node *head) {
    int count = 0;
    node *pCur;

    if (head == NULL) {
        printf("Jumlah data di linked list: 0");
    } else {
        pCur = head;
        do {
            count++;
            pCur = pCur->next;
        } while (pCur != head);
        printf("Jumlah data di linked list: %d", count);
    }
    getch();
}

//========================================================

void sumData(node *head) {
    int sum = 0;
    node *pCur;

    if (head == NULL) {
        printf("Jumlah total semua data: 0");
    } else {
        pCur = head;
        do {
            sum += pCur->data;
            pCur = pCur->next;
        } while (pCur != head);
        printf("Jumlah total semua data: %d", sum);
    }
    getch();
}

//========================================================

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    if (head == NULL) {
        printf("List kosong\n");
    } else {
        pWalker = head;
        do {
            printf("%d -> ", pWalker->data);
            pWalker = pWalker->next;
        } while (pWalker != head);
        printf("Kembali ke awal\n");
    }
    getch();
}
