#include <stdio.h>

#define MAX 20

int hashTable[MAX];
int n;

/* function to insert key using Linear Probing */
void insert(int key)
{
    int index = key % n;

    if (hashTable[index] == -1)
    {
        hashTable[index] = key;
    }
    else
    {
        int i = 1;
        while (hashTable[(index + i) % n] != -1)
        {
            i++;
        }
        hashTable[(index + i) % n] = key;
    }
}

/* function to display hash table */
void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < n; i++)
    {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}

int main()
{
    int key, choice;

    printf("Enter size of hash table: ");
    scanf("%d", &n);

    /* Initialize hash table */
    for (int i = 0; i < n; i++)
        hashTable[i] = -1;

    do
    {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            display();
            break;
        }
    } while (choice != 3);

    return 0;
}
