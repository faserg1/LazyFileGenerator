#include "EnvConfigProvider.hpp"
#include <cstdlib>
#include <range/v3/view/split_when.hpp>
#include <range/v3/view/transform.hpp>

using namespace lfg::config;
using namespace std::string_view_literals;

std::vector<std::string_view> EnvConfigProvider::getDefaultPaths() const
{
    using namespace ranges::views;
    std::vector<std::string_view> paths;
    auto env = std::string_view(std::getenv("LFGPATH"));
    auto split_func = [](auto ch) -> bool {
        constexpr const auto delim = _WIN32 ? ';' : ':';
        return ch == delim;
    };
    auto convert_func = [](auto &&rng) -> std::string_view {
        return std::string_view(&*rng.begin(), ranges::distance(rng));
    };
    for (const std::string_view path : env | split_when(split_func) | transform(convert_func))
    {
        paths.push_back(path);
    }
    return std::move(paths);
}