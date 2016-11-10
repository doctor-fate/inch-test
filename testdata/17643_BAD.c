int strdiff(char *a, char *b) {
int count_bytes=0;
int res=-2;
int i;

while (1) {
  if (a[count_bytes]==b[count_bytes]) {
    if (a[count_bytes]==0) {
      res=-1;
      break;
      }
    else count_bytes++;
    }
  else {
    for (i=0; i<8; i++) {
      if ((a[count_bytes]^b[count_bytes])&(1<<i)) {
        break;
        }
      }
    res=count_bytes*8+i;
    break;
    }
  }
return (res);
}