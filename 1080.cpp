#include <vector>
#include <iostream>
#define inf 0x7fffffff 
#include <algorithm>
using namespace std;
typedef struct Stu
{
	int Ge;
	int Score;
	vector<int> want;
	int ID;
}Stu;
typedef struct Sc{
	int Score;
	int Ge;
}Sc;

bool cmp(Stu first, Stu second)
{
	if (first.Score != second.Score) return first.Score > second.Score;
	else if (first.Ge != second.Ge)  return first.Ge > second.Ge;
	else return first.ID > second.ID;
}
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> Quota(M);
	for (int i = 0; i < M; i++)
		cin >> Quota[i];
	vector<Stu> Applicants(N);
	for (int i = 0; i < N; i++)
	{
		Applicants[i].ID = i;
		int Gi;
		cin >> Applicants[i].Ge;
		cin >> Gi;
		Applicants[i].Score = Applicants[i].Ge + Gi;
		for (int j = 0; j < K; j++)
		{
			int t;
			cin >> t;
			Applicants[i].want.push_back(t);
		}
	}
	sort(Applicants.begin(), Applicants.end(), cmp);
	vector<vector<int>> Result(M);
	vector<Sc> top(M, { inf, inf });
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < Applicants[i].want.size(); j++)
			if (Result[Applicants[i].want[j]].size() < Quota[Applicants[i].want[j]] || (top[Applicants[i].want[j]].Score == Applicants[i].Score&&top[Applicants[i].want[j]].Ge == Applicants[i].Ge))
			{
				Result[Applicants[i].want[j]].push_back(Applicants[i].ID);
				top[Applicants[i].want[j]] = { Applicants[i].Score, Applicants[i].Ge };
				break;
			}
	}
	for (int i = 0; i < M; i++)
	{
		if (Result[i].size() == 0)
			cout << endl;
		else
		{
			sort(Result[i].begin(),Result[i].end());
			cout << Result[i][0];
			for (int j = 1; j < Result[i].size(); j++)
				cout << " " << Result[i][j];
			cout << endl;
		}
	}

	return 0;
}