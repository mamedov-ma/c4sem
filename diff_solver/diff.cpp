#include <iostream>
#include <curses.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iomanip>
#include <sys/time.h>

using namespace std;

// Consider a differential equation
// dy/dx=(x - y)
float func(float x, float y)
{
    return (x - y);
}

// Function for Euler formula
void euler(int num, float x0, float y, float h, float x)
{
    // Iterating till the point at which we
    // need approximation

    while (x0 < x) {
        y = y + h * func(x0, y);
        x0 = x0 + h;
        cout << "solver №" << num << "    x = "
             << x0 << "  y = " << fixed << setprecision(3) << y << endl; 
    }
    // Printing approximation
    cout << "solver №" << num << "    x = "
         << x << "  y = " << fixed << setprecision(3) << y << endl;
  
}

// Driver program
int main(int argc, char ** argv)
{
    // Initial Values
    float start = atoi(argv[1]);
    float end = atoi(argv[2]);
    int num = atoi(argv[3]);
    float y0 = 1;
    float h = 0.005;
    float loc_start, loc_end;
    int loc_num = 0, Pid, i;
    int wpid;
    struct timeval t1;
    struct timeval t2;
    
    gettimeofday(&t1, NULL);
    
    for(i = 1; i <= num; i++)
    {
        loc_start = (end - start)/num * (i - 1) + start;
        loc_end = (end - start)/num * i + start;
        loc_num = i;  
        
        if ((Pid = fork())== 0)
        {   
            euler(loc_num, loc_start, y0, h, loc_end);
            exit(0);
        }          
    }
    
    while((wpid = wait(NULL)) > 0);      
    
    gettimeofday(&t2, NULL);
    float time = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec) * 0.000001;
    cout << "Total time " << time << endl;

    return 0;
}   

