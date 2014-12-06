int main() {

int i;
	
#pragma omp parallel for
for (i=0; i<10; i=i+1) {
}

  return 0;
}
