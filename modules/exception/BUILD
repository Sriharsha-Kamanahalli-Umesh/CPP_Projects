load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
  name = "my_exception",
  srcs = ["my_exception.cc"],
  hdrs = ["my_exception.h"],
  visibility = ["//visibility:public"]
)
cc_binary(
  name = "main_test",
  srcs = ["main_test.cc"],
  deps = [":my_exception"]
)