int A, B; // number of left & right vertices

bool vis[A]; // did I already see this vertex?
int  rev[B]; // what is this right-vertex matched with? (-1 if not)

bool dfs(int pos){
	if(vis[pos]) return false;
	vis[pos]=true;
	for(auto& nxt : edge[pos]){ // for all connected vertices
		if(rev[nxt]==-1 || dfs(rev[nxt])){
			rev[nxt]=pos;
			return true;
		}
	}
	return false;
}

// now, if you want to find maximal matching...
for(int j=0; j<B; ++j) rev[j]=-1;
int matchings = 0;
for(int i=0; i<A; ++i){
	for(int j=0; j<A; ++j) vis[j]=false;
	if(dfs(i)) ++matchings;
}