#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define MAX 10e10
#define ll long long
using namespace std;

int main()
{
	ll t;
	cin>>t;
	while (t--){
		int n,k;
		cin>>n>>k;
		vector <vector <int>> A(2001,vector <int>(2001,0));
		vector <int> B;
		for (int i=0;i<n;i++){
			int x;
			cin>>x;
			A[i+1][x]++;
			B.push_back(x);
		}
		for (int i=0;i<2001;i++){
			int sum=0;
			for (int j=0; j<2001;j++){
				sum+=A[j][i];
				A[j][i]=sum;
			}
		}


		ll ans=0;
		for (int si=1;si<=n;si++){
			multiset <int> pq;


			int temp= si, z=1;
			if (temp<k){
				if (k%temp == 0) z=k/temp;
				else z=k/temp+1;
			}

			int x;
			if (k%z==0) x= k/z;
			else x=k/z+1;

			int m=si;

			while (m--) {
				pq.insert(B[m]);
				if (pq.size()>x) pq.erase(prev(pq.end(),1));
			}

			for (int l=1;l<=n-si+1;l++){

				int r= l+si-1;


				int j=*prev(pq.end(),1);

				if (pq.find(B[l-1])!=pq.end()) pq.erase(pq.find(B[l-1]));
				if (r<n) pq.insert(B[r]);

				// for (int i=0;i<2001;i++){
				// 	j+= A[r][i]-A[l-1][i];
				// 	if (j>=x) {
				// 		j=i;
				// 		break;
				// 	}
				// }


				temp=(A[r][j]-A[l-1][j]);
				if (A[r][temp]-A[l-1][temp]>0) ans++;

				// int c=0;
				// for (int i=0;i<n;i++){
				// 	if (A[i].second<=r && A[i].second>=l && j==A[i].first) c++;
				// }
				// for (int i=0;i<n;i++){
				// 	if (A[i].second<=r && A[i].second>=l && c==A[i].first) {
				// 		ans++;
				// 		break;
				// 	}
				// }
			}
		}

		cout<<ans<<endl;
	}
}

