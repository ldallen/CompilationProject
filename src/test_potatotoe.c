int foo(int x, int y, int z){
	
	return x+y+z;
}

int main()
{
	int x;
	x=4;
	x = x + foo(2,3,4);
	x = x - 3 + foo(1,2,3);
	x = x +5;
  return 0;
}
