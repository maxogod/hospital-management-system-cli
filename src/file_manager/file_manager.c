#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../records/record.h"
#include "file_manager.h"

void add_new_record(const char* filename, record_t* record) {

    FILE* file = fopen(filename, "a+");
    if (!file) return;

    fseek(file, 0, SEEK_END); // Move to the end of the file
    long filePos = ftell(file);

    if (filePos == 0) {
        fprintf(file, "name,id,phone number,reason,cost\n");
        fflush(file); // make sure to write the first line
    }

    fprintf(file, "%s,%d,%d,%s,%d\n", record->name, record->id, record->phone_number, record->reason, record->cost);

    fclose(file);
}

record_t* find_record_by_name(const char* filename, char* name) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    record_t* found_record = NULL;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        
        char* name_token = strtok(line, ",");
        if (name_token && strcmp(name_token, name) == 0) {
            long id = atol(strtok(NULL, ","));
            int phone_number = atoi(strtok(NULL, ","));
            char* reason = strtok(NULL, ",");
            int cost = atoi(strtok(NULL, ","));

            found_record = create_record(name_token, id, phone_number, reason, cost);
            break;
        }
    }
    fclose(file);
    return found_record;
}

record_t* find_record_by_id(const char* filename, long id) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    record_t* found_record = NULL;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        
        char* name = strtok(line, ",");
        long id_token = atol(strtok(NULL, ","));
        if (id_token && id == id_token) { 
            int phone_number = atoi(strtok(NULL, ","));
            char* reason = strtok(NULL, ",");
            int cost = atoi(strtok(NULL, ","));

            found_record = create_record(name, id_token, phone_number, reason, cost);
            break;
        }
    }
    fclose(file);
    return found_record;
}

