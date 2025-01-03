#include <iostream>
#include <limits>
#define SZ 20
using namespace std;

class Graph
{
		char lm[20][15];
		int n,ecnt,cflag;
		int g[SZ][SZ];
	public:
	    void create();
		void kruskal();
		void DFS(int);
};
struct Edge
  {
    int v1,v2,d;
  }E[SZ],T;
int visit[SZ];   // Global array
void Graph :: DFS(int v)
  {
	int i;
	if(visit[v]==0)
	  visit[v]=1;

	// Loop to find vertex which is connected v and unvisited
	for(i=1;i<=n;i++)
	  {
		if(visit[i]==0 && g[v][i]!=999)
		  DFS(i);
	  }
  }

void Graph :: create()
  {
    int i,j,d,k=0;
	cflag=0;
	cout<<"\nEnter No Of Landmarks : ";
	while (true)
        {
            cin>>n;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid integer: ";
            }
            else
                break;
        }
	//Init visit array and graph g
    for(i=1;i<=n;i++)
      {
		visit[i]=0;
	    for(j=1;j<=n;j++)
	      g[i][j]=999;
      }
	cin.ignore();
    for(i=1;i<=n;i++)
      {
		cout<<"\nEnter landmark name"<<i<<" : ";
		cin.getline(lm[i],15);
	  }
	//To create graph g and edge array E
    while(1)
     {
       for(i=1;i<=n;i++)
		 cout<<i<<"."<<lm[i]<<"\t";
       cout<<"\nEnter Two Landmarks Nos For Edge(Press Any No And -1 To Stop) : ";
	   while (true)
        {
            cin>>i>>j;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid integer: ";
            }
            else
                break;
        }
       if(i==-1||j==-1)
	     break;
       else
	     {
	       if(i<1||i>n||j<1||j>n)
	         cout<<"\nInvalid Edge!!";
	       else
		     {
			   cout<<"\nEnter Edge Dist : ";
			   while (true)
				{
					cin>>d;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input! Please enter a valid integer: ";
					}
					else
						break;
				}
			   g[i][j]=g[j][i]=d;
			   E[k].v1=i;
	           E[k].v2=j;
	           E[k].d=d;
			   k++;
	         }
	     }
     }
	//To Sort Edge array E in ascending order of distance.
	ecnt=k;
    for(i=0;i<ecnt-1;i++)
      {
		for(j=i+1;j<ecnt;j++)
		  {
			if(E[i].d>E[j].d)
			  {
				T=E[i];
				E[i]=E[j];
				E[j]=T;
			  }
		  }
      }
	DFS(1);
	for(i=1;i<=n;i++)
	{
		if(visit[i]==0)
		  {
			cflag=1;
			break;
		  }
    }
 }

void Graph :: kruskal()
  {
    int visit[20],es,i,j,k,sum=0,pv1,pv2,c[SZ][SZ];
	if(cflag==1)
	  {
		cout<<"\nGraph Is Not Connected!!!";
        return;
	  }
	//To initialize component array c
    for(i=1;i<=n;i++)
      {
		for(j=1;j<=n;j++)
		  {
			if(j==1)
			  c[i][j]=i;
			else
			  c[i][j]=0;
		  }
      }
    es=0;k=0;
    while(es<n-1)
      {
		T=E[k];
		k++;

		for(i=1;i<=n;i++)
		  {
			for(j=1;j<=n;j++)
			  {
				 if(c[i][j]==T.v1)
				   pv1=i;
				 if(c[i][j]==T.v2)
				   pv2=i;
			  }
		  }
		if(pv1!=pv2)
		  {
			cout<<"\n"<<lm[T.v1]<<" <----->  "<<lm[T.v2]<< " = "<<T.d;
			sum=sum+T.d;
			es++;
			//to merge component array
			for(i=1;c[pv1][i]!=0;i++); // this ; is imp here
			for(j=1;c[pv2][j]!=0;j++,i++)
			  {
				c[pv1][i]=c[pv2][j];
				c[pv2][j]=0;
			  }
		  }
      }
    cout<<"\nCost Of Spanned Tree : "<<sum;
  }

int main()
  {
    Graph G;
	G.create();
	G.kruskal();
	return(0);
  }
