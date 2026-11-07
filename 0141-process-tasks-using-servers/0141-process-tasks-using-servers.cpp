class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using Server = pair<int, int>; 
        using Busy = tuple<long long, int, int>; 

        priority_queue<Server, vector<Server>, greater<Server>> free;
        priority_queue<Busy, vector<Busy>, greater<Busy>> busy;

        for (int i = 0; i < servers.size(); ++i) {
            free.push({servers[i], i});
        }

        vector<int> ans(tasks.size());
        long long time = 0;

        for (int j = 0; j < tasks.size(); ++j) {
            time = max(time, static_cast<long long>(j));

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, index] = busy.top();
                busy.pop();
                free.push({weight, index});
            }

            if (free.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finish, weight, index] = busy.top();
                    busy.pop();
                    free.push({weight, index});
                }
            }

            auto [weight, index] = free.top();
            free.pop();
            ans[j] = index;
            busy.push({time + tasks[j], weight, index});
        }

        return ans;
    }
};