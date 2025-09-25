#include <gtest/gtest.h>
#include "sample.cpp"

// 测试默认构造函数
TEST(CarTest, DefaultConstructor) {
    Car car;
    // 检查默认构造函数的输出
    testing::internal::CaptureStdout();
    Car temp;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "一辆空气汽车已生产完毕！\n");
}

// 测试带参数的构造函数
TEST(CarTest, ParameterizedConstructor) {
    testing::internal::CaptureStdout();
    Car car("BYD", "汉", 2023, 4, 6, "LED");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "一辆 BYD 汉 已生产完毕！\n");
}

// 测试start方法
TEST(CarTest, StartMethod) {
    Car car("BYD", "汉", 2023, 4, 6, "LED");
    testing::internal::CaptureStdout();
    car.start();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "引擎启动了！Vroom!\n");
    // 检查状态是否更新
    testing::internal::CaptureStdout();
    car.displaySpecs();
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("当前状态: 已启动"), std::string::npos);
}

// 测试honk方法
TEST(CarTest, HonkMethod) {
    Car car("BYD", "汉", 2023, 4, 6, "LED");
    testing::internal::CaptureStdout();
    car.honk();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "喇叭声：滴滴！\n");
}

// 测试turnOnHeadlights方法
TEST(CarTest, TurnOnHeadlightsMethod) {
    Car car("BYD", "汉", 2023, 4, 6, "LED");
    testing::internal::CaptureStdout();
    car.turnOnHeadlights();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "LED 大灯已打开。\n");
}

// 测试displaySpecs方法
TEST(CarTest, DisplaySpecsMethod) {
    Car car("BYD", "汉", 2023, 4, 6, "LED");
    testing::internal::CaptureStdout();
    car.displaySpecs();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("品牌型号: BYD 汉 (2023款)"), std::string::npos);
    EXPECT_NE(output.find("轮胎数量: 4个"), std::string::npos);
    EXPECT_NE(output.find("车窗数量: 6个"), std::string::npos);
    EXPECT_NE(output.find("大灯类型: LED"), std::string::npos);
    EXPECT_NE(output.find("当前状态: 已熄火"), std::string::npos);
}

// 测试析构函数
TEST(CarTest, Destructor) {
    testing::internal::CaptureStdout();
    {
        Car car("BYD", "汉", 2023, 4, 6, "LED");
    }
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "一辆 BYD 汉 已生产完毕！\n一辆 BYD 汉 已报废！\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}