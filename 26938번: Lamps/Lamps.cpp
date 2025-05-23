#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int h, P;
    cin >> h >> P;
    
    const int life_incandescent = 1000;
    const int life_energy_saving = 8000;
    const int cost_incandescent = 5;
    const int cost_energy_saving = 60;
    const int watt_incandescent = 60;
    const int watt_energy_saving = 11;

    double total_cost_incandescent = 0.0;
    double total_cost_energy_saving = 0.0;
    double hours_used = 0.0;
    int days = 0;

    // Assume initial purchase for energy saving lamp
    total_cost_energy_saving += cost_energy_saving;

    while (true) {
        days++;
        hours_used += h;

        // Calculate lamp replacements and cost for incandescent
        int lamps_needed = ceil(hours_used / life_incandescent);
        double purchase_cost_incandescent = lamps_needed * cost_incandescent;
        double energy_cost_incandescent = (watt_incandescent * hours_used * P) / 100000.0;
        total_cost_incandescent = purchase_cost_incandescent + energy_cost_incandescent;

        // Calculate energy cost for energy saving lamp (purchase cost added initially)
        double energy_cost_energy_saving = (watt_energy_saving * hours_used * P) / 100000.0;
        total_cost_energy_saving = cost_energy_saving + energy_cost_energy_saving;

        // Check if energy saving lamp becomes cheaper
        if (total_cost_energy_saving < total_cost_incandescent) {
            cout << days << endl;
            break;
        }
    }

    return 0;
}