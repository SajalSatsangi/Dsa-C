#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define max 100000
void display(int a[],int n);
void bubble_sort(int a[],int n,int choice1);
void selection_sort(int a[],int n,int choice1);
void insertion_sort(int a[],int n,int choice1);
//-----------------Main Function----------------------
int main()
{
 int n,choice,i,choice1;
 clock_t t;
 int arr[max];
 printf("Enter no. of elements u want to sort : ");
 scanf("%d",&n);

 for(i=0;i<n;i++)
 arr[i]= rand()%100000;
printf("Please select any option Given Below for Sorting : \n");

while(1)
 {
  printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Display Array.\n5. Exit the Program.\n");
  printf("\nEnter your Choice : ");
  scanf("%d",&choice);
 switch(choice)
 {
     case 1:
           t=clock();
           printf("\n1. Ascending order\n2. Descending order\n\nEnter your Choice : ");
           scanf("%d",&choice1);
           bubble_sort(arr,n,choice1);
           t= clock()-t;
           double time_taken = ((double)t)/CLOCKS_PER_SEC;
           printf("\nSorting took %f seconds to execute \n", time_taken);
           break;
     case 2:
           t=clock();
           printf("\n1. Ascending order\n2. Descending order\n\nEnter your Choice : ");
           scanf("%d",&choice1);
           selection_sort(arr,n,choice1);
           t= clock()-t;
           double time_take = ((double)t)/CLOCKS_PER_SEC;
           printf("\nSorting took %f seconds to execute \n", time_take);
           break;
     case 3:
           t=clock();
           printf("\n1. Ascending order\n2. Descending order\n\nEnter your Choice : ");
           scanf("%d",&choice1);
           insertion_sort(arr,n,choice1);
           t= clock()-t;
           double time_tak = ((double)t)/CLOCKS_PER_SEC;
           printf("\nSorting took %f seconds to execute \n", time_tak);
           break;
     case 4:
           display(arr,n);
           break;
     case 5:
           return 0;
     default:
           printf("\nPlease Select only 1-5 option ----\n");
}
}
return 0;
}
//-----------End of main function---------------------

//-------------------Display Function-----------------
void display(int arr[],int n)
{
   for(int i=0;i<n;i++)
       {
       printf(" %d ",arr[i]);
       }
}
//---------------------Bubble Sort Function-----------
void bubble_sort(int arr[],int n,int choice1)
{   int i,j,temp;

  switch(choice1)
{
    case 1:
        for(i=0;i<n;i++)
    {   for(j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
           {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
           }
    }
}
printf("After Bubble sort Elements are : ");
display(arr,n);
break;

case 2:
        for(i=0;i<n;i++)
    {   for(j=0;j<n-i-1;j++)
    {
        if(arr[j]<arr[j+1])
           {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
           }
    }
}
printf("After Bubble sort Elements are : ");
display(arr,n);
break;
default: printf("\n Either ascending order or descending order ie 1 or 2\n");
}
}
//------------------Selection Sort Function---------
void selection_sort(int arr[],int n,int choice1)
{   int i,j,temp;
    switch(choice1)
    {
     case 1:
          for(i=0;i<n-1;i++)
        { for(j=i+1;j<n;j++)
        {
          if(arr[i]>arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}
printf("After Selection sort Elements are : ");
display(arr,n);
break;
case 2:
                    for(i=0;i<n-1;i++)
        { for(j=i+1;j<n;j++)
        {
          if(arr[i]<arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}
printf("After Selection sort Elements are : ");
display(arr,n);
break;
default :  printf("\n Either ascending order or descending order ie 1 or 2\n");
}
}
//---------------Insertion Sort Function-------------------
void insertion_sort(int arr[],int n,int choice1)
{    int i,j,min;
    switch(choice1)
{
     case 1:
          for(i=1;i<n;i++)
        {
          min=arr[i];
          j=i-1;
          while(min<arr[j] && j>=0)
        {
          arr[j+1]=arr[j];
          j=j-1;
        }
          arr[j+1]=min;
        }
printf("After Insertion sort Elements are : ");
display(arr,n);
break;
    case 2:
          for(i=1;i<n;i++)
        {
          min=arr[i];
          j=i-1;
          while(min>arr[j] && j>=0)
        {
          arr[j+1]=arr[j];
          j=j-1;
        }
          arr[j+1]=min;
        }
printf("After Insertion sort Elements are : ");
display(arr,n);
break;
default :  printf("\n Either ascending order or descending order ie 1 or 2\n");
}
}
