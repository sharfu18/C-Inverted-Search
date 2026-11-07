#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inverted_search.h"

int main(void){
    List *indexed_head = NULL;
    List *indexed_tail = NULL;

    //create array of structures
    hash_t hash[27];
    for (int i = 0; i < 27; i++){
        hash[i].index = i;
        hash[i].link = NULL;
    }
    //display menu
    int db_loaded = 0;
    int choice;
    while (1){
        printf("\nEnter the choice:\n");
        printf("1. Create DataBase\n");
        printf("2. Display DataBase\n");
        printf("3. Update DataBase\n");
        printf("4. Search a Word in DataBase\n");
        printf("5. Save DataBase\n");
        printf("6. Exit\n");

        scanf("%d", &choice);
        switch (choice){
            case 1:
            {
                char filename[100];
                printf("Enter the filename: ");
                scanf("%99s", filename);

                // Validate filename
                if (validate_args(filename, 1) == e_failure){
                    printf("ERROR : Invalid file\n");
                    break;
                }

                // Check duplicate filenames
                List *temp = indexed_head;
                int found = 0;
                while (temp != NULL){
                    if (strcmp(temp->name, filename) == 0){
                        found = 1;
                        break;
                    }
                    temp = temp->link;
                }
                if (found){
                    printf("INFO : File already indexed\n");
                    break;
                }

                List *newNode = malloc(sizeof(List));
                if (newNode == NULL){
                    printf("Memory allocation failed\n");
                    break;
                }
                strcpy(newNode->name, filename);
                newNode->link = NULL;
                if (create_database(newNode, hash) == e_success){
                    // Add filename to indexed list
                    if (indexed_head == NULL){
                        indexed_head = newNode;
                        indexed_tail = newNode;
                    }
                    else{
                        indexed_tail->link = newNode;
                        indexed_tail = newNode;
                    }
                    db_loaded = 1;
                    printf("INFO : Database Created Successfully\n");
                }
                else{
                    printf("ERROR : Database Creation Failed\n");
                    free(newNode);
                }
                break;
            }
            case 2:
                // display_database();
                if(display_database(hash) == e_success){
                    printf("\nINFO : DataBase Displayed Successfully\n");
                }
                else{
                    printf("INFO : DataBase is empty\n");
                }
                break;

            case 3:
                // update_database();
                if(db_loaded){
                    printf("INFO : DataBase already loaded\n");
                }
                else{
                    if(update_database(hash,&indexed_head,&indexed_tail) == e_success){
                        db_loaded = 1;
                    }
                    else{
                        printf("ERROR : Unable to Update DataBase\n");
                    }
                }
                break;
            case 4:
                // search_database();
                {
                    char search_Word[100];
                    printf("Enter a word to search\n");
                    scanf("%99s",search_Word);
                    if(search_database(hash,search_Word) == e_failure){
                        printf("INFO : Word not Found\n");
                    }
                }
                break;
            case 5:
                // save_database();
                char filename[100];
                printf("Enter backup file name : \n");
                scanf("%s",filename);
                if(save_database(hash,filename) == e_success){
                    printf("INFO : DataBase Saved Successfully\n");
                }
                else{
                    printf("ERROR : Unable to Save the DataBase\n");
                }
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
