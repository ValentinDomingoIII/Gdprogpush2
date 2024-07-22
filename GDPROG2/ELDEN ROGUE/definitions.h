#pragma once

#define STORMVEIL_FLOOR_COUNT 3
#define STORMVEIL_SPAWN_FLOOR { {0,6,0}, \
                                {2,0,2}, \
                                {0,0,0}, \
                                {0,0,0}, \
                                {0,0,0}, \
                                {0,0,0}, \
                                {0,9,0} }

#define STORMVEIL_SECOND_FLOOR { {0,0,0,6,0,0,0}, \
                                 {0,0,0,2,0,0,0}, \
                                 {0,0,0,0,0,0,0}, \
                                 {2,0,2,2,2,0,2}, \
                                 {0,0,0,0,0,0,0}, \
                                 {0,0,2,0,2,0,0}, \
                                 {0,0,0,7,0,0,0} }

#define STORMVEIL_BOSS_FLOOR { {0,0,8,0,0}, \
                               {0,0,0,0,0}, \
                               {0,0,0,0,0}, \
                               {0,0,4,0,0}, \
                               {0,0,0,0,0}, \
                               {0,0,0,0,0}, \
                               {0,0,7,0,0} }
                               
#define STORMVEIL_INITIAL_PLAYER_LOCATION {1,0,0}
#define STORMVEIL_INITIALIZER {STORMVEIL_SPAWN_FLOOR, STORMVEIL_SECOND_FLOOR, STORMVEIL_BOSS_FLOOR, STORMVEIL_INITIAL_PLAYER_LOCATION}