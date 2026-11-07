#include "inverted_search.h"

Status validate_args(char str[],int file_no){
    char *ptr = strstr(str,".txt");
    //strcmp used to check whether .txt is at end or not
    if(ptr != NULL && strcmp(ptr,".txt") != 0){
        printf("ERROR : File %d Extension dosent contain .txt \n",file_no);
        return e_failure;
    }
    FILE *fp = fopen(str,"r");
    if(fp == NULL){
        printf("ERROR : File %d Not Found\n",file_no);
        return e_failure;
    }
    if(fgetc(fp) == EOF){
        printf("ERROR : No content in the file %d\n",file_no);
        fclose(fp);
        return e_failure;
    }
    fclose(fp);
    return e_success;
}