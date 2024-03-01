load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("@rules_foreign_cc//foreign_cc:configure.bzl", "configure_make")
load("@rules_foreign_cc//foreign_cc:make.bzl", "make")

# configure_make(
#     name = "libgnutls",
#     lib_source = "@libgnutls//:all",
#     configure_options = ["--with-included-unistring"],
#     out_include_dir = "include/gnutls",
#     # shared_libraries = ["libgnutls.so"],
# )

# configure_make(
#     name = "libmicrohttpd",
#     lib_source = "@libmicrohttpd//:all",
#     deps = [":libgnutls"],
# )

make(
    name = "libhttpserver",
    lib_source = "@libhttpserver//:all",
    # make_commands = [
    #     "./bootstrap",
    #     "mkdir build_dir",
    #     "cd build_dir",
    #     "../configure --prefix=${INSTALLDIR}",
    #     "make",
    #     "make install",
    # ],
    # deps = [":libmicrohttpd", ":libgnutls"],
)

cc_library(
    name = "client-service",
    srcs = [
        "client.cpp",
        "client_service.cpp",
        "client_repository.cpp",
    ],
    hdrs = [
        "client.h",
        "client_service.h",
        "client_repository.h",
        "transaction.h",
    ],
)

cc_binary(
    name = "rinha",
    srcs = [        
        "main.cpp",
    ],
    deps = [
        ":client-service",
        ":libhttpserver"
    ]
)
