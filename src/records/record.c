#include <stdlib.h>
#include <stdio.h>
#include "record.h"

record_t* create_record(char* name, long id, int phone_number, char* reason, int cost) {

    record_t* new_record = malloc(sizeof(record_t));
    if (!new_record) return NULL;

    new_record->name = name;
    new_record->id = id;
    new_record->phone_number = phone_number;
    new_record->cost = cost;
    new_record->reason= reason;

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
    free(record);
}

