#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LEN 100

typedef struct {
    char description[TASK_LEN];
    int is_done;
} Task;

Task todo_list[MAX_TASKS];
int task_count = 0;


void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("List is full!\n");
        return;
    }
    printf("Enter task: ");
    getchar(); 
    fgets(todo_list[task_count].description, TASK_LEN, stdin);
    todo_list[task_count].description[strcspn(todo_list[task_count].description, "\n")] = 0;
    todo_list[task_count].is_done = 0;
    task_count++;
}

void view_tasks() {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        printf("%d. [%s] %s\n", i + 1, todo_list[i].is_done ? "X" : " ", todo_list[i].description);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Task\n2. View Tasks\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_task(); break;
            case 2: view_tasks(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
