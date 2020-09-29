# Computing-the-Convex-Hull
Computing the Convex Hull of a set of points using Graham's Scan Algorithm
## Introduction
Computing the Convex Hull of a set of points
using Graham's Scan Algorithm.
## Algorithm
The algorithm uses a stack to detect and remove concavities in the bounder
efficiently. The points are ordered by their angles.
### Implementation
I choose to make a struct that defines a point: it has 2 double variables for its
coordinates and an int variable for its index in the list. My program works the
following way:
- it reads the points from a file
- it calls the function graham
- graham first calls a function stangajos() that searches the first element,
the one that is the lowest in the coordinates and should be the first point
in the list; it puts it in the vector stack so the stack will not be empty;
Also, it orders the rest of the points and puts the second one as well in
the vector stack
- then takes all the points and verifies if the new point that can be added in
the stack will not make an angle that turns the figure. To verify that, it
makes the CrossProduct of the points and verifies the angles made between
the new point to be added and the last two in the stack. If the point is
okey, it is put in the stack. Otherwise, it pops back the last element in
the stack and then puts the new point
- the last step of my program call the functions afiseaza() that displays the
nodes from the stack (their indexes).
