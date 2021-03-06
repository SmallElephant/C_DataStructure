//
//  Practice.h
//  1-Tree
//
//  Created by FlyElephant on 2018/4/21.
//  Copyright © 2018年 rrd. All rights reserved.
//

#ifndef Practice_h
#define Practice_h

#include <stdio.h>
#include "CustomStruct.h"
#include "Tree.h"

#endif /* Practice_h */

void testPath(void);

void testDoubleOrder(void);

BTNode *createBTree(char pre[],char in[], int preLeft, int preRight, int inLeft, int inRight);
BTNode *createBTTreePost(char post[], char in[], int postLeft, int postRight, int inLeft, int inRight);

// 统计二叉树的叶子节点数量
int countNode(BTNode *node);
int leafNodeCount(BTNode *node);

void linkLeafNode(BTNode *node);
void printLeafNodeLink(void);

void updateParentTree(BTParentNode *cur, BTParentNode *par);
void printParentNodePath(BTParentNode *node);
void printParentAllPath(BTParentNode *root);

void changePreToPost(char pre[],char post[],int preLeft,int preRight,int postLeft,int postRight);

void levelNode(BTNode *p, char x);

int levelNode2(BTNode *p, char x, int level);

void doubleOrder(BTNode *root);

void testAllPath(void);
void printAllPath(BTNode *p); // 打印所有根节点到叶子节点的路径


