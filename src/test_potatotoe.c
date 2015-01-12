
int foo1(int a, int b, int c, int d, int e, int f, int g, float h)
{
	return a+b+c+d+e+f+g+h;
}

void foo2(int a, int b, int c, int d, int e, int f, int g, int h)
{
	a=a+b+c+d+e+f+g+h;
}

int main()
{
  foo1(1,0,3,4,5,6,7,2.0);
  int y[10];
  int * x = y;
  x[3]=2;
  
  return 0;
}
