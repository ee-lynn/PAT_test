#include <iostream>
#include <map>
using namespace std;
class RGB
{
public:
	RGB(int tmp = 0)
	{
		B = tmp % 0x77;
		tmp /= 0x77;
		G = tmp % 0x77;
		tmp /= 0x77;
		R = tmp % 0x77;
	}
	bool operator<(const RGB another) const
	{
		return R * 0x7777 + G * 0x77 + B < another.R * 0x7777 + another.G * 0x77 + another.B;
	}
private:
	char R;
	char G;
	char B;
};

int main()
{
	int M, N;
	cin >> M >> N;
	int half = M*N / 2;
	int tmp;
	map<RGB, int> Record;
	int result = -1;
	bool found = false;
	for (int i = 0; i < M*N; i++)
	{
		scanf("%d",&tmp);
		if (!found)
		{
            RGB rgb(tmp);
			if (Record.find(rgb) != Record.end())
			{
				if (++Record[rgb]>half)
				{
					result = tmp;
					found = true;
				}
			}
			else
				Record.insert(pair<RGB, int>(rgb, 1));
		}
	}

	cout << tmp << endl;
	return 0;
}