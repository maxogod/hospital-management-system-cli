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
    return NULL;
}

record_t* find_record_by_id(const char* filename, long id) {
    return NULL;
}

