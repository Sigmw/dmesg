#include <stdio.h>
#include <sys/klog.h>
#include <stdlib.h>
#include <unistd.h>

void* emalloc(size_t size) {
  void *p;
  p = malloc(size);
  return p;
}

enum {
  SYSLOG_ACTION_SIZE_BUFFER = 10,
  SYSLOG_ACTION_READ_ALL = 3
};
void dmesg(const char* buf, size_t n) {
  const char *p = buf;
  ssize_t r;

  r = write(1, p, n);
}
int main() {
  int n;
  char *buf;
  n = klogctl(SYSLOG_ACTION_SIZE_BUFFER, NULL, 0);
  if(n < 0)
    perror("stderr");
  buf = emalloc(n);
  n = klogctl(SYSLOG_ACTION_READ_ALL, buf, n);
  dmesg(buf, n);
  free(buf);
}
