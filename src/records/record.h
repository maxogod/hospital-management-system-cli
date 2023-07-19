#ifndef RECORD_H
#define RECORD_H

typedef struct record {
    char* name;
    long id;
    int phone_number;
    char* reason;
    int cost;
} record_t;

record_t* create_record(char* name, long id, int phone_number, char* reason, int cost);

int modify_record(record_t* record, char* name, long id, int phone_number, char* reason, int cost);

void destroy_record(record_t* record);

typedef struct record_array {
    record_t** all_records;
    size_t len;
    size_t occupied;
} record_array_t;

record_array_t* create_record_array(size_t len);

void add_record_to_array(record_array_t* record_array, record_t* record);

void destroy_record_array(record_array_t* record_array);

#endif // RECORD_H
