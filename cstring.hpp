//
//  cstring.hpp
//  Task 1 by Koval Pavlo
//
//  Created by Павло Коваль on 30.07.2021.
//

#ifndef cstring_hpp
#define cstring_hpp

#include <stdlib.h>
#include <string.h>

typedef char* String;

/* Initializes list */
void StringListInit(char*** list);

/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list);

/* Inserts value at the end of the list. */
void StringListAdd(char** list, String str);

/* Removes all ocurences of str. */
void StringListRemove(char** list, String str);

/* Returns the number of items in the list. */
int StringListSize(char** list);

/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, String str);

/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list);

/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, String before, String after);

/* Sorts the list of strings in ascending order */
void StringListSort(char** list);

#endif /* cstring_hpp */
