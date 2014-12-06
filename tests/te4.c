int main() {
	
int tab[10];

#pragma omp parallel for
for (i=0; i<10; i=i+1) {
	#pragma omp parallel for
	for (j=0; j<10; j=j+1) {
		tab[j] = 10*i;
	}
}
  return 0;
}
