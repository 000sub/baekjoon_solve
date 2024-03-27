#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {    
    int base_time = bandage[0];
    int heal_per_sec = bandage[1];
    int additional_heal = bandage[2];

    int max_health = health;
    int cur = 0;
    
    for (vector<int>& v : attacks) {
        int gap = v[0] - cur - 1;
        cur = v[0];
        
        health += gap * heal_per_sec + (gap / base_time * additional_heal);
        health = min(health, max_health);
        health -= v[1];
        
        if (health <= 0) return -1;
    }
      
    return health;
}