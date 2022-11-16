#include <stdlib.h> 
#include <stdio.h> 
#include <assert.h> 

/*
This program implements a simple 'List' structure and some related functions
which can be used to manipulate it.  The List represents a variable sized array
that you can add elements to, or remove elements from.
First fill in the 'List' structure
You should implement the functions in this order:
1. makeList
2. resizeList
3. pushList
4. popList
5. getList
6. setList
7. sumList
8. freeList
Roughly, each comment can be converted to one or two lines of code that you
need.
Note that the test is not exhaustive and only tests basic functionality.
*/

typedef struct List {
    // (start) int*: The pointer to an integer array
int *start;
    // (len) int: Length of the list, i.e. the number of valid elements
int Len;
    // (maxlen) int: The maximum number of elements that can currently be stored
int maxLen;

} List;

List* makeList() {
    // Create a pointer to a new List structure using malloc
  List *list = (List *)malloc(sizeof(List));
    // Initialize length and maxlength
    // Set the len
  list -> Len = 0;
    // Set the maxlen (start at 2)
  list -> maxLen = 2;
    // Create a pointer to a new integer array of size maxlen (using malloc)
  int *arr = malloc(sizeof(int) * list -> maxLen);
    // Set the start equal to that pointer
  list -> start = arr;
    // Return the list pointer
  return list;
}

/* Resize the list to a new maximum length */
void resizeList(List *list, int size) {
    // Assert that the size is greater than the current length
  assert(size > list -> Len);
  int *arr = malloc(sizeof(int) * size);
    // Reallocate the array with more space
  for (int x = 0; x < size; x++) {
  arr[x] = list -> start[x];
  }
  
    // Change the maxlen to the new maximum length
  list -> start = arr;
  list -> maxLen = size;
}

/* Add 'value' to the end of the list */
void pushList(List *list, int value) {
    // If not enough space, resize the list to two times its current size
  if (list-> maxLen <= list -> Len) {
    resizeList(list, list -> maxLen * 2);
  }
    // Add the value to the end of the list
  list -> start [list -> Len] = value;
    // Increment the len by 1
  list -> Len++;
}

/* Remove and return the last element of the list */
int popList(List *list) {
    // Assert the list has len greater than 0
  assert(list -> Len > 0);
    // Decrement the length by 1
  list -> Len--;
    // Get the last value in the list
  int value = list -> start [list -> Len];
    // If the list size is now less than half its current maximum length,
  if ((list -> Len) < (list -> maxLen)/2) {
    // resize the list to half its current maximum length
    resizeList(list, (list -> maxLen)/2);
  }
    
    // Return the last value
  return value;
}

int getList(List *list, int index) {
    // Assert index is greater than or equal to 0 and less than the list len
  assert((index >= 0) && (index < list -> Len));
    // Get the element at position 'index' in the list
  int value = list -> start [index];
}

void setList(List *list, int index, int value) {
    // Assert index is greater than or equal to 0 and less than the list len
  assert((index >= 0) && (index < list -> Len));
    // Set the element at position 'index' to 'value'
  list -> start[index] = value;
}

int sumList(List *list) {
    // Return the sum of all valid elements
  int sumofelements = 0;
  for (int x = 0; x < list -> Len; x++) {
    sumofelements += list -> start[x]; 
  }
}

void freeList(List *list) {
    // Free the array space
  free(list -> start);
    // Free the list space
  free(list);
}

int main() {
    List *list = makeList();
    pushList(list, 1);
    pushList(list, 2);
    pushList(list, 3);
    assert(sumList(list) == 6);
    popList(list);
    popList(list);
    popList(list);
    for (int n = 0; n < 100; n++) {
        pushList(list, n);
        assert(getList(list, n) == n);
    }
    for (int n = 99; n >= 0; n--) {
        int m = popList(list);
        assert(m == n);
    }
    freeList(list);
}
