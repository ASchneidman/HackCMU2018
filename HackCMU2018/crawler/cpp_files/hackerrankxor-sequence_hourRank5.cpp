#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        long L;
        long R;
        cin >> L >> R;
        long xor1,xor2,a,exor1,exor2,b;
        for(long l=L;l<L+4;++l)
            {
            if(ceil(l/16.0)==floor(l/16.0))
                xor1=0;
            else if(ceil((l-4)/16.0)==floor((l-4)/16.0))
                xor1=l-4;
            else if(ceil((l-8)/16.0)==floor((l-8)/16.0))
                xor1=4;
            else if(ceil((l-12)/16.0)==floor((l-12))/16.0)
                xor1=l;

            if(ceil((l-6)/16.0)==floor((l-6)/16.0))
                xor2=l-3;
            else if(ceil((l-10)/16.0)==floor((l-10)/16.0))
                xor2=4;
            else if(ceil((l-14)/16.0)==floor((l-14)/16.0))
                xor2=l+1;
            else if(ceil((l-18)/16.0)==floor((l-18))/16.0)
                xor2=0;

             if(ceil((l-1)/4.0)==floor((l-1))/4.0)
                a=(l-1)/4;

           }

        for(long l=R;l>R-4;--l)
            {
            if(ceil(l/16.0)==floor(l/16.0))
                exor1=l;
            else if(ceil((l-4)/16.0)==floor((l-4)/16.0))
                exor1=4;
            else if(ceil((l-8)/16.0)==floor((l-8)/16.0))
                exor1=l+4;
            else if(ceil((l-12)/16.0)==floor((l-12))/16.0)
                exor1=0;

            if(ceil((l-6)/16.0)==floor((l-6)/16.0))
                exor2=4;
            else if(ceil((l-10)/16.0)==floor((l-10)/16.0))
                exor2=l+5;
            else if(ceil((l-14)/16.0)==floor((l-14)/16.0))
                exor2=0;
            else if(ceil((l-18)/16.0)==floor((l-18))/16.0)
                exor2=l+1;

             if(ceil((l-1)/4.0)==floor((l-1))/4.0)
                b=(l-1)/4;

           }
        long xor3=b-a+1;
        if(xor3%2==0)
            xor3=0;
        else
            xor3=1;
        long ans=(exor1 xor xor1) xor (exor2 xor xor2) xor xor3;
        printf("%ld\n",ans);

    }
    return 0;
}
