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

#endif // RECORD_H
