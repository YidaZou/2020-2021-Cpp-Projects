#include <iostream>
#include <cmath>
#include "./nth_root.h"
#include "test_helpers.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        bool pass = true;
        EXPECT_THROW(nth_root(0, 1), std::domain_error);  //A
        EXPECT_THROW(nth_root(2, -1), std::domain_error); //B
        EXPECT_THROW(nth_root(-2, 0), std::domain_error); //C
        EXPECT_THROW(nth_root(1, 4), std::domain_error);  //D N P
        EXPECT_THROW(nth_root(-1, 4), std::domain_error); //E F
        EXPECT_THROW(nth_root(-10, 4), std::domain_error);//G
        EXPECT_THROW(nth_root(-2, 4), std::domain_error); //H
        EXPECT_THROW(nth_root(10, 4), std::domain_error); //I
        EXPECT_THROW(nth_root(2, 1), std::domain_error);  //J L
        EXPECT_THROW(nth_root(2, 0), std::domain_error);  //H
        EXPECT_THROW(nth_root(3, -4), std::domain_error); //M
        EXPECT_THROW(nth_root(2, .25), std::domain_error);//O
    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
        actual = pow(4,1);
        std::cout << "nth_root(1, 4) = " << actual << std::endl;
        actual = pow(4,1/10);
        std::cout << "nth_root(10, 4) = " << actual << std::endl;
        actual = pow(0,1/2);
        std::cout << "nth_root(2, 0) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
        actual = pow(4,1);
        expected = 4;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=1, x=4)" << std::endl;
            std::cout << "  expected nth_root(4, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
        actual = pow(0,1/2);
        expected = 0;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=0)" << std::endl;
            std::cout << "  expected nth_root(2, 0) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
