int f(int i){
		
	return i*i+1;
	
}

int main() {
	
	int i;
	
#pragma omp parallel for
for (i=0; i<200; i=f(i)) {
}
  
  return 0;
}
