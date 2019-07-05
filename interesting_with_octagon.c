int main(void) {
  mineEx1();

  wasProblem();
  attempt();
  example1();
  example2();
  example2a();
  example2b();

  example3();
  example4();
  example5();
  example6();

  p1();
  p2();
}

// Examples from https://www-apr.lip6.fr/~mine/publi/article-mine-HOSC06.pdf
void mineEx1(void) {
  int X = 0;
  int N = rand();
  if(N < 0) { N = 0; }

  while(X < N) {
    X++;
  }
}

// Attempt to understand
void attempt(void) {
  int x;

  if(rand()){
    x = 3;
  } else {
    x = 7;
  }

  int y = x;
}

// Array related examples

// Simple example (employing MustBeEqual)
void example1(void) {
  int a[42];
  int i = 0;
  int x;

  while(i < 42) {
    a[i] = 0;
    int v = i;
    x = a[v];
    i++;
  }
}

// Simple example (employing MayBeEqual / MayBeSmaller)
void example2(void) {
  int a[42];
  int i = 0;

  while(i<=9) {
    a[i] = 9;
    int j = i+5;
    // a[j] = 42;
    
    // Here we know a[i] is 9 when we have MayBeEqual
    assert(a[i] == 9);
    
    // but only about the part to the left of i if we also have MayBeSmaller
    if(i>0) {
      int k = a[i-1];
      assert(k == 9);

      int l = a[0];
      assert(l == 9);
    }

    i++;
  }
}

// Just like the example before except that it tests correct behavior when variable order is reversed
void example2a(void) {
  int a[42];
  int j;
  int i = 0;

  while(i<=9) {
    a[i] = 9;
    j = i+5;
    a[j] = 42;
    
    // Here we know a[i] is 9 when we have MayBeEqual
    assert(a[i] == 9);
    
    // but only about the part to the left of i if we also have MayBeSmaller
    if(i>0) {
      assert(a[i-1] == 9);
    }

    i++;
  }
}

// Just like the example before except that it tests correct behavior when operands for + are reversed
void example2b(void) {
  int a[42];
  int j;
  int i = 0;

  while(i<=9) {
    a[i] = 9;
    j = 5+i;
    a[j] = 42;
    
    // Here we know a[i] is 9 when we have MayBeEqual
    assert(a[i] == 9);
    
    // but only about the part to the left of i if we also have MayBeSmaller
    if(i>0) {
      assert(a[i-1] == 9);
    }

    i++;
  }
}

// Works only when octagons are in use
void example3(void) {
  int a[40];
  int i = 0;

  a[i] = 0;

  while(i < 42) {
    int j = i;
    a[j] = 0;
    i++;
  }
}

// Does not currently work as desired, ideally we would use the condition to gain more information in the Octagon domain
void example4(void) {
  int a[42];
  int i = 0;

  while(i<30) {
    a[i] = 0;
    i++;

    int j=0;
    while(j<i) {
      assert(a[j] == 0);
      j++;
    }
  }
}

// Works only when Octagons are in use
void example5(void) {
  int top;
  
  int a[42];
  int i = 0;

  int j;

  while(i<30) {
    a[i] = 0;
    i++;

    if(i > 10) {
      if(top) {
        j = i-5;
      } else {
        j = i-7;
      }

      assert(a[j] == 0);
    }
  }
}

void example6(void) {
  int a[42];
  int i = 0;
  int j = i;

  while(i < 22) {
    a[i] = 0;
    i++;
    j = i;
    a[j-1] = 0;
    a[j] = 0;
    j++;      // Octagon knows -1 <= i-j <= -1
    i = j;    // We lose partitioning here because we don't know how far the move has been, ideally we would want to know this here. Because we can determine that (j-i == -1)
    int dontcare = 5812;
  }
}



void p1(void) {
  int j = 0;
  int i = 0;

  while(i<=9) {
    j = 5;
    i++;
  }
}

void p2(void) {
  int k;
  int h = 0;

  while(h<=9) {
    h++;
    k=h;
  }
}

void wasProblem() {
  int y = 0;
  int x;

  if(x == 0) {
    y = 2; // if octagon and base analysis are run together, this was reported as unreachable
  } else {
    y = 3;
  }
}