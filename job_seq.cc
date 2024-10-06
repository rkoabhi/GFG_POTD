/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compare(Job a, Job b){
        return a.profit > b. profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector <Job> jobs(arr,arr+n);
        
        // now I need to sort using highest profits so that i can palce the highest at the right end
        sort(jobs.begin(),jobs.end(),compare);
        
        int deadline =0;
        for (const auto &job:jobs){
            deadline = max(deadline, job.dead);
        }
        vector<int> slots(deadline+1,-1);
        
        int tprofit =0;
        int jcount =0;
        
        for(const auto& job:jobs){
            for(int i =job.dead;i>0;i--){
                if(slots[i]==-1){
                    slots[i] = job.id;
                    tprofit = tprofit +job.profit;
                    jcount++;
                    break;
                }
            }
        }
        return {jcount,tprofit};
    } 
};
