int rotationCount(int a[], int size)
{
  int b,min=a[0],n;
  for(b=0;b<size;b++)
  {
    if(a[b]<min)
    {
      min=a[b];
      n=b;
    }
  }
  if(min==a[0])
    return -1;
  else
    return n;
  
}
