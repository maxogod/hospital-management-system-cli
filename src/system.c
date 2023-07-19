#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./tests/record_test.h"
#include "./records/record.h"
#include "./file_manager/file_manager.h"
#include "./utils/utils.h"
#include "./cli_printer/io.h"

int main() {

    char input[MAX_INPUT_SIZE];
    char* user_input = NULL;

    while (1) {
        home_component();

        printf("Your input: ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            user_input = malloc(strlen(input) + 1);
            if (!user_input) {
                continue;
            }
            strcpy(user_input, input);

            if (strcmp(user_input, "H") == 0) {
                register_record_component(HOSPITALIZATION_FILE, "Hospitalizing patient");
            } else if (strcmp(user_input, "C") == 0) {
                register_record_component(CONSULTATION_FILE, "Registering new consultation");
            } else if (strcmp(user_input, "D") == 0) {
                remove_record_component(HOSPITALIZATION_FILE, "Discharging patient");
            } else if (strcmp(user_input, "R") == 0) {
                remove_record_component(CONSULTATION_FILE, "Removing consultation from waitlist");
            } else if (strcmp(user_input, "S") == 0) {
                search_component();
            } else if (strcmp(user_input, "A") == 0) {
                show_records_component();
            } else if (strcmp(user_input, "x") == 0) {
                single_clear_component();
            } else if (strcmp(user_input, "X") == 0) {
                clear_all_component();
            } else if (strcmp(user_input, "exit") == 0) {
                free(user_input);
                return 0;
            } 
            
            free(user_input);
            user_input = NULL;
        } else {
            printf("System closed\n");
            return 0;
        }
    }

    return 0;
}

