cmake_minimum_required(VERSION 3.20)

# Set project information
project(
  Chapter_6
  VERSION 1.0
  DESCRIPTION "Designing Classes"
  LANGUAGES CXX)

# Add subdirectories with examples
add_subdirectory(6.1_PointClass)
add_subdirectory(6.3_RationalClass)
add_subdirectory(6.4_TokenScannerClass)
add_subdirectory(6.5_CheckoutLineClass)
