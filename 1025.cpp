#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef struct record
{
  string ID;
  int final_rank;
  int location;
  int local_rank;
  int score;
}record;
bool scorecmp(record first, record second)
{
  return first.score > second.score || (first.score == second.score &&first.ID < second.ID);
}
int main()
{
  int num_place;
  cin >> num_place;
  int* place = new int[num_place];
  vector<record> Records;
  for (int i = 0; i < num_place; i++)
  {
    cin >> place[i];
    for (int j = 0; j < place[i]; j++)
    {
      string ID;
      int score;
      cin >> ID >> score;
      record t = { ID, 0, i + 1, 0, score };
      Records.push_back(t);
    }
  }
  for (int i = 1; i < num_place; i++)
    place[i] = place[i - 1] + place[i];
  for (int i = 0; i < num_place; i++)
  {
    if (i == 0)
    {
      sort(Records.begin(), Records.begin() + place[0], scorecmp);
      for (int j = 0; j < place[0]; j++)
      {
        Records[j].local_rank = j;
        for (int k = j - 1; k >= 0; k--)
        {
          if (Records[j].score != Records[k].score)
            break;
          else// (Records[j].score ==Records[k])
            Records[j].local_rank--;
        }
      }
    }
    else
    {
      sort(Records.begin() + place[i - 1], Records.begin() + place[i], scorecmp);
      for (int j = place[i - 1]; j < place[i]; j++)
      {
        Records[j].local_rank = j - place[i - 1];
        for (int k = j - 1; k >= 0; k--)
        {
          if (Records[j].score != Records[k].score)
            break;
          else// (Records[j].score ==Records[k])
            Records[j].local_rank--;
        }
      }
    }
  }
  sort(Records.begin(), Records.end(), scorecmp);
  for (int i = 0; i < place[num_place - 1]; i++)
  {
    Records[i].final_rank = i;
    for (int j = i - 1; j >= 0; j--)
    {
      if (Records[i].score != Records[j].score)
        break;
      else
        Records[i].final_rank--;
    }
  }
  cout << place[num_place-1] << endl;
  for (int i = 0; i < place[num_place - 1]; i++)
    cout << Records[i].ID << " " << ++Records[i].final_rank << " " << Records[i].location << " " << ++Records[i].local_rank << endl;
  delete[] place;
  return 0;
}