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
    // (len) int: Length of the list, i.e. the number of valid elements
    // (maxlen) int: The maximum number of elements that can currently be stored
} List;

List* makeList() {
    // Create a pointer to a new List structure using malloc
    // Initialize length and maxlength
    // Set the len
    // Set the maxlen (start at 2)
    // Create a pointer to a new integer array of size maxlen (using malloc)
    // Set the start equal to that pointer
    // Return the list pointer
}

/* Resize the list to a new maximum length */
void resizeList(List *list, int size) {
    // Assert that the size is greater than the current length
    // Reallocate the array with more space
    // Change the maxlen to the new maximum length
}

/* Add 'value' to the end of the list */
void pushList(List *list, int value) {
    // If not enough space, resize the list to two times its current size
    // Add the value to the end of the list
    // Increment the len by 1
}

/* Remove and return the last element of the list */
int popList(List *list) {
    // Assert the list has len greater than 0
    // Decrement the length by 1
    // Get the last value in the list
    // If the list size is now less than half its current maximum length,
    // resize the list to half its current maximum length
    // Return the last value
}

int getList(List *list, int index) {
    // Assert index is greater than or equal to 0 and less than the list len
    // Get the element at position 'index' in the list
}

void setList(List *list, int index, int value) {
    // Assert index is greater than or equal to 0 and less than the list len
    // Set the element at position 'index' to 'value'
}

int sumList(List *list) {
    // Return the sum of all valid elements
}

void freeList(List *list) {
    // Free the array space
    // Free the list space
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
