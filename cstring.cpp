//
//  cstring.cpp
//  Task 1 by Koval Pavlo
//
//  Created by Павло Коваль on 30.07.2021.
//

#include "cstring.hpp"

/*
 std::cout << std::endl;
 
 tempNode[0] == NULL ? std::cout << "TEMP: NULL" << std::endl
                 : std::cout << "TEMP: " << tempNode[0] << std::endl;
 
 prevNode[0] == NULL ? std::cout << "PREV: NULL" << std::endl
                 : std::cout << "PREV: " << prevNode[0] << std::endl;

currentNode[0] == NULL ? std::cout << "CURRENT: NULL" << std::endl
                 : std::cout << "CURRENT: " << currentNode[0] << std::endl;
 */

/* Initializes list */
void StringListInit(char*** list)
{
    /*
    Func init not an first node, but root node
    Root node - is used as an pointer to linked list
    */
    

    *(list) = (char**)malloc(sizeof(char*) * 2);
    
    /*
     @ node[0] - data
     @ node[1] - next
    */

    (*list)[0] = NULL;
    (*list)[1] = NULL;
}

/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list)
{
    if ( list == NULL ) return;
    
    char** nextNode = nullptr;

    while ( nextNode != NULL )
    {
        /*
         1:: giving to an <next> adress of next node
         2:: deleting current node
         3:: <list> become a saved node in a variable <next>
        */
        nextNode = (char**)(*list)[1];
        free((*list)[0]);
        free(*list);
        *list = nextNode;
    }

    free(nextNode);
    nextNode = NULL;
    
    list = NULL;
}

/* Inserts value at the end of the list. */
void StringListAdd(char** list, String str)
{
    /* if linked list doesn`t exist func will exit*/
    if ( list == NULL )
        return;
    
    /* creating new node */
    char** newNode;
    newNode = (char**)malloc(sizeof(char*) * 2);
    
    /* if it doesn't exist, func will stop*/
    if (newNode == NULL)
        return;
    
    char** currentNode = list;
    
    /* until we reach last element of the node it will continue going*/
    while( currentNode[1] != NULL )
        /*giving addres of next element*/
        currentNode = (char**)currentNode[1];

    /*we're saving to last node addres of our new node*/
    currentNode[1] = (char*)newNode;
    
    /*moving to new node and giving it a new data and telling that it is an last element*/
    currentNode = (char**)currentNode[1];
    
    currentNode[0] = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(currentNode[0], str);
    currentNode[1] = NULL;
    
}

/* Removes all ocurences of str. */
void StringListRemove(char** list, String str)
{
    /* if linked list doesn`t exist func will exit*/
    if ( list == NULL )
        return;
    
    char** currentNode = (char**)list[1];
    char** prevNode = list;
    
    while ( prevNode[1] != NULL )
    {
       /*
         1:: loop will continue going until reaches end of the list
         2:: if our current node's data IS equal to <str> READ @2
         3:: if our current node's data IS NOT equal to <str> READ @3
       */
        
        if ( !strcmp(str, currentNode[0]) )
        {
            /*
              ---@2
                it will save to <previousNode>, next node's addres
             
                |previous node| -> |current node| -> |next node|
                |previous node| -> |next node|
                
            */
            prevNode[1] = currentNode[1];
            
            free(currentNode[0]);
            free(currentNode);
            
            currentNode[0] = NULL;
            currentNode = NULL;
            
            currentNode = (char**)prevNode[1];
            
        } else
        {
            /*
              ---@3
                it will just move list forward by one element
                |p node| -> |c node| -> |n node|
                            |p node| -> |c node| -> |n node|
                
            */
            prevNode = currentNode;
            currentNode = (char**)currentNode[1];
        }
    }
}

/* Returns the number of items in the list. */
int StringListSize(char** list)
{
    const int listIsNotInit = -2; /* value which means that list wasn't init */
    
    /* if linked list doesn`t exist func will exit*/
    if ( list == NULL )
        return listIsNotInit;
    
    int size = 0;
    
    char** currentNode = list;
    
    while( currentNode[1] != NULL )
    {
        /*
         1:: loop will continue going until reaches end of the list
         2:: moving to next node
         3:: incresing size by 1
         */
        currentNode = (char**)currentNode[1];
        size++;
    }

    return size;
}

/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char** list, String str)
{
    const int valueNotFound = -1; /* value which means that value wasn't found */
    const int listIsNotInit = -2; /* value which means that list wasn't init */
        
    /* if linked list doesn`t exist func will exit*/
    if (list == NULL)
        return listIsNotInit;
    
    int size = 0;
    char** currentNode = (char**)list[1];
    
    while ( currentNode != NULL )
    {
        /*
        1:: loop will continue going until reaches end of the list
        2:: if our current node's data IS equal to <str> READ @2
        3:: if our current node's data IS NOT equal to <str> and loop is ended READ @3
        */
        
        if ( !strcmp(str, currentNode[0]) )
        {
            /*
                 ---@2
                 it will return index of the element
             */
            return size;
        }
    
        
        size++;
        currentNode = (char**)currentNode[1];
        
    }
    /* if loop doesn't found str that user was looking for, it will return: - 1*/

    return valueNotFound;
}

/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char** list)
{
    /* if linked list doesn`t exist func will exit*/
    if ( list == NULL )
        return;
    
    char** currentNode = list;
    char** prevNode = list;
    char** tempNode;
    
    while ( currentNode[1] != NULL )
    {
        currentNode = (char**)currentNode[1];
        prevNode = currentNode;
        tempNode = (char**)currentNode[1];
        
        while ( prevNode[1] != NULL )
        {
            /*
              1:: loop will continue going until reaches end of the list
              2:: if our <tempNode> data IS equal to <currenNode[0]> READ @2
              3:: if our <tempNode> data IS NOT equal to <currenNode[0]>  READ @3
            */
            
            if ( !strcmp(currentNode[0], tempNode[0]) )
            {
                /*
                  ---@2
                    it will save to <previousNode>, next node's addres
                 
                    |previous node| -> |temp node| -> |next node|
                    |previous node| -> |next node|
                    
                */
                prevNode[1] = tempNode[1];
                
                free(tempNode[0]);
                free(tempNode);
                
                tempNode[0] = NULL;
                tempNode = NULL;
                
                tempNode = (char**)prevNode[1];
                
            } else
            {
                /*
                  ---@3
                    it will just move list forward by one element
                    |p node| -> |t node| -> |n node|
                                |p node| -> |t node| -> |n node|
                    
                */
                prevNode = tempNode;
                tempNode = (char**)tempNode[1];
            }
        }

    }
}

/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char** list, String before, String after)
{
    /* if linked list doesn`t exist func will exit*/
    if (list == NULL)
        return;
    
    char** currentNode = (char**)list[1];
    
    while ( currentNode != NULL )
    {
        /*
          1:: loop will continue going until reaches end of the list
          2:: if our <currentNode> data IS equal to <before> READ @2
          3:: if our <tempNode> data IS NOT equal to <currenNode[0]>  READ @3
        */
        
        if ( !strcmp(before, currentNode[0]) )
        {
            /*
              ---@2
                it will change <currentNode[0]> data to <after>
            */
            strcpy(currentNode[0], after);
        }
    
        
        currentNode = (char**)currentNode[1];
        
    }
}

/* Sorts the list of strings in ascending order */
void StringListSort(char** list)
{
    int N = StringListSize(list);
    char**  currentNode = (char**)list[1];
    char** tempNode;
    
    for ( int i = 0; i < N ; i++ )
    {
        /*
         1:: loop is going until we reaches last element
         2:: we chose element than we go into a second <j> loop
         3:: checking if condition
        */
        
        tempNode = (char**)currentNode[1];
        
        for ( int j = i + 1; j < N; j++ )
        {
            if ( currentNode[0][0] > tempNode[0][0] )
            {
                char* t = currentNode[0];
                currentNode[0] = tempNode[0];
                tempNode[0] = t;
            }
            tempNode = (char**)tempNode[1];
        }
        
        currentNode = (char**)currentNode[1];
    }
}

