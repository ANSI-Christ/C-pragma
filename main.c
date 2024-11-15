#include <stdio.h>

#define OUTMAIN_BEFORE puts("before 1");
#include "outmain.h"

#define OUTMAIN_AFTER puts("after 1");
#include "outmain.h"


#define OUTMAIN_MARK another
#define OUTMAIN_BEFORE puts("before 2");
#define OUTMAIN_AFTER puts("after 2");
#include "outmain.h"

int main(){
    puts("main");
    return 0;
}
