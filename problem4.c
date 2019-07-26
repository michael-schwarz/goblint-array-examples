int main(int argc, char const *argv[])
{
    int l;
    int r = 42;

    while(1) {
        if (l-r <= 0) {
            r--;
        } else {
            break;
        }
    }

   return 0;
}