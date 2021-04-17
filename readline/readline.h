#pragma once

typedef struct _COMMAND_LIST {
    struct _COMMAND_LIST* Next;
    char* Buffer;
    struct _COMMAND_LIST* Child;
}COMMAND_LIST, *PCOMMAND_LIST;

typedef struct _HISTORY_LIST {
    struct _HISTORY_LIST* Blink;
    struct _HISTORY_LIST* Flink;
    char* Buffer;
}HISTORY_LIST, *PHISTORY_LIST;

void Lock();
void UnLock();
void CommandLineRecover();
int AddCommand(const char* command);
int AddChildCommand(int num, char* Parent, ...);
int AddHistory(const char* command);
char* readline(const char* commandline);