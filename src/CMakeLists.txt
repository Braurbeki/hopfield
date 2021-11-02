add_executable(Build)

target_sources(Build PRIVATE
    main.cpp
    sources/symbols_reader.cpp
    sources/neural_network.cpp
)

target_include_directories(Build PRIVATE
    .
)