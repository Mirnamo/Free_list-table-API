#include <stdio.h>
#include <string.h>
#include <stdint.h>

//I want to create a function that creates the table
//this structure is useful to change into what elements you need
typedef struct FreeNode{
  size_t header;
  struct FreeNode *next;
    
} FreeNode;

//the function needs to return the table intialized using calloc
//the function takes the number of elements needed to intialize the table 
FreeNode **create_table(size_t size){
    if(size <= 0){
        return NULL;
    }
    //calloc takes the number of elemnts and the size of the element
    //calloc ensures that each element is set to 0 and next pointer is NUll
   FreeNode **table = calloc(size, sizeof(FreeNode *));
   //if allocation failed
   if(table == NULL){
    return NULL;
   }
   //else return table created
   return table;
}

//create function to return size of the elements in each element in the array table
size_t sizeof_list(FreeNode **table){
    if(table == NULL){
        return 0;
    }
    size_t count = 0;
    for(size_t i = 0; table[i] != NULL; i++){
      FreeNode *current = table[i];
      while(current != NULL){
         count++;
         current = current->next;
      }
    }
    return count;
}

//create a function to get the head of the element at the list
FreeNode *retreive_head(FreeNode **table, size_t index){
    if(table == NULL){
        return NULL;
    }
    if(index < 0){
        return NULL;
    }
    return table[index];
}

//create a function to append an element in the array at an index
void append_node(FreeNode **table, size_t index, size_t header) {
    // Create a new node
    if(table == NULL){
        return;
    }
    if(index < 0){
        return;
    }
    if(header <= 0){
        return;
    }
    FreeNode *new_node = calloc(1, sizeof(FreeNode));
    if (new_node == NULL) {
        return;
    }
    new_node->header = header;
    new_node->next = NULL;

    // If the list at the index is empty, set the new node as the head
    if (table[index] == NULL) {
        table[index] = new_node;
    } else {
        // Traverse to the end of the list
        FreeNode *current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        // Append the new node at the end
        current->next = new_node;
    }
}

//function to add at the beginning of the array
void change_header(FreeNode **table, size_t index, size_t size){
    if(table == NULL){
        return;
    }
    if(index < 0){
        return;
    }
    if(size <= 0){
        return;
    }
    FreeNode *new_head = calloc(1, sizeof(FreeNode));
    if(new_head == NULL){
        return;
    }
    new_head->header = size;
    new_head->next = table[index];
    //update table
    table[index] = new_head;
}

// Function to insert a node at a specific position in the list at a specific index in the table
void insert_node(FreeNode **table, size_t table_index, size_t index, size_t header) {
    if (table == NULL || header <= 0) {
        return;
    }

    FreeNode *new_node = (FreeNode *)calloc(1, sizeof(FreeNode));
    if (new_node == NULL) {
        return;
    }
    new_node->header = header;

    // If inserting at the beginning or if the list is empty
    if (index == 0 || table[table_index] == NULL) {
        new_node->next = table[table_index];
        table[table_index] = new_node;
        return;
    }

    // Traverse to the position before the insertion point
    FreeNode *current = table[table_index];
    for (size_t i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            break; // Reached end of list before reaching the desired index
        }
        current = current->next;
    }

    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
}

//function to delete element the head and return it
FreeNode *remove_head(FreeNode **table, size_t index){
    if(table == NULL){
        return NULL;
    }
    if(index < 0){
        return NULL;
    }
    FreeNode *head = table[index];
    table[index] = table[index]->next;
    return head;
}

//function to just delete the head
void delete_head_only(FreeNode **table, size_t index){
    if(table == NULL){
        return;
    }
    if(index < 0){
        return;
    }
    table[index] = table[index]->next;
}

//pop element at the end of the array
void pop(FreeNode **table, size_t index) {
    if (table == NULL || table[index] == NULL) {
        return;
    }

    FreeNode *current = table[index];
    FreeNode *previous = NULL;

    // Traverse to the end of the list
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // If the list has only one element
    if (previous == NULL) {
        free(table[index]);
        table[index] = NULL;
    } else {
        free(current);
        previous->next = NULL;
    }
}

//function to delete an element at the given index
void delete_node(FreeNode **table, size_t table_index, size_t index) {
    if (table == NULL || table[table_index] == NULL) {
        return;
    }

    FreeNode *current = table[table_index];
    FreeNode *previous = NULL;

    // If deleting the first node
    if (index == 0) {
        table[table_index] = current->next;
        free(current);
        return;
    }

    // Traverse to the node before the deletion point
    for (size_t i = 0; i < index; i++) {
        if (current == NULL) {
            return; 
        }
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return;
    }

    // Delete the node
    previous->next = current->next;
    free(current);
}
