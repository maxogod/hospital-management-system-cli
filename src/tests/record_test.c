#include <stdio.h>
#include "./record_test.h"
#include "../file_manager/file_manager.h"
#include "../records/record.h"

void test_record_creation() {

    record_t* rec = create_record("mapo", 251, 21032, "hypoglycemia", 50);

    add_new_record(HOSPITALIZATION_FILE, rec);

    destroy_record(rec);
    return;
}

void test_find_by_name() {

    char* name = "max";
    record_t* rec = find_record_by_name(HOSPITALIZATION_FILE, name);

    if (rec) {
        printf("%s,%d,%d,%s,%d\n", rec->name, rec->id, rec->phone_number, rec->reason, rec->cost);
    }

    destroy_record(rec);
    return;
}

void test_find_by_id() {

    long id = 340;
    record_t* rec = find_record_by_id(HOSPITALIZATION_FILE, id);

    if (rec) {
         printf("%s,%d,%d,%s,%d\n", rec->name, rec->id, rec->phone_number, rec->reason, rec->cost);
    }

    destroy_record(rec);
    return;
}

void test_get_all_records() {
    record_array_t* records = get_all_records(HOSPITALIZATION_FILE);
    
    for (int i = 0; i < records->len; i++) {
        printf("%s,%d\n", records->all_records[i]->name, records->all_records[i]->id);
    }

    destroy_record_array(records);
}

