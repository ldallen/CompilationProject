int foo()
{
		int x;
		x = 3;
		return x;
}
int main()
{
  int x;
  int y;
  x = 3;
  y = 10;
  if(x < y)
	printint(x+y);
  x = foo();
  printint(x);
  
  return 0;
}
