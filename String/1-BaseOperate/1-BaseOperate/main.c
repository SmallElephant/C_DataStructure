//
//  main.c
//  1-BaseOperate
//
//  Created by FlyElephant on 2018/3/27.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_length(char *s) { // 字符串的长度
    int len = 0;
    while (*s != '\0') {
        s++;
        len++;
    }
    return len;
}

int str_compare(char *s1, char *s2) { // 字符串长度比较
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

char *str_cat(char *s1, char *s2) { // 字符串拼接
    char *res = (char *)malloc(str_length(s1) + str_length(s2) + 1);
    char *head = res;
    while (*s1) {
        *res++ = *s1++;
    }
    while (*s2) {
        *res++ = *s2++;
    }
    *res = '\0';
    return head;
}

char *str_sub(char *s1, int pos, int len) { // 字符串截取
    char *res = (char *)malloc(len + 1);
    char *head = res;
    int i = 0;
    while (*s1) {
        if (i >= pos && (i - pos) < len) {
             *res++ = *s1;
        }
        s1++;
        i++;
    }
    *res = '\0';
    return head;
}

int index_substring(char *source, char *sub) {
    int len = str_length(source);
    int len2 = str_length(sub);
    if (len < len2) {
        return -1;
    }
    int pos = -1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len2; j++) {
            if (source[i+j] != sub[j]) {
                break;
            }
            if (j == (len2-1)) {
                pos = i;
                break;
            }
        }
    }
    return pos;
}

int index_match(char *s, char *p) {
    int sLen = str_length(s);
    int pLen = str_length(p);
    if (sLen < pLen) {
        return -1;
    }
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == pLen) {
        return i - j;
    } else {
        return -1;
    }
}

void getNext(char *pattern, int *next)
{
    int j = -1;
    int len = str_length(pattern);
    for (int i = 0; i < len; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (j == -1 || pattern[i] == pattern[j]) { // j = -1 第一个匹配的字符串长度是0
            j++;
        }
        next[i] = j;
    }
}

int kmp_match(char *s, char *p) {
    int sLen = str_length(s);
    int pLen = str_length(p);
    if (sLen < pLen) {
        return -1;
    }
    int i = 0;
    int j = 0;
    int *next = (int *)malloc((pLen + 1) * sizeof(int));
    getNext(p, next);
    while (i < sLen && j < pLen) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == pLen) {
        return i - j;
    } else {
        return -1;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char *str1 = "abc";
    int n = str_length(str1);
    printf("字符串的长度:%d\n",n);
    char *str2 = "defg";
    int res = strcmp(str1, str2);
    if (res < 0) {
        printf("字符串%s小于%s\n",str1, str2);
    } else if (res == 0) {
        printf("字符串%s等于%s\n",str1, str2);
    } else {
        printf("字符串%s等于%s\n",str1, str2);
    }
    char *result = str_cat("abc", "def");
    printf("字符串拼接的结果:%s\n",result);
    char *sub = str_sub("abcdefg", 1, 2);
    printf("截取的结果:%s\n",sub);
    int pos = index_substring("abcdefg", "def");
    printf("子字符串中的位置:%d\n",pos);
    int pos1 = index_match("abcdefg", "def");
    printf("子字符串中的位置:%d\n",pos1);
    int next[10] = {0};
    char *pattern = "abababca";
    GetNext(pattern, next);
    for (int i = 0 ; i < str_length(pattern); i++) {
        printf("%d\t",next[i]);
    }
    printf("\n");
    return 0;
}
