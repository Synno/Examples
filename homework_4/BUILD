py_binary(
    name = "generate_testset",
    srcs = ["generate_testset.py"],
)

cc_library(
    name = "sort",
    srcs = ["sort.cc"],
    hdrs = ["sort.h"],
)

cc_binary(
    name = "sort_main",
    srcs = ["sort_main.cc"],
    data = glob(["*.txt"]),
    deps = [
        ":sort",
    ],
)
