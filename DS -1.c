#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
typedef struct{
	int id;
	char pName[20];
	int priority;
	float BT;
}Process;
int count=0;
void Add(Process table[],int n){
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
void BubbleSortByPriority(Process table[],int n){
	int i,j;
	for(i=0;i<count;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(table[j].priority>table[j+1].priority)
			{
				int temp=table[j].priority;
				table[j].priority=table[j+1].priority;
				table[j+1].priority=temp;
			}
		}
	}
 printf("Sorted by Priority successfully\n");	
	
}
void InsertionSortByPid(Process table[], int n){
	  int i, j;
    Process key;

    for(i=1;i<count;i++){
        key = table[i];
        j = i - 1;

        while(j >= 0 && table[j].id > key.id){
            table[j+1] = table[j];
            j--;
        }
        table[j+1] = key;
    }
    printf("Sorted by PID using Insertion Sort\n");

}
void shellSortByBT(Process table[], int n){
	 int gap, i, j;
    Process temp;

    for(gap = count/2; gap > 0; gap /= 2){
        for(i = gap; i < count; i++){
            temp = table[i];
            for(j = i; j >= gap && table[j-gap].BT > temp.BT; j -= gap){
                table[j] = table[j-gap];
            }
            table[j] = temp;
        }
    }
    printf("Sorted by Burst Time using Shell Sort\n");

}
void linearSearchByPid(Process table[], int n){
	 int key, i, found = 0;
    printf("Enter PID to search: ");
    scanf("%d", &key);

    for(i=0;i<count;i++){
        if(table[i].id == key){
            printf("Process Found:\n");
            printf("Pid=%d\tPname=%s\tPriority=%d\tBT=%.2f\n",
            table[i].id, table[i].pName, table[i].priority, table[i].BT);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Process not found\n");
}
void BinarySearchByPid(Process table[], int n){
	int low = 0, high = count - 1, mid, key;
    printf("Enter PID to search: ");
    scanf("%d", &key);

    while(low <= high){
        mid = (low + high) / 2;

        if(table[mid].id == key){
            printf("Process Found:\n");
            printf("Pid=%d\tPname=%s\tPriority=%d\tBT=%.2f\n",
            table[mid].id, table[mid].pName, table[mid].priority, table[mid].BT);
            return;
        }
        else if(table[mid].id < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Process not found\n");
	
}
main(){
 Process table[SIZE];
	while(1){
	printf("1.Add\n2.Display\n3.BubbleSortByPriority\n4.InsertionSortByPid\n5.shellSortByBT\n6.linearSearchByPid\n7.BinarysearchByPid\n8.exit\n");
	int choice;
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1:Add(table,SIZE);break;
    	case 2:Display(table,SIZE);break;
    	case 3:BubbleSortByPriority(table,SIZE);break;
    	case 4:InsertionSortByPid(table, SIZE);break;
    	case 5:shellSortByBT(table, SIZE);break;
    	case 6:linearSearchByPid(table, SIZE);break;
    	case 7:printf("come here after sorting");
		       BinarySearchByPid(table, SIZE);break;
	    case 8:exit(0);break;	
	}
}
    
	
}
