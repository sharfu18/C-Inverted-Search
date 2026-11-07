#include "inverted_search.h"

Status search_database(hash_t hash[],char word[]){
    int index;
    if(word[0] >= 'a' && word[0] <= 'z'){
        index = word[0] - 'a';
    }
    else if(word[0] >= 'A' && word[0] <= 'Z'){
        index = word[0] - 'A';
    }
    else{
        index = 26;
    }
    main_node_t *temp = hash[index].link;
    if(hash[index].link != NULL){
        while(temp != NULL){
            if(strcmp(temp->word,word) == 0){
                printf("\nWord %s is Present in %d files \n",word,temp->file_count);
                sub_node_t *temp1 = temp->sublink;
                while(temp1 != NULL){
                    printf("\n In %s %d times \n",temp1->file_name,temp1->word_count);
                    temp1 = temp1->link;
                }
                return e_success;
            }
            temp = temp->link;
        }
    }
    return e_failure;
}