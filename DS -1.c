

#define SIZE 50

typedef struct {
    int id;
    char pName[20];
    int priority;
    float BT;
} Process;

int count = 0;

void Add(Process table[]) {
    if (count >= SIZE) {
        printf("Process table full\n");
        return;
    }

    printf("Enter process-%d details\n", count + 1);

    printf("Enter PID: ");
    scanf("%d", &table[count].id);

    printf("Enter process name: ");
    scanf("%s", table[count].pName);

    printf("Enter priority: ");
    scanf("%d", &table[count].priority);

    printf("Enter BT: ");
    scanf("%f", &table[count].BT);

    count++;
}

void Display(Process table[]) {
    int i;
    if (count == 0) {
        printf("No processes to display\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nProcess-%d ", i + 1);
        printf("Pid=%d\tPname=%s\tPriority=%d\tBT=%.2f\n",
               table[i].id, table[i].pName,
               table[i].priority, table[i].BT);
    }
}

void BubbleSortByPriority(Process table[]) {
    int i, j;
    Process temp;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (table[j].priority > table[j + 1].priority) {
                temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
    printf("Sorted by Priority successfully\n");
}

void InsertionSortByPid(Process table[]) {
    int i, j;
    Process key;

    for (i = 1; i < count; i++) {
        key = table[i];
        j = i - 1;

        while (j >= 0 && table[j].id > key.id) {
            table[j + 1] = table[j];
            j--;
        }
        table[j + 1] = key;
    }
    printf("Sorted by PID using Insertion Sort\n");
}

void ShellSortByBT(Process table[]) {
    int gap, i, j;
    Process temp;

    for (gap = count / 2; gap > 0; gap /= 2) {
        for (i = gap; i < count; i++) {
            temp = table[i];
            for (j = i; j >= gap && table[j - gap].BT > temp.BT; j -= gap) {
                table[j] = table[j - gap];
            }
            table[j] = temp;
        }
    }
    printf("Sorted by Burst Time using Shell Sort\n");
}

void LinearSearchByPid(Process table[]) {
    int key, i;

    printf("Enter PID to search: ");
    scanf("%d", &key);

    for (i = 0; i < count; i++) {
        if (table[i].id == key) {
            printf("Process Found:\n");
            printf("Pid=%d\tPname=%s\tPriority=%d\tBT=%.2f\n",
                   table[i].id, table[i].pName,
                   table[i].priority, table[i].BT);
            return;
        }
    }
    printf("Process not found\n");
}

void BinarySearchByPid(Process table[]) {
    int low = 0, high = count - 1, mid, key;

    printf("Enter PID to search: ");
    scanf("%d", &key);

    while (low <= high) {
        mid = (low + high) / 2;

        if (table[mid].id == key) {
            printf("Process Found:\n");
            printf("Pid=%d\tPname=%s\tPriority=%d\tBT=%.2f\n",
                   table[mid].id, table[mid].pName,
                   table[mid].priority, table[mid].BT);
            return;
        } else if (table[mid].id < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Process not found\n");
}

int main() {
    Process table[SIZE];
    int choice;

    while (1) {
        printf("\n1.Add\n2.Display\n3.BubbleSortByPriority");
        printf("\n4.InsertionSortByPid\n5.ShellSortByBT");
        printf("\n6.LinearSearchByPid\n7.BinarySearchByPid\n8.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Add(table); break;
            case 2: Display(table); break;
            case 3: BubbleSortByPriority(table); break;
            case 4: InsertionSortByPid(table); break;
            case 5: ShellSortByBT(table); break;
            case 6: LinearSearchByPid(table); break;
            case 7:
                printf("NOTE: Sort by PID before Binary Search\n");
                BinarySearchByPid(table);
                break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

