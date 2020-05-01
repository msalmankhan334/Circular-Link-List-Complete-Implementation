typedef struct Node
{
    int number;
    struct Node *next;
}Node;
int getValue(char *str);
Node *createNodeList(Node *head, int size);
void printCList(Node **head);
void insertNodeAtStrt(Node **head);
int Listlength(Node **head);
void insertNodeAtEnd(Node **head);
void insertNodeAtPos(Node **head, int pos);
void deleteNodeFrmStrt(Node **head);
void deleteNodeFrmEnd(Node **head);
void deleteNodeFrmPos(Node **head, int pos);
void deleteCompleteCList(Node **head);