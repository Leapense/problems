#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

class VerboseTestListener : public EmptyTestEventListener {
    public:
        explicit VerboseTestListener(TestEventListener* default_printer) : default_printer_(default_printer) {

        }

        void OnTestProgramStart(const UnitTest& unit_test) override {
            default_printer_->OnTestProgramStart(unit_test);
            cout << "[CustomLog] Test Program Start!\n";
        }

        void OnTestSuiteStart(const TestSuite& test_suite) override {
            default_printer_->OnTestSuiteStart(test_suite);
            cout << "[CustomLog] Test Suite Start: " << test_suite.name() << "\n";
        }

        void OnTestStart(const TestInfo& test_info) override {
            default_printer_->OnTestStart(test_info);
            cout << "[CustomLog] Test Start: " << test_info.test_suite_name() << "." << test_info.name() << "\n";
        }

        void OnTestEnd(const TestInfo& test_info) override {
            default_printer_->OnTestEnd(test_info);
            if (test_info.result()->Passed()) {
                cout << "[CustomLog] Test Passed: " << test_info.test_suite_name() << "." << test_info.name() << "\n";
            } else {
                cout << "[CustomLog] Test Failed: " << test_info.test_suite_name() << "." << test_info.name() << "\n";
            }
        }

        void OnTestSuiteEnd(const TestSuite& test_suite) override {
            default_printer_->OnTestSuiteEnd(test_suite);
            cout << "[CustomLog] Test Suite End: " << test_suite.name() << "\n";
        }

        void OnTestProgramEnd(const UnitTest& unit_test) override {
            default_printer_->OnTestProgramEnd(unit_test);
            cout << "[CustomLog] Test Program End!\n";
        }

    private:
        TestEventListener* default_printer_;
};

vector<int> sievePrimes(int maxVal) {
    vector<bool> isPrime(maxVal + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= maxVal; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxVal; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= maxVal; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

long long solveSilverStar(int P) {
    vector<int> primes = sievePrimes(P);
    vector<long long> dp(primes.size(), 0LL);

    int startIndex = -1;
    for (int i = 0; i < (int)primes.size(); i++) {
        if (primes[i] == 2) {
            startIndex = i;
            break;
        }
    }

    dp[startIndex] = 1LL;

    for (int i = startIndex + 1; i < (int)primes.size(); i++) {
        for (int j = startIndex; j < i; j++) {
            if (primes[i] - primes[j] <= 14) {
                dp[i] += dp[j];
            }
        }
    }

    int endIndex = -1;
    for (int i = 0; i < (int)primes.size(); i++) {
        if (primes[i] == P) {
            endIndex = i;
            break;
        }
    }

    return dp[endIndex];
}

TEST(SilverStarTest, SampleInput1) {
    EXPECT_EQ(solveSilverStar(7), 4LL);
}

TEST(SilverStarTest, SampleInput2) {
    EXPECT_EQ(solveSilverStar(31), 416LL);
}

TEST(SilverStarTest, EdgeCaseP2) {
    EXPECT_EQ(solveSilverStar(2), 1LL);
}

TEST(SilverStarTest, AnotherPrimeExample) {
    long long result = solveSilverStar(29);

    EXPECT_GT(result, 10LL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    auto& listeners = UnitTest::GetInstance()->listeners();
    TestEventListener* default_printer = listeners.Release(listeners.default_result_printer());

    listeners.Append(new VerboseTestListener(default_printer));

    return RUN_ALL_TESTS();
}
