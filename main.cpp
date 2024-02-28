#include <iostream>
#include <random>
#include <RInside.h>

int main(int argc, char *argv[]) {
    std::cout << "Starting RInside..." << std::endl;
    RInside R(argc, argv);

    std::cout << "Running initial R code..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    R.parseEvalQ("source('../initial.R')");

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> initial_time = end - start;
    std::cout << "Done running initial R code, " << initial_time.count() << "ms" << std::endl;

    std::cout << "Running main R code..." << std::endl;
    start = std::chrono::high_resolution_clock::now();

    R.parseEvalQ("source('../main.R')");

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> main_time = end - start;
    std::cout << "Done running main R code, " << main_time.count() << "ms" << std::endl;
}
