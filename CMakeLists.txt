cmake_minimum_required(VERSION 3.21)
project(Lab_5_6_Pb_4)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Lab_5_6_Pb_4 main.cpp Source/Model/Tutorial.cpp Header/Model/Tutorial.h Source/Model/Repository.cpp Header/Model/Repository.h Source/View/UserUi.cpp Header/View/UserUi.h Source/View/AdminUi.cpp Header/View/AdminUi.h Source/Controller/AdminController.cpp Header/Controller/AdminController.h Source/Controller/UserController.cpp Header/Controller/UserController.h Header/Model/Repository.tpp GoogleTest/TestModel/TestTutorial.cpp Header/Model/TemplateRepository.h Source/Model/InMemoryRepository.cpp Header/Model/StlRepository.tpp Header/Exception/CustomException.h Header/Exception/TutorialValidator.h Header/Exception/Test.h Source/Exception/Test.cpp)



#[[
# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example example.cpp)
target_link_libraries(example gtest_main)
add_test(NAME example_test COMMAND example)]]
