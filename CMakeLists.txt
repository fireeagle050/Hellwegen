# Ustawienie minimalnej wymaganej wersji CMake
cmake_minimum_required(VERSION 3.10)

# Definicja projektu (nazwa, wersja, języki)
project(Hellwegen VERSION 0.1.0 LANGUAGES CXX)

# Ustawienie standardu języka C++ na C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Informowanie CMake, gdzie znajdują się pliki nagłówkowe
include_directories(include)

# Dodanie pliku wykonywalnego, który powstanie z plików źródłowych
# Na razie dodajemy tylko main.cpp, który zostanie utworzony w następnym kroku
add_executable(hellwegen src/main.cpp)

# Komunikat wyświetlany po pomyślnej konfiguracji
message(STATUS "Projekt Hellwegen został skonfigurowany pomyślnie.")