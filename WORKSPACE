load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "aspect_gcc_toolchain",
    sha256 = "3341394b1376fb96a87ac3ca01c582f7f18e7dc5e16e8cf40880a31dd7ac0e1e",
    strip_prefix = "gcc-toolchain-0.4.2",
    urls = [
        "https://github.com/aspect-build/gcc-toolchain/archive/refs/tags/0.4.2.tar.gz",
    ],
)

load("@aspect_gcc_toolchain//toolchain:repositories.bzl", "gcc_toolchain_dependencies")

gcc_toolchain_dependencies()

load("@aspect_gcc_toolchain//toolchain:defs.bzl", "gcc_register_toolchain", "ARCHS")

gcc_register_toolchain(
    name = "gcc_toolchain_x86_64",
    target_arch = ARCHS.x86_64,
)

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
git_repository(
    name = "served",
    commit = "2eb36b83fa69330900ae58ef41d12b5f7abc138c",
    remote = "https://github.com/meltwater/served",
)

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "00b9b9ecb9b43564de44ea0b10e22b29dcf84d79",
    remote = "https://github.com/nelhage/rules_boost",
)
load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

git_repository(
    name = "nlohmann_json",
    commit = "9cca280a4d0ccf0c08f47a99aa71d1b0e52f8d03",
    remote = "https://github.com/nlohmann/json",
)
