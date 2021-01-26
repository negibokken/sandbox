#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 256

int main(int argc, char *argv[]) {
  char buf[MAX_BUF];
  int readNum;

  int fi = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  if (fi == -1) {
    return -1;
  }
  while ((readNum = read(STDIN_FILENO, buf, MAX_BUF)) != 0) {
    write(STDOUT_FILENO, buf, readNum);
    write(fi, buf, readNum);
  }
  int r = close(fi);
  if (r != 0) {
    return -1;
  }
  return 0;
}
