

struct pairs
{
    int health;
    int armor;

    pairs(int health, int armor)
    {
        this->health = health;
        this->armor = armor;
    }
};

bool isPossible(int health, int armor, pairs &p)
{
    int lhealth = health+p.health;
    int larmor = armor+p.armor;
   
    if(lhealth<=0 or larmor<=0)
    {
        return false;
    }
    return true;
}

pairs getVal(int health, int armor, pairs &p)
{
    int lhealth = health+p.health;
    int larmor = armor+p.armor;

    pairs newPair = pairs(lhealth,larmor);
    return newPair;
}

void diehard(int health, int armor)
{
    pairs air = pairs(3,2);
    pairs water = pairs(-5,-10);
    pairs fire = pairs(-20,5);

    bool moveAir = true;
    int cnt = 0;
    while(health>=0 or armor>=0)
    {
        
        if(moveAir)
        {
            cnt++;
            moveAir = false;
            health += air.health;
            armor += air.armor;
        

        }
        else 
        {
       
            moveAir = true;
            if(isPossible(health,armor,water))
            {
               
                cnt++;
                health = getVal(health,armor,water).health;
                armor = getVal(health,armor,water).armor;
                
            }
            else if(isPossible(health,armor,fire))
            {
                
                cnt++;
                health = getVal(health,armor,fire).health;
                armor = getVal(health,armor,fire).armor;
            }
            else 
            {
                
                cout<<cnt<<endl;
                break;
            }

        }

    }
}



int main()
{
    file_in_out();

    int t;
    cin>>t;

    while(t--)
    {
        int health,armor;
        cin>>health>>armor;

        diehard(health,armor);
    }

}
