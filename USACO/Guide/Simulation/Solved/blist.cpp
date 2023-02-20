#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("blist");
    
    int N;
    cin >> N;

    vector<int> start_times(N);
    vector<int> end_times(N);
    vector<int> buckets(N);

    for (int i=0; i<N; i++) {
        cin >> start_times[i] >> end_times[i] >> buckets[i];
    }

    int earliest = *min_element(start_times.begin(), start_times.end());
    int latest = *max_element(end_times.begin(), end_times.end());

    vector<int> bucket_list;
    // 0 = in use, 1 = free
    vector<int> bucket_status;

    for (int time=earliest; time<latest+1; time++) {
        // Find which cow is ending milking at this time and free up their bucket(s)
        if (find(end_times.begin(), end_times.end(), time) != end_times.end()) {
            int end_milk = find(end_times.begin(), end_times.end(), time) - end_times.begin();
            int used_bucket_idx;
            for (int i=0; i<buckets[end_milk]; i++) {
                used_bucket_idx = find(bucket_status.begin(), bucket_status.end(), 0) - bucket_status.begin();
                bucket_status[used_bucket_idx] = 1;
            }
        }

        // Find which cow is starting to milk at this time and find buckets for them
        if (find(start_times.begin(), start_times.end(), time) != start_times.end()) {
            int begin_milk = find(start_times.begin(), start_times.end(), time) - start_times.begin();
            if (time == earliest) {
                for (int i=0; i<buckets[begin_milk]; i++) {
                    bucket_list.push_back(69);
                    bucket_status.push_back(0);
                }
            } else {                
                int buckets_needed = buckets[begin_milk];

                for (int idx=0; idx<bucket_status.size(); idx++) {
                    if (buckets_needed != 0) {
                        buckets_needed -= bucket_status[idx];
                        if (bucket_status[idx] == 1) {
                            bucket_status[idx] = 0;
                        }
                    } else {
                        break;
                    }
                }

                for (int i=0; i<buckets_needed; i++) {
                    bucket_list.push_back(69);
                    bucket_status.push_back(0);
                }
            }
        }
    }

    
    cout << bucket_list.size() << '\n';
}
