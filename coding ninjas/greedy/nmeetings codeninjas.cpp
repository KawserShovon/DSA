
struct triplets
{
    int idx;
    int start;
    int end;
};


bool cmp(const triplets&a, const triplets &b)
{
    if(a.end == b.end) return a.idx<b.idx;

    return a.end<b.end;
}


vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<triplets>vt(start.size());

    for(int i=0 ;i<start.size(); i++)
    {
        vt[i].idx = i;
        vt[i].start = start[i];
        vt[i].end = end[i];
    }


    sort(vt.begin(),vt.end(),cmp);
 

    triplets last = vt[0];
    vector<int>meetings;
    meetings.push_back(vt[0].idx+1);
    int currdiff;
    for(int i=1 ;i<vt.size(); i++)
    {
        if(vt[i].start>last.end)
        {
            meetings.push_back(vt[i].idx+1);
       
            last = vt[i];
            currdiff = vt[i].end=vt[i].start;
        }
       
    }

    return meetings;
    
}