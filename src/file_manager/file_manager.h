#ifndef FILE_MANAGER_H

#define HOSPITALIZATION_FILE "hospitalizations.csv"
#define CONSULTATION_FILE "consultations.csv"

void add_new_record(const char* filename, record_t* record);

record_t* find_record_by_name(const char* filename, char* name);

record_t* find_record_by_id(const char* filename, long id);

#endif // FILE_MANAGER_H
