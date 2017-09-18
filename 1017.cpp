#include <iostream>
#include <algorithm>
#include <vector>
#define endtime 61200
#define starttime 28800
using namespace std;
typedef struct record
{
	int arrive_time; //in sec
	int process_time; //in sec   
}record;
bool cmp(record first, record second)
{
	return first.arrive_time < second.arrive_time;
}
int main()
{
	int N, K;
	cin >> N >> K;
	double total_wait = 0.0;
	vector<record> Server;
	for (int i = 0; i < N; i++)
	{
		int h, m, s, p;
		scanf("%d:%d:%d %d", &h, &m, &s, &p);
		int sectime = h * 3600 + m * 60 + s;
		if (sectime <= endtime)
		{
			record t = { sectime, 60 * p };
			Server.push_back(t);
		}
	}
    if (Server.size()<=K)
        printf("0.0\n");
    else
    {
        sort(Server.begin(), Server.end(), cmp);
	    vector<int> Processing(K);
	    for (int i = 0; i < K; i++)
	    {
	    	if (Server[i].arrive_time < starttime)
	    	{
	    		total_wait += starttime - Server[i].arrive_time;
	    		Processing[i] = starttime + Server[i].process_time;
	    	}
	    	else
	    		Processing[i] = Server[i].arrive_time + Server[i].process_time;
        
	    }
	    sort(Processing.begin(), Processing.end());
	    for (int i = K; i<Server.size(); i++)
	    {
	    	if (Processing[0]>Server[i].arrive_time)
            {
                total_wait += Processing[0] - Server[i].arrive_time;
                Processing[0] += Server[i].process_time;
            }
	    	else	
	    	    Processing[0] = Server[i].arrive_time + Server[i].process_time;
	    	sort(Processing.begin(), Processing.end());
	    }
	    printf("%.1f\n", total_wait / 60 / Server.size());
    }
	return 0;
}