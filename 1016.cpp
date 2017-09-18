#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int toll[24] ={ 10, 10, 10, 10, 10, 10, 20, 20, 20, 15, 15, 15, 15, 15, 15, 15, 20, 30, 20, 15, 15, 10, 10, 10};
typedef struct calltime
{
	int mon;
	int day;
	int hour;
	int min;
}calltime;
typedef struct record
{
	calltime ontime;
	calltime offtime;
	bool is_matched;
}record;
int duration(calltime t1, calltime t2)
{
	return t1.day * 1440 + t1.hour * 60 + t1.min - t2.day * 1440 - t2.hour * 60 - t2.min;
}
float costcalulation(calltime t1, calltime t2)//t1 off,t2 on
{
	float cost = toll[t2.hour] * (60 - t2.min) + toll[t1.hour] * t1.min;
	for (int i = t2.hour + 1; i < t1.hour; i++)
		cost += toll[i] * 60;
	cost /= 100;
	return cost;
}
int main()
{
	map<string, vector<record>> Server;
	for (int i = 0; i < 24; i++)
		cin >> toll[i];
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		string name;
		int m, d, h, mi;
		string action;
		cin >> name;
		scanf("%d:%d:%d:%d", &m, &d, &h, &mi);
		cin >> action;
		calltime thistime = { m, d, h, mi };
		if (action == "on-line")
		{
			if (Server.find(name) == Server.end())
			{
				vector<record> Records(1);
				Records[0].ontime = thistime;
				Records[0].is_matched = false;
				pair<string, vector<record>> t = pair<string, vector<record>>(name, Records);
				Server.insert(t);
			}
			else
			{
				record newrecord;
				newrecord.ontime = thistime;
				newrecord.is_matched = false;
				if (duration(thistime, Server[name].back().ontime) < 0)
					continue;
				else
					Server[name].push_back(newrecord);
			}
		}
		else
		{
			if (Server.find(name) == Server.end())
				continue;
			else
			{
				if (Server[name].back().is_matched)
					continue;
				else
				{
					Server[name].back().offtime = thistime;
					Server[name].back().is_matched = true;
				}
					
			}
		}
	}
	//已建好server,输出时直接计算费用
	map<string, vector<record>>::iterator p;
	for (p = Server.begin(); p != Server.end(); p++)
	{ //还没按照时间排序
		float cost = 0;
		for (int j = 0; j < p->second.size(); j++)
		{
			if ((p->second)[j].is_matched)
			{
				printf("%s %02d\n", p->first.c_str(), p->second[j].ontime.mon);
				int dur = duration(p->second[j].offtime, p->second[j].ontime);
				float thiscost = costcalulation(p->second[j].offtime, p->second[j].ontime);
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", p->second[j].ontime.day, p->second[j].ontime.hour, p->second[j].ontime.min, p->second[j].offtime.day, p->second[j].offtime.hour, p->second[j].offtime.min, dur,thiscost);
				cost += thiscost;
			}
		}
		if (fabs(cost)>0)
			printf("Total amount: $%.2f\n", cost);
	}
	return 0;
}