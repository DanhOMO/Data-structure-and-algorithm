#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct node{
    char data[100];
    node *next;
};
typedef struct node Node;
Node* khoiTaoNode(char x[]){
    Node *p = new Node;
    if(p == NULL) return NULL;
    strcpy(p->data,x);
    p->next = NULL;
    return p;
}
Node *head = NULL;
void themDau(Node *p){
    if(head == NULL){
        head = p; return;
    }
    p->next = head;
    head = p;
}
void xuatNode(){
    Node *temp = head;
    while(temp != NULL){
        printf("%s ", temp->data);
        temp = temp->next;
    }
}
void themCuoi(Node *p){
    if(head == NULL) {
        head = p; return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = p;
}
void themGiua(Node *p,int k){
    if(head == NULL){
        head = p; return;
    }
    Node *temp = head; int count = 0;
    while(temp != NULL){
        if(++count == k){
            p->next = temp->next;
            temp->next = p;
            return;
        }
        temp = temp->next;
    }
}
void xoaPhanTuDau(){
    if(head == NULL) return;
    Node *temp = head;
    head = head->next;
    delete temp;
}
void xoaPhanTuCuoi(){
    if(head == NULL) return;
    Node *temp = head; 
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
void xoaPhanTuGiua(int k){
    if(head == NULL){
        return ;
    }
    Node *temp = head; int count = 0;
    while(temp != NULL){
        if(++count == k){
             Node *p = temp->next;
                temp->next = temp->next->next;
                delete p; return;
        }
        temp = temp->next;
    }
}
void nhapNode(){
    
}
void doiChoTrucTiep() {
    if (head == NULL) return;
    Node* i = head;
    while (i->next != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (strcmp(i->data, j->data) > 0) {
                char temp[100];
                strcpy(temp, i->data);
                strcpy(i->data, j->data);
                strcpy(j->data, temp);
            }
            j = j->next;
        }
        i = i->next;
    }
}
void hoanVi(char *a , char *b){
    char temp[100] ;
    strcpy(temp , a);
    strcpy(a , b);
    strcpy(b , temp);
}
void doiChoTrucTiep1(){
    Node *i = head;
    while(i->next != NULL){
        Node *j = i->next;
        while(j != NULL){
            if(strcmp(i->data,j->data) > 0){
                hoanVi(i->data, j->data);
            } j = j->next;
        }i = i->next;
    }
}
void sapXepBubbleSort(){
    // thuat toan sap xep noi bot
   // D0 moi lan lap thi se giam di 1 phan tu nhung code cua ban khong dap an duoc yeu cau do
   // ban co the hien lai thuat toan nay mot cac chinh xac
    if(head == NULL) return;
//    Node *p = head;
//    Node *q = NULL;
//     Node *end = NULL;
//     while(end != head->next){
//         p = head;
//         while(p->next != end){
//             q = p->next;
//             if(strcmp(p->data,q->data) > 0){
//                 char temp[100];
//                 strcpy(temp,p->data);
//                 strcpy(p->data,q->data);
//                 strcpy(q->data,temp);
//             }
//             p = p->next;
//         }
//         end = p;
//     }
    Node *temp = head;
    Node *i = NULL;
    Node *end = NULL;
    while(end != head->next){
        i= head;
        while(i->next != end){
            Node *j = i->next;
            if(strcmp(i->data,j->data) > 0){
                char temp[100];
                strcpy(temp,i->data);
                strcpy(i->data,j->data);
                strcpy(j->data,temp);
            }
            i = i->next;
        } end = i;
    }
}
void sapXepNoiBot(){
    Node *i = head;
    Node *j = NULL ;
    Node *end = NULL;
    while(i != NULL){
        j = head;
        while(j->next != end){
            if(strcmp((j->data), (j->next->data)) > 0){
                hoanVi(j->data, j->next->data);
            } j = j->next;
        } end = j;
        i = i->next;
    }
}
void chonTrucTiep1(){
    Node *i = head;
    Node *j = NULL;
    Node *min = NULL;
    while(i->next != NULL){
        min  = i;          
        j = i->next;
        while(j != NULL){
            if(strcmp(min->data, j->data) > 0){
                min = j;
            }j = j->next;

        }
        if(strcmp(min->data, i->data) != 0){
            hoanVi(min->data, i->data);
        }
        i = i->next;
    }
}
void chonTrucTiep(){
    Node *p = head;
    Node *q = NULL;
    Node *min = NULL;
    while(p->next != NULL){
        min = p ;
        q = p->next;
        while(q != NULL){
            if(strcmp(min->data,q->data) > 0){
                min = q;
            }
            q = q->next;
        }
        char temp[100];
        strcpy(temp,p->data);
        strcpy(p->data,min->data);
        strcpy(min->data,temp);
        p = p->next;
    }
}
void chenTruCTiepLinkedList() {
    if (head == NULL || (head)->next == NULL) {
        return; // Already sorted or empty list
    }

    Node* sorted = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;

        // Insert current node into sorted list
        if (sorted == NULL || strcmp(current->data, sorted->data) < 0) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && strcmp(current->data, temp->next->data) > 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    head = sorted; // Update the head of the sorted list
}
void chenTrucTiep1(){
    Node *p = head;
    Node *q = NULL;
    while(p != NULL){
        Node *next = p->next;
        if(q == NULL || strcmp(p->data, q->data) < 0){
            p->next = q;
            q = p;
        }
         else{
            Node *temp = q;
            while(temp->next != NULL && strcmp(p->data, temp->next->data) > 0){
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
         }
            p = next;
    }
    head = q;
    }
void chenTruCTiep(char *a[], int n) {
    for (int i = 1; i < n; i++) {
        char* ai = a[i];
        int j = i - 1;
        while (j >= 0 && strcmp(ai, a[j]) < 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = ai;
    }
}
void chenTrucTiep2(){
    Node *i = head;
    Node *j = NULL;
    while(i->next != NULL){
    Node *ai = i->next;
    j = head;
    while(j != ai ){
        if(strcmp(ai->data , j->data) < 0)
        hoanVi(ai->data , j->data);
        j = j->next;
    }
    i = i->next;
    }
}
char* upperToCase(char *a){
    char *result = strdup(a);
    for (int i = 0; i < strlen(result); i++)
    {
            result[i] = toupper(result[i]);
    }
    return result;
}
Node* timKiemTienTinh(char *targe){
    Node *temp = head;
    while(temp != NULL && strstr(upperToCase(temp->data),upperToCase(targe)) == NULL){
        temp = temp->next;
    }
    if(temp == NULL){
     return NULL;
    }
    return temp;
}
bool hasCycle(Node *a) {
    if(a == NULL || a->next == NULL) return false;
    Node *slow = a;
    Node *fast = a;
    while(slow != fast){
        if(fast == NULL || fast->next == NULL) return false;
        slow = slow->next;
        fast = fast->next;
    }return true;
}
Node *ReveredLinkedList(){
    if(head == NULL || head->next == NULL) return head;
    Node *i = head;
    while(i->next != NULL){
        Node *nextNode = i->next;
        i->next = nextNode->next;
        nextNode->next = head;
        head = nextNode;
    }return head;
}
int main(){
    int n;
    printf("Nhap so luong node: "); scanf("%d",&n);
    fflush(stdin);
    for(int i = 0;i < n;i++){
        char x[100];
       printf("Nhap gia tri node thuw %d: ",i+1); fgets(x , sizeof(x), stdin);
        x[strcspn(x , "\n")] = '\0';
       Node *p = khoiTaoNode(x);
        themCuoi(p);
    }

    // // themGiua(khoiTaoNode("5"),2);
    // // xuatNode();
    // // xoaPhanTuGiua(2);
    // // printf("\n");
    sapXepNoiBot();
    // xuatNode();
    // printf("\n4Sau khi resered\n");
    // ReveredLinkedList();
    xuatNode();
    // char temp[] = "Nguyen,Cong,Danh";
    // char *token = strtok(temp , ",");
    // while(token != NULL){
    // char result[] = "";
    // strcat(result , token);
    // printf("%s ", result);
    // token = strtok(NULL , ",");
    
}