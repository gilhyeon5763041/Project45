#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head->link);
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

ListNode* delete_first(ListNode* head)
{
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    ListNode* temp = head->link;
    if (head == temp) {
        free(head);
        return NULL;
    }
    head->link = temp->link;
    free(temp);
    return head;
}

ListNode* delete_last(ListNode* head)
{
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    ListNode* temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }
    if (temp == head) {
        free(head);
        return NULL;
    }
    temp->link = head->link;
    free(head);
    return temp;
}

int main() {

    ListNode* head = NULL;

    int menu = -1;
    while (menu != 0) {
        printf("\nMenu\n");
        printf("(1) Insert First\n");
        printf("(2) Insert Last\n");
        printf("(3) Delete First\n");
        printf("(4) Delete Last\n");
        printf("(5) Print List\n");
        printf("(0) Exit\n");
        printf("Enter the menu: ");
        scanf("%d", &menu);

        switch (menu) {
        case 1: {
            int num;
            printf("Enter a number: ");
            scanf("%d", &num);
            head = insert_first(head, num);
            break;
        }
        case 2: {
            int num;
            printf("Enter a number: ");
            scanf("%d", &num);
            head = insert_last(head, num);
            break;
        }
        case 3: {
            head = delete_first(head);
            break;
        }
        case 4: {
            head = delete_last(head);
            break;
        }
        case 5: {
            printf("List: ");
            print_list(head);
            break;
        }
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid menu. Please select again.\n");
            break;
        }
    }

    return 0;
}
