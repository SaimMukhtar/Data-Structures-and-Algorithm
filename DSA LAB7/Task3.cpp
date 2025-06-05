#include <iostream>
#include <queue>

using namespace std;

struct Task {
    int id;
    int remainingTime;
};

void roundRobinScheduling(queue<Task>& tasks, int quantum) {
    while (!tasks.empty()) {
        Task currentTask = tasks.front();
        tasks.pop();

        if (currentTask.remainingTime <= quantum) {
            cout << "Processing task " << currentTask.id << " for " << currentTask.remainingTime << " units." << endl;
            cout << "Task " << currentTask.id << " completed." << endl;
        }
        else {
            cout << "Processing task " << currentTask.id << " for " << quantum << " units." << endl;
            currentTask.remainingTime -= quantum;
            cout << "Task " << currentTask.id << " not completed. Remaining time: " << currentTask.remainingTime << endl;
            tasks.push(currentTask); 
        }
    }
}

int main() {
    queue<Task> tasks;
    int numTasks, quantum;

    cout << "Enter number of tasks: ";
    cin >> numTasks;

    for (int i = 1; i <= numTasks; ++i) {
        int time;
        cout << "Enter CPU time for task " << i << ": ";
        cin >> time;
        tasks.push({ i, time });
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    roundRobinScheduling(tasks, quantum);

    return 0;
}
