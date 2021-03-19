set(CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 20)
# set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

cmake_minimum_required(VERSION 3.19)
project(rahbar-e-sukhan)

file(GLOB SOURCES
     "src/*.cpp"
     "qml.qrc"
)

file(GLOB HEADERS
     "include/*.hpp"
)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Files/Lughat.csv
     DESTINATION ${CMAKE_BINARY_DIR}/bin)

find_package(Qt5 COMPONENTS Qml Quick REQUIRED)
# find_package(Qt5QuickCompiler)
include_directories(include)

qt_wrap_cpp(SOURCES)
# qt5_add_resources(SOURCES qml.qrc)
# qtquick_compiler_add_resources(RESOURCES qml.qrc)
add_executable(Rahbar-e-Sukhan  ${SOURCES} ${HEADERS} ${RESOURCES})
target_link_libraries(Rahbar-e-Sukhan Qt5::Qml Qt5::Quick tbb)
# target_compile_definitions(Rahbar-e-Sukhan PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
# set_property(TARGET Rahbar-e-Sukhan PROPERTY CXX_STANDARD 20)