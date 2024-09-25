



//atividade dia 25/09
#include <stdio.h>
#include <stdlib.h>

struct No
{
    int data;
    struct No* next;
};

void initialize(struct No** head_ref) {
    *head_ref = NULL;
}

void insertAtBeginning(struct No** head_ref, int new_data) {
    struct No* new_no = malloc(sizeof(struct No));

    new_no->data = new_data;

    // Apontar o próximo do novo nó para o nó atual da cabeça
    new_no->next = *head_ref;

    *head_ref = new_no;
} 

void printList(struct No* no) {
    while (no != NULL) {
        printf("%d -> ", no->data);
        no = no->next;
    }
    printf("NULL\n");
}

void reverse(struct No** head_ref) {
    struct No* prev = NULL;
    struct No* current = *head_ref;
    struct No* next = NULL;

    while (current != NULL) {
        next = current->next; 
        current -> next = prev; 
        prev = current;       
        current = next;       
    }
    *head_ref = prev; 
}


int main(){
    struct No* head = NULL;
    
    initialize(&head);

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printList(head);

    reverse(&head);

    return 0;
}