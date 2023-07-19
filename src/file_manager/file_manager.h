#ifndef FILE_MANAGER_H

#include "../records/record.h"

#define HOSPITALIZATION_FILE "hospitalizations.csv"
#define CONSULTATION_FILE "consultations.csv"
#define HISTORY_FILE "history.csv"

void add_new_record(const char* filename, record_t* record);

record_t* find_record_by_name(const char* filename, char* name);

record_t* find_record_by_id(const char* filename, long id);

void move_record_to_history(const char* filename, long id);

// returns all records from file as an array
record_array_t* get_all_records(const char* filename);

void clear_file(const char* filename);

#endif // FILE_MANAGER_H
