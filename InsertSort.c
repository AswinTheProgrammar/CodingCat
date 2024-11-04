#include <stdio.h>
int *insertionSort(int array[], int n)
{
int j , temp ,i;
for(i = 1 ; i<n ; i++)
{
j = i;
while(j>0&&array[j]<array[j-1])
{
temp =array[j];
array[j] = array[j-1];
array[j-1] = temp;
j--;

}
}
return array;
}
int main()
{
 int array[1000],n, i;
printf("Enter the number of elements you want to Sort : ");
scanf("%d",&n);
printf("Enter Elements in the list : ");
for(i = 0 ; i<n ; i++)
{
scanf("%d",&array[i]);
}
int *sortArray = insertionSort(array,n);
for(i = 0;i<n;i++)
printf("%d\t",sortArray[i]);
}