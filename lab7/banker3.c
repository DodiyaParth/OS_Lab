#include<stdio.h>
#include<stdlib.h>
struct p{
	int pid, allo[100], max[100],need[100],done;
};
void main(){
	int n = 0,res, j =0, k =0;
	int sequence_i = 0;
	int sequence[100],avai[100];
	struct p pro[100];
	int op;
	printf("Enter the number of resources: ");
	scanf("%d", &res);

	int i= 0;
	printf("Enter the available resources: ");
	while(i < res){
		scanf("%d", &avai[i]);
		i++;
	}
	int flag =0;

	do{
		printf("Do you want to add a process(1-y,0-n) :" );
		scanf("%d", &op);
		switch(op){
			case 1: 
				flag = 0;
				pro[n].pid = n;
				printf("Enter the allocation resources for process %d : ",n);
				for (j = 0; j < res; ++j)
					scanf("%d", &pro[n].allo[j]);

				printf("Enter the max resources for process %d : ",n);
				for (j = 0; j < res; ++j)
					scanf("%d", &pro[n].max[j]);
		
				for(int k= 0;k<res;k++){
					if( pro[n].max[k] - pro[n].allo[k] > avai[k])
						flag = 1;
				}

				if(flag ==0){
					for( k =0;k<res;k++){
						avai[k] += pro[j].allo[k];
					}
				sequence[sequence_i] = sequence_i; 
				n++;
				}
				else
					printf("Deadlock\n");
				break;

			case 0: 
				break;
		}
	}while(op!=0);
	
	

	i = 0;
	printf("The sequence is : ");
	while(i < n){
		printf("P%d ", sequence[i]);
		i++;
	}
}
