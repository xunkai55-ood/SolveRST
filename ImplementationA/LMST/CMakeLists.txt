set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(lmst LMST.cpp main.cpp ../SMST/SMST.cpp ../SMST/PointsGenerator.cpp)
