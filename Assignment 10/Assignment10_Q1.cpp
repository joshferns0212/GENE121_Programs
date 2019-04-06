#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

//Joshua Fernandes
using namespace std;

const int MAX_NUM_OF_TASKS = 9;
int actualNumOfTasks = 0;

class Task
{
	private:
		//data members
		string taskName;
		int startTime, duration;

	public:
		//constructors
		Task()
		{
			taskName = "";
			startTime = 800;
			duration = 1;
		}
		Task(string inputTaskName, int inputStartTime, int inputDuration)
		{
			Task();
			setTaskName(inputTaskName);
			setStartTime(inputStartTime);
			setDuration(inputDuration);
		}
		//accessor methods
		string getTaskName() const
		{
			return taskName;
		}
		int getStartTime() const
		{
			return startTime;
		}
		int getDuration() const
		{
			return duration;
		}
		//mutator methods
		void setTaskName(string inputTaskName)
		{
			taskName = inputTaskName;
		}
		void setStartTime(int inputStartTime)
		{
			if (inputStartTime >= 800 && inputStartTime <= 1600 && inputStartTime == inputStartTime / 100 * 100)
				startTime = inputStartTime;
		}
		void setDuration(int inputDuration)
		{
			if (inputDuration > 0 && inputDuration <= 10)
				duration = inputDuration;
		}
		//member functions
		int endsAt() const
		{
			return (startTime + 100 * duration);
		}
		bool isTooLong()
		{
			return endsAt() > 1700;
		}
		/**
		 * Tasks conflict when the ending of one task occurs after the beginning
		 * of the next task. This means the ending time of the first task is
		 * greater than the start time of the next task
		**/
		bool overlaps(Task const &nextTask) const
		{
			return endsAt() > nextTask.startTime;
		}
		void operator=(Task const &task)
		{
			taskName = task.getTaskName();
			startTime = task.getStartTime();
			duration = task.getDuration();
		}
		//friend functions
		friend ostream &operator<<(ostream &out, Task const &task);
		friend ostream &operator<<(ostream &out, Task tasks[MAX_NUM_OF_TASKS]);
		friend istream &operator>>(istream &in, Task const &task);
		friend istream &operator>>(istream &in, Task tasks[MAX_NUM_OF_TASKS]);
};
void swap(Task &task1, Task &task2)
{
	Task tempTask;

	tempTask = task1;
	task1 = task2;
	task2 = tempTask;
}
//overloaded operators
ostream &operator<<(ostream &out, Task const &task)
{
	out << task.taskName << ": " << task.startTime << " " << task.duration;
	return out;
}
ostream &operator<<(ostream &out, Task tasks[MAX_NUM_OF_TASKS])
{
	int numOfConflicts = 0;
	for (int i = 0; i < actualNumOfTasks; i++)
	{
		out << tasks[i];

		if (tasks[i].isTooLong())
			cout << " late";
		if (i > 0 && tasks[i - 1].overlaps(tasks[i]))
			numOfConflicts++;

		cout << endl;
	}

	cout << "Number of conflicts: " << numOfConflicts;
}
istream &operator>>(istream &in, Task &task)
{
	string tempTaskName = "";
	int tempStartTime = 0, tempDuration = 0;

	in >> tempTaskName >> tempStartTime >> tempDuration;

	task.setTaskName(tempTaskName);
	task.setStartTime(tempStartTime);
	task.setDuration(tempDuration);

	return in;
}
istream &operator>>(istream &in, Task tasks[MAX_NUM_OF_TASKS])
{
	for (int i = 0; i < MAX_NUM_OF_TASKS; i++)
	{
		in >> tasks[i];
		if (tasks[i].getTaskName() == "")
			break;
		actualNumOfTasks++;
	}

	int minIndex;

	for (int i = 0; i < actualNumOfTasks - 1; i++)
	{
		minIndex = i;

		for (int j = i + 1; j < actualNumOfTasks; j++)
		{
			if (tasks[j].getStartTime() < tasks[minIndex].getStartTime())
				minIndex = j;
		}

		swap(tasks[minIndex], tasks[i]);
	}
}
int main()
{
	ifstream fin("mike_tasks_hard.txt");
	Task tasks[MAX_NUM_OF_TASKS];

	fin >> tasks;
	cout << tasks;

	fin.close();
	return EXIT_SUCCESS;
}
/*Output
GENE121_marking: 800 3
walk_dog: 800 1
Clean_whiteboard: 900 1
TA_management: 1100 3
MTE100_planning: 1400 2
lunch: 1600 1
meeting: 1600 2 late
Number of conflicts: 2
*/
