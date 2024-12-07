#include <stdio.h>

static void before_1(void){
    puts("before 1");
}
#define PRAGMA_STARTUP before_1
#include "pragma.h"

void after_1(void){
    puts("after 1");
}
#define PRAGMA_ATEXIT after_1
#include "pragma.h"


void before_2(void){
    puts("before 2");
}

static void after_2(void){
    puts("after 2");
}

#define PRAGMA_STARTUP before_2
#define PRAGMA_ATEXIT after_2
#include "pragma.h"


#define PRAGMA_PACK 1
#include "pragma.h"
struct t_test{
    char a;
    int b;
}
#include "pragma.h"

int main(){
    puts("main");
    printf("sizeof(struct t_test)=%u\n",sizeof(struct t_test));
    return 0;
}
