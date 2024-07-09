#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class process
{
	public:
		int pno;
		int arr, burst;
		int start, end;
		int resp,wait,turn;
		process()
		{
		}
		process(int no, int bur, int ar=0)
		{
			pno=no;
			burst=bur;
			arr=ar;
			start=arr;end=arr+burst;resp=0;wait=0;
			turn=end-arr;
		}
		void calc()
		{
			resp=start-arr;
			wait=start-arr;
			turn=end-arr;
		}
		void disp()
		{
			cout<<left<<setw(12)<<pno
				<<left<<setw(12)<<arr
				<<left<<setw(12)<<burst
				<<left<<setw(12)<<start
				<<left<<setw(12)<<end
				<<left<<setw(12)<<resp
				<<left<<setw(12)<<wait
				<<left<<setw(12)<<turn<<endl;
		}
		void headdisp()
		{
			cout<<left<<setw(12)<<"Process no"
				<<left<<setw(12)<<"Arrival"
				<<left<<setw(12)<<"Burst"
				<<left<<setw(12)<<"Start"
				<<left<<setw(12)<<"End"
				<<left<<setw(12)<<"Response"
				<<left<<setw(12)<<"Wait"
				<<left<<setw(12)<<"Turnaround"<<endl;
		}
};
int main()
{
	int pu,n,b,a;
	cout<<"Enter Number of processers:";
	cin>>pu;
	cout<<"Enter Number of processes:";
	cin>>n;
	int procers[pu]={};
	int procerind[pu]={};
	process procs[n];
	int totb=0;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Burst and arrival time for process number "<<i+1<<": ";
		cin>>b>>a;
		procs[i]=process(i+1,b,a);
		totb=totb+b;
	}
	process temp;
	for(int x=1;x<n;x++)
	{
		for(int y=x;y>0;y--)
		{
			if (procs[y].arr<procs[y-1].arr)
			{
				temp=procs[y];
				procs[y]=procs[y-1];
				procs[y-1]=temp;
			}
		}
	}
	int current=0;
	for (int t=procs[0].arr-1;t<=totb-1;t++)
	{
		for(int j=0;j<pu;j++)
		{
			bool runnin=false;
			if(procers[j]>0)
			{
				runnin=true;
				procers[j]--;
			}
			if(procers[j]==0)
			{
				if (current<n && procs[current].arr<=t)
				{
					procers[j]=procs[current].burst;
					procerind[j]=current;
					procs[current].start=t;
					procs[current].end=t+procs[current].burst;
					current++;
				}
			}
			if (runnin && current>=n)
			break;	
		}
	}
	int waitavg=0;int turnavg=0;
	procs[0].headdisp();
	for(int i=0;i<n;i++)
	{
		procs[i].calc();
		waitavg=waitavg+procs[i].wait;
		turnavg=turnavg+procs[i].turn;
		procs[i].disp();
	}
	cout<<"Average Waiting time is: "<<waitavg/n<<endl;
	cout<<"Average Turnaround time is: "<<turnavg/n<<endl;
}
