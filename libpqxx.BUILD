#
# Copyright 2022 Anysphere, Inc.
# SPDX-License-Identifier: MIT
#

load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
    visibility = ["//:__pkg__"],
)

cmake(
    name = "pqxx",
    build_args = [
        "--verbose",
    ],
    cache_entries = {
        "CMAKE_C_FLAGS": "-fPIC",
	"CMAKE_STATIC_LINKER_FLAGS": "-lpqxx -lpq",
	#"CMAKE_EXE_LINKER_FLAGS": "-lpqxx -lpq",
	#"CMAKE_SHARED_LINKER_FLAGS": "-lpqxx -lpq",
	#"PostgreSQL_TYPE_INCLUDE_DIR": "/usr/include/postgresql",
	#"PostgreSQL_INCLUDE_DIR": "/usr/include/postgresql",
        #"PostgreSQL_LIBRARY": "/usr/lib/x86_64-linux-gnu/libpq.so",
    },
    lib_source = "@pqxx//:all_srcs",
    visibility = ["//visibility:public"],
    out_static_libs = ["libpqxx.a"],
    targets = ["pqxx"],
)


#cmake(
#    name = "libpqxx",
#    build_args = [
#        "--verbose",
#    ],
#    cache_entries = {
#        "CMAKE_C_FLAGS": "-fPIC",
#        "PostgreSQL_TYPE_INCLUDE_DIR": "/usr/include/postgresql",
#        "PostgreSQL_INCLUDE_DIR": "/usr/include/postgresql",
#        "PostgreSQL_LIBRARY": "/usr/lib/x86_64-linux-gnu/libpq.so",
#    },
    # generate_args = [
    #     "-G Ninja",
    # ],
#    lib_source = ":all_srcs",
#    out_static_libs = [
#        "libpqxx.a",
#    ],
    # toolchain = "@rules_foreign_cc//toolchains:preinstalled_ninja_toolchain",
#)
