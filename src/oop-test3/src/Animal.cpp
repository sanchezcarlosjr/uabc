//
// Created by cest on 5/5/21.
//

#include "Animal.h"

int Animal::totalBySex[2][2] = {{0, 0},
                                {0, 0}};

vector<vector<vector<int>>> Animal::animalsByZone({
                                                          {
                                                                  {0, 0, 0, 0},
                                                                  {0, 0, 0, 0}
                                                          },
                                                          {
                                                                  {0, 0, 0, 0},
                                                                  {0, 0, 0, 0}
                                                          }
                                                  });
