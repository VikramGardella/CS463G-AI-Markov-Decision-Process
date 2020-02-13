Author: Vikram Dudee


Course: CS463G



Date Submitted: 12/6/2016



Program Description: My program uses a grid of squares with the reward value
for each square specified.
Using Bellman's Theorem and the Markov Decision
Process, the program generates a "utility value" corresponding
with the
square. This utility value is updated each iteration for 7 iterations and
correlates with the
usefulness of moving to that square with which direction.

Technical Specifications: To represent my grids, I
used 2-Dimensional arrays.
Most were doubles, except for the directional graph which was a char[][] and 
used
'^', 'v', '<', and '>' to represent up, down, left, and right,
respectively. Blocked off regions were represented
in my 2-D arrays as
"-1" because they must be a double to be accepted. When my grids were
printed, I had "[]"
printed instead of "-1" for clarity's sake. In terms of
results, The final directed graph after 7 iterations
appears to be accurate
in how it recommends a direction to move in. My utility values may grow to
be too large
rather than plateau so there may be some error(s) in my math.


What I Learned: Bellman's Theorem and the Markov Decision Process are very
effective ways to determine which
direction to move in when you know your 
location and the layout of a region. It could be (and probably has
been)
applied to autonomous robot navigation.



My Favorite Thing About CS463G: Being in a close-knit, driven, and
enthusiastic CS environment and learning
about AI techniques/solutions that
 can be applied to real-life engineering problems.