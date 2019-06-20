#include <stdlib.h>
#include <stdio.h>

int z = 0;

int q2 (int w, int x, int y) {
  switch (w) {
    case 10: return x + y;
    case 12: return x - y;
    case 14: if (x > y) {
      return 1;
    } return 0;
    case 16: if (x < y) {
      return 1;
    } return 0;
    case 18: if (x == y) {
      return 1;
    } return 0;
    default: return 0;
  }
}

int main(int argc, char** argv){
  z = q2(atoi(argv[1]), atoi(argv[2]),atoi(argv[3]));
  printf("z = %d", z);
}
