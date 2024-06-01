load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")
load("@rules_cc//cc:defs.bzl", "cc_test")
cc_library(
  name = "my_vector",
  srcs = ["my_vector.cc"],
  hdrs = ["my_vector.h"],
  visibility = ["//visibility:public"],
)

cc_test(
  name = "test_vec",
  srcs = ["my_vector_test.cc"],
  deps = ["@com_google_googletest//:gtest_main",
          ":my_vector"  
        ]
)