#include "types.h"
#include "user.h"
#include "syscall.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    /*
        START: test symlinks
        Creating a
        Linking b -> a
        Writing to a
        Reading from b
        Removing a
        Linking a -> b
        Attempting to open b (cycle)
        Symlinking c to nonexistent file
        Creating symlink chain 1->2->3->4
        SUCCESS: test symlinks
    */
	printf(1,"START: test symlinks \n");
	
    printf(1,"Creating a \n");
	char filename1[] = "file_a";
	int file1_fd = open(filename1, O_CREATE|O_RDWR);

    printf(1,"Writing to a \n");
	write(file1_fd, "HelloWorld", 10);
	

    printf(1,"Linking b -> a \n");
	char store[512];
	int fd2;
	char symlinkfilename[] = "symlinkfile";
	printf(1, "%d\n", symlink(filename1, symlinkfilename));

    printf(1,"Reading from b \n");
	fd2 = open(symlinkfilename, O_NOFOLLOW);
	printf(1, "%d\n", fd2);
	printf(1, "%d\n", read(fd2, store, 10));
	printf(1, "%s\n", store);
	
    fd2 = open(symlinkfilename, O_RDWR);
	printf(1, "%d\n", fd2);
	printf(1, "%d\n", read(fd2, store, 10));
	printf(1, "%s\n", store);
	
    printf(1, "%d\n", symlink("1", "2"));
    printf(1, "%d\n", symlink("2", "3"));
    printf(1, "%d\n", symlink("3", "1"));
    fd2 = open("1", O_RDWR);
    
	printf(1,"\n");
	exit();
}