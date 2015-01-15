int main() {
	
int tab[10];
int i,j;
#pragma omp parallel for
for (i=0; i<10; i=i+1) {
	#pragma omp parallel for
	for (j=0; j<10; j=j+1) {
		tab[j] = 10*i;
	}
} // On ne sait pas quelle sera la valeur du tab à la fin..
  return 0;
}
