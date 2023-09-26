#include <stdio.h>
int checkIfOccupied(int sb,int c[][20],int b[],int n){
	for(int i=0;i<n;i++)
		if(c[i][0]<sb &&c[i][b[i]-1]>sb)
			return 1;
	return 0;
}
int checkCanOccupy(int s,int bs,int c[][20],int n){
	int f=s+bs-1;
	for(int i=0;i<n;i++)
	{
		if(s<c[i][0]&&f>=c[i][0])
			return 1;
	}
	return 0;
}
int main(){
	int i,j,n,p;
	printf("enter the number of files");
	scanf("%d",&n);
	int sb[n],b[n],c[n][20];
	
	for(i=0;i<n;i++){
		printf("enter the starting block of file-%d :",i+1);
		scanf("%d",&sb[i]);
		if(checkIfOccupied(sb[i],c,b,p)){
			printf("already occupied\n");
			i--;
			continue;
		}
		printf("enter the number of blocks of file- %d :",i+1);
		scanf("%d",&b[i]);
		if(checkCanOccupy(sb[i],b[i],c,p)){
			printf("can't allocate the file\n");
			i--;
			continue;
		}
					
		for(j=0;j<b[i];j++)
			c[i][j]=sb[i]++;
		p++;
	}
	printf("ID\t\tblock length\tstarting block\t allocated memories\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t",i+1,b[i],c[i][0]);
		for(j=0;j<b[i];j++)
			printf("%d,",c[i][j]);
		printf("\n");
	}	
}

