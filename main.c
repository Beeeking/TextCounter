//
// Created by 王旭、张子墨、周浩 on 2023/12/18.（排名不分先后)
//
#include "textcounter.h"
int
main() {
    ShowUI();//显示欢迎界面
    FILE *F;//
    printf("< Loading Your Text...... >   ");
    if(!LinkText(&F)) return 11;//没有text文件时创建该文件，有的话以读模式返回该文件指针,错误码11
    char pattern[PatternMAX];//子串存放变量
    int subCount;//子串计数变量
    TextTable T;LinkQueue Q;
    if(!InitTable(&T)) return 22;//创建文档表并初始化，错误码22
    if(!InitQueue(&Q)) return 33;//初始化队列，错误码33
    rerun:if(!FInput_Count(&T, F)) return 44;//错误码44
    printf("< Success! >\n\n");
    Output(&T);//输出用户文档内容
    ShowMenu();//显示功能选择菜单
    while(TRUE){
        switch (getchar()) {
            case '0':{
                free(T.elem);fclose(F);
                printf("< Thanks for using out program, have a good day づ￣ 3￣)づ >");
                return 0;
            }
            case '1':{
                getchar();//同理吃掉回车符
                GetPattern(pattern);
                subCount = SearchPattern(&T, pattern, &Q);
                printf("< %d substring%s has found, Do you want to DELETE THEM ALL? >\n"
                       "< Enter [Y/N] >\n", subCount, (subCount == 1 || subCount == 0) ? "" : "s");getchar();
                if(getchar() == 'Y'){
                    DeleteSubstring(&T, &Q, (int)strlen(pattern));
                    printf("< Here is the processed text >\n");
                    Output(&T);
                }getchar();
                printf("< Do you want to save the processed text into your text file? >\n"
                       "< Enter [Y/N] >\n");
                if(getchar() == 'Y'){
                    F = fopen("text.txt", "w");
                    fprintf(F, "%s", T.elem);
                    fclose(F);
                    F = fopen("text.txt", "r");getchar();
                    goto rerun;
                }getchar();
            }break;
            case '2':{
                getchar();//同理吃掉回车符
                GetPattern(pattern);
                subCount = SearchPattern(&T, pattern, &Q);
                printf("< Your text has %d substring%s like that. >\n", subCount, (subCount == 1 || subCount == 0) ? "" : "s");
            }break;
            case '3':printf("< Your text has %d numbers%s. >\n", T.numbers, (T.numbers == 1 || T.numbers == 0) ? "" : "s");break;
            case '4':printf("< Your text has %d alpha%s. >\n", T.alphas, (T.alphas==1 || T.alphas==0) ? "" : "s");break;
            case '5':printf("< Your text has %d word%s. >\n", T.words, (T.words==1 || T.words==0) ? "" : "s");break;
            case '6':printf("< Your text has %d blank%s. >\n", T.blanks, (T.blanks==1 || T.blanks==0) ? "" : "s");break;
            default:printf("< ERROR: the numbers is illegal (×_×) >\n");
        }
        printf("< You can still go ahead and choose ^_^: >\n");
        getchar();//将输入流中留存的回车符吃掉防止干扰后面的输入
    }
}