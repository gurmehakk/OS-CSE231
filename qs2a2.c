#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

//void copy( float** s, float** d,int n_rows,int n_cols)
 //{
   
  //float matrix[n_rows][n_cols];
	//memcpy(matrix , s , sizeof(matrix)); 
  //memcpy(d , matrix , sizeof(matrix)); 
 //}
 
 int main(){
  float s[2][2]; 
	float d[2][2]; 
	for ( int i  = 0 ; i <2; i++){
	for ( int j = 0 ; j<2; j++){
	s[i][j]= i+ j ; 
  }
  }
  for ( int i  = 0 ; i <2; i++){
	for ( int j = 0 ; j<2 ; j++){
	printf("%f ",d[i][j]);
  }printf("\n");
  }
    //void ** source = &s ; 
    //void ** des = &d ; 
   // copy(s, d,2,2);
    syscall(448,s,d,2,2);
    //kernel_2d_memcpy(335,s,d,2,2);
    for ( int i  = 0 ; i <2; i++){
	for ( int j = 0 ; j<2 ; j++){
	printf("%f ",d[i][j]);
  }printf("\n");
  }
  



 return 0;
 }