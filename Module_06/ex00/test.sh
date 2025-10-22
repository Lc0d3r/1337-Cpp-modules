#!/bin/bash

# Path to your compiled convert program
EXECUTABLE="./convert"

# Array of test cases
TEST_CASES=(
  # Valid char literals
  "a"
  "Z"
  "0"
  " "

  # Invalid char literals
  "\\n"
  "\\t"
  "\\x7F"  # DEL (non-displayable)

  # Valid int literals
  "0"
  "-42"
  "42"
  "2147483647"   # INT_MAX
  "-2147483648"  # INT_MIN

  # Invalid int literals
  "9999999999999999999999999999999999999999"
  "abc"
  "42abc"

  # Valid float literals
  "0.0f"
  "-4.2f"
  "4.2f"
  "+inff"
  "-inff"
  "nanf"

  # Valid double literals
  "0.0"
  "-4.2"
  "4.2"
  "+inf"
  "-inf"
  "nan"

  # Edge cases
  "42.0f"
  "42.0"
  "127"     # max displayable ASCII
  "128"     # non-displayable char
  "nonliteral"
  ""
)

echo "Running ScalarConverter tests..."
echo "--------------------------------"

for input in "${TEST_CASES[@]}"; do
  echo "Test input: $input"
  $EXECUTABLE "$input"
  echo "--------------------------------"
done
