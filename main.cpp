#include <iostream>
#include<chrono>
#include <thread>
#include <vector>

using namespace std;

bool wolframRule(bool bf, bool i, bool af)
{
    bool connvination[8]={
        0,//000
        1,//010
        1,//100
        1,//001
        0,//110
        1,//011   
        0,//101
        0,//111
    };

    if (!bf && !i && !af)
    {
        return connvination[0];
    }
    if (!bf && i && !af)
    {
        return connvination[1];
    }
    if (bf && !i && !af)
    {
        return connvination[2];
    }
    if (!bf && !i && af)
    {
        return connvination[3];
    }
    if (bf && i && !af)
    {
        return connvination[4];
    }
    if (!bf && i && af)
    {
        return connvination[5];
    }

    if (!bf && i && !af)
    {
        return connvination[6];
    }
    if (bf && i && af)
    {
        return connvination[7];
    }

    return false;
    
}

int main()
{
    int size=220;

    bool n[size] ;
    for(int i=0;i<size;i++){
        n[i]=0;
    }
        n[size/2]=true;
while(true)
    {

        for (bool i : n)
        {
            if (i)
            {
                cout <<"■";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
        this_thread::sleep_for(chrono::milliseconds(40));
    
        

        bool old[size];
        for (int i = 0; i < size; i++)
        {
            old[i] = n[i];
        }

        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                n[i] = wolframRule(old[size-1], old[i], old[i + 1]);
                continue;
            }
            if (i == size-1)
            {
                n[i] = wolframRule(old[i - 1], old[i], old[0]);
                continue;
            }
            n[i] = wolframRule(old[i - 1], old[i], old[i + 1]);
        }
    }

    return 0;
}
