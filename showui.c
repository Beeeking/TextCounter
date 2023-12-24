//
// Created by 王旭、张子墨、周浩 on 2023/12/18.（排名不分先后)
//
#include "textcounter.h"
void ShowUI(void){
    printf(" _______        _    _____                  _            \n"
           "|__   __|      | |  / ____|                | |           \n"
           "   | | _____  _| |_| |     ___  _   _ _ __ | |_ ___ _ __ \n"
           "   | |/ _ \\ \\/ / __| |    / _ \\| | | | '_ \\| __/ _ \\ '__|\n"
           "   | |  __/>  <| |_| |___| (_) | |_| | | | | ||  __/ |   \n"
           "   |_|\\___/_/\\_\\\\__|\\_____\\___/ \\__,_|_| |_|\\__\\___|_|   \n"
    );
    printf("        < *****  Welcome to TextCounter  ***** >\n");
}

void ShowMenu(void){
    printf("< Enter a numbers to run the corresponding function: >\n"
           "(1) Delete a substring\t(2) Counting a substring\n"
           "(3) Counting numbers\t(4) Counting alphas\n"
           "(5) Counting words\t\t(6) Counting blanks\n"
           "(0) EXIT\n");
}