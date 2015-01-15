
int main()
{
  int i;
  #pragma omp parallel for
  for(i = 0 ; i < 20 ; i = i + 1){
    printint(i);
  }
  return 0;
}
