
#include <stdio.h>

struct point{
	float x;
	float y;
};

void printpoint(struct point p){
	printf("Point = {%f,%f)\n", p.x, p.y);
}

struct point addpoints( struct point p1, struct point p2 ) {
        p1.x += p2.x;
  	p1.y += p2.y;
	printpoint(p1);
	return p1;
}

int main(){
	struct point point1 = {1.3, 3.2};
	struct point point2 = {4.3, 1.2};
	addpoints(point1, point2);
	printpoint(point1);
	printpoint(point2);
}
