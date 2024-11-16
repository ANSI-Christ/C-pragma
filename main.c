#include <stdio.h>

static void before_1(void){
    puts("before 1");
}
#define OUTMAIN_BEFORE before_1
#include "outmain.h"

void after_1(void){
    puts("before 1");
}
#define OUTMAIN_AFTER after_1
#include "outmain.h"


void before_2(void){
    puts("before 2");
}

static void after_2(void){
    puts("before 2");
}

#define OUTMAIN_BEFORE before_2
#define OUTMAIN_AFTER after_2
#include "outmain.h"

int main(){
    puts("main");
    return 0;
}
