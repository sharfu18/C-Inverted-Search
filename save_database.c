#include "inverted_search.h"

Status save_database(hash_t hash[],char* filename){
    FILE *fp = fopen(filename,"w");
    if (fp == NULL){
        return e_failure;
    }
    int found = 0;
    for(int i = 0;i<27;i++){
        if(hash[i].link != NULL){
            main_node_t *temp_mainNode = hash[i].link;
            while(temp_mainNode != NULL){
                found = 1;
                //save main node contents
                fprintf(fp, "#%d;%s;%d;",i,temp_mainNode->word,temp_mainNode->file_count);

                sub_node_t *temp_subNode = temp_mainNode->sublink;
                while(temp_subNode != NULL){
                    //save sub node contents
                    fprintf(fp, "%s;%d;",temp_subNode->file_name,temp_subNode->word_count);

                    temp_subNode = temp_subNode->link;
                }
                fprintf(fp,"#\n");
                temp_mainNode = temp_mainNode->link;
            }
        }
    }
    fclose(fp);
    if(!found){
        // printf("INFO : Database is empty\n");
        return e_failure;
    }
    return e_success;
}