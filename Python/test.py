#!/bin/python3.9

import sys
import os
import subprocess

g_exec_path = "./build/warcraft"
g_test_path = "./tests/real/"


def compare_lines(expected: str, actual: str):
  """\
  Pass the expected and received output as strings.
  The first difference is printed and False is returned.
  True is returned upon successfully comparing 
  the second-to-last expected line.\
  """

  expected = expected.splitlines()
  actual = actual.splitlines()

  for line in range(len(expected) - 1):
    try:
      actual[line]
    except:
      print(f"Reached end of output on line {line}:\n" +
            f"EXPECTED: {expected[line]}")
      return False

    if expected[line] != actual[line]:
      print(f"Difference on line {line}:\n" +
            f"EXPECT: {expected[line]}\n" +
            f"ACTUAL: {actual[line]}")
      return False

  return True


def test_output(test_in_name, test_out_name):
  """\
  Runs the specified executable with input from test_in
  and compares its output with test_out, printing the result.\
  """
  in_file = open(g_test_path + test_in_name)
  out_file = open(g_test_path + test_out_name)

  try:
    out = subprocess.run(
      [g_exec_path], stdout=subprocess.PIPE, stdin=in_file)
  except:
    print(f"Failed to execute {g_exec_path}")
    exit()

  out_stream = out.stdout.decode()

  if compare_lines(out_file.read(), out_stream):
    print(f" {test_in_name} -> {test_out_name} is correct.")
  else:
    print(f"in {test_in_name} -> {test_out_name}")

  in_file.close()
  out_file.close()


if __name__ == __main__:
  try:
    test_ins = [file for file in os.listdir(g_test_path) if "in" in file]
    test_outs = [file for file in os.listdir(g_test_path) if "out" in file]

    test_ins.sort()
    test_outs.sort()
  except:
    print(f"Test files not found in {os.getcwd()}/{g_test_path}")
    return

  if len(test_ins) != len(test_outs):
    print("Test in/out files not matched. Exiting.")
    return

  for i in range(len(test_ins)):
    test_output(test_ins[i], test_outs[i])

