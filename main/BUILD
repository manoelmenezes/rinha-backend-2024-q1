load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

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
        "@served//:served",
        "//proto:cpp_rinha_proto",  
    ]
)
