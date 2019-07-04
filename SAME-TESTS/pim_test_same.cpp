#include <iostream>
#include <stdio.h>

//Necessary
#include <gem5/m5ops.h>

void print_pic_matrix(int mat[][256]){
	for(int i =0; i <256; i++){
		for(int j = 0; j <256; j++){
			printf("%d ",mat[i][j]);
			if(j == 255){printf("\n");}		
		}	
	}
	printf("\n");

}

void test_cont(int num_lines,int pic_mat[256][256]){    
	static int pic_mat_ryan[256][256]= {0};
	int d=0; //placeholder
    int height=256;
    int width= 256;
    int i = 1;
    num_lines+=1; //line incrementation +1
    int increment=num_lines-1; //to increment num_lines which lets CPU know when to stop
    int run_limit=2*increment+1; //stops flow of for stment when pattern should restart
    while(i<height-1){
        for(; i < run_limit; i++){
            if(i==height-1){
                break;
            }
            for(int j=1;j<width-1;j++){
                if(i<num_lines){
                	int curr = pic_mat[i-1][j-1] + 2*pic_mat[i-1][j] + pic_mat[i-1][j+1] - pic_mat[i+1][j-1] - 2*pic_mat[i+1][j] - pic_mat[i+1][j+1];
			pic_mat_ryan[i][j] = curr;    
                }else{
			int curr=0;
                    PIM((uint64_t)pic_mat,(uint64_t)&d,(uint64_t)&curr);
			pic_mat_ryan[i][j] = curr;
                }
            }
        
        }
    num_lines+=increment*2;
    run_limit+=increment*2;
    }
	//print_pic_matrix(pic_mat_ryan);
}
	
int main(){
	int arr[256][256]={3};
	test_cont(1,arr);
	printf("SUCCESS, check stats same 1 split\n");
	//std::cout<<"(pim_test.cpp) : Use PIM to calculate the sum from 1 to 100"<<std::endl;
	//uint64_t sum=0;
	//uint64_t sum2=0;
	//uint64_t b[2] = {4,5};
	//uint64_t *ptr=b+1;
	//uint64_t *ptr1= c+1;
	/**
	uint64_t *ptr;//=c+8;
	uint64_t *d;//=c+11;
	uint64_t sum= -1;

uint64_t c[45] = {0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,160,0,0,0,0,0,0,0};
	
ptr=c+12;
d=c+7;
	//uint64_t c =5;
	//for(uint64_t i=1;i<=1;i++){
		//sum+=i;
		
		PIM((uint64_t)ptr,(uint64_t)d,(uint64_t)&sum);
		

	//}
	printf("RESULT, sum: %d\n",sum);
	//printf("RESULT, c[3]: %d\n",c[3]);
		
}		
**/
}

