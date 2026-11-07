#ifndef inverted_search_h
#define inverted_search_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Define a enum for failure and success operations
typedef enum{
    e_failure,
    e_success
}Status;

//Define a Sub Node Structure
typedef struct sub_node{
    int word_count;
    char file_name[25];
    struct sub_node *link;
}sub_node_t;

//Define a  Main Node Structure
typedef struct main_node{
    char word[100];
    int file_count;
    sub_node_t *sublink;
    struct main_node *link;
}main_node_t;

typedef struct node{
    int index;
    main_node_t *link;
}hash_t;

//For storing File mane in a linked List
typedef struct list{
    char name[25];
    struct list *link;
}List;

//Function prototypes
Status validate_args(char str[],int file_no);
Status create_database(List *head,hash_t hash[]);
Status display_database(hash_t hash[]);
Status save_database(hash_t hash[],char* filename);
Status search_database(hash_t hash[],char word[]);
Status update_database(hash_t hash[], List **indexed_head, List **indexed_tail);
Status validate_database_file(FILE *fp);
#endif

