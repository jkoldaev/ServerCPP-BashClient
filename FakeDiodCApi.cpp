//
//  FakeDiodCApi.cpp
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#include "FakeDiodCApi.h"

char state = 1;
char rate = 5;
int rgb = RED;

void diod_init(char st, char rt, int cr){
    state = st;
    rate = rt;
    rgb = cr;
}

void diod_setState(char st){state = st;}
void diod_setRate(char rt){rate = rt;}
void diod_setColor(int cr){rgb = cr;}

const char diod_getState(){return state;}
const char diod_getRate(){return rate;}
const int  diod_getColor(){return rgb;}

