#include "TensorOperations.h"
#include <corecrt_math.h>

const double u1 = 1 / sqrt(2);
const double u2 = 1 / sqrt(2);
const double u3 = 0;

// rotates the pointer "a" around unit vector "u" by angle "theta"
// then rotates it around "z" axis by angle "alpha"
// returns projected point onto xy plane
Point TensorOperations::Convert(Point p, double theta, double alpha)
{
	double c=cos(theta);
	double s=sin(theta);

	double x = p.x * (u1 * u1 * (1 - c) + c) + p.y * (u1 * u2 * (1 - c) - u3 * s) + p.z * (u1 * u3 * (1 - c) + u2 * s);
	double y = p.x * (u2 * u1 * (1 - c) + u3 * s) + p.y * (c + u2 * u2 * (1 - c)) + p.z * (u2 * u3 * (1 - c) - u1 * s);
	double z = p.x * (u3 * u1 * (1 - c) - u2 * s) + p.y * (u3 * u2 * (1 - c) + u1 * s) + p.z * (c + u3 * u3 * (1 - c));

	c = cos(alpha);
	s = sin(alpha);

	return Point(
		x*c - y*s,
		x*s + y*c,
		0
	);
}
