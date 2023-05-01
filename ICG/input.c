
void decrease(){
  int x;
  x = 69;
  printf("%d",x);
}
void increase_number()
{
	int x;
  x = 10;
	int y;
	y = 10 + x;
  decrease();
	printf("%d",y);
	
}

void main()
{
	int x;
	x = 4;
	increase_number();
	printf("%d", x);
}