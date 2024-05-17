# FreeNode Table Management Library

This library provides functions to create and manage a table of linked lists, where each list is composed of nodes of type `FreeNode`. Each node contains a header and a pointer to the next node. The library includes functions to create the table, add nodes, and perform various operations on the lists.

## Structure Definition

```c
typedef struct FreeNode {
    size_t header;
    struct FreeNode *next;
} FreeNode;
```

## Functions

### create_table

```c
FreeNode **create_table(size_t size);
```

- **Description**: Creates and initializes a table with the specified number of elements using `calloc`. Each element is a pointer to a `FreeNode`.
- **Parameters**: 
  - `size`: Number of elements in the table.
- **Returns**: A pointer to the initialized table, or `NULL` if memory allocation fails.

### sizeof_list

```c
size_t sizeof_list(FreeNode **table);
```

- **Description**: Calculates the total number of nodes in all lists in the table.
- **Parameters**: 
  - `table`: A pointer to the table.
- **Returns**: The total number of nodes.

### retreive_head

```c
FreeNode *retreive_head(FreeNode **table, size_t index);
```

- **Description**: Returns the head of the list at the specified index.
- **Parameters**: 
  - `table`: A pointer to the table.
  - `index`: The index of the list.
- **Returns**: A pointer to the head node of the list, or `NULL` if the table or index is invalid.

### append_node

```c
void append_node(FreeNode **table, size_t index, size_t header);
```

- **Description**: Appends a new node with the specified header value at the end of the list at the given index.
- **Parameters**: 
  - `table`: A pointer to the table.
  - `index`: The index of the list.
  - `header`: The header value for the new node.

### change_header

```c
void change_header(FreeNode **table, size_t index, size_t size);
```

- **Description**: Adds a new node with the specified header value at the beginning of the list at the given index.
- **Parameters**: 
  - `table`: A pointer to the table.
  - `index`: The index of the list.
  - `size`: The header value for the new node.

### insert_node

```c
void insert_node(FreeNode **table, size_t table_index, size_t index, size_t header);
```

- **Description**: Inserts a new node with the specified header value at the specified position in the list at the given index.
- **Parameters**: 
  - `table`: A pointer to the table.
  - `table_index`: The index of the list.
  - `index`: The position in the list where the new node should be inserted.
  - `header`: The header value for the new node.

### remove_head

```c
FreeNode *remove_head(FreeNode **table, size_t index);
```

- **Description**: Removes and returns the head node of the list at the specified index.
- **Parameters**: 
  - `table`: A pointer to the table.
  - `index`: The index of the list.
- **Returns**: A pointer to the removed head node, or `NULL` if the table or index is invalid.

### delete_head_only

```c
void delete_head_only(FreeNode **table, size_t index);
```

- **Description**: Deletes the head node of the list at the specified index.
- **Parameters**: 
  - `table`: A pointer to the table.
  - `index`: The index of the list.

### pop

```c
void pop(FreeNode **table, size_t index);
```

- **Description**: Removes the last node of the list at the specified index.
- **Parameters**: 
  - `table`: A pointer to the table.
  - `index`: The index of the list.

### delete_node

```c
void delete_node(FreeNode **table, size_t table_index, size_t index);
```

- **Description**: Deletes the node at the specified position in the list at the given index.
- **Parameters**: 
  - `table`: A pointer to the table.
  - `table_index`: The index of the list.
  - `index`: The position in the list of the node to be deleted.

## Usage Example

```c
#include <stdio.h>
#include <stdlib.h>
#include "freenode.h"  // Include the header file containing the above definitions

int main() {
    size_t size = 10;
    FreeNode **table = create_table(size);
    if (table == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    append_node(table, 0, 1);
    append_node(table, 0, 2);
    append_node(table, 0, 3);

    change_header(table, 0, 10);

    insert_node(table, 0, 1, 20);

    pop(table, 0);

    delete_node(table, 0, 1);

    printf("Total nodes in the table: %zu\n", sizeof_list(table));

    FreeNode *head = retreive_head(table, 0);
    if (head != NULL) {
        printf("Head of list at index 0: %zu\n", head->header);
    }

    for (size_t i = 0; i < size; i++) {
        FreeNode *current = table[i];
        while (current != NULL) {
            FreeNode *next = current->next;
            free(current);
            current = next;
        }
    }
    free(table);

    return 0;
}
```

## Compilation

To compile the example code:

```sh
gcc -o freenode_example freenode_example.c
```

Replace `freenode_example.c` with the name of your source file.

## License

This project is licensed under the MIT License.

---

This README provides a detailed overview of the library, including structure definitions, function prototypes, descriptions, parameters, return values, usage example, compilation instructions, and license information.
