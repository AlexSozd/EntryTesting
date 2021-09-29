#include <iostream>
#include <fstream>
using namespace std;
struct Point
{
    float x;
    float y;
};
int main(char argv1[], char argv2[])
{
    int ans, i;
    Point p[4], p1;
    ifstream fs1, fs2;
    fs1.open(argv1);
    if(!fs1)
    {
        cerr << "\nОшибка при открытии файла " << argv1 << endl;
        exit(1);
    }
    i = 0;
    while(i < 4)
    {
        fs1 >> p[i].x >> p[i].y;
        i++;  
    }
    fs1.close();
    fs2.open(argv2);
    if(!fs2)
    {
        cerr << "\nОшибка при открытии файла " << argv2 << endl;
        exit(1);
    }
    while(fs2.peek() != EOF)
    {
        fs2 >> p1.x >> p1.y;
        if((p1.x >= p[0].x) && (p1.x <= p[2].x) && (p1.y >= p[0].y) && (p1.y <= p[2].y))
        {
            ans = 2;
            i = 0;
            while((i < 2) && (ans == 2))
            {
                if(p1.x == p[2*i].x)
                {
                    if((p1.y == p[2*i].y) || (p1.y == p[2*i+1].y))
                    {
                        ans = 0;
                    }
                    else 
                    {
                        ans = 1;
                    }
                }
                else
                {
                    if(p1.y == p[2*i].y)
                    {
                        if(p1.x == p[3-2*i].x)
                        {
                            ans = 0;
                        }
                        else 
                        {
                            ans = 1;
                        }        
                    }
                }
                i++;   
            }
        }
        else
        {
            ans = 3;
        }
        cout << ans << endl;  
    }
    fs2.close();
    return 0;
}
