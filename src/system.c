#include <stdio.h>
#include "./records/record.h"
#include "./file_manager/file_manager.h"

int main(void) {

    record_t* rec = create_record("max", 340, 15032, "headache", 20);

    add_new_record(HOSPITALIZATION_FILE, rec);

    destroy_record(rec);

    return 0;
}
