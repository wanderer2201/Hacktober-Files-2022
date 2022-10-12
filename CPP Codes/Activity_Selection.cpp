vector<pair<int,int>> v;

        

        for (int i=0;i<n;i++){

            v.push_back(make_pair(end[i],start[i]));

        }

        

        sort(v.begin(),v.end());

        

        int lastmeet=v[0].first; int count=1;

        for(int i=1;i<n;i++){

            if(lastmeet<v[i].second){

                count++;

                lastmeet=v[i].first;

            }

        }

        return count;
