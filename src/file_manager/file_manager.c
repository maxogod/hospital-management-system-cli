#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../records/record.h"
#include "file_manager.h"
#include "../utils/utils.h"

void add_new_record(const char* filename, record_t* record) {

    FILE* file = fopen(filename, "a+");
    if (!file) return;

    fseek(file, 0, SEEK_END); // Move to the end of the file
    long filePos = ftell(file);

    if (filePos == 0) {
        fprintf(file, "name,id,phone number,reason,cost\n");
        fflush(file); // make sure to write the first line
    }

    fprintf(file, "%s,%ld,%d,%s,%d\n", record->name, record->id, record->phone_number, record->reason, record->cost);

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

record_array_t* get_all_records(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    int records_number = (lines_in_file(filename) - 1);
    record_array_t* records = create_record_array(records_number);
 
    char line[256];
    fgets(line, sizeof(line), file); // skip header line

    while (fgets(line, sizeof(line), file)) { 
        line[strcspn(line, "\n")] = '\0';

        char* name = strtok(line, ",");
        long id = atol(strtok(NULL, ","));
        int phone_number = atoi(strtok(NULL, ","));
        char* reason = strtok(NULL, ",");
        int cost = atoi(strtok(NULL, ",")); 

        record_t* record = create_record(name, id, phone_number, reason, cost); 
        add_record_to_array(records, record);
    }

    fclose(file); 
    return records;
}

void clear_file(const char* filename) {

    remove(filename);
    return;
}

void move_record_to_history(const char* filename, long id) { 

    record_array_t* records = get_all_records(filename);
    if (!records) return;

    clear_file(filename);
    record_t* deleted_record = NULL;

    for (int i = 0; i < records->len; i++) {
        record_t* record = records->all_records[i];
        if (record->id != id) {
            add_new_record(filename, record);
        } else {
            deleted_record = record;
        }
    }

    if (deleted_record) {
        add_new_record(HISTORY_FILE, deleted_record);
    } 
    destroy_record_array(records);
}

