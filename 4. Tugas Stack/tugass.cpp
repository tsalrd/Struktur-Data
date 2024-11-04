#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    int count;
    Node* top;
};

// Fungsi untuk membuat stack baru
void createStack(Stack& stack) {
    stack.count = 0;
    stack.top = NULL;
}

// Fungsi untuk menambah elemen ke dalam stack (Push)
bool push(Stack& stack, int data) {
    Node* newPtr = new Node;
    if (newPtr == NULL) {
        cout << "Stack penuh. Tidak dapat menambah elemen." << endl;
        return false; // Stack penuh jika tidak ada memori
    }

    newPtr->data = data;
    newPtr->next = stack.top;
    stack.top = newPtr;
    stack.count++;
    return true;
}

// Fungsi untuk menghapus elemen dari stack (Pop)
bool pop(Stack& stack, int& dataOut) {
    if (stack.top == NULL) {
        cout << "Stack kosong. Tidak ada elemen untuk dihapus." << endl;
        return false; // Stack kosong
    }

    Node* dltPtr = stack.top;
    dataOut = stack.top->data;
    stack.top = stack.top->next;
    delete dltPtr;
    stack.count--;
    return true;
}

// Fungsi untuk melihat elemen teratas stack tanpa menghapusnya (Top)
bool stackTop(const Stack& stack, int& dataOut) {
    if (stack.top == NULL) {
        cout << "Stack kosong. Tidak ada elemen di atas." << endl;
        return false; // Stack kosong
    }

    dataOut = stack.top->data;
    return true;
}

// Fungsi untuk memeriksa apakah stack kosong
bool isEmpty(const Stack& stack) {
    return stack.top == NULL;
}

// Fungsi untuk memeriksa apakah stack penuh
bool isFull() {
    Node* testPtr = new Node;
    if (testPtr == NULL) {
        return true; // Tidak ada memori, stack penuh
    }
    delete testPtr;
    return false;
}

// Fungsi untuk mendapatkan jumlah elemen dalam stack
int stackCount(const Stack& stack) {
    return stack.count;
}

// Fungsi untuk menghancurkan stack
void destroyStack(Stack& stack) {
    while (stack.top != NULL) {
        Node* temp = stack.top;
        stack.top = stack.top->next;
        delete temp;
    }
    stack.count = 0;
}

// Fungsi utama untuk menguji stack
int main() {
    Stack stack;
    createStack(stack);

    // Menambahkan elemen ke stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    cout << "Jumlah elemen dalam stack: " << stackCount(stack) << endl;

    // Melihat elemen teratas stack
    int topValue;
    if (stackTop(stack, topValue)) {
        cout << "Elemen teratas stack: " << topValue << endl;
    }

    // Menghapus elemen dari stack
    int poppedValue;
    if (pop(stack, poppedValue)) {
        cout << "Elemen yang dihapus: " << poppedValue << endl;
    }

    cout << "Jumlah elemen dalam stack setelah pop: " << stackCount(stack) << endl;

    // Menghancurkan stack
    destroyStack(stack);
    cout << "Stack telah dikosongkan. Jumlah elemen sekarang: " << stackCount(stack) << endl;

    return 0;
}

