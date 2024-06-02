load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
  name = "my_stack",
  srcs = ["my_stack.cc"],
  hdrs = ["my_stack.h"],
  visibility = ["//visibility:public"]
)
cc_binary(
  name = "main_test",
  srcs = ["stack_main.cc"],
  deps = [":my_stack"]
)