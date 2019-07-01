int main(void) {
  int y = 0;

  int x;

  if(x == 0) {
    y = 2; // if octagon and base analysis are run together, this is reported as unreachable
  } else {
    y = 3;
  }
}