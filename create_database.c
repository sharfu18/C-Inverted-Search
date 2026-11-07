#include "inverted_search.h"

Status create_database(List *head,hash_t hash[]){
    List *temp = head;
    int index;
    while (temp != NULL){
        FILE *fp = fopen(temp->name, "r");
        if(fp == NULL){
            printf("ERROR : Unable to open the file\n");
            return e_failure;
        }
        char word[100];
        while (fscanf(fp, "%99s", word) == 1){
            //check if first character is Alphabet or not
            if(word[0] >= 'a' && word[0] <= 'z'){
                index = word[0] - 'a';
            }
            else if(word[0] >= 'A' && word[0] <= 'Z'){
                index = word[0] - 'A';
            }
            //Special index which is kept for special characters
            else{
                index = 26;
            }
            main_node_t *main = hash[index].link;
            main_node_t *prev = NULL;
            //Search for the existing word
            while(main != NULL){
                if(strcmp(main->word,word) == 0){
                    break;
                }
                prev = main;
                main = main->link;
            }
            //if word already exists
            if(main != NULL){
                sub_node_t *sub = main->sublink;
                sub_node_t *sub_prev = NULL;
                //Search for the existing file name
                while(sub != NULL){
                    if(strcmp(sub->file_name,temp->name) == 0){
                        break;
                    }
                    sub_prev = sub;
                    sub = sub->link;
                }
                //If Sub != NULL Means it is present so increment count
                if(sub != NULL){
                    sub->word_count++;
                }
                //Same word but present in different file
                else{
                    sub_node_t *newSub = malloc(sizeof(sub_node_t));
                    if(newSub == NULL){
                        fclose(fp);
                        return e_failure;
                    }
                    strcpy(newSub->file_name,temp->name);
                    newSub->link = NULL;
                    newSub->word_count = 1;
                    sub_prev->link = newSub;//Link with previous sub node
                    main->file_count++; // increment file count in main node
                }
            }
            //Word doesnot exist
            else{
                //create main node
                main_node_t *newMain = malloc(sizeof(main_node_t));
                if(newMain == NULL){
                    fclose(fp);
                    return e_failure;
                }
                newMain->file_count = 1;
                newMain->link = NULL;
                newMain->sublink = NULL;
                strcpy(newMain->word,word);

                //create sub node
                sub_node_t *newSub = malloc(sizeof(sub_node_t));
                if(newSub == NULL){
                    fclose(fp);
                    return e_failure;
                }
                newSub->link = NULL;
                newSub->word_count = 1;
                strcpy(newSub->file_name,temp->name);
                newMain->sublink = newSub;

                //Link this main Node with previous main Node
                if(prev == NULL){
                    hash[index].link = newMain;
                }
                else{
                    prev->link = newMain;
                }
            }
        }
        fclose(fp);
        temp = temp->link;
    }
    return e_success;
}
