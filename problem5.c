int main(int argc, char const *argv[])
{
    int j = -1;
    int digits = 0;
    
    int hour12;
    int number_value;
    
    if (hour12 > 12) {
        hour12 -= 12;
    }

    digits = 0;

    while (j < 9)
    { //TODO:HERE
        number_value /= 10;
        j++;
    }
    
    return 0;
}