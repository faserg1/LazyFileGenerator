#include <string>
#include <iostream>
#include <run/RunnerFactory.hpp>

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << std::endl;
    auto opts = lfg::options::Options(argc, argv);
    auto runner = lfg::run::RunnerFactory::create(opts);
    runner->run();
    return 0;
}