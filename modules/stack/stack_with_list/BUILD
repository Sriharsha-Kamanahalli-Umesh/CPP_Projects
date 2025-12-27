load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
  name = "stack",
  srcs = ["stack_with_list.cc"],
  hdrs = ["stack_with_list.h"],
  visibility = ["//visibility:public"]
)
cc_binary(
  name = "main_test",
  srcs = ["main_test.cc"],
  deps = [":stack"]
)