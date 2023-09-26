#include <stdio.h>
int checkIfOccupied(int x,int c[][20],int b[],int n,int sb[]){
	for(int i=0;i<n;i++){
		if(x==sb[i]){
			return 1;
		}
		for(int j=0;j<b[i];j++){
			if(c[i][j]==x)
				return 1;
		}
	}
	return 0;
}
int main(){
	int i,j,n,p=0,temp;
	printf("enter the number of files");
	scanf("%d",&n);
	int sb[n],b[n],c[n][20];
	for(i=0;i<n;i++)
	{
		printf("enter the block size of file-%d :",i+1);
		scanf("%d",&b[i]);
		printf("enter the block number of index of file-%d :",i+1);
		scanf("%d",&temp);
		if(checkIfOccupied(temp,c,b,p,sb)){
			printf("block already occupied\n");
			i--;
			continue;
		}
		sb[i]=temp;
		printf("enter the blocks:");
		for(j=0;j<b[i];j++)
		{
			scanf("%d",&temp);
			if(checkIfOccupied(temp,c,b,p,sb))
			{
				printf("block already occupied\n");
				j--;
				continue;
			}
			c[i][j]=temp;
		}
		p++;
	}
	printf("no\t\tblock of table\tblock length\t allocated blocks\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t",i+1,sb[i],b[i]);
		for(j=0;j<b[i];j++)
			printf("%d,",c[i][j]);
		printf("\n");
	}
}
