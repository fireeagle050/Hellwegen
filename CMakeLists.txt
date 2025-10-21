cmake_minimum_required(VERSION 3.10)
project(Hellwegen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)

# Używamy bibliotek dynamicznych
set(SFML_STATIC_LIBRARIES OFF)

FetchContent_MakeAvailable(SFML)

# Dodajemy plik wykonywalny
add_executable(hellwegen src/main.cpp)

# Linkujemy z bibliotekami SFML
target_link_libraries(hellwegen PRIVATE sfml-graphics sfml-window sfml-system)

# Kopiujemy katalog assets do katalogu z plikiem wykonywalnym po kompilacji
add_custom_command(TARGET hellwegen POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:hellwegen>/assets
    COMMENT "Kopiowanie zasobów (assets)"
)