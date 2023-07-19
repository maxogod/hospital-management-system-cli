#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./io.h"
#include "../records/record.h"
#include "../file_manager/file_manager.h"

void ascii_art() {
    printf(
            "\033[1;34m                                                                                                  \n"
            "                                                                                                  \n"
            "    ,---,.,-.----.             .--.--.                          ___                       ____   \n"
            "  ,'  .' |\\    /  \\           /  /    '.                      ,--.'|_                   ,'  , `. \n"
            ",---.'   |;   :    \\         |  :  /`. /                      |  | :,'               ,-+-,.' _ | \n"
            "|   |   .'|   | .\\ :         ;  |  |--`             .--.--.   :  : ' :            ,-+-. ;   , || \n"
            ":   :  |-,.   : |: |         |  :  ;_         .--, /  /    '.;__,'  /     ,---.  ,--.'|'   |  || \n"
            ":   |  ;/||   |  \\ :          \\  \\    `.    /_ ./||  :  /`./|  |   |     /     \\|   |  ,', |  |, \n"
            "|   :   .'|   : .  /           `----.   \\, ' , ' :|  :  ;_  :__,'| :    /    /  |   | /  | |--'  \n"
            "|   |  |-,;   | |  \\           __ \\  \\  /___/ \\: | \\  \\    `. '  : |__ .    ' / |   : |  | ,     \n"
            "'   :  ;/||   | ;\\  \\         /  /`--'  /.  \\  ' |  `----.   \\|  | '.'|'   ;   /|   : |  |/      \n"
            "|   |    \\:   ' | \\'        '--'.     /  \\  ;   : /  /`--'  /;  :    ;'   |  / |   | |`-'       \n"
            "|   :   .':   : :-'            `--'---'    \\  \\  ;'--'.     / |  ,   / |   :    |   ;/           \n"
            "|   | ,'  |   |.'                           :  \\  \\ `--'---'   ---`-'   \\   \\  /'---'            \n"
            "`----'    `---'                              \\  ' ;                      `----'                  \n"
            "                                              `--`                                                \033[0m\n"
            );
}

void creating_record(char* name, long id, int phone_number, char* reason, int cost, char* record_type) {
    system("cls");
    ascii_art();
    printf(
            "~~ %s\n\n"
            "\033[1;37m~ name: %s\n"
            "~ id: %d\n"
            "~ phone number: %d\n"
            "~ reason: %s\n"
            "~ cost: $%d\033[0m\n\n"
            "\033[1;32m[Y] to confirm\033[0m\n"
            "\033[1;31m[C] to cancel\033[0m\n\n",
            record_type, name, id, phone_number, reason, cost
            );
}

void home_component() {
    system("cls");
    ascii_art();
    printf(
            "~~ Hello, welcome to the hospital ER management system\n\n"
            "~ \033[1;33m[H] hospitalize patient\033[0m\n"
            "~ \033[1;33m[C] register consultation\033[0m\n"
            "~ \033[1;32m[D] discharge patient\033[0m\n"
            "~ \033[1;32m[R] remove consultation from waitlist\033[0m\n"
            "~ \033[1;35m[S] search record\033[0m\n"
            "~ \033[1;35m[A] all records of a type\033[0m\n"
            "~ \033[1;37m[x] clear a specific file\033[0m\n"
            "~ \033[1;37m[X] clear all\033[0m\n\n"
            "\033[1;31m[exit] to exit system\033[0m\n\n"
            );

}

void register_record_component(const char* filename, char* record_type) {
    char input[MAX_INPUT_SIZE];
    char* user_input = NULL;

    char* name = "\0";
    char* reason = "\0";
    long id = 0;
    int phone_number = 0;
    int cost = 0;
    
    creating_record(name, id, phone_number, reason, cost, record_type);

    while (1) {
        printf("Your input: ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            user_input = malloc(strlen(input) + 1);
            if (!user_input) {
                continue;
            }
            strcpy(user_input, input);

            if (strcmp(user_input, "Y") == 0) {
                free(user_input);

                if (name != "\0") {
                    free(name);
                }
                if (reason != "\0") {
                    free(reason);
                }

                record_t* record = create_record(name, id, phone_number, reason, cost);
                add_new_record(filename, record);

                destroy_record(record);
                return;
            } else if (strcmp(user_input, "C") == 0) {
                free(user_input);
                if (name != "\0") {
                    free(name);
                }
                if (reason != "\0") {
                    free(reason);
                }
                return;
            } else {
                if (strcmp(name, "\0") == 0) {
                    name = malloc(strlen(input) + 1);
                    if (!name) {
                        continue;
                    }
                    strcpy(name, user_input);

                } else if (id == 0) {
                    id = atol(user_input);
                } else if (phone_number == 0) {
                    phone_number = atoi(user_input);
                } else if (strcmp(reason, "\0") == 0) {
                    reason = malloc(strlen(input) + 1);
                    if (!reason) {
                        continue;
                    }
                    strcpy(reason, user_input);

                } else if (cost == 0) {
                    cost = atoi(user_input);
                }
                creating_record(name, id, phone_number, reason, cost, record_type);
            } 
            
            free(user_input);
            if (name != "\0") {
                free(name);
            }
            if (reason != "\0") {
                free(reason);
            }
            user_input = NULL; 
        } else {
            printf("System closed\n");
            return;
        }
    }
}

void discharge_component() {}

void remove_consultation_component() {}

void search_component() {}

void show_records_component() {}

void single_clear_component() {}

void clear_all_component() {}

