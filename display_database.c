#include "inverted_search.h"

Status display_database(hash_t hash[]){
    int found = 0;

    printf("\n========== INVERTED SEARCH DATABASE ==========\n\n");

    printf("%-8s %-16s %-13s %-15s %-10s\n",
           "Index", "Word", "File Count",
           "Filename", "Word Count");

    printf("---------------------------------------------------------------\n");

    for(int i = 0;i<27;i++){
        if(hash[i].link != NULL){
            main_node_t *temp_mainNode = hash[i].link;
            while(temp_mainNode != NULL){
                found = 1;
                //print main node contents

                char index[10];
                sprintf(index, "[%d]", i);

                sub_node_t *temp_subNode = temp_mainNode->sublink;
                int first = 1;

                while(temp_subNode != NULL){
                    //print sub node contents

                    if(first){
                        printf("%-8s %-16s %-13d %-15s %-10d\n",
                               index,
                               temp_mainNode->word,
                               temp_mainNode->file_count,
                               temp_subNode->file_name,
                               temp_subNode->word_count);

                        first = 0;
                    }
                    else{
                        printf("%-8s %-16s %-13s %-15s %-10d\n",
                               "", "", "",
                               temp_subNode->file_name,
                               temp_subNode->word_count);
                    }

                    temp_subNode = temp_subNode->link;
                }

                temp_mainNode = temp_mainNode->link;
            }
        }
    }

    if(!found){
        // printf("INFO : Database is empty\n");
        return e_failure;
    }
    printf("---------------------------------------------------------------\n");
    return e_success;
}