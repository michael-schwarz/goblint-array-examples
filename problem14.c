int main(void)
{
  int arr[7000000000];
  fun(arr);

  arr[0] = 13;
}

void fun(int* a) {
  long long i = 0;
  int j = 0;

  while(i < 6999999998LL) {
    a[i] = 3;
    i++;
  }

  assert(i < 0);
}
