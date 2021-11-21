#include <gtest/gtest.h>
#include <thread>
#include <future>
#include <vector>

int sumA(std::vector<int> v, int i, int j) {
    int acc = 0;
    for (; i < j; i++) {
        acc += v[i];
    }
    return acc;
}

int sum(std::vector<int> v) {
    const auto processor_count = std::thread::hardware_concurrency();
    std::vector<std::future<int>> futures;
    int start = 0;
    int diff = v.size() / processor_count;
    for (int i = 0; i < processor_count; i++) {
        futures.emplace_back(std::async(sumA, v, start, start + diff));
        start = start + diff;
    }
    int acc = 0;
    for(auto&& f: futures)
        acc += f.get();
    return acc;
}


TEST(ThreadSum, sum) {
    std::vector<int> v;
    for (int i = 0; i < 10000; i++) {
        v.push_back(i);
    }
    auto start = std::chrono::high_resolution_clock::now();
    int total = sum(v);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    ASSERT_EQ(total, 49995000);
    std::cout << "Elapsed time to compute: " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() << "ns\n";
    auto start2 = std::chrono::high_resolution_clock::now();
    sumA(v, 0, 100);
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Elapsed time to compute: " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed2).count() << "ns\n";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}