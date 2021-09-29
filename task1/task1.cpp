#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(char argv[])
{
    //Считать числа из файла и посчитать:
    //- 90 перцентиль
    //- медиана
    //- максимальное значение
    //- минимальное значение
    //- среднее значение
    int i, i1, n = 0, /*m1,*/ n1, min = 32767, max = -32767, min_1, /*max_90,*/ x, x1;
    float av_val = 0.00, med_val, proc_90;
    ifstream fs, fs1;
    fs.open(argv);
    if(!fs)
    {
        cerr << "\nОшибка при открытии файла " << endl;
        exit(1);
    }
    //Открыть файл и считать построчно
    while(fs.peek() != EOF)
    {
        fs >> x;
        if(x < min)
        {
            min = x;             
        }
        if(x > max)
        {
            max = x;             
        }
        av_val = av_val + x;
        n++;
    }
    fs.close();
    av_val = av_val / n;
    fs.open(argv);
    if(!fs)
    {
        cerr << "\nОшибка при открытии файла " << endl;
        exit(1);
    }
    //Открыть файл и считать построчно
    i = 0;
    while(fs.peek() != EOF)
    {
        fs >> x;
        
        fs1.open(argv);
        if(!fs1)
        {
            cerr << "\nОшибка при открытии файла " << endl;
            exit(1);
        }
        i1 = 0; m1 = 0; n1 = 0; min_1 = max;
        while(fs1.peek() != EOF)
        {
            fs1 >> x1;
            if(x <= x1)
            {
                 //m1++;
                 if((x1 < min_1) && (i1 != i)) { x1 = min_1; }
                 //if((x1 < max_90) && (i1 != i)) { x1 = max_90; }             
            }
            if(x >= x1)
            {
                 n1++;             
            }
            i1++;
        }
        /*if(m1 == n1) 
        { 
            if(n%2 == 0) { med_val = (x + max_1)/2; }
            else { med_val = x; }
        }*/
        if(n1 == (n / 2))
        {
            if((n % 2) == 0) { med_val = (x + min_1) / 2.00; }
            else { med_val = min_1; }
        }
        if(n1 == floor((n + 1) * 0.9)) { proc_90 = x + (((n + 1) * 0.9) - floor((n + 1) * 0.9)) * (min_1 - x); }
        
        i++;
    }
    fs.close();
    
    cout.precision(2);
    cout << proc_90 << endl;
    cout << med_val << endl;
    cout << max << endl;
    cout << min << endl;
    cout << av_val << endl;
    
    return 0;
}
