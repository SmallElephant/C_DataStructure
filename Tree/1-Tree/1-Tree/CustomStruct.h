//
//  CustomStruct.h
//  1-Tree
//
//  Created by FlyElephant on 2018/4/17.
//  Copyright © 2018年 rrd. All rights reserved.
//

#ifndef CustomStruct_h
#define CustomStruct_h

#include <stdio.h>

#endif /* CustomStruct_h */

typedef struct BTNode {
    char data;
    struct BTNode *leftNode;
    struct BTNode *rightNode;
} BTNode;

typedef struct LevelNode {
    BTNode *node;
    int level;
} LevelNode;
