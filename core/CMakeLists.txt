file(GLOB core_files "src/*.cpp")
add_library(core SHARED ${core_files})

target_include_directories(core PUBLIC src)
