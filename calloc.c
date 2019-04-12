struct blub
{
    int blubby;
};

struct ms
{
    struct blub b;
    int x;
    int y;
    int z;
};


void fun(int *ptr) {
    *ptr++;
}


int main() {
    struct ms *ptr  = kzalloc(sizeof(struct ms));

    fun(&ptr->b.blubby);

    ptr->b.blubby = 8;

    ptr->x = 47;
    ptr->y = 11;

    return 0;
}