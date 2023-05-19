
void printSubsequences( string s, string ans)
{
   if(s.length()==0)
   {
        cout<<ans<<endl;
        return;
   }

   printSubsequences(s.substr(1),ans);
   printSubsequences(s.substr(1),ans+s[0]);
}

void printSubsequences(char input[]) {
    // Write your code here
    string s ="";
    int i =0;
    while(input[i] != NULL)
    {
        s += input[i];
        i++;
    }
    
    printSubsequences(s,"");

}
