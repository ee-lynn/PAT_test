#include <iostream>
#define Inf 0x7fffffff
using namespace std;
myMap[500][500]{{0}};

int main()
{
    int N,M,C1,C2;
    cin>>N>>M>>C1>>C2;  //C1 in.  C2 to go
    int* Num_rescue = new int[N];
    for (int i=0;i<N;i++)
        cin>>Num_rescue[i];
    for (int i=0;i<M;i++)
    {
        int no1,no2,length;
        cin>>no1>>no2>>length;
        myMap[no1][no2] = length;
        myMap[no2][no1] = length;
    }
    //Dijrkstra algorithm
    int* last_city = new int[N];
    int* shorted_length = new int[N];
    bool* visited = new bool[N];
    for (int i=0;i<N;i++)  //initial
    {
        if (i!=C1&&myMap[C1][i]>0)
        {
            last_city[i] = C1;
            shorted_length[i] = myMap[C1][i];
        }
        else if (i!=C1)
        {
            last_city[i] = -1;
            shorted_length[i] = 0;
        } 
        else
        {
            last_city[i] = -1;
            shorted_length[i] = Inf;
        }
    }
    for (int i=1;i<N;i++) //greedy  //how to deal with same shortest path?? 
                                    //and gather peple without repeated calculation
    {
        for (int j=0;j<N;i++)
        {
            int min=Inf,index=0;
            if (shorted_length[j]<min&&)
        }
        
    }
    
    
    
    
    
    
    
    
    
    delete[] last_city;
    delete[] shorted_length;
    delete[] visited;
    delete[] Num_rescue;
    return 0;
    
}