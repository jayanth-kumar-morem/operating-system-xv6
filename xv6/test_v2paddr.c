#include "types.h"
#include "user.h"
#include "syscall.h"

int main(int argc,char *argv[])
{
    printf(1,"\n ><><><><VIRTUAL TO PHYSICAL ADDRESS SYSTEM CALL TESTS><><><><\n");
    unsigned va[]={0xABC,0xA68,0x12323424,0x88723642};
    unsigned pa;
    for(int i=0;i<4;i++){
        printf(1,"\n v2paddr system call status: %d\n",v2paddr(&va[i],&pa));
    }
    exit();
}
