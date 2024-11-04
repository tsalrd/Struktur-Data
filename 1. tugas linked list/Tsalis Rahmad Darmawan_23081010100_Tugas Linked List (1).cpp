#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================
//Nama  : Tsalis Rahmad Darmawan
//NPM   : 23081010100
//Kelas : Struktur Data E081

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Fungsi yang baru ditambahkan
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void sumData(node *head);

// Fungsi yang sudah ada sebelumnya
void tambahAwal(node **head);
void tambahData(node **head);
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
        if (pilih == '1')
            tambahAwal(&head);
        else if (pilih == '2')
            tambahData(&head);
        else if (pilih == '3')
            tambahAkhir(&head);
        else if (pilih == '4') {
            tranverse(head);
            getch();
        } else if (pilih == '5')
            hapusAwal(&head);
        else if (pilih == '6')
            hapusTengah(&head);
        else if (pilih == '7')
            hapusAkhir(&head);
        else if (pilih == '8')
            cariData(head);
        else if (pilih == '9')
            jumlahData(head);
        else if (pilih == '10')
            sumData(head);
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;
        *head = pNew;
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
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
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
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head) {
    node *pTemp;

    system("cls");
    if (*head == NULL) {
        printf("List kosong");
    } else {
        pTemp = *head;
        *head = (*head)->next;
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
    while (pCur != NULL && pCur->data != pos) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan");
    } else {
        if (pPrev != NULL) {
            pPrev->next = pCur->next;
        } else {
            *head = pCur->next;
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
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Data akhir berhasil dihapus");
    } else {
        pCur = *head;
        pPrev = NULL;
        while (pCur->next != NULL) {
            pPrev = pCur;
            pCur = pCur->next;
        }
        pPrev->next = NULL;
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
    while (pCur != NULL && pCur->data != bil) {
        pCur = pCur->next;
    }

    if (pCur == NULL) {
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

    pCur = head;
    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data di linked list: %d", count);
    getch();
}

//========================================================

void sumData(node *head) {
    int sum = 0;
    node *pCur;

    pCur = head;
    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }

    printf("Jumlah total semua data: %d", sum);
    getch();
}

//========================================================

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    pWalker = head;
    while (pWalker != NULL) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("NULL\n");
}
