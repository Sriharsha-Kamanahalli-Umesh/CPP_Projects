load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
  name = "sort",
  srcs = ["sort.cc"],
  hdrs = ["sort.h"],
  visibility = ["//visibility:public"]
)
cc_test(
  name = "test_sort",
  srcs = ["test_sort.cc"],
  deps = ["@com_google_googletest//:gtest_main",
          ":sort"
        ]
)