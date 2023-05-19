int carfleet(vi position, vi speed, int target)
{
    int n = position.size();
    vector<vector<double>> cardata(n,vector<double>(2,0));
    //0-> position
    // 1-> speed

    for(int i=0; i<n; i++)
    {
        cardata[i][0] = position[i]*1.0;
        cardata[i][1] = (target-position[i]*1.0)/(speed[i]*1.0);
    }

    //remind to pass by reference otherwise it will show you TLE
    sort(cardata.begin(),cardata.end(),[](vector<double>&a, vector<double>&b)->bool
                                            {
                                                return a[0]<b[0];
                                            });

    int noofFleet = 1;
    double tt = cardata[n-1][1];
    for(int i=n-2; i>=0; i--)
    {
        if(cardata[i][1]> tt)
        {
            noofFleet++;
            tt = cardata[i][1];
        }
    }

    return noofFleet;
}