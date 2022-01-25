#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	// refer https://www.ibm.com/docs/en/zos/2.1.0?topic=functions-open-open-file for details of the parameters
	int fd = open("/tmp/file", O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
	assert(fd > -1);
	int rc = write(fd, "hello world\n", 13);
	assert(rc == 13);
	close(fd);
	return 0;
 }