int minTicketCost(int tc[], int m, int n, int mt[], int nt[]){
	int mincost = 0;
	int mcab = 0;
	int mrick = 0;
	for(int i=0; i<m; ++i){
		int mPcab = min( (mt[i]*tc[0]), tc[1] );
		mcab += mPcab;
	}
	mcab = min(mcab,tc[2]);
	for(int i=0; i<n; ++i){
		int mPrick = min( (nt[i]*tc[0]), tc[1] );
		mrick += mPrick;
	}
	mrick = min(mrick, tc[2]);
	mincost = min( (mcab+mrick), tc[3] );
	return mincost;	
}
