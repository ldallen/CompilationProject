int main() {

int tab[10];
	
#pragma omp parallel for
for (i=0; i<10; i=i+1) {
	tab[i] = 10*i;
}
  
  return 0;
}
