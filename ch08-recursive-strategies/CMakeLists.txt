cmake_minimum_required(VERSION 3.20)

# Set project information
project(
  Chapter_8
  VERSION 1.0
  DESCRIPTION "Recursive Strategies"
  LANGUAGES CXX)

# Add subdirectories with examples
add_subdirectory(8.1_Hanoi)
add_subdirectory(8.2_SubsetSum)
add_subdirectory(8.3_Permutations)
add_subdirectory(8.3_Anagrams)
add_subdirectory(8.4_Mondrian)
add_subdirectory(8.4_Snowflake)
