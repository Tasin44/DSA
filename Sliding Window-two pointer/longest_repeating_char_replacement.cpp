
///approach 1
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i,l=0,r=0,maxf=0,maxlen=0,change;
        map<char,int>cnt;
        while(r<n)
        {
          cnt[s[r]]++;
          maxf=max(maxf,cnt[s[r]]);
          change=(r-l+1)-maxf;//also checking if this substring is valid or not
          if(change<=k)
          maxlen=max(maxlen,r-l+1);
          else
          {
             int maxf2=0;
             while(change>k)
             {
                l++;
                cnt[s[l-1]]--;
                maxf2=max(maxf2,cnt[s[l]]);
                change=(r-l+1)-maxf2;
             }
             maxlen=max(maxlen,r-l+1);
          }
          r++;
        }

    return maxlen;
    }
};

/*
Summary:The char which has maximum frequency,I'll not convert it,
because it'll take more operation so conversion I required ,
len - maxfrquency

change=(r-l+1)-maxf meaning
possiblility of this segment changing,also checking if this substring is valid or not


TC: O(n+n)
Each character count operation in the map is O(log26).

SC:
The space used by the map cnt is O(26) , so O(1)
*/




///approach-2

///This is the most optimal solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i,l=0,r=0,maxf=0,maxlen=0,change;
        map<char,int>cnt;

        /*
         The char which has maximum frequency,I'll not convert it,because it'll take more operation
         so conversion I required ,
         len-maxfrquency*/

        while(r<n)
        {
            cnt[s[r]]++;
            maxf=max(maxf,cnt[s[r]]);
            change=(r-l+1)-maxf;
            //possiblility of this segment changing,also checking if this substring is valid or not

             if(change>k)
             {
                l++;
                cnt[s[l-1]]--;
             }
             maxlen=max(maxlen,r-l+1);

            r++;
          }
    return maxlen;
    }
};
/*
why I removed here inner while loop:
because only removing a single extra first occurrence
can make the condition valid(check through test cases)
if don't understand,see striver lecture from 22 min
https://youtu.be/_eNhaDCr6P0?feature=shared
*/


/*
Time Complexity: O(n)
Space Complexity: O(1)
*/





















