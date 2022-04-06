#define _POSIX_SOURCE
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>


main() {
  int  fd, ret, offset;
  char buf[4] = "abc";
  fd = open("/dev/sdb", O_RDWR);

  //pwrite and fsync
    offset = 1;
    ret = pwrite(fd, &buf, 4, offset);
    
    
    offset = 4097;
    ret = pwrite(fd, &buf, 4, offset);
    
    
    offset = 8193;
    ret = pwrite(fd, &buf, 4, offset);
   
 
  //cleanup
  close(fd);
  return 0;
}
