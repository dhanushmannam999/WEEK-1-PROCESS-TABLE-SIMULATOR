#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 50

typedef struct{
	int id;
	char pName[20];
	int priority;
	float BT;
}Process;

int count=0;

void Add(Process table[],int n){
	if(count >= n){
		printf("Table full\n");
		return;
	}
	printf("Enter process-%d details\n",count+1);
	printf("Enter Pid\n");
	scanf("%d",&table[count].id);
	printf("Enter process name\n");
	scanf("%s",table[count].pName);
	printf("Enter priority\n");
	scanf("%d",&table[count].priority);
	printf("Enter BT\n");
	scanf("%f",&table[count].BT);
	count++;
}

void Display(Process table[],int n){
	int i;
	for(i=0;i<count;i++)
	{
		printf("\nprocess-%d ",i+1);
		printf("Pid=%d\tPname=%s\tpriority=%d\tBT=%f\n",
		table[i].id,table[i].pName,table[i].priority,table[i].BT);
	}
}

void swap(Process* a, Process* b){
	Process temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSortByPriority(Process table[],int n){
	int i,j;
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(table[j].priority > table[j+1].priority)
			{
				swap(&table[j], &table[j+1]);
			}
		}
	}
	printf("Sorted by priority (ascending)\n");
}

void InsertionSortByPid(Process table[], int n){
	int i, j;
	for(i=1; i<count; i++){
		Process key = table[i];
		j = i-1;
		while(j>=0 && table[j].id > key.id){
			table[j+1] = table[j];
			j--;
		}
		table[j+1] = key;
	}
	printf("Sorted by Pid (ascending)\n");
}

void shellSortByBT(Process table[], int n){
	int i, j, gap;
	float tempBT;
	char tempName[20];
	int tempId, tempPri;
	for(gap = count/2; gap>0; gap/=2){
		for(i=gap; i<count; i++){
			tempBT = table[i].BT;
			strcpy(tempName, table[i].pName);
			tempId = table[i].id;
			tempPri = table[i].priority;
			for(j=i; j>=gap && table[j-gap].BT > tempBT; j-=gap){
				table[j].BT = table[j-gap].BT;
				strcpy(table[j].pName, table[j-gap].pName);
				table[j].id = table[j-gap].id;
				table[j].priority = table[j-gap].priority;
			}
			table[j].BT = tempBT;
			strcpy(table[j].pName, tempName);
			table[j].id = tempId;
			table[j].priority = tempPri;
		}
	}
	printf("Sorted by BT (ascending)\n");
}

void linearSearchByPid(Process table[], int n){
	int pid, i, found=0;
	printf("Enter Pid to search: ");
	scanf("%d", &pid);
	for(i=0; i<count; i++){
		if(table[i].id == pid){
			printf("Found: Pid=%d Pname=%s priority=%d BT=%f\n", table[i].id, table[i].pName, table[i].priority, table[i].BT);
			found=1;
			break;
		}
	}
	if(!found) printf("Pid not found\n");
}

void BinarySearchByPid(Process table[], int n){
	int pid, low=0, high=count-1, mid, found=0;
	printf("Enter Pid to search: ");
	scanf("%d", &pid);
	while(low <= high){
		mid = (low + high)/2;
		if(table[mid].id == pid){
			printf("Found: Pid=%d Pname=%s priority=%d BT=%f\n", table[mid].id, table[mid].pName, table[mid].priority, table[mid].BT);
			found=1;
			break;
		}
		else if(table[mid].id < pid) low = mid+1;
		else high = mid-1;
	}
	if(!found) printf("Pid not found\n");
}

int main(){
	Process table[SIZE];
	while(1){
		printf("\n1.Add\n2.Display\n3.BubbleSortByPriority\n4.InsertionSortByPid\n5.shellSortByBT\n6.linearSearchByPid\n7.BinarySearchByPid\n8.exit\n");
		int choice;
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: Add(table,SIZE); break;
			case 2: Display(table,SIZE); break;
			case 3: BubbleSortByPriority(table,SIZE); break;
			case 4: InsertionSortByPid(table,SIZE); break;
			case 5: shellSortByBT(table,SIZE); break;
			case 6: linearSearchByPid(table,SIZE); break;
			case 7: printf("Use option 4 first for sorting by Pid\n");
					BinarySearchByPid(table,SIZE); break;
			case 8: exit(0); break;
			default: printf("Invalid choice\n");
		}
	}
	return 0;
}

