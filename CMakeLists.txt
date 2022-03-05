cmake_minimum_required(VERSION 3.0.0)
project(transport_catalogue VERSION 0.1.0)

add_executable(transport_catalogue main.cpp domain.cpp geo.cpp json_reader.cpp json.cpp json_builder.cpp map_renderer.cpp request_handler.cpp svg.cpp transport_catalogue.cpp)
target_compile_features(transport_catalogue PRIVATE cxx_std_17)

