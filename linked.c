#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
} node;

struct NODE* newnode(int n) {
    node* newNode;
    newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = n;
    newNode->next = NULL;
    return newNode; // Add return statement
}

void append(node* head, node* newNode) {
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = newNode;
}

int main() {
    int i, j, n, num;
    printf("Enter the number of files: ");
    scanf("%d", &n);
    node* sb[n];
    int b[n];
    node* temp;

    for (i = 0; i < n; i++) {
        printf("Enter the block size of file-%d: ", i + 1);
        scanf("%d", &b[i]);
        printf("Enter the blocks: ");
        for (j = 0; j < b[i]; j++) {
            scanf("%d", &num);
            if (j == 0) { 
                sb[i] = newnode(num);
            } else {
                temp = newnode(num);
                append(sb[i], temp);
            }
        }
    }

   printf("no\t\tblock length\tstarting block\t ending\n");
	for(i=0;i<n;i++){
		temp=sb[i];
		while(temp->next!=NULL){
			temp=temp->next;
		}
		printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,b[i],sb[i]->data,temp->data);
	}

    return 0;
}

