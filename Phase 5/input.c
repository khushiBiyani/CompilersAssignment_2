
void p(int a){
  printf("%d = a ",a);
}
void increase_number(int n,int y)
{
// 	int x;
//   x = 10;
// 	int y;
	// y = 10 + x;
  p(45);
	printf("n: %d y: %d",n,y);
	printf("CHANGES\n");
}


void main()
{

	int x;
	x = 4;
  printf("%d", x);
	increase_number(5,3);
	printf("%d", x);
  for( x = 0;x<5;x++){
    int j;
    for(j=0;j<5;j++){
      int x;
      printf("%d %d", x,j);
    }
  }
  printf("x: %d", x);


}