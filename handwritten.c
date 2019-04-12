// Handcrafted examples I used when designing the domain
int main(void) {
  example1();
  example2();
  example3();
  example4();
  example5();
  example6();
  example7();
  example8();
  example9();
  example10();
  example11();
  example12();
  example13();
  example14();
  example15();
  example16();
}

// Simple example
void example1(void) {
  int a[42];
  int i = 0;

  while(i < 42) {
    a[i] = 0;
    i++;
  }
}

// More complicated logic in initialization
void example2(void) {
  int a[42];
  int i = 0;

  while(i < 42) {
    a[i] = 0;

    if(i < 7) {
      a[i] = 3;
    }

    i++;
  }
}

// More complicated expression to index rather than just a variable
void example3(void) {
  int a[42];
  int i = 1;

  while(i < 43) {
    a[i-1] = 0;
    i++;
  }
}

// What if the content domain requires widening?
void example4(void) {
  int a[42];
  int i = 0;

  while(i < 42) {
    a[i] = i;
    i++;
  }
}

// Example showing that partial initialization is problematic when we start from
// the middle (not from the very left/right)
void example5(void) {
  int a[42];
  int i = 1;

  while(i < 42) {
    a[i] = 0;
    i++;
  }
}

// Two values initialized in one loop
void example6(void) {
  int a[42];
  int i = 0;

  while(i < 42) {
      a[i] = 0;
      i++;
      a[i] = 1;
      i++;
  }
}

// What happens when we assign a variable in the expression e so that we lose
// it
void example7(void) {
  int a[42];
  int i = 0;
  int j;

  while(i < 42) {
    a[i] = 0;
    i++;
    j = i;
    i = 31;
    i = j;
  }
}

// What happens when we assign a variable in the expression e so that we lose
// it, via a function call
void example8(void) {
  int a[42];
  int i = 41;
  int j;

  while(i >= 0)  {
    a[i] = 0;
    i--;
    j = i;
    i = rand();
    i = j;
  }
}

// Nested loops
void example9(void) {
  int a[42];
  int i = 0;
  int j;

  while(i < 42) {
    a[i] = 0;
    j = i;

    while(j < 42) {
      a[j] = 2;
      j++;
    }

    i++;
  }
}

// What if two different vars are used to index in the array?
void example10(void) {
  int a[42];

  int x = srand();

  if(x == 0) {
    int j = 0;

    while(j < 42) {
      a[j] = 0;
      j++;
    }
  } else {
    int i = 0;

    while(i < 42) {
      a[i] = 0;
      i++;
    }
  }
}

// Example where initialization proceeds backwards
void example11(void) {
  int a[42];
  for(int j=41; j >= 0; j--) {
    a[j] = 0;
  }
}

// Example reading from the array
void example12(void) {
  int a[42];
  int i = 0;

  while (i < 42) {
    a[i] = 7;
    i++;
  }

  int x = a[5];
  int y = a[1];
  int z = a[i-1];

  assert(x == 7);
  assert(y == 7);
  assert(z == 7);
}

// Example having two arrays partitioned according to one expression
void example13(void) {
  int a[42];
  int b[42];

  for(int i=0; i<42;i++) {
    a[i] = 2;
    b[41-i] = 0;
  }
}

// Example modifying sth used to index into the array via a pointer
void example14(void) {
  int a[42];
  int i = 0;
  int *ip = &i;

  while(*ip < 42) {
    a[i] = 0;
    (*ip)++; // unable to determine how much move was
  } 
}

void example15(void) {
  int a[42];
  int i=0;
  int *ip=&i;

  while(i < 42) {
    a[*ip] = 0;
    i++;
  }
}

void example16(void) {
  int a[42];
  int i = 0;
  int j = 0;
  int top;

  while(i < 42) {
    a[i] = 4;
    i++;
  }

  i = top;

  while(j<10) {
    a[j] = -1;
    j++;
  }
}