
#define int long long

const int N=100005;

int n, k;
int a[N];

int check(int x)
{
	int reqd=1, sum=a[1];
	if(a[1]>x)
		return 0;
	for(int i=2;i<=n;i++)
	{
		if(sum+a[i]>x)
		{
			if(a[i]>x)
				return 0;
			reqd++;
			sum=a[i];
		}
		else
			sum+=a[i];
	}
	return reqd<=k;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int main()
{
	scanf("%d %d", &k, &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	int ans=binsearch(1, 1e18);
	printf("%d", ans);
	return 0;
}
