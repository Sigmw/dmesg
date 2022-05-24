#include <stdio.h>
#include <sys/klog.h>
#include <stdlib.h>
#include <unistd.h>


void dmesg(const char* buf, size_t n) {
  const char *p = buf;
  ssize_t r;

  r = write(1, p, n);
}
int main() {
  int n;
  char *buf;
  n = klogctl(10, NULL, 0);
  if(n < 0)
    perror("stderr");
  buf = malloc(n);
  n = klogctl(3, buf, n);
  dmesg(buf, n);
  free(buf);
}
