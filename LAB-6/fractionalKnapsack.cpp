#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
  int value, weight;
};

bool compare(const Item& a, const Item& b) {
  double r1 = static_cast<double>(a.value) / a.weight;
  double r2 = static_cast<double>(b.value) / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
  sort(items.begin(), items.end(), compare);

  double totalValue = 0.0;
  int currentWeight = 0;

  for (const auto& item : items) {
    if (currentWeight + item.weight <= capacity) {
      currentWeight += item.weight;
      totalValue += item.value;
    } else {
      int remain = capacity - currentWeight;
      totalValue += item.value * (static_cast<double>(remain) / item.weight);
      break;
    }
  }

  return totalValue;
}

int main() {
  int n, capacity;
  cout << "Enter the number of items: ";
  cin >> n;

  cout << "Enter the total knapsack capacity: ";
  cin >> capacity;

  vector<Item> items(n);
  for (int i = 0; i < n; i++) {
    cout << "Enter value and weight for item " << i + 1 << ": ";
    cin >> items[i].value >> items[i].weight;
  }

  double maxValue = fractionalKnapsack(capacity, items);
  cout << "Maximum value in Knapsack = " << maxValue << "\n";
  return 0;
}