#include <stdio.h>

#define OUTMAIN_BEFORE before_1 , puts("before 1");
#include "outmain.h"

#define OUTMAIN_AFTER after_1, puts("after 1");
#include "outmain.h"



#define OUTMAIN_BEFORE before_2, puts("before 2");
#define OUTMAIN_AFTER after_2, puts("after 2");
#include "outmain.h"

int main(){
    puts("main");
    return 0;
}
