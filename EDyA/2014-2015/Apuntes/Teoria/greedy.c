#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int start;
	int finish;
	int number;
} task;

int cmpTasks(const void *p, const void *q)
{
	task *fst = (task *)p;
	task *snd = (task *)q;

	return fst->finish - snd->finish;
}

void solve(task tasks[], int sz)
{
	int possible_tasks = 0;
	int previous_task;
	int i;

	printf("Tareas elegidas: ");

	qsort(tasks, sz, sizeof(task), cmpTasks);

	printf("%d", tasks[0].number);
	possible_tasks++;
	previous_task = 0;

	for (i = 1; i < sz; i++)
	{
		if (tasks[i].start >= tasks[previous_task].finish)
		{
			printf(" %d", tasks[i].number);
			possible_tasks++;
			previous_task = i;
		}
	}

	printf(".\nTotal de tareas máxima: %d.\n", possible_tasks);
}

int main(void)
{
	int number_of_tasks;
	task *tasks;
	int i;

	scanf("%d", &number_of_tasks);
	tasks = malloc(sizeof(task) * number_of_tasks);

	for (i = 0; i < number_of_tasks; i++)
	{
		scanf("%d%d", &tasks[i].start, &tasks[i].finish);
		tasks[i].number = i;
	}

	solve(tasks, number_of_tasks);

	return 0;
}
