
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
  name = "runtime_poly",
  srcs = ["runtime_poly.cc"],
  hdrs = ["runtime_poly.h"]
)
cc_binary(
  name = "main",
  srcs = ["main.cc"],
  deps = [":runtime_poly"]
)