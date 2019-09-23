// PARAM: --sets solver td3 --enable ana.int.interval --disable ana.int.trier --disable exp.fast_global_inits --enable exp.partition-arrays.enabled  --sets exp.partition-arrays.keep-expr "last" --set ana.activated "['base','expRelation']"

int fun_5() { return 5; }
int fun_6() { return 6; }
int fun_5b() { return 5; }

int main () {
  int i,k2,t;

  int (*f[2])() = {fun_5, fun_6};

  // array has set of addresses:
  if (k2) {
    f[i] = fun_5b;
  }

  t = f[1]();

  assert(t == 5); // UNKNOWN

  return 0;
}
