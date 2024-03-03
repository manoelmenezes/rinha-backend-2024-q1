load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_binary(
    name = "rinha",
    srcs = [        
        "main.cpp",
    ],
    deps = [
        "//model:client-service",
        "@served//:served",
        "@nlohmann_json//:json",
        "@libpqxx",
    ]
)
