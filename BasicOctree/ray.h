// ray.h
// 2D to start, 3D later
// Ill keep all the math in here to start, not sure where it 'should' go
#pragma once
#include <vector>
#include "quadtree.h"

class ray
{
public:
	ray();
	ray(float o_x, float o_y, float o_z, float v_x, float v_y, float v_z);
	std::vector<float> origin;
	std::vector<float> direction;

	entity2D* intersects_quadtree(quadtree* qtree);
	bool intersects_plane(quadtree* qtree, std::vector<float> plane_origin, std::vector<float> plane_normal);
};