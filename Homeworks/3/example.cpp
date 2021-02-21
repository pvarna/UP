#include <iostream>
#include <algorithm>
using namespace std;

int tasksCount, days, timeDay, timeTotal;

class Task
{
	public :
	
		int id, time, cost;
		double prior;
};

bool cmp (Task task1, Task task2)
{
	return task1 . prior > task2 . prior;
}

Task tasks [40];
int tasksTaken [40], cntTaken, maxCost;
int tasksAnswer [40], cntAnswer;

void solve (int ind, int timeSoFar, int costSoFar)
{
	if (ind == tasksCount)
	{
		if (costSoFar > maxCost)
		{
			maxCost = costSoFar;
			for (int i = 0; i < cntTaken; i ++)
				tasksAnswer [i] = tasksTaken [i];
			cntAnswer = cntTaken;
		}
		return ;
	}
	
	if (timeSoFar + tasks [ind] . time <= timeTotal)
	{
		tasksTaken [cntTaken ++] = ind;
		
		solve (ind + 1, timeSoFar + tasks [ind] . time, costSoFar + tasks [ind]. cost);
		
		cntTaken --;
	}
		
	solve (ind + 1, timeSoFar, costSoFar);
}

int main()
{
	ios_base :: sync_with_stdio (0);
	cin . tie (0);
	cout . tie (0);
	
	cin >> tasksCount;
	
	for (int i = 0; i < tasksCount; i ++)
	{
		cin >> tasks [i]. id >> tasks [i] . time >> tasks [i]. cost;
		
		tasks [i] . prior = tasks [i] . cost / double (tasks [i] . time);
	}
	
	sort (tasks, tasks + tasksCount, cmp);
		
	cin >> days;
	
	for (int i = 0; i < days; i ++)
	{
		cin >> timeDay;
		
		timeTotal += timeDay;
	}
	
	solve (0, 0, 0);
	
	for (int i = 0; i < cntAnswer; i ++)
		cout << tasks [tasksAnswer [i]] . id << " ";
	cout << endl;
	
	return 0;
}

