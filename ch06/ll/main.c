#include <stdio.h>
#include <stdlib.h>

#define XMAX 10
#define YMAX 10


struct point{
    int x;
    int y;
};
struct rect{
    struct point pt1;
    struct point pt2;
};

int main()
{
    struct point makepoint(int, int);
    struct point addpoint(struct point, struct point);

    struct rect screen;
    struct point middle;
    screen.pt1 = makepoint(3 , 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
    struct point pt3;
    pt3 = addpoint(screen.pt1, screen.pt2);
    printf("pt3: %d %d\n", pt3.x, pt3.y);
    printf("pt1: %d %d\n", screen.pt1.x, screen.pt1.y);
    printf("pt2: %d %d\n", screen.pt2.x, screen.pt2.y);
    return 0;
}

struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
};

struct point addpoint(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
};
