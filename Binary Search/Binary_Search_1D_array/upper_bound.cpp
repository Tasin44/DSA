
//procedure 1
int upperBound(vector<int> &arr, int x, int n)
{
		int l=0,r=n-1,ans=n;
		while(l<=r)
		{
            int mid=l+(r-l)/2;
			if(arr[mid]>x)
            {
               r=mid-1;
               ans=min(ans,mid);
            }

			else l=mid+1;
		}
return ans;
}


//procedure 2
int upperBound(vector<int> &arr, int x, int n)
{
		int l=0,r=n-1;
		while(l<=r)
		{
            int mid=l+(r-l)/2;
			if(arr[mid]>x)
			r=mid-1;
			else l=mid+1;
		}
return r+1;
}
