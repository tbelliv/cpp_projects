#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>

int insert(int value, std::vector<int> &table){
  
    int index = value % 1000;
    int collisions = 0;
  
    while(table[index] != -1){
        collisions++;
        index = (index + 1) % 1000;
    }

    table[index] = value;

    return collisions;

}

int main() {
  // Prepare some random but distinct values
  constexpr int NUM_VALUES = 500;
  std::vector<int> value(NUM_VALUES);
  int prev_value = 0;
  for (int i = 0; i < NUM_VALUES; i++) {
    prev_value += rand()%25 + 1;
    value[i] = prev_value;
  }

  // Create hash table of size 1000 initialized with -1
  std::vector<int> table(1000,-1);

  // Insert values and track the maximum number of collisions
  int max_hit = 0, max_value = -1;
  for (int i = 0; i < NUM_VALUES; i++) {
    int hit = insert(value[i],table);
    if (hit > max_hit) {
      max_hit = hit;  
      max_value = value[i];
    }
  }

  std::cout << "Inserting value " << max_value << " experienced " << max_hit << " collisions." << std::endl <<std::endl;

  // Print the table contents
  for (int j = 0; j < 1000; j += 10) {
    std::cout << std::setw(3) << j << ":";
    for (int i = 0; i < 10; i++) {
      if (table[j+i] == -1)
        std::cout << "      ";
      else
        std::cout << std::setw(6) << table[j+i];
    }
    std::cout << std::endl;
  }

}