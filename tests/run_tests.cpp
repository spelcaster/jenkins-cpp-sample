#include <gtest/gtest.h>

#include "../lib/fff/fff.h"

DEFINE_FFF_GLOBALS

int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
