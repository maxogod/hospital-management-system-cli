#ifndef IO_H
#define IO_H

#define MAX_INPUT_SIZE 100        

void home_component();

void register_record_component(const char* filename, char* record_type);

void remove_record_component(const char* filename, char* record_type);

void search_component();

void show_records_component();

void single_clear_component();

void clear_all_component();

#endif // IO_H
