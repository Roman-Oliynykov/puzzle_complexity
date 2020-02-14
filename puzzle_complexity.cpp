#include <iostream>
#include <vector>

using namespace std;

const double minX = 1;
const double maxX = 10000000;

vector<pair<double,double> > pt = { pair<double, double>( minX / 1.1 ,0.1),  // the initial value, the first component should be lower than minX
			pair<double, double>(1,0.2),
			pair<double, double>(10,1),  // coins <---> minutes
			pair<double, double>(100,10),
			pair<double, double>(1000,60),
			pair<double, double>(10000,90),
			pair<double, double>(50000,120),
			pair<double, double>(100000,150),
			pair<double, double>(200000,180),
			pair<double, double>(1000000,240),
			pair<double, double>(10000000,600),
			pair<double, double>(maxX * 1.1, 3) // the final value, the first component should be greater than maxX
};

double f(double x) {
	if (x < minX or x > maxX ) return -1;

	for(unsigned int i = 1; i < pt.size(); i++)
		if ( x < pt[ i ].first ) {
			double a = ( pt[ i ].second - pt[ i - 1 ].second ) / ( pt[ i ].first - pt[ i - 1 ].first );
			double b = pt[ i - 1 ].second - pt[ i - 1 ].first * a;
			return a * x + b;
		}

// this point is never reached
	return -1;
}

double inX[] = {1, 2, 3, 4, 5, 9, 10, 20, 30, 50, 99, 100, 1000, 1100, 1500, 2000, 5000, 9000, 10000, 50000, 100000, \
		150000, 500000, 900000, 1000000, 2500000, 5000000, 7500000, 10000000 };

int main() {

	for(double x:inX)
		printf("%11.2f -> %6.2f\n", x, f(x) );

	return 0;
}
