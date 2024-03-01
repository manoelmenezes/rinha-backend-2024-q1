load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")

proto_library(
    name = "rinha_proto",
    srcs = ["rinha.proto"],
    deps = ["@protobuf//:timestamp_proto"],
)

cpp_proto_library(
    name = "cpp_rinha_proto",
    protos = [":rinha_proto"],
    visibility = [
        "//visibility:public",
    ],
)
