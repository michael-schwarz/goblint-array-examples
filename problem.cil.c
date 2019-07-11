int main(int argc , char const   **argv ) 
{ 
  int top;
  int pad = 0;
  int to_uppcase;
  int change_case = 0;


  int bla = 41;

  while (1) {
    while_continue: /* CIL Label */ ;

    if (change_case != 1) {
        if (! (to_uppcase != 0)) {
            goto while_break;
        }
    } else {
        goto while_break;
    }

    if (top == 47) {
        to_uppcase = 1;
        goto while_continue;
    }

    if (top == 2) {
        change_case = 1;
        goto while_continue;
    }

    goto while_break;
  }
  while_break: /* CIL Label */ ;

  return (0);
}

void nop(void) {

}