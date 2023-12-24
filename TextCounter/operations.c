//
// Created by 王旭、张子墨、周浩 on 2023/12/18.（排名不分先后)
//
#include "textcounter.h"

Status
InitTable(TextTable *p){
    if(p){
        if(!(p->elem = (ElemType *)malloc(sizeof (char [TableMAX + 1]))))
            return ERROR;
        p->alphas = 0;
        p->blanks = 0;
        p->words = 0;
        p->numbers = 0;
        p->length = 0;
        return OK;
    }
    return ERROR;
}

Status
LinkText(FILE **F){//若文档已经创建则返回文档指针，否则创建文档
    if((*F = fopen("text.txt", "r")) == NULL) {
        printf("< Please save your text into the text.txt which is in the same\ndirectory"
               " of the program and then run the program again ^_^ >\n");
        fclose(fopen("text.txt", "w"));
        return ERROR;
    }
    return OK;
}

Status
FInput_Count(TextTable *T, FILE *F){//从文件读入字符，同时计算相关字符数
    if(T==NULL || F==NULL) return ERROR;//错误处理交给主调函数
    int c, i=0, Tag=1;
    while((c = fgetc(F)) != EOF) {
        if(i >= TableMAX) {//越界检查
            printf("< ERROR:Too Much Characters (╯▔皿▔)╯ (LESS THAN %d CHARACTERS PLEASE) >", TableMAX);
            return ERROR;
        }
        T->elem[i++] = (char) c;//存入文档表(顺序表)
        if(c==' ' || c=='\t' || c=='\n') Tag = 1;
        else if(Tag) {T->words++; Tag = 0;}
        if(isblank(c)) T->blanks++;//数空白符个数
        else if(isalpha(c)) T->alphas++;//数字母个数
        else if(isnumber(c)) T->numbers++;//数数字个数
    }
    T->length = i;
    T->elem[i] = '\0';
    return OK;
}

Status
Output(TextTable *T){//输出用户文档内容
    printf("%s\n\n", T->elem);
    return OK;
}

int
SearchPattern(TextTable *T, char *Pattern, LinkQueue *Q){
    char *pos = T->elem;
    int i = 0;
    size_t length = strlen(Pattern);
    while((pos=strstr(pos, Pattern)) != NULL){
        i++;
        EnQueue(Q, pos);//位置入队
        pos += length;
    }
    return i;
}

Status
GetPattern(char *Pattern){
    printf("< Input your Pattern: >\n");
    scanf("%s", Pattern);
    return OK;
}

Status
InitQueue(LinkQueue *Q){
    if((Q->front = Q->rear = (QNode *) malloc(sizeof (QNode))) == NULL)
        return ERROR;
    Q->front->next = NULL;
    return OK;
}

Status
EnQueue(LinkQueue *Q, QElemType e){
    QNode *p;
    p = (QNode *) malloc(sizeof (QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}

Status
DeQueue(LinkQueue *Q, QElemType *e){
    QNode *p;
    if(Q->front == Q->rear)
        return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return OK;
}

Status
QueueEmpty(LinkQueue *Q){
    if(Q->front == Q->rear)
        return TRUE;
    return ERROR;
}

static void
Move(ElemType **p, ElemType **q, const ElemType *tag, int length){
    while(*q != tag){
        (*(*p)++) = (*(*q)++);
    }
    *q += length;
}

void
DeleteSubstring(TextTable *T, LinkQueue *Q, int length){
    ElemType *p, *q;
    p = q = T->elem;
    QElemType t;
    while(!QueueEmpty(Q)){
        DeQueue(Q, &t);
        Move(&p, &q, t, length);
    }
    while(*q != '\0'){
        (*p++) = (*q++);
    }
    *p = '\0';
}












