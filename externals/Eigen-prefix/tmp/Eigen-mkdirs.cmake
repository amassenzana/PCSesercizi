# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Main_Source/eigen3"
  "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Main_Build/eigen3"
  "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Eigen-prefix"
  "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Eigen-prefix/tmp"
  "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Eigen-prefix/src/Eigen-stamp"
  "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Eigen-prefix/src"
  "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Eigen-prefix/src/Eigen-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Eigen-prefix/src/Eigen-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/masse/OneDrive/Desktop/PCS/PCS2024_Exercises/externals/Eigen-prefix/src/Eigen-stamp${cfgdir}") # cfgdir has leading slash
endif()
