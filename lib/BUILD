
# load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
  name = "add",
  srcs = ["add.cc"],
  hdrs = ["add.h"]
)
cc_binary(
  name = "main",
  srcs = ["main.cc"],
  deps = [":add"]
)