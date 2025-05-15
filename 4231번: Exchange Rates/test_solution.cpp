#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>

void SolveExchangeRates(std::istream& in, std::ostream& out);

TEST(ExchangeRatesTest, Sample1) {
    std::istringstream input("3\n1.0500\n0.9300\n0.9900\n0\n");
    std::ostringstream output;
    SolveExchangeRates(input, output);
    EXPECT_EQ(output.str(), "1001.60\n");
}

TEST(ExchangeRatesTest, Sample2) {
    std::istringstream input("2\n1.0500\n1.1000\n0\n");
    std::ostringstream output;
    SolveExchangeRates(input, output);
    EXPECT_EQ(output.str(), "1000.00\n");
}

TEST(ExchangeRatesTest, NoExchange) {
    std::istringstream input("4\n1.0100\n1.0100\n1.0100\n1.0100\n0\n");
    std::ostringstream output;
    SolveExchangeRates(input, output);
    EXPECT_EQ(output.str(), "1000.00\n");
}

TEST(ExchangeRatesTest, AlwaysBetterToSwitch) {
    std::istringstream input("2\n2.0000\n1.0000\n0\n");
    std::ostringstream output;
    SolveExchangeRates(input, output);
    // After day 1, best to switch to USD, after day 2, back to CAD at better rate
    EXPECT_EQ(output.str(), "1940.60\n");
}

void SolveExchangeRates(std::istream& in, std::ostream& out) {
    while (true) {
        int d;
        in >> d;
        if (d == 0) break;
        std::vector<double> rate(d);
        for (int i = 0; i < d; ++i) in >> rate[i];
        double cad = 1000.0, usd = 0.0;
        for (int i = 0; i < d; ++i) {
            double new_cad = cad;
            double new_usd = usd;
            new_usd = std::max(new_usd, std::floor(cad * 0.97 / rate[i] * 100.0) / 100.0);
            new_cad = std::max(new_cad, std::floor(usd * 0.97 * rate[i] * 100.0) / 100.0);
            cad = new_cad;
            usd = new_usd;
        }
        out << std::fixed << std::setprecision(2) << cad << '\n';
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}