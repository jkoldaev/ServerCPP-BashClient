//
//  FakeDiodCApi.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_FakeDiodCApi_h
#define Server_FakeDiodCApi_h

#include <stdio.h>

#define RED 10
#define GREEN 20
#define BLUE 30



//c api

void diod_init(char st, char rt, int cr);

void diod_setState(char st);
void diod_setRate(char rt);
void diod_setColor(int cr);

const char diod_getState();
const char diod_getRate();
const int  diod_getColor();

#endif
