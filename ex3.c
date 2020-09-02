#include <stdio.h>
#include <stdlib.h>
//node structure
struct Node {
  int data;
  struct Node* next;
};
//function that prints a list
void print_list(struct Node* head){
  if (head==NULL){
     printf("the list is empty\n"); 
  }
  //untill we reach the end, print elements
  while(head!=NULL){
    printf("%d\t", head->data);
    head=head->next;
  }
}
//function to delete an element with a certain value
void delete_node(struct Node **head_r, int data) 
{ 
    // Store head node 
    struct Node *prev; 
    struct Node* temp = *head_r;
    
    // If head is to be deleted
    if (temp != NULL && temp->data == data) 
    {  //change address stored in a head
        *head_r = temp->next;   
        free(temp);               
        return; 
    } 
   
    // Search for the key to be deleted
    while (temp != NULL && temp->data != data) 
    {   //track the previous node
        prev = temp; 
        temp = temp->next; 
    } 
    
    // If there is no such key in the list
    if (temp == NULL) 
    {printf("element does not exist");
    return; }
    
    // delete the node by delinking
    prev->next = temp->next; 
    
    
    free(temp);  // Free memory 
} 
//inserting the node at the first position
void first(struct Node** head_ref, int data) 
{ 
    //allocate memory
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    //put the data into the node
    new_node->data = data; 
  
   //consider the next of our node to the next of head
    new_node->next = (*head_ref); 
  
    //set head to new node
    (*head_ref) = new_node; 
}
//insetring an element into the list after particular one
struct Node* insert_node(struct Node* prev_node, int data) 
{ 
    //check if the node we want to insert after exists
    if (prev_node == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return NULL; 
    } 
  
    //allocate new memory for storing the node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    //put the data
    new_node->data = data; 
  
    // insert the node into the linked list
    new_node->next = prev_node->next;
    prev_node->next = new_node; 
    return new_node;
  
} 
int main(void) {
  //create 2 main points of linked list: head and last
  struct Node* head = NULL;
  struct Node* last = NULL;
  //this variable allows to use several instructions on one lsit interactively
  int decision=1;
  //description of features
  printf("Choose the operation:\n");
  printf("a - display a list\n");
  printf("b - insert a node\n");
  printf("c - delete a node\n");
  printf("type in 1/0 to switch/stop\n");
  //while user wants to perform operations do:
  while (decision==1){
  //scan the command identifier and perform needed instuction
  char v;
  scanf("%c", &v);
     if (v== 'a')
        {print_list(head);}
    //for head i considered sequentiall adding, however, the fuction //allows to add after certain node
     if (v=='b'){
       //if list is empty
         if (head==NULL){
           printf("What's the first element?\n");
           //scan the first element 
           int num;
           scanf("%d", &num);
           //add first element
           first(&head, num);}
           //switch to add next or choose another instruction
           printf("Do you want to continue adding the elements: 1/0?\n");
           int cond;
           scanf("%d", &cond);
           while(cond){
             //add next element untill cnd=0(user stops operation)
           int num1;
           printf("What's the next element?\n");
           scanf("%d", &num1);
           //add new element store the link to in into last
           //add after last
           if(last==NULL){
           last=insert_node(head, num1);}
           else{
            last=insert_node(last, num1);
           }
           printf("Do you want to continue adding the elements: 1/0?\n");
           scanf("%d", &cond);
            }
     }
     //delete for c
    if(v=='c'){
      //define the data of node to delete
         printf("What element do you wanna delete?\n");
         int todel;
         scanf("%d", &todel);
         //call function
         delete_node(&head, todel);
         //switch condition 
         printf("Do you want to continue deleting the elements: 1/0?\n");
           int conddel;
           scanf("%d", &conddel);
           //if want to delete more enter the loop untill condell==0
           while(conddel){
          printf("What's the next element to delete?\n");
          //call function
           delete_node(&head, todel);
           //set condell again
           printf("Do you want to continue deleting the elements: 1/0?\n");
           scanf("%d", &conddel);
         }
    }
  //scans whether user wants to continue
  scanf("%d", &decision);}

  return 0; }