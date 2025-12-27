load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
  name = "queue",
  srcs = ["queue.cc"],
  hdrs = ["queue.h"]
)

cc_binary(
  name = "queue_main",
  srcs = ["queue_main.cc"],
  deps = [":queue"]
)