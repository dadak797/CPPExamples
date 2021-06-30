#include <filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem::v1;

void PrintPermission(fs::perms permission)
{
    std::cout << ((permission & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
        << ((permission & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((permission & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
        << ((permission & fs::perms::group_read) != fs::perms::none ? "r" : "-")
        << ((permission & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((permission & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
        << ((permission & fs::perms::others_read) != fs::perms::none ? "r" : "-")
        << ((permission & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((permission & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
        << std::endl;
}

int main()
{
    fs::path filePath = "D:\\Work\\PDFs\\CFD\\COMPUATIONAL_FLUID_DYNAMICS_AN_INTRODUCT.pdf";
    PrintPermission(fs::status(filePath).permissions());

    return 0;
}
