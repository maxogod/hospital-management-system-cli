#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "record.h"

// RECORD_T

record_t* create_record(char* name, long id, int phone_number, char* reason, int cost) {

    record_t* new_record = malloc(sizeof(record_t));
    if (!new_record) {
        free(new_record);
        return NULL;
    }

    new_record->name = malloc(strlen(name) + 1);
    new_record->reason = malloc(strlen(reason) + 1);

    if (!new_record->name || !new_record->reason) {
        free(new_record->name);
        free(new_record->reason);
        free(new_record);
        return NULL;
    }

    strcpy(new_record->name, name);
    strcpy(new_record->reason, reason);

    new_record->id = id;
    new_record->phone_number = phone_number;
    new_record->cost = cost;
    
    return new_record;
}

int modify_record(record_t* record, char* name, long id, int phone_number, char* reason, int cost) {

    if (!record) return 1;
    
    record->name = name;
    record->id = id;
    record->phone_number = phone_number;
    record->cost = cost;
    record->reason= reason;
    
    return 0;
}

void destroy_record(record_t* record) {
    if (!record) return;

    free(record->name);
    free(record->reason);
    free(record);
}

// RECORD_ARRAY_T

record_array_t* create_record_array(size_t len) {
    record_array_t* new_record_array = malloc(sizeof(record_array_t));
    if (!new_record_array) {
        free(new_record_array);
        return NULL;
    }

    new_record_array->all_records = calloc(len, sizeof(record_t*));

    if (!new_record_array->all_records) {
        free(new_record_array->all_records);
        free(new_record_array);
        return NULL;
    }

    new_record_array->len = len;
    new_record_array->occupied = 0;

    return new_record_array;
}

void add_record_to_array(record_array_t* record_array, record_t* record) {
    if (record_array->occupied == (record_array->len)) return;
 
    record_array->all_records[record_array->occupied] = record;    
    record_array->occupied = record_array->occupied + 1;
}

void destroy_record_array(record_array_t* record_array) { 
    if (!record_array) return;
    for (int i = 0; i < record_array->len; i++) {
        destroy_record(record_array->all_records[i]);
    }

    free(record_array->all_records);
    free(record_array);
}

