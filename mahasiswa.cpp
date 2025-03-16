#include "mahasiswa.h"

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <malloc.h>
#include "boolean.h"

boolean isEmpty(address p) {
    return (p == NULL);
}

void Create_Node(address *p) {
    *p = (address) malloc(sizeof(Mahasiswa));
}

void Isi_Node(address *p, char *nama, int nilai) {
    if (*p != NULL) {
        strcpy((*p)->nama, nama);
        (*p)->nilai = nilai;
        (*p)->next = NULL;
    }
}

void Tampil_List(address p) {
    while (p != NULL) {
        printf("%s - %d\n", p->nama, p->nilai);
        p = p->next;
    }
}

void Ins_Awal(address *p, address PNew) {
    if (PNew != NULL) {
        PNew->next = *p;
        *p = PNew;
    }
}

void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew;
    } else {
        address last = *p;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = PNew;
    }
}

void Ins_SortedByName(address *head, char *nama, int nilai) {
    address newNode = (address)malloc(sizeof(Mahasiswa));
    strcpy(newNode->nama, nama);
    newNode->nilai = nilai;
    newNode->next = NULL;
    
    if (*head == NULL || strcmp((*head)->nama, nama) > 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
address temp = *head;
    while (temp->next != NULL && strcmp(temp->next->nama, nama) < 0) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void TampilListDescending(address head) {
    if (!head) return;
    address sorted = NULL;
    while (head) {
        address newNode = (address)malloc(sizeof(Mahasiswa));
        strcpy(newNode->nama, head->nama);
        newNode->nilai = head->nilai;
        newNode->next = NULL;
        if (!sorted || newNode->nilai > sorted->nilai) {
            newNode->next = sorted;
            sorted = newNode;
        } else {
            address temp = sorted;
            while (temp->next && temp->next->nilai > newNode->nilai) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        head = head->next;
    }
    Tampil_List(sorted);
}

int hitungElements(address head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void copydiatas70(address L1, address *L2) {
    while (L1) {
        if (L1->nilai > 70) {
            Ins_SortedByName(L2, L1->nama, L1->nilai);
        }
        L1 = L1->next;
    }
}

void hapusDuplikasi(address *head) {
    address temp = *head;
    while (temp && temp->next) {
        if (strcmp(temp->nama, temp->next->nama) == 0) {
            address duplicate = temp->next;
            temp->next = temp->next->next;
            free(duplicate);
        } else {
            temp = temp->next;
        }
    }
}

void hapusList(address *head) {
    address temp;
    while (*head) {
        temp = *head;
        printf("\nMenghapus: %s dengan nilai %d\n ", temp->nama, temp->nilai);
        *head = (*head)->next;
        free(temp);
    }
}

address Search(address p, char *nama) {
    while (p != NULL) {
        if (strcmp(p->nama, nama) == 0) return p;
        p = p->next;
    }
    return NULL;
}

address BalikList(address p) {
    address prev = NULL, current = p, next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
#endif
