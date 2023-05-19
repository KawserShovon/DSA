    struct triplets
    {
        int idx;
        int start;
        int end;
    };
    
    class cmp
    {
        public:
        bool operator()(const triplets&a, const triplets &b)
        {
            if(a.end == b.end) return a.start<b.start;

            return a.end<b.end;
        }
    };
    
    int maxMeetings(int start[], int end[], int n)
    {
       vector<triplets>vt(n);

        for(int i=0 ;i<vt.size(); i++)
        {
            vt[i].idx = i;
            vt[i].start = start[i];
            vt[i].end = end[i];
        }
    
        
        cmp cp;
        sort(vt.begin(),vt.end(),cp);
        // for(auto x:vt)
        // {
        //     cout<<x.idx<<" "<<x.start<<" "<<x.end<<endl;
        // }
    
        triplets last = vt[0];
        vector<int>meetings;
        meetings.push_back(vt[0].idx+1);
        for(int i=1 ;i<vt.size(); i++)
        {
            if(vt[i].start>last.end)
            {
                meetings.push_back(vt[i].idx+1);
                last.end = vt[i].end;
            }
        }
    
        return meetings.size();
    }