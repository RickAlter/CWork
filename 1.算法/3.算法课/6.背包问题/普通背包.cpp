/*************************************************************************
	> File Name: 普通背包.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月17日 星期二 20时44分58秒
 ************************************************************************/

#include<iostream>
using namespace std;


void swap(int *t1, int *t2){
    int temp;    
	temp = *t1;    
	*t1 = *t2;    
	*t2 = temp;
} 
void bubble_sort(int a[], int len, int w[],int v[],int num[]){
    int i, j;     
	for (i = 0; i < len -1; i++){    
	    for (j = 0; j < len -1 -i; j++){      
		    if (a[j] < a[j + 1]){            //		    if (arr[j] > arr[j + 1]){      
			    swap(&a[j], &a[j + 1]); 
				swap(&w[j], &w[j + 1]); 
				swap(&v[j], &v[j + 1]);  
				swap(&num[j], &num[j + 1]); 	         
			}        
		}    
	}
}

int KnapSack(int n,int w[],int v[],int x[],int num[],int C){
    int a[n];          
    int i,j,V;
	for(j=0;j<n;j++)
    	a[j]=v[j]/w[j];
		
    bubble_sort(a,n,w,v,num);

    for (i=0; i<n; i++){
        if (w[i]>C)     break;
        x[i] = 1;
        C -= w[i];
        V += v[i];
    }
    
    if(C!=0)
        x[i]=1;
        V=V+C*a[i];
        printf("排列后物品顺序是:\n");
        for(i=0;i<n;i++)
            printf("%d ",num[i]);
        printf("\n");        
        printf("选中的物品是:\n");
        for(i=0;i<n;i++)
            printf("%d ",x[i]);
        printf("\n");
    return V;
} 

int main(){
    int s;//获得的最大价值
    int w[15];//物品的重量
    int v[15];//物品的价值
    int x[15];//物品的选取状态
    int num[15];//物品序号 
    for(int k=0;k<15;k++) num[k]=k+1;
    int n,i;
    int C;//背包最大容量
    n=5;
    printf("请输入背包的最大容量:\n");
    scanf("%d",&C);

    printf("输入物品数:\n");
    scanf("%d",&n);
    printf("请分别输入物品的重量:\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);

    printf("请分别输入物品的价值:\n");
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);

    s=KnapSack(n,w,v,x,num,C);

    printf("最大物品价值为:\n");
    printf("%d\n",s);
    return 0;
}

