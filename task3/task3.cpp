#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(char argv[])
{
    int i, j;
    float max_i, max = 0.000, sum, x[5];
    char *fn = new char[strlen(argv) + 11];
    for(i = 0; i < strlen(argv); i++)
    {
       fn[i] = argv[i];
    }
    strcat(fn, "/Cash0.txt");
    ifstream fs[5];
    for(i = 0; i < 5; i++)
    {
       fn[strlen(argv) + 5] = (i + 1) + '0';
       //fs[i].open(argv + "/Cash" + (i + 1) + ".txt");
       fs[i].open(fn);
       if(!fs[i])
       {
           cerr << "\nОшибка при открытии файла " << "Cash" << (i + 1) << ".txt" << endl;
           exit(1);
       }                
    }
    i = 0;
    while(i < 16)
    {
        sum = 0.000;
        for(j = 0; j < 5; j++)
        {
            fs[j] >> x[j];
            sum = sum + x[j];               
        }
        i++;
        if(sum > max)
        {
             max = sum;
             max_i = i;             
        }  
    }
    for(i = 0; i < 5; i++)
    {
        fs[i].close();               
    }
    cout << max_i << endl;
    delete[] fn;
    return 0;
}
