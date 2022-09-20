#include <iostream>

#include "circle.h"
#include "square.h"
#include "sphere.h"
#include "cube.h"
#include "point.h"
using std::cout;

int main()
{
	Square sqr( 12, 2, 2 );
	Sphere sph( 5, 1.5, 4.5 );
	Cube cub( 2.2 );
	Circle cir( 3.5, 6, 9 );
	Shape *ptr[ 4 ] = { &cir, &sqr, &sph, &cub };

	for ( int x = 0; x < 4; ++x )
		cout << *( ptr[ x ] ) << '\n';

    cout<<"-------------------after shifting------------------"<<std::endl;
    Point point(1,2,3);

    for (int i = 0; i < 4; ++i){
        *ptr[i] + point;
		cout << *( ptr[ i ] ) << '\n';

    }
	


	return 0;


}

