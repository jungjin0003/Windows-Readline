//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <direct.h>
//#include <conio.h>
//#include <time.h>
//#include <Windows.h>
//#include "readline.h"
//
//COMMAND_LIST* CommandList = NULL;
//HISTORY_LIST* HistoryList = NULL;
//HISTORY_LIST* CurrentHistory = NULL;
//
//PCRITICAL_SECTION ReadLine_CS;
//
//int count;
//int x;
//char* str;
//char* CommandLine;
//
//void Lock()
//{
//    if (ReadLine_CS == NULL)
//    {
//        ReadLine_CS = malloc(sizeof(CRITICAL_SECTION));
//        InitializeCriticalSection(ReadLine_CS);
//    }
//    EnterCriticalSection(ReadLine_CS);
//}
//
//void UnLock()
//{
//    LeaveCriticalSection(ReadLine_CS);
//}
//
//void CommandLineRecover()
//{
//    printf("%s%s", CommandLine, str);
//    x = count;
//}
//
//int AddCommand(const char* command)
//{
//    PCOMMAND_LIST temp = CommandList;
//    if (temp == NULL)
//    {
//        temp = (PCOMMAND_LIST)malloc(sizeof(COMMAND_LIST));
//        temp->NextNode = NULL;
//        temp->Buffer = command;
//        CommandList = temp;
//    }
//    else if (temp->NextNode == NULL)
//    {
//        temp->NextNode = (PCOMMAND_LIST)malloc(sizeof(COMMAND_LIST));
//        temp->NextNode->NextNode = NULL;
//        temp->NextNode->Buffer = command;
//    }
//    else
//    {
//        PCOMMAND_LIST NewCommand = (PCOMMAND_LIST)malloc(sizeof(COMMAND_LIST));
//        NewCommand->NextNode = NULL;
//        NewCommand->Buffer = command;
//        while (temp->NextNode)
//        {
//            temp = temp->NextNode;
//        }
//        temp->NextNode = NewCommand;
//    }
//
//    return 0;
//}
//
//int AddHistory(const char* command)
//{
//    PHISTORY_LIST temp = HistoryList;
//
//    if (temp == NULL)
//    {
//        temp = (PHISTORY_LIST)malloc(sizeof(HISTORY_LIST));
//        temp->Blink = NULL;
//        temp->Flink = NULL;
//        temp->Buffer = command;
//        HistoryList = temp;
//    }
//    else if (temp->Blink == NULL)
//    {
//        if (strcmp(temp->Buffer, command) != 0)
//        {
//            temp->Blink = (PHISTORY_LIST)malloc(sizeof(HISTORY_LIST));
//            temp->Blink->Flink = temp;
//            temp->Blink->Blink = NULL;
//            temp->Blink->Buffer = command;
//            HistoryList = temp->Blink;
//        }
//    }
//    else
//    {
//        while (temp->Blink)
//        {
//            temp = temp->Blink;
//        }
//
//        if (strcmp(temp->Buffer, command) != 0)
//        {
//            temp->Blink = (PHISTORY_LIST)malloc(sizeof(HISTORY_LIST));
//            temp->Blink->Flink = NULL;
//            temp->Blink->Blink = NULL;
//            temp->Blink->Buffer = command;
//        }
//    }
//
//    return 0;
//}
//
//char* GetHistory(BOOL check)
//{
//    PVOID ret = NULL;
//    char* buffer = NULL;
//
//    if (HistoryList == NULL)
//    {
//        return ret;
//    }
//    else if (CurrentHistory == NULL)
//    {
//        if (!check)
//        {
//            CurrentHistory = HistoryList;
//            buffer = (char*)malloc(strlen(CurrentHistory->Buffer) + 1);
//            strcpy(buffer, CurrentHistory->Buffer);
//            return buffer;
//        }
//        else
//        {
//            return NULL;
//        }
//    }
//
//    if (!check)
//    {
//        if (CurrentHistory->Flink == NULL)
//        {
//            ret = NULL;
//        }
//        else
//        {
//            CurrentHistory = CurrentHistory->Flink;
//            buffer = (char*)malloc(strlen(CurrentHistory->Buffer) + 1);
//            strcpy(buffer, CurrentHistory->Buffer);
//            ret = buffer;
//        }
//    }
//    else
//    {
//        if (CurrentHistory->Blink == NULL)
//        {
//            ret = CurrentHistory = NULL;
//        }
//        else
//        {
//            CurrentHistory = CurrentHistory->Blink;
//            buffer = (char*)malloc(strlen(CurrentHistory->Buffer) + 1);
//            strcpy(buffer, CurrentHistory->Buffer);
//            ret = buffer;
//        }
//    }
//
//    return ret;
//}
//
//char* BeforeHistory()
//{
//    return GetHistory(FALSE);
//}
//
//char* AfterHistory()
//{
//    return GetHistory(TRUE);
//}
//
//char* save(char* str, int ch, int x)
//{
//    int i = 0;
//    int len;
//    char* newstr;
//
//    len = str == NULL ? 0 : strlen(str);
//    // len = strlen(str);
//
//    /*if (ch == VK_BACK)
//    {
//        newstr = (char *)malloc(len + 1);
//        if (str != NULL)
//        {
//            strcpy(newstr, str);
//        }
//        newstr[len - 1] = NULL;
//    }
//    else
//    {
//        newstr = (char*)malloc(len + 2);
//        if (str != NULL)
//        {
//            strcpy(newstr, str);
//        }
//        newstr[len] = ch;
//        newstr[len + 1] = NULL;
//    }*/
//
//    /*if (ch == VK_BACK)
//    {
//        newstr = calloc(len, 1);
//        memcpy(newstr, str, len);
//        newstr[len - 1] = NULL;
//        free(str);
//    }
//    else
//    {
//        newstr = realloc(str, len + 2);
//        newstr[len] = ch;
//        newstr[len + 1] = NULL;
//    }*/
//
//    if (ch == VK_BACK)
//    {
//        newstr = calloc(len, 1);
//        for (; i < x - 1; i++)
//        {
//            newstr[i] = str[i];
//        }
//        for (int temp = i; temp < len; temp++)
//        {
//            newstr[temp] = str[temp + 1];
//            _putch(str[temp + 1]);
//        }
//        _putch(NULL);
//        for (; i < len + 1; i++)
//        {
//            _putch(VK_BACK);
//        }
//    }
//    else
//    {
//        newstr = calloc(len + 2, 1);
//        for (; i < x; i++)
//        {
//            newstr[i] = str[i];
//        }
//        newstr[i] = ch;
//        for (int temp = i; temp < len; temp++)
//        {
//            newstr[temp + 1] = str[temp];
//            _putch(str[temp]);
//        }
//        for (; i < len; i++)
//        {
//            _putch(VK_BACK);
//        }
//        /*newstr[len] = ch;
//        newstr[len + 1] = NULL;*/
//    }
//
//    /*if (str != NULL)
//    {
//        free(str);
//    }*/
//
//    free(str);
//
//    return newstr;
//}
//
//void Sort(const char* command)
//{
//}
//
//void Relation(const char* input)
//{
//    PCOMMAND_LIST temp = CommandList;
//
//    if (temp != NULL)
//    {
//        int len = input == NULL ? 0 : strlen(input);
//        do
//        {
//            if (strncmp(input, temp->Buffer, len) == 0)
//            {
//                printf("\n%s", temp->Buffer);
//            }
//        } while (temp = temp->NextNode);
//    }
//
//    printf("\n\n");
//}
//
//char* AutoComplete(char* input)
//{
//    char* str = NULL;
//    PCOMMAND_LIST temp = CommandList;
//    if (input == NULL || temp == NULL)
//    {
//        return NULL;
//    }
//    else
//    {
//        int len = strlen(input);
//        do
//        {
//            if (strncmp(input, temp->Buffer, len) == 0)
//            {
//                if (str == NULL)
//                {
//                    str = (char*)malloc(strlen(temp->Buffer) + 1);
//                    strcpy(str, temp->Buffer);
//                }
//                else
//                {
//                    free(str);
//                    return NULL;
//                }
//            }
//        } while (temp = temp->NextNode);
//
//        if (str != NULL)
//        {
//            free(input);
//        }
//
//        return str;
//    }
//}
//
//int Exec(const char* command)
//{
//    /*STARTUPINFOA si = { 0, };
//    PROCESS_INFORMATION pi = { 0, };
//    si.cb = sizeof(STARTUPINFOA);*/
//
//    int ret;
//
//    printf("[*] Exec : %s\n\n", command);
//
//    if (strncmp(command, "cd", 2) == 0)
//    {
//        ret = _chdir(command + 3);
//    }
//    else
//    {
//        ret = system(command);
//    }
//    // WaitForSingleObject(pi.hProcess, INFINITE);
//
//    puts("");
//
//    return ret;
//}
//
//char* readline(const char* commandline)
//{
//    if (ReadLine_CS == NULL)
//    {
//        ReadLine_CS = malloc(sizeof(CRITICAL_SECTION));
//        InitializeCriticalSection(ReadLine_CS);
//    }
//
//    clock_t time = INFINITE;
//    count = 0;
//    x = 0;
//    str = calloc(1, 1);
//    CommandLine = commandline;
//
//    // char* str = NULL;
//    printf("%s", commandline);
//    while (1)
//    {
//        int ch = _getch();
//        EnterCriticalSection(ReadLine_CS);
//        switch (ch)
//        {
//        case VK_BACK:
//            if (count != 0 && x != 0)
//            {
//                CurrentHistory = NULL;
//                _putch(ch);
//                _putch(NULL);
//                _putch(ch);
//                str = save(str, ch, x);
//                count -= 1;
//                x -= 1;
//            }
//            break;
//
//        case VK_TAB:
//            if (clock() - time < 190)
//            {
//                time = clock();
//                Relation(str);
//                printf("%s", commandline);
//                if (str != NULL)
//                {
//                    printf("%s", str);
//                }
//            }
//            else
//            {
//                time = clock();
//                char* AutoCommand = AutoComplete(str);
//                if (AutoCommand != NULL)
//                {
//                    str = AutoCommand;
//                    for (int i = 0; i < x; i++)
//                    {
//                        _putch(VK_BACK);
//                    }
//                    count = x = strlen(str);
//                    printf("%s", str);
//                }
//                else
//                {
//                    time = clock();
//                    Sleep(10);
//                }
//            }
//            {/*if (readline)
//            {
//                end = clock();
//                if (end - start < 190)
//                {
//                    Relation(str);
//                    printf("%s", commandline);
//                    if (str != NULL)
//                    {
//                        printf("%s", str);
//                    }
//                }
//                readline = 0;
//            }
//            else
//            {
//                char* AutoCommand = AutoComplete(str);
//                if (AutoCommand != NULL)
//                {
//                    //free(str);
//                    str = AutoCommand;
//                    for (int i = 0; i < count; i++)
//                    {
//                        _putch(8);
//                    }
//                    count = strlen(str);
//                    printf("%s", str);
//                }
//                else
//                {
//                    start = clock();
//                    readline = 1;
//                    Sleep(10);
//                }
//            }*/}
//            break;
//
//        case VK_RETURN:
//            if (count != 0)
//            {
//                AddHistory(str);
//                CurrentHistory = NULL;
//                _putch('\n');
//                return str;
//            }
//            _putch('\n');
//            printf("%s", commandline);
//            break;
//
//        case 0xE0:
//            ch = _getch();
//
//            switch (ch)
//            {
//            case 0x48:
//            {
//                char* BeforeCommand = BeforeHistory();
//
//                if (BeforeCommand != NULL)
//                {
//                    free(str);
//                    str = BeforeCommand;
//                    for (int i = 0; i < x; i++)
//                    {
//                        _putch(VK_BACK);
//                        _putch(NULL);
//                        _putch(VK_BACK);
//                    }
//                    count = x = strlen(str);
//                    printf("%s", str);
//                }
//                break;
//            }
//            case 0x50:
//            {
//                char* AfterCommand = AfterHistory();
//
//                for (int i = 0; i < x; i++)
//                {
//                    _putch(VK_BACK);
//                    _putch(NULL);
//                    _putch(VK_BACK);
//                }
//
//                free(str);
//                str = AfterCommand;
//
//                if (str == NULL)
//                {
//                    count = x = NULL;
//                }
//                else if (str != NULL)
//                {
//                    count = x = strlen(str);
//                    printf("%s", str);
//                }
//                else if (CurrentHistory != NULL)
//                {
//                    CurrentHistory = NULL;
//                    count = 0;
//                }
//
//                {/*if (AfterCommand != NULL)
//                {
//                    str = AfterCommand;
//                    for (int i = 0; i < count; i++)
//                    {
//                        _putch(VK_BACK);
//                        _putch(NULL);
//                        _putch(VK_BACK);
//                    }
//                    count = strlen(str);
//                    printf("%s", str);
//                }
//                else if (CurrentHistory != NULL)
//                {
//                    CurrentHistory = NULL;
//                    for (int i = 0; i < count; i++)
//                    {
//                        _putch(VK_BACK);
//                        _putch(NULL);
//                        _putch(VK_BACK);
//                    }
//                    count = 0;
//                    free(str);
//                    str = NULL;
//                }*/}
//                break;
//            }
//            case 0x4B:
//                if (x != 0)
//                {
//                    _putch(VK_BACK);
//                    x -= 1;
//                }
//                break;
//
//            case 0x4D:
//                if (x != count)
//                {
//                    _putch(str[x]);
//                    x += 1;
//                }
//                break;
//            }
//            break;
//
//        default:
//            _putch(ch);
//            str = save(str, ch, x);
//            CurrentHistory = NULL;
//            count += 1;
//            x += 1;
//            break;
//        }
//        LeaveCriticalSection(ReadLine_CS);
//    }
//}
//
//int main()
//{
//    AddCommand("sessions");
//    AddCommand("screenshot");
//    AddCommand("set");
//    AddCommand("use");
//
//    while (TRUE)
//    {
//        char* string = readline("test > ");
//
//        // printf("press : %s\n", string);
//
//
//        Exec(string);
//        // free(string);
//    }
//
//    system("pause");
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "readline.h"

COMMAND_LIST* CommandList = NULL;
HISTORY_LIST* HistoryList = NULL;
HISTORY_LIST* CurrentHistory = NULL;

PCRITICAL_SECTION ReadLine_CS;

int count;
int x;
char* str;
char* CommandLine;

void Lock()
{
    if (ReadLine_CS == NULL)
    {
        ReadLine_CS = malloc(sizeof(CRITICAL_SECTION));
        InitializeCriticalSection(ReadLine_CS);
    }
    EnterCriticalSection(ReadLine_CS);
}

void UnLock()
{
    LeaveCriticalSection(ReadLine_CS);
}

void CommandLineRecover()
{
    printf("%s%s", CommandLine, str);
    x = count;
}

int AddCommand(const char* command)
{
    PCOMMAND_LIST temp = CommandList;
    if (temp == NULL)
    {
        temp = (PCOMMAND_LIST)malloc(sizeof(COMMAND_LIST));
        temp->Next = NULL;
        temp->Buffer = command;
        temp->Child = NULL;
        CommandList = temp;
    }
    else if (temp->Next == NULL)
    {
        temp->Next = (PCOMMAND_LIST)malloc(sizeof(COMMAND_LIST));
        temp->Next->Next = NULL;
        temp->Next->Buffer = command;
        temp->Next->Child = NULL;
    }
    else
    {
        PCOMMAND_LIST NewCommand = (PCOMMAND_LIST)malloc(sizeof(COMMAND_LIST));
        NewCommand->Next = NULL;
        NewCommand->Buffer = command;
        NewCommand->Child = NULL;
        while (temp->Next)
        {
            temp = temp->Next;
        }
        temp->Next = NewCommand;
    }

    return 0;
}

int AddChildCommand(int num, char* Parent, ...)
{
    if (CommandList == NULL)
    {
        AddCommand(Parent);
    }

    PCOMMAND_LIST COMMANDLIST = CommandList;
    PCOMMAND_LIST temp = CommandList;

    va_list ap;

    va_start(ap, num);

    for (int i = 0; i < num; i++)
    {
        BOOL bFind = FALSE;
        char* command = va_arg(ap, char*);
        PVOID backup = temp;

        do
        {
            if (strcmp(command, temp->Buffer) == 0)
            {
                if (temp->Child == NULL && i < num - 1)
                {
                    va_list tap = ap;
                    temp->Child = malloc(sizeof(COMMAND_LIST));
                    temp->Child->Next = NULL;
                    temp->Child->Buffer = va_arg(tap, char*);
                    temp->Child->Child = NULL;
                }
                temp = temp->Child;
                bFind = TRUE;
                break;
            }
        } while (temp = temp->Next);

        if (bFind == FALSE)
        {
            temp = backup;
            temp->Next = malloc(sizeof(COMMAND_LIST));
            temp->Next->Next = NULL;
            temp->Next->Buffer = command;
            temp->Next->Child = NULL;
            if (i < num - 1)
            {
                va_list tap = ap;
                temp->Child = malloc(sizeof(COMMAND_LIST));
                temp->Child->Next = NULL;
                temp->Child->Buffer = va_arg(tap, char*);
                temp->Child->Child = NULL;
                temp = temp->Child;
            }
        }
    }
}

int AddHistory(const char* command)
{
    PHISTORY_LIST temp = HistoryList;

    if (temp == NULL)
    {
        temp = (PHISTORY_LIST)malloc(sizeof(HISTORY_LIST));
        temp->Blink = NULL;
        temp->Flink = NULL;
        temp->Buffer = command;
        HistoryList = temp;
    }
    else if (temp->Blink == NULL)
    {
        if (strcmp(temp->Buffer, command) != 0)
        {
            temp->Blink = (PHISTORY_LIST)malloc(sizeof(HISTORY_LIST));
            temp->Blink->Flink = temp;
            temp->Blink->Blink = NULL;
            temp->Blink->Buffer = command;
            HistoryList = temp->Blink;
        }
    }
    else
    {
        while (temp->Blink)
        {
            temp = temp->Blink;
        }

        if (strcmp(temp->Buffer, command) != 0)
        {
            temp->Blink = (PHISTORY_LIST)malloc(sizeof(HISTORY_LIST));
            temp->Blink->Flink = NULL;
            temp->Blink->Blink = NULL;
            temp->Blink->Buffer = command;
        }
    }

    return 0;
}

char* GetHistory(BOOL check)
{
    PVOID ret = NULL;
    char* buffer = NULL;

    if (HistoryList == NULL)
    {
        return ret;
    }
    else if (CurrentHistory == NULL)
    {
        if (!check)
        {
            CurrentHistory = HistoryList;
            buffer = (char*)malloc(strlen(CurrentHistory->Buffer) + 1);
            strcpy(buffer, CurrentHistory->Buffer);
            return buffer;
        }
        else
        {
            return NULL;
        }
    }

    if (!check)
    {
        if (CurrentHistory->Flink == NULL)
        {
            ret = NULL;
        }
        else
        {
            CurrentHistory = CurrentHistory->Flink;
            buffer = (char*)malloc(strlen(CurrentHistory->Buffer) + 1);
            strcpy(buffer, CurrentHistory->Buffer);
            ret = buffer;
        }
    }
    else
    {
        if (CurrentHistory->Blink == NULL)
        {
            ret = CurrentHistory = NULL;
        }
        else
        {
            CurrentHistory = CurrentHistory->Blink;
            buffer = (char*)malloc(strlen(CurrentHistory->Buffer) + 1);
            strcpy(buffer, CurrentHistory->Buffer);
            ret = buffer;
        }
    }

    return ret;
}

char* BeforeHistory()
{
    return GetHistory(FALSE);
}

char* AfterHistory()
{
    return GetHistory(TRUE);
}

char* save(char* str, int ch, int x)
{
    int i = 0;
    int len;
    char* newstr;

    len = str == NULL ? 0 : strlen(str);
    // len = strlen(str);

    /*if (ch == VK_BACK)
    {
        newstr = (char *)malloc(len + 1);
        if (str != NULL)
        {
            strcpy(newstr, str);
        }
        newstr[len - 1] = NULL;
    }
    else
    {
        newstr = (char*)malloc(len + 2);
        if (str != NULL)
        {
            strcpy(newstr, str);
        }
        newstr[len] = ch;
        newstr[len + 1] = NULL;
    }*/

    /*if (ch == VK_BACK)
    {
        newstr = calloc(len, 1);
        memcpy(newstr, str, len);
        newstr[len - 1] = NULL;
        free(str);
    }
    else
    {
        newstr = realloc(str, len + 2);
        newstr[len] = ch;
        newstr[len + 1] = NULL;
    }*/

    if (ch == VK_BACK)
    {
        newstr = calloc(len, 1);
        for (; i < x - 1; i++)
        {
            newstr[i] = str[i];
        }
        for (int temp = i; temp < len; temp++)
        {
            newstr[temp] = str[temp + 1];
            _putch(str[temp + 1]);
        }
        _putch(NULL);
        for (; i < len + 1; i++)
        {
            _putch(VK_BACK);
        }
    }
    else
    {
        newstr = calloc(len + 2, 1);
        for (; i < x; i++)
        {
            newstr[i] = str[i];
        }
        newstr[i] = ch;
        for (int temp = i; temp < len; temp++)
        {
            newstr[temp + 1] = str[temp];
            _putch(str[temp]);
        }
        for (; i < len; i++)
        {
            _putch(VK_BACK);
        }
        /*newstr[len] = ch;
        newstr[len + 1] = NULL;*/
    }

    /*if (str != NULL)
    {
        free(str);
    }*/

    free(str);

    return newstr;
}

void Sort(const char* command)
{
}

void Relation(char* input)
{
    PCOMMAND_LIST COMMANDLIST = CommandList;

    if (COMMANDLIST != NULL)
    {
        int len = input == NULL ? 0 : strlen(input) - 1;
        int check = 0;
        
        if (len)
        {
            for (int i = 0; i <= len; i++)
            {
                if (input[i] == ' ')
                {
                    input[i] = NULL;
                    do
                    {
                        if (strcmp(input + check, COMMANDLIST->Buffer) == 0)
                        {
                            COMMANDLIST = COMMANDLIST->Child;
                            break;
                        }
                    } while (COMMANDLIST = COMMANDLIST->Next);
                    check = i + 1;
                    input[i] = ' ';
                }
            }

            len = strlen(input + check);
        }

        if (COMMANDLIST != NULL)
        {
            do
            {
                if (strncmp(input + check, COMMANDLIST->Buffer, len) == 0)
                {
                    printf("\n%s", COMMANDLIST->Buffer);
                }
            } while (COMMANDLIST = COMMANDLIST->Next);
        }
    }

    printf("\n\n");
}

char* AutoComplete(char* input)
{
    PCOMMAND_LIST COMMANDLIST = CommandList;

    if (input == NULL || COMMANDLIST == NULL)
    {
        return NULL;
    }
    else
    {
        char* str = NULL;
        char* parents = NULL;
        int len = input == NULL ? 0 : strlen(input) - 1;
        int check = 0;

        if (len)
        {
            for (int i = 0; i <= len; i++)
            {
                if (input[i] == ' ')
                {
                    input[i] = NULL;
                    if (strcmp(input + check, COMMANDLIST->Buffer) == 0)
                    {
                        if (parents)
                        {
                            char* temp = malloc(strlen(parents) + strlen(COMMANDLIST->Buffer) + 2);
                            sprintf(temp, "%s %s", parents, COMMANDLIST->Buffer);
                            free(parents);
                            parents = temp;
                        }
                        else
                        {
                            parents = malloc(strlen(COMMANDLIST->Buffer) + 1);
                            strcpy(parents, COMMANDLIST->Buffer);
                        }
                        COMMANDLIST = COMMANDLIST->Child;
                    }
                    check = i + 1;
                    input[i] = ' ';
                }
            }

            len = strlen(input + check);
        }

        if (COMMANDLIST != NULL)
        {
            do
            {
                if (strncmp(input + check, COMMANDLIST->Buffer, len) == 0)
                {
                    if (str == NULL)
                    {
                        if (parents == NULL)
                        {
                            str = (char*)malloc(strlen(COMMANDLIST->Buffer) + 1);
                            strcpy(str, COMMANDLIST->Buffer);
                        }
                        else
                        {
                            str = (char*)malloc(strlen(COMMANDLIST->Buffer) + strlen(parents) + 2);
                            sprintf(str, "%s %s", parents, COMMANDLIST->Buffer);
                        }

                        if (strcmp(input + check, COMMANDLIST->Buffer) == 0)
                        {
                            char* temp = (char*)malloc(strlen(str) + 2);
                            sprintf(temp, "%s ", str);
                            free(str);
                            str = temp;
                        }
                    }
                    else
                    {
                        free(str);
                        return NULL;
                    }
                }
            } while (COMMANDLIST = COMMANDLIST->Next);
        }

        if (str != NULL)
        {
            free(input);
        }

        return str;
    }
}

int Exec(const char* command)
{
    /*STARTUPINFOA si = { 0, };
    PROCESS_INFORMATION pi = { 0, };
    si.cb = sizeof(STARTUPINFOA);*/

    int ret;

    printf("[*] Exec : %s\n\n", command);

    if (strncmp(command, "cd", 2) == 0)
    {
        ret = _chdir(command + 3);
    }
    else
    {
        ret = system(command);
    }
    // WaitForSingleObject(pi.hProcess, INFINITE);

    puts("");

    return ret;
}

char* readline(const char* commandline)
{
    if (ReadLine_CS == NULL)
    {
        ReadLine_CS = malloc(sizeof(CRITICAL_SECTION));
        InitializeCriticalSection(ReadLine_CS);
    }

    clock_t time = INFINITE;
    count = 0;
    x = 0;
    str = calloc(1, 1);
    CommandLine = commandline;

    // char* str = NULL;
    printf("%s", commandline);
    while (1)
    {
        int ch = _getch();
        EnterCriticalSection(ReadLine_CS);
        switch (ch)
        {
        case VK_BACK:
            if (count != 0 && x != 0)
            {
                CurrentHistory = NULL;
                _putch(ch);
                _putch(NULL);
                _putch(ch);
                str = save(str, ch, x);
                count -= 1;
                x -= 1;
            }
            break;

        case VK_TAB:
            if (clock() - time < 190)
            {
                time = clock();
                Relation(str);
                printf("%s", commandline);
                if (str != NULL)
                {
                    printf("%s", str);
                }
            }
            else
            {
                time = clock();
                char* AutoCommand = AutoComplete(str);
                if (AutoCommand != NULL)
                {
                    str = AutoCommand;
                    for (int i = 0; i < x; i++)
                    {
                        _putch(VK_BACK);
                    }
                    count = x = strlen(str);
                    printf("%s", str);
                }
                else
                {
                    time = clock();
                    Sleep(10);
                }
            }
            {/*if (readline)
            {
                end = clock();
                if (end - start < 190)
                {
                    Relation(str);
                    printf("%s", commandline);
                    if (str != NULL)
                    {
                        printf("%s", str);
                    }
                }
                readline = 0;
            }
            else
            {
                char* AutoCommand = AutoComplete(str);
                if (AutoCommand != NULL)
                {
                    //free(str);
                    str = AutoCommand;
                    for (int i = 0; i < count; i++)
                    {
                        _putch(8);
                    }
                    count = strlen(str);
                    printf("%s", str);
                }
                else
                {
                    start = clock();
                    readline = 1;
                    Sleep(10);
                }
            }*/}
            break;

        case VK_RETURN:
            if (count != 0)
            {
                AddHistory(str);
                CurrentHistory = NULL;
                _putch('\n');
                return str;
            }
            _putch('\n');
            printf("%s", commandline);
            break;

        case 0xE0:
            ch = _getch();

            switch (ch)
            {
            case 0x48:
            {
                char* BeforeCommand = BeforeHistory();

                if (BeforeCommand != NULL)
                {
                    free(str);
                    str = BeforeCommand;
                    for (int i = 0; i < x; i++)
                    {
                        _putch(VK_BACK);
                        _putch(NULL);
                        _putch(VK_BACK);
                    }
                    count = x = strlen(str);
                    printf("%s", str);
                }
                break;
            }
            case 0x50:
            {
                char* AfterCommand = AfterHistory();

                for (int i = 0; i < x; i++)
                {
                    _putch(VK_BACK);
                    _putch(NULL);
                    _putch(VK_BACK);
                }

                free(str);
                str = AfterCommand;

                if (str == NULL)
                {
                    count = x = NULL;
                }
                else if (str != NULL)
                {
                    count = x = strlen(str);
                    printf("%s", str);
                }
                else if (CurrentHistory != NULL)
                {
                    CurrentHistory = NULL;
                    count = 0;
                }

                {/*if (AfterCommand != NULL)
                {
                    str = AfterCommand;
                    for (int i = 0; i < count; i++)
                    {
                        _putch(VK_BACK);
                        _putch(NULL);
                        _putch(VK_BACK);
                    }
                    count = strlen(str);
                    printf("%s", str);
                }
                else if (CurrentHistory != NULL)
                {
                    CurrentHistory = NULL;
                    for (int i = 0; i < count; i++)
                    {
                        _putch(VK_BACK);
                        _putch(NULL);
                        _putch(VK_BACK);
                    }
                    count = 0;
                    free(str);
                    str = NULL;
                }*/}
                break;
            }
            case 0x4B:
                if (x != 0)
                {
                    _putch(VK_BACK);
                    x -= 1;
                }
                break;

            case 0x4D:
                if (x != count)
                {
                    _putch(str[x]);
                    x += 1;
                }
                break;
            }
            break;

        default:
            _putch(ch);
            str = save(str, ch, x);
            CurrentHistory = NULL;
            count += 1;
            x += 1;
            break;
        }
        LeaveCriticalSection(ReadLine_CS);
    }
}

int main()
{
    AddChildCommand(4, "Sessions", "-i", "test1", "test2");
    AddChildCommand(4, "Sessions", "-i", "test1", "test3");
    AddChildCommand(2, "Sas", "aaa");
    AddCommand("Set");
    AddCommand("Setting");
    AddCommand("Sasaaaa");
    while (TRUE)
    {
        char* string = readline("test > ");

        // printf("press : %s\n", string);


        Exec(string);
        // free(string);
    }

    system("pause");
}