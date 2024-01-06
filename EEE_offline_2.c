#include <stdio.h>
#include <stdlib.h>
const int N=100;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Check_sorted(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return 0;
        }
    }
    return 1;
}

void Input_array(int arr[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

int Sort_array(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
}

void Print_array(int arr[],int n){
    for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
}

float Mean(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum/n;
}

void Median(int arr[],int n){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }
    if(!Check_sorted(arr,n)){
        Sort_array(temp,n);
    }
    
    if(n%2!=0){
        printf("Median: %d\n",temp[n/2]);
    }
    else{
        printf("Median: %d  %d\n",temp[n/2-1],temp[n/2]);
    }
}

int Maximum_repeated_element(int arr[],int n){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }
    Sort_array(temp,n);
    int max_arr_idx=0;
    int max_count=0;
    int current_max_count=0;
    for(int i=0;i<n;i++){
        current_max_count=1;
        while(temp[i]==temp[i+1]){
            current_max_count++;
            i++;
        }
        if(current_max_count>max_count){
            max_count=current_max_count;
            max_arr_idx=i;
        }
    }
    if(max_count==1){
        return -1;
    }
    return max_arr_idx;
}

void Mode(int arr[],int n){
    int mode_idx=Maximum_repeated_element(arr,n);
    if(mode_idx==-1){
      printf("All number are unique\n"); 
    }
    else{
       printf("Mode: %d\n",arr[mode_idx]); 
    }
    
}

void Unique_elements(int arr[],int n){
    int should_print=1;
    for(int i=0;i<n;i++){
        should_print=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]==arr[i]){
                should_print=0;
            }
        }
        if(should_print==1){
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}

void Matrix_Addition(int r1,int c1,int arr1[][N],int r2,int c2,int arr2[][N]){
    if(r1==r2 && c1==c2){
        printf("Matrix Addition(A+B):\n");
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                int sum=arr1[i][j]+arr2[i][j];
                printf("%d ",sum);
            }
            printf("\n");
        }
    }
    else{
        printf("The dimensions of the matrix should be same\n");
        return;
    }
}

void Matrix_Subtraction(int r1,int c1,int arr1[][N],int r2,int c2,int arr2[][N]){
    if(r1==r2 && c1==c2){
        printf("Matrix Subtraction(A-B):\n");
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                int sub=arr1[i][j]-arr2[i][j];
                printf("%d ",sub);
            }
            printf("\n");
        }
    }
    else{
        printf("The dimensions of the matrix should be same\n");
        return;
    }
}

void Matrix_Multiplication(int r1,int c1,int arr1[][N],int r2,int c2,int arr2[][N]){
    if(c1==r2){
        int n=c1;
        printf("Matrix Multiplication(A x B):\n");
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                int sum=0;
                for(int k=0;k<n;k++){
                    sum+=arr1[i][k]*arr2[k][j];
                }
                printf("%d ",sum);
            }
            printf("\n");
        }
    }
    else{
        printf("The Row of A & coloum of B matrix should be same\n");
        return;
    }
}

void Union(int arr1[],int n1,int arr2[],int n2){
    Sort_array(arr1,n1);
    Sort_array(arr2,n2);
    int i=0,j=0,k=0;
    int n=n1+n2;
    int arr[n];
    while(i!=n1 && j!=n2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }
    while(i!=n1){
        arr[k++]=arr1[i++];
    }
    while(j!=n2){
        arr[k++]=arr2[j++];
    }
    printf("\nUnion: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    int flag=0;
    while(1){
        if(flag==1){
            printf("Invaild array size!!!\n");
        }
        printf("Enter the number of array element:");
        scanf("%d",&n);
        if(n>0){
            break;
        }
        flag=1;
    }
    int arr[n];//array which to manipulate
    int option;
    while(1){
        system("cls");
        printf("\n1) Input\n");
        printf("2) Sort\n");
        printf("3) Mean\n");
        printf("4) Median\n");
        printf("5) Mode\n");
        printf("6) Print array elements\n");
        printf("7) Check array is sorted or not\n");
        printf("8) Find all unique elements\n");
        printf("9) Union of two arrays\n");
        printf("10) Matrix Operation\n");
        printf("11) Exit\n");
        printf("\nEnter any option:");
        scanf("%d",&option);

        if(option==1){
            Input_array(arr,n);
        }

        else if(option==2){
            Sort_array(arr,n);
        }

        else if(option==3){
            printf("\nMean: %f\n",Mean(arr,n));
            system("pause");
        }

        else if(option==4){
            Median(arr,n);
            system("pause");
        }

        else if(option==5){
            Mode(arr,n);
            system("pause");
        }

        else if(option==6){
            Print_array(arr,n);
            system("pause");
        }

        else if(option==7){
            if(Check_sorted(arr,n)){
                printf("The array is sorted\n");
            }
            else{
                printf("The array is not sorted\n");
            }
            system("pause");
        }

        else if(option==8){
            Unique_elements(arr,n);
            system("pause");
        }

        else if(option==9){
            int n1;
            printf("Enter the number of 1st array element:");
            scanf("%d",&n1);
            int arr1[n1];
            for(int i=0;i<n1;i++){
                scanf("%d",&arr1[i]);
            }
            int n2;
            printf("Enter the number of 2nd array element:");
            scanf("%d",&n2);
            int arr2[n2];
            for(int i=0;i<n2;i++){
                scanf("%d",&arr2[i]);
            }
            Union(arr1,n1,arr2,n2);
            printf("\n");
            system("pause");
        }

        else if(option==10){
            int suboption;
            int r1=0,r2=0,c1=0,c2=0;
            int arr1[N][N];
            int arr2[N][N]; 
            while(1){
                system("cls");
                printf("1. Matrix Input\n");
                printf("2. Matrix Addition\n");
                printf("3. Matrix Subtraction\n");
                printf("4. Matrix Multiplication\n");
                printf("5. Back to main\n");
                printf("Enter any sub-option: ");
                scanf("%d",&suboption);
                if(suboption==1){
                    printf("\nEnter (Row x Coloumn) of matrix A:\n");
                    scanf("%d%d",&r1,&c1);
                    printf("Enter elements of matrix A:\n");
                    for(int i=0;i<r1;i++){
                        for(int j=0;j<c1;j++){
                            scanf("%d",&arr1[i][j]);
                        }
                    }
                    printf("\nEnter (Row x Coloumn) of matrix B:\n");
                    scanf("%d%d",&r2,&c2);
                    printf("Enter elements of matrix B:\n");
                    for(int i=0;i<r2;i++){
                        for(int j=0;j<c2;j++){
                            scanf("%d",&arr2[i][j]);
                        }
                    }
                }
                else if(suboption==2){
                    Matrix_Addition(r1,c1,arr1,r2,c2,arr2);
                    system("pause");
                }
                else if(suboption==3)
                {
                    Matrix_Subtraction(r1,c1,arr1,r2,c2,arr2);
                    system("pause");
                }
                else if(suboption==4)
                {
                    Matrix_Multiplication(r1,c1,arr1,r2,c2,arr2);
                    system("pause");
                }
                else if(suboption==5)
                {
                    break;
                }
                else{
                    printf("\nInvaild option\n");
                    system("pause");
                }
            }
        }

        else if(option==11){
            exit(0);
        }

        else{
            printf("\nInvaild option\n");
            system("pause");
        }
    }
    
   return 0;
}
