int main(){
	
int i;

#pragma omp parallel for
for (i=0; i<10; i=i+1) {

if (i==3){
	return i;
	}
if (i==8){
	return i;
}
  
  return 0;
}
