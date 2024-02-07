// ray.cpp
#include <iostream>
#include <numeric>
#include <vector>
#include "ray.h"
#include "quadtree.h"

using namespace std;

ray::ray()
{
	origin = vector<float>(3);
	direction = vector<float>(3);
}

ray::ray(float o_x, float o_y, float o_z, float v_x, float v_y, float v_z)
{
	origin = { o_x, o_y, o_z };
	float length = v_x * v_x + v_y * v_y + v_z * v_z;
	direction = { v_x/length, v_y/length, v_z/length };
}

bool ray::intersects_quadtree(quadtree* qtree)
{
	// if not in range of tree, no intersection
	return false;
	
	// If not leaf and in range, check children
	// probably not all long term, prob just the ones on the side of the intersected plane?

	// if leaf and in range, intersects (well, then you check the actual mesh I suppose)
	
}

// Do math to see if this ray intersects with a given plane
// Done by first calculating where the ray crosses the infinite plane,
// then if intersection point exists in the actual extent of the qtrees side
// This should technically expect normalized vectors to be passed in but
//   practically for now its easier to convert here than on the generation side
// 
// qtree, owner of the plane
// plane_origin, center of plane in 3d space
// plane normal, defining normal of plane in 3d space
// return: bool, true if intersects, false if not
bool ray::intersects_plane(quadtree* qtree, vector<float> plane_origin, vector<float> plane_normal_raw)
{
	// normalize plane_normal
	float length = plane_normal_raw[0] * plane_normal_raw[0] + plane_normal_raw[1] * plane_normal_raw[1] + plane_normal_raw[2] * plane_normal_raw[2];
	vector<float> plane_normal = { plane_normal_raw[0] / length, plane_normal_raw[1] / length, plane_normal_raw[2] / length };

	// find t at which ray intersects plane
	// P0 = plane origin
	// R0 = ray origin
	// Pn = Plane normal
	// R = ray direction
	// t = (P0 - R0) dot Pn / ( R dot Pn)
	float t;
	vector<float> diff = { plane_origin[0] - origin[0],
						plane_origin[1] - origin[1],
						plane_origin[2] - origin[2]
	};
	float upper = (float)inner_product(diff.begin(), diff.end(), plane_normal.begin(), 0);
	float lower = (float)inner_product(direction.begin(), direction.end(), plane_normal.begin(), 0.0);

	// if lower is too small, ray and plane are probably parallel (and not intersecting)
	// can tell the difference later
	if (lower < 0.0001) // mess with this value
		return false;

	t = upper / lower;
	if (t < 0)
		return false;

	// get intersection point p
	// p(t) = Ray * t + R0
	vector<float> point = {
		origin[0] + direction[0] * t,
		origin[1] + direction[1] * t,
		origin[2] + direction[2] * t
	};

	// check if p is actually in range of plane
	// as long as the point is on the plane (given), simply checking all 3 dimensions are less than tree.radius from the plane origin 
	// should be enough to prove it's within the trees bounds
	int rad = qtree->get_radius();
	if (abs(point[0] - plane_origin[0]) < rad
		&& abs(point[1] - plane_origin[1]) < rad
		&& abs(point[2] - plane_origin[2]) < rad)
	{
		return true;
	}

	return false;
}
