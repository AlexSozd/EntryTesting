#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//List of structure and we need maxvalue;
struct TimePoint
{
    int hb;
    int mb;
    int he;
    int me;
    char tb[6];
    char te[6];
    //int count = 1;
    TimePoint *next;
};
int main(char argv[])
{
    int i, k, h_min, m_min, max = 0;
    TimePoint *p, *p1, *q, *q1, *s, *x, *y;                           //p,q - begin of lists; p1, q1 - end
    char tb[6], te[6], buf[3];
    ifstream fs;
    fs.open(argv);
    if(!fs)
    {
        cerr << "\nОшибка при открытии файла" << endl;
        exit(1);
    }
    //Открыть файл и считать построчно
    while(fs.peek() != EOF)
    {
        fs >> tb >> te;
        /*if(t1 == tb)
        {
            i++;
        }
        else
        {
            if(t2 == tb)
            {
                i--;      
            }
        }*/
        x = new TimePoint();
        strcpy(x->tb, tb); strcpy(x->te, te);
        i = 0; k = 0;
        while(tb[i] != '\0')
        {
            buf[k] = tb[i];
            k++;
            if(tb[i + 1] == ':')
            {
                buf[k] = '\0';
                x->hb = (int)buf; k = 0;
            }
            i++;
        }
        buf[k] = '\0';
        x->mb = (int)buf;
        i = 0; k = 0;
        while(te[i] != '\0')
        {
            //if(te[i] == ':') { k++; i++; }
            buf[k] = te[i];
            k++;
            if(te[i + 1] == ':')
            {
                buf[k] = '\0';
                x->he = (int)buf; k = 0;
            }
            i++;
        }
        buf[k] = '\0';
        x->me = (int)buf;
        
        if(p == NULL)
        {
            p = x; p1 = x; i = 1; max = 1; q = new TimePoint();
            strcpy(q->tb, x->tb); q->hb = x->hb; q->mb = x->mb;
            q1 = q;
        }
        //if(x.tb == p.te) { p = p->next; i--; }  //Создать интервал
        if((p->he < x->hb) || ((p->he == x->hb) && (p->me < x->mb))) { p = p->next; i--; }
        if((p->he > x->he) || ((p->he == x->he) && (p->me >= x->me)))
        {
            p1->next = x; p1 = p1->next; i++;
            if(i > max) { max = i; q = NULL; q = x; q1 = q; }
            if(i == max)
            {
                q1->next = new TimePoint(); q1 = q1->next;
                strcpy(q1->tb, x->tb); q1->hb = x->hb; q1->mb = x->mb;
                //Find the end of interval
                s = p; y = p; h_min = x->he; m_min = x->me;
                //while (s->next != null)
                while (s != NULL)
                {
                    if(s->he < h_min)
                    {
                        y = s;
                        h_min = s->he; 
                    }
                    else
                    {
                        if((s->he == h_min) && (s->me < m_min))
                        {
                            y = s;
                            m_min = s->me;
                        }
                    }
                    s = s->next;
                }
                strcpy(q1->te, y->te); q1->he = y->he; q1->me = y->me;
            }
        }
        if((p->he < x->he) || ((p->he == x->he) && (p->me <= x->me)))
        {
            p1->next = x; p1 = p1->next; i++;
            if(i > max) { max = i; q = NULL; q = x; }
            if(i == max)
            {
                q1->next = new TimePoint(); q1 = q1->next;
                strcpy(q1->tb, x->tb); q1->hb = x->hb; q1->mb = x->mb; 
                strcpy(q1->te, x->te); q1->he = x->he; q1->me = x->me;
            }
        }
    }
    fs.close();
    
    s = q;
    while (s != NULL)     //joining contiguous intervals
    {
        y = s->next;
        if(strcmp(s->te, y->tb) == 0) //if(s->te == y->tb)
        {
            strcpy(s->te, y->te); s->he = y->he; s->me = y->me;
            s->next = y->next;  
        }
        s = s->next;
    }
    
    s = q;
    while (s != NULL)
    {
        cout << s->tb << s->te;
        s = s->next;
    }
    
    return 0;
}
