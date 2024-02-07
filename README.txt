Prompt for this was build a spatial representation (e.g. octree, kd tree, bsp tree), place some entities in it, and then perform some raycasts against those entities.

I chose octree, then only got as far as a quadtree. I started with the quad to test the logic then figured I'm add the extra dimension last, which I still think will be a very painless process, just didn't get that far. It would be the very next thing I do next time I work on this, now that the rest of the logic works in most cases.

Firing rays still seems pretty slow, in my visual studio testing I did around 2500 rays a second (napkin math, didn't meausure exact numbers).

What works
Adding many entities to the tree
    certain cases reject new entities (same position)
Rays return entities they hit
Rays return null if no entities are hit

To do
STRESS TEST! Some of what works might not!
Change quadtree to octree
If a ray could potentially hit two entities, then what?
Entities very close together sometimes fail to both resolve
    Better deal with small boxes by:
        switching all coordinates to floats
        switching to an extent system
        both?
Improve performance

plane intersection equations from: https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-plane-and-ray-disk-intersection.html  
This site was enormously helpful in understanding octrees/quadtrees: https://jimkang.com/quadtreevis/  
For better or worse, all the logic / structure is my own.  
