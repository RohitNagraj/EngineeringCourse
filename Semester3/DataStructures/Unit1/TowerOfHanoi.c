/*
Explaination: Assume we have n disks in the source, the basic idea of the algorithm is, move n-1 disks to temp,
move the last remaining one to destination, move all n-1 disks from temp to destination.
Base condition: If theres only one disk to be moved, move it from source to destination
Recurssion: if there is more than 1 disk, move all the n-1 to temp, move nth disk to destination, move n-1 from
temp to destination.
*/

#include<stdio.h>
#include<conio.h>
int step=0;

void moveTower(int size, char source, char destination, char temp)
//The order in the above line is important, first parameter is always size, 2nd is always source, 3rd is always
//destination and 4th is always temp.
{
  if(size==1) //Base condition
  {
    printf("Move disk %d from %c to %c\n",size,source,destination);
  }

  else
  {
    moveTower(size-1,source,temp,destination);
    //This line moves n-1 disks to temp since temp is passed as the destination for the function
    printf("Move disk %d from %c to %c\n",size,source,destination);
    //This line moves the nth disk from source to destination
    moveTower(size-1,temp,destination, source);
    //This line moves n-1 disks back from temp to destination.
  }

  step++; //To count no. of steps

}
int main()
{
  int size;
  char source='A',destination = 'B', temp='C';
  printf("Enter the size of the tower: ");
  scanf("%d",&size);
  moveTower(size,source,destination,temp);
  printf("\nSteps = %d\n",step);

  return 0;
}
