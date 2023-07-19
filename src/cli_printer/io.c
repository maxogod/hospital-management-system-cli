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

void removing_record(record_t* record, char* record_type) {
    system("cls");
    ascii_art();

    if (!record) {
        printf(
                "~~ %s\n\n"
                "\033[1;37m~ No records yet 'please type a (valid) id'\n\n"
                "\033[1;31m[C] to cancel\033[0m\n\n",
                record_type
                );
    } else {
        printf(
            "~~ %s\n\n"
            "\033[1;37m~ name: %s\n"
            "~ id: %d\n"
            "~ phone number: %d\n"
            "~ reason: %s\n"
            "~ cost: $%d\033[0m\n\n"
            "\033[1;32m[Y] to confirm\033[0m\n"
            "\033[1;31m[C] to cancel\033[0m\n\n",
            record_type, record->name, record->id, record->phone_number, record->reason, record->cost
            );
    }
}

void show_all_records(char* filename, record_array_t* records) {
    system("cls");
    ascii_art();

    if (strcmp(filename, "\0") != 0) {
        printf("Selected file - %s\n\n", filename);
        if (!records) {
            printf("\033[1;32mNo records to show..\033[0m\n");
        } else {
            for (int i = 0; i < records->len; i++) {
                record_t* record = records->all_records[i];
                printf(
                        "\033[1;37m~ name: %s\n"
                        "~ id: %d\n"
                        "~ phone number: %d\n"
                        "~ reason: %s\n"
                        "~ cost: $%d\033[0m\n\n"
                        "\033[1;31m- - - - - - - - -\033[0m\n\n",
                        record->name, record->id, record->phone_number, record->reason, record->cost
                        );
            }
        }
    }
    printf(
            "~~ Select a file\n\n"
            "~ \033[1;33m[H] hospitalization file\033[0m\n"
            "~ \033[1;33m[C] consultation file\033[0m\n"
            "~ \033[1;33m[O] history file\033[0m\n\n"
            "\033[1;31m[B] to go back\033[0m\n\n"
            );
}

void show_clear_file(char* filename) {
    system("cls");
    ascii_art();
    
    if (strcmp(filename, "\0") == 0) {
        printf(
            "~~ Select a file\n\n"
            "~ \033[1;33m[H] hospitalization file\033[0m\n"
            "~ \033[1;33m[C] consultation file\033[0m\n"
            "~ \033[1;33m[O] history file\033[0m\n\n"
            "\033[1;31m[B] to go back\033[0m\n\n"
            );
    } else if (strcmp(filename, "ALL") == 0) {
        printf(
                "~~ \033[1;33mAre you sure you want to delete *all files*? this action cannot be undone\033[0m\n\n"
                "\033[1;32m[Y] to confirm\033[0m\n"
                "\033[1;31m[B] to go back\033[0m\n\n"
                );
    } else {
        printf(
                "~~ \033[1;33mAre you sure you want to delete %s? this action cannot be undone\033[0m\n\n"
                "\033[1;32m[Y] to confirm\033[0m\n"
                "\033[1;31m[B] to go back\033[0m\n\n",
                filename
                );
    }
}

void show_search(char* filename, record_t* record, char* name, long id) {
    system("cls");
    ascii_art();

    if (strcmp(filename, "\0") == 0) {
        printf(
                "~~ Select a file to search\n\n"
                "~ \033[1;33m[H] hospitalization file\033[0m\n"
                "~ \033[1;33m[C] consultation file\033[0m\n"
                "~ \033[1;33m[O] history file\033[0m\n\n"
                "\033[1;31m[B] to go back\033[0m\n\n"
                );
    } else {
        if (!record) {
            printf(
            "~~ Searching in %s (type a name or an id)\n\n"
            "\033[1;37m~ name: %s\n"
            "~ id: %d\033[0m\n\n"
            "\033[1;31m[B] to go back\033[0m\n\n",
            filename, name, id
            );
        } else {
            printf(
            "~~ Searched in %s\n\n"
            "\033[1;37m~ name: %s\n"
            "~ id: %d\n"
            "~ phone number: %d\n"
            "~ reason: %s\n"
            "~ cost: $%d\033[0m\n\n"
            "\033[1;31m[B] to go back\033[0m\n\n",
            filename, record->name, record->id, record->phone_number, record->reason, record->cost
            );
        }
    }
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

                if (strcmp(name, "\0") != 0) {
                    free(name);
                }
                if (strcmp(reason, "\0") != 0) {
                    free(reason);
                }

                record_t* record = create_record(name, id, phone_number, reason, cost);
                add_new_record(filename, record);

                destroy_record(record);
                return;
            } else if (strcmp(user_input, "C") == 0) {
                free(user_input);
                if (strcmp(name, "\0") != 0) {
                    free(name);
                }
                if (strcmp(reason, "\0") != 0) {
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
            if (strcmp(name, "\0") != 0) {
                free(name);
            }
            if (strcmp(reason, "\0") != 0) {
                free(reason);
            }
            user_input = NULL; 
        } else {
            printf("System closed\n");
            return;
        }
    }
}

void remove_record_component(const char* filename, char* record_type) {
    char input[MAX_INPUT_SIZE];
    char* user_input = NULL;
    record_t* record = NULL;
 
    removing_record(record, record_type);

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
                if (!record) {
                    removing_record(record, record_type);
                    printf("nope\n");
                    continue;
                }

                move_record_to_history(filename, record->id);
                destroy_record(record);
                return;
            } else if (strcmp(user_input, "C") == 0) {
                free(user_input);
                destroy_record(record);
                return;
            } else {
                long id = atol(user_input);
                if (id) {
                    record = find_record_by_id(filename, id);
                }
                removing_record(record, record_type);
            } 
            
            free(user_input);
            if (record) {
                destroy_record(record);
            }
            user_input = NULL;
        } else {
            printf("System closed\n");
            return;
        }
    }
}

void search_component() {
    char input[MAX_INPUT_SIZE];
    char* user_input = NULL;

    char* name = "\0";
    long id = 0;
    record_t* record = NULL;
    char* filename = "\0";

    show_search("\0", record, name, id);

    while (1) {
        printf("Your input: ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            user_input = malloc(strlen(input) + 1);
            if (!user_input) {
                continue;
            }
            strcpy(user_input, input);

            if (strcmp(user_input, "H") == 0) {
                filename = malloc(strlen(HOSPITALIZATION_FILE) + 1);
                if (!filename) {
                    continue;
                }
                strcpy(filename, HOSPITALIZATION_FILE);
                free(user_input);
            } else if (strcmp(user_input, "C") == 0) {
                filename = malloc(strlen(CONSULTATION_FILE) + 1);
                if (!filename) {
                    continue;
                }
                strcpy(filename, CONSULTATION_FILE);
                free(user_input); 
            } else if (strcmp(user_input, "O") == 0) {
                filename = malloc(strlen(HISTORY_FILE) + 1);
                if (!filename) {
                    continue;
                }
                strcpy(filename, HISTORY_FILE);
                free(user_input);
            } else if (strcmp(user_input, "B") == 0) {
                free(user_input);
                if (strcmp(name, "\0") != 0) {
                    free(name);
                }
                if (strcmp(filename, "\0") != 0) {
                    free(filename);
                }
                if (record) {
                    destroy_record(record);
                }
                return;
            } else {
                if (strcmp(filename, "\0") == 0) {
                    continue;
                }
                if (atol(user_input) && strcmp(name, "\0") == 0) {
                    id = atol(user_input);
                    record = find_record_by_id(filename, id);
                } else if (strcmp(name, "\0") == 0) {
                    name = malloc(strlen(input) + 1);
                    if (!name) {
                        continue;
                    }
                    strcpy(name, user_input);
                    record = find_record_by_name(filename, name);
                }
            }
            show_search(filename, record, name, id);
            
            free(user_input);
            if (strcmp(name, "\0") != 0) {
                free(name);
            }
            if (strcmp(filename, "\0") != 0) {
                free(filename);
            }
            if (record) {
                destroy_record(record);
            }
            user_input = NULL;
        } else {
            printf("System closed\n");
            return;
        }
    }
}

void show_records_component() {
    char input[MAX_INPUT_SIZE];
    char* user_input = NULL;

    record_array_t* records = NULL;

    show_all_records("\0", records);

    while (1) {
        printf("Your input: ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            user_input = malloc(strlen(input) + 1);
            if (!user_input) {
                continue;
            }
            strcpy(user_input, input);

            if (strcmp(user_input, "H") == 0) {
                free(user_input);
                records = get_all_records(HOSPITALIZATION_FILE);
                show_all_records(HOSPITALIZATION_FILE, records);
            } else if (strcmp(user_input, "C") == 0) {
                free(user_input);
                records = get_all_records(CONSULTATION_FILE);
                show_all_records(CONSULTATION_FILE, records);
            } else if (strcmp(user_input, "O") == 0) {
                free(user_input);
                records = get_all_records(HISTORY_FILE);
                show_all_records(HISTORY_FILE, records);
            } else if (strcmp(user_input, "B") == 0) {
                free(user_input);
                if (records) {
                    destroy_record_array(records);
                }
                return;
            }
            
            free(user_input);
            if (records) {
                destroy_record_array(records);
            }
            user_input = NULL;
        } else {
            printf("System closed\n");
            return;
        }
    }
}

void single_clear_component() {
    char input[MAX_INPUT_SIZE];
    char* user_input = NULL;

    char* filename = "\0";
    show_clear_file(filename);

    while (1) {
        printf("Your input: ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = '\0';

            user_input = malloc(strlen(input) + 1);
            if (!user_input) {
                continue;
            }
            strcpy(user_input, input);

            if (strcmp(user_input, "H") == 0) {
                free(user_input);
                filename = malloc(strlen(HOSPITALIZATION_FILE) + 1);
                if (!filename) {
                    continue;
                }
                strcpy(filename, HOSPITALIZATION_FILE);
                show_clear_file(filename);
            } else if (strcmp(user_input, "C") == 0) {
                free(user_input);
                filename = malloc(strlen(CONSULTATION_FILE) + 1);
                if (!filename) {
                    continue;
                }
                strcpy(filename, CONSULTATION_FILE);
                show_clear_file(filename);
            } else if (strcmp(user_input, "O") == 0) {
                free(user_input);
                filename = malloc(strlen(HISTORY_FILE) + 1);
                if (!filename) {
                    continue;
                }
                strcpy(filename, HISTORY_FILE);
                show_clear_file(filename);
            } else if (strcmp(user_input, "Y") == 0) {
                free(user_input);
                if (strcmp(filename, "\0") == 0) {
                    continue;
                }
                clear_file(filename);
                printf("\033[1;32mDELETED %s\033[0m\n\n", filename);
            } else if (strcmp(user_input, "B") == 0) {
                free(user_input);
                if (strcmp(filename, "\0") != 0) {
                    free(filename);
                }
                return;
            }

            free(user_input);
            if (strcmp(filename, "\0") != 0) {
                free(filename);
            }
            user_input = NULL;
        } else {
            printf("System closed\n");
            return;
        }
    }
}

void clear_all_component() {
    char input[MAX_INPUT_SIZE];
    char* user_input = NULL;

    show_clear_file("ALL");

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
                clear_file(HOSPITALIZATION_FILE);
                clear_file(CONSULTATION_FILE);
                clear_file(HISTORY_FILE);
                printf("\033[1;32mDELETED %s - %s - %s\033[0m\n\n", HOSPITALIZATION_FILE, CONSULTATION_FILE, HISTORY_FILE);
            } else if (strcmp(user_input, "B") == 0) {
                free(user_input);
                return;
            }

            free(user_input);
            user_input = NULL;
        } else {
            printf("System closed\n");
            return;
        }
    }
}

