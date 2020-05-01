#include <stdio.h>
#include "funcheader.h"

int main() {
    Node *Head = NULL;
    int size = getValue("Enter The Size of Cicular List to Create: ");
    Head = createNodeList(Head, size);
    printCList(&Head);
    printf("The Length of Circular list is: %d\n", Listlength(&Head));
    printf("Node Is Inserted at the Start: \n");
    insertNodeAtStrt(&Head);
    printCList(&Head);
    printf("The Length of Cirular list is: %d\n", Listlength(&Head));
    printf("Node Is Inserted at the End of List: \n");
    insertNodeAtEnd(&Head);
    printCList(&Head);
    printf("The Length of Cirular list is: %d\n", Listlength(&Head));
    printf("Insert Node At the Position: \n");
    int position = getValue("Enter the Position: ");
    insertNodeAtPos(&Head, position);
    printCList(&Head);
    printf("The Length of Cirular list is: %d\n", Listlength(&Head));
    printf("Deleting Node From the Start: \n");
    deleteNodeFrmStrt(&Head);
    printCList(&Head);
    printf("The Length of Cirular list is: %d\n", Listlength(&Head));
    printf("Deleting Node From the End:\n");
    deleteNodeFrmEnd(&Head);
    printCList(&Head);
    printf("The Length of Cirular list is: %d\n", Listlength(&Head));
    position = getValue("Enter The Position To Delete the Position Node: ");
    deleteNodeFrmPos(&Head, position);
    printCList(&Head);
    printf("The Length of Cirular list is: %d\n", Listlength(&Head));
    printf("Deleting Complete Circular List: \n");
    deleteCompleteCList(&Head);
    printCList(&Head);
    printf("The Length of Cirular list is: %d\n", Listlength(&Head));
    return 0;
}