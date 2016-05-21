long long int quick_count=0;
int merge_count=0;

long long int bubble_sort(int a[],int n)
{
  int i,j,t,count=0;
  for(i=0;i<n;i++)
  {
    for(j=n-1;j>i;j--)
    {
      count++;
      if(a[j]<a[j-1])
      {
        t=a[j];
        a[j]=a[j-1];
        a[j-1]=t;
      }
    }
  }
  return count;
}

long long int insertion_sort(int a[],int n)
{
  int l;
  int key,i,j,count=0;
  for(j=1;j<n;j++)
  {
    key = a[j];
    i=j-1;

    while(i>=0 && a[i]>key)       // inSErTiOn SOrT
    {
      a[i+1]=a[i];
      count++;
      i=i-1;
      a[i+1]=key;
    }
    count++;
  }
    return count;
}

int partition(int a[],int p,int r)
{
  int x,i,t,j;
  x=a[r];
  i = p-1;
  for(j=p;j<=r-1;j++)
  {
    quick_count++;
    if(a[j]<=x)
    {
      i=i+1;
      t=a[i];
      a[j]=a[i];
      a[i]=t;
    }
  }
  t=a[i+1];
  a[i+1]=a[r];
  a[r]=t;
  return i+1;
}


long long int quick_sort(int a[],int p,int r)
{
  if(p<r)
  { int q;
    q=partition(a,p,r);
    quick_sort(a,p,q-1);
    quick_sort(a,q+1,r);
  }
  return quick_count;
}

long long int selection_sort(int a[],int m)
{
  int i,j,small,pos,swap,count;
  int n=0;
  while(n<m-1)
  {
    small = a[n];
    pos = n;
    for(i=n+1;i<m;i++)
    { count++;
      if(a[i]<small)
      {
        small=a[i];
        pos=i;
      }
    }
    swap=a[pos];
    a[pos]=a[n];
    a[n]=swap;
    n++;
  }
  return count;
}

void merge(int a[], int l, int m, int r)
{

  int i,j,k;
  int n1 = m-l+1;
  int n2 = r-m;
  int la[n1],ra[n2];
  for(i=0;i<n1;i++)
      la[i]=a[l+i];
  for(j=0;j<2;j++)
      ra[j] = a[m+1+j];
  i=0;
  j=0;
  k=l;
  while (i<n1 && j<n2)
  {    merge_count++;

      if (la[i] <= ra[j])
      {
          a[k] = la[i];
          i++;
      }
      else
      {
          a[k] = ra[j];
          j++;
      }
      k++;
  }

}

long long int merge_sort(int a[], int l, int r)
{
  if (l<r)
  {
	  int d;
    int m = l+(r-l)/2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    merge(a, l, m, r);
  }
    return merge_count;
  }
