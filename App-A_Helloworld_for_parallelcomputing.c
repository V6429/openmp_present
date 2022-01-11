/**
 * @file App-A_Helloworld_for_parallelcomputing.c
 * @brief This is the hello world equivalent in parallel computing
 * This is a simple integration problem with a result equal to 3.1415....
 * The integral of (4/(1+(x^2)) = PI over the interval 0 to 1
 */


/**
 * ---------numerical integration------
 * area under a curve as the sum of small rectanglar areas under the curve
 *   https://www.reddit.com/r/mathmemes/comments/gapzbj/the_common_numerical_integration_techniques/ 
 *   we are using midpoint rule here (notice the center of rectangle)
 * 
 * if you just stackup the heights of rectangle  and multiply the width(common) with it, u have the area 
 * 
*/ 



#include<stdio.h>

long num_steps=100000; // how many slices to use
double step;

int main()
{
    int i; 
    double  x,                  // to calculate for each x b/w 0 to 1
            pi,                 // to store result which should be 3.14
            sum=0.0;            // to take sum of all the recangles(heights)



    // the size of each slice i.e the thickness of recatngle
    step = (1.0-0.0)/num_steps;
    printf("step= %lf",step);


    for(i=0;i<num_steps;i++){
        x=(i+0.5)*step; // considering x @ center of the rectangle (midpoint rule)
        sum=sum+4.0/(1.0+x*x); // 1) the graph eqn 2) adding all the heights
    }

    pi=step*sum; // area =lxb   here height into thickness
    printf("\nResult=%f",pi);// result shuld be pi

}