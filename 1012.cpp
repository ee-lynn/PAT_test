#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct record
{
	int ID;
	int C;
	int M;
	int E;
	int A;
}record;
bool cmp_c(record first, record second)
{
	return first.C > second.C;
}
bool cmp_m(record first, record second)
{
	return first.M > second.M;
}
bool cmp_e(record first, record second)
{
	return first.E > second.E;
}
bool cmp_a(record first, record second)
{
	return first.A > second.A;
}

int main()
{
	int num;
	int num_rec;
	cin >> num >> num_rec;
	vector<record> Records(num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d %d", &Records[i].ID, &Records[i].C, &Records[i].M, &Records[i].E);
		Records[i].A = (Records[i].C + Records[i].M + Records[i].E) / 3;
	}
	vector<record> Records_C = Records;
	sort(Records_C.begin(), Records_C.end(), cmp_c);
	vector<record> Records_M = Records;
	sort(Records_M.begin(), Records_M.end(), cmp_m);
	vector<record> Records_E = Records;
	sort(Records_E.begin(), Records_E.end(), cmp_e);
	vector<record> Records_A = Records;
	sort(Records_A.begin(), Records_A.end(), cmp_a);

	int* query = new int[num_rec];
	for (int i = 0; i < num_rec; i++)
		cin >> query[i];
	for (int i = 0; i < num_rec; i++)
	{
		int rank_c, rank_m, rank_e, rank_a;
		for (rank_c = 0; rank_c < num; rank_c++)
		{
			if (query[i] == Records_C[rank_c].ID)
				break;
		}
		while (rank_c != num && rank_c != 0 && Records_C[rank_c].C == Records_C[rank_c - 1].C)
			--rank_c;

		for (rank_m = 0; rank_m < num; rank_m++)
		{
			if (query[i] == Records_M[rank_m].ID)
				break;
		}
		while (rank_m != num && rank_m != 0 && Records_M[rank_m].M == Records_M[rank_m - 1].M)
			--rank_m;

		for (rank_e = 0; rank_e < num; rank_e++)
		{
			if (query[i] == Records_E[rank_e].ID)
				break;
		}
		while (rank_e != num &&rank_e != 0 && Records_E[rank_e].E == Records_E[rank_e - 1].E)
			--rank_e;

		for (rank_a = 0; rank_a < num; rank_a++)
		{
			if (query[i] == Records_A[rank_a].ID)
				break;
		}
		while (rank_a != num &&rank_a != 0 && Records_A[rank_a].A == Records_A[rank_a - 1].A)
			--rank_a;

		if (rank_a == num)
			cout << "N/A" << endl;
		else if (rank_a <= rank_c&&rank_a <= rank_e&&rank_a <= rank_m)
			cout << ++rank_a << " " << "A" << endl;
		else if (rank_c < rank_a&&rank_c <= rank_e&&rank_c <= rank_m)
			cout << ++rank_c << " " << "C" << endl;
		else if (rank_m < rank_a&&rank_m < rank_c&&rank_m <= rank_e)
			cout << ++rank_m << " " << "M" << endl;
		else
			cout << ++rank_e << " " << "E" << endl;
	}
	delete[] query;
	return 0;
}