//Codechef :  https://www.codechef.com/status/CDZ14C,rashedcs
#include<bits/stdc++.h>
using namespace std;


int arr[20][20];

int vis[20][20];
int dist[20][20];

int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

int n, m, ans;

int safe(int x,int y)
{
  return x>=0 && y>=0 && x<n && y<m;
}


void bfs(int sx, int sy, int dx, int dy)
{
            ans = INT_MAX;
       

	    queue< pair<int,int> > q;
   	    q.push(make_pair(sx,sy));

            vis[sx][sy]=1;
            dist[sx][sy]=0;

	     while(!q.empty())
	     {
		    int r=q.front().first;
	            int c=q.front().second;
		    q.pop();
			
                    if(arr[r][c]==0 ) 
		    {
	                 //   ans = -1 //No need to initialize ans = -1 because it at first initialize INT_MIN
			break;
		    }      
       
                    if(dx==r && dy==c)  
                    {
                          ans = 1;   //If destination is found then ans=true, break;
                          break;
                    }
		     
	    	    for(int i=0; i<4; i++)
	    	    {
		          int a = r + dr[i];
		    	  int b = c + dc[i];

                          if(safe(a,b)  && !vis[a][b] && arr[a][b])
                          {
                              q.push(make_pair(a,b));
                              dist[a][b] = dist[r][c]+1;
                              vis[a][b]=1;
                          }
		   }
	       }
   }


int main()
{
    ios::sync_with_stdio(false);
    int tc, dx, dy;

    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;

        memset(arr,0,sizeof(arr));
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));

        for(int i=0; i<n; i++)
        {
           for(int j=0; j<m; j++)
           {
              cin>>arr[i][j];
           }
        }
        cin>>dx>>dy;

       bfs(0,0,dx,dy);
       
        if(ans==1) // If destination node is possible
	        cout<<dist[dx][dy]<<endl;
        else    // Otherwise -1 
	        cout<<"-1"<<endl;

    }
    return 0;
}

