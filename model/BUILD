load("@rules_cc//cc:defs.bzl", "cc_library")

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
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "@nlohmann_json//:json",
    ]
)
