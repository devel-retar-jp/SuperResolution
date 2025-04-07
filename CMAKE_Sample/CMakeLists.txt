# CMakeList.txt : CMAKE_Sample の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
#############################################################################################
# このファイルを編集したらキャッシュの構成を！！！
#############################################################################################
#
#
# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable (CMAKE_Sample "CMAKE_Sample.cpp" "CMAKE_Sample.h")
#
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMAKE_Sample PROPERTY CXX_STANDARD 20)
endif()
#############################################################################################
# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
#
#
# CMakePresets.jsonにも設定追加を忘れないで！
# vcpkgの位置を指定
#
#          "cacheVariables": {
#            "CMAKE_BUILD_TYPE": "Debug",
#            "CMAKE_TOOLCHAIN_FILE": "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
#          }
#
#          "cacheVariables": {
#            "CMAKE_BUILD_TYPE": "Release",
#            "CMAKE_TOOLCHAIN_FILE": "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
#          }
#
#
#vcpkgの設定を追加
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows")
#
#リンク
target_link_libraries(CMAKE_Sample PRIVATE ${OpenCV_LIBS} ZLIB::ZLIB)
#
#OpenCV設定 -> パッケージごとに追加する
#C:\vcpkg\installed\x64-windows\share\opencv4\usage <- 参照ファイル
#C:\vcpkg\installed\x64-windows\share\opencv4\OpenCVConfig.cmake <- 参照ファイル
#
find_package(OpenCV CONFIG REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
#リンカーを忘れずに！
message(STATUS ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
message(STATUS "OpenCV Include Dirs: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV Libraries: ${OpenCV_LIBS}")
message(STATUS ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
#
#zlib設定 -> パッケージごとに追加する
#C:\vcpkg\installed\x64-windows\share\zlib\usage <- 参照ファイル
#C:\vcpkg\installed\x64-windows\share\zlib\vcpkg-cmake-wrapper.cmake <- 参照ファイル
#
find_package(ZLIB REQUIRED)
#リンカーを忘れずに！
message(STATUS ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
message(STATUS "ZLIB Include Dirs: ${ZLIB_INCLUDE_DIR}")
message(STATUS "ZLIB RELEASE Libraries: ${ZLIB_LIBRARY_RELEASE}")
message(STATUS "ZLIB DEBUG Libraries: ${ZLIB_LIBRARY_DEBUG}")
message(STATUS ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
