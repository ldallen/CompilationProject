int main() {

int i;
int a = 0;
#pragma omp parallel for
for (i=0; i<10; i=i+1) {
   if (	i<5 && a>0)
	{a = a -1;}
	else if ( i>=5 && a<=0)
	{a = a + 1;}
}
  
  return 0;
}
