//
// Created by 王旭、张子墨、周浩 on 2023/12/18.（排名不分先后)
//

#ifndef TEXTCOUNTER2_TEXTCOUNTER_H
#define TEXTCOUNTER2_TEXTCOUNTER_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define OK 1
#define TRUE 1
#define ERROR 0
#define PatternMAX 200
#define TableMAX 2000

typedef int Status;//状态类型
typedef char ElemType;//处理对象类型
typedef ElemType *QElemType;
typedef struct{
    int words;
    int alphas;
    int blanks;
    int numbers;
    int length;
    ElemType *elem;
}TextTable;//文档表结构体

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//相关函数声明
void ShowUI(void);
Status InitTable(TextTable *);
Status LinkText(FILE **);
Status FInput_Count(TextTable *T, FILE *F);
Status Output(TextTable *);
void ShowMenu(void);
int SearchPattern(TextTable *, char *, LinkQueue *);
Status GetPattern(char *);
Status InitQueue(LinkQueue *);
Status EnQueue(LinkQueue *, QElemType);
Status DeQueue(LinkQueue *, QElemType *);
void DeleteSubstring(TextTable *, LinkQueue *, int);
Status QueueEmpty(LinkQueue *);
#endif //TEXTCOUNTER2_TEXTCOUNTER_H
