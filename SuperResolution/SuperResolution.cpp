/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
/// 高解像度化 Samples
/// 
/// SuperResolution.cpp 
/// 
///	
///   履歴	
///   2025/04/04 V1.00 First
///
///
///                        Copyright(c) 2025, Retar.jp, All Rights Reserved.
///                        http://www.retar.jp/
/// 
/// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// *重要*
/// DEBUG時はDebugのバイナリディレクトリにあるqt.confを編集する
/// DEBUG時のプラグインがみつけられない
/// 
/// [Paths]
/// Prefix = C:/vcpkg/installed/x64-windows/debug/Qt6
/// Plugins = C :/vcpkg/installed/x64-windows/debug/Qt6/plugins
/// Qml2Imports = C :/vcpkg/installed/x64-windows/debug/Qt6/qml
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <codecvt>
#include <locale>
#include <filesystem> // C++17以降で使用可能
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn_superres.hpp>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "SuperResolution.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    try {
        // 現在の作業ディレクトリを取得
        std::string currentPath = std::filesystem::current_path().string();
        std::cout << "Exec Dir: " << currentPath << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 入力画像を読み込み
    cv::Mat inputImage = cv::imread("TrumpPortrait_Small.jpg");
    //
    if (inputImage.empty())
    {
        std::cout << "画像が読み込めません。" << std::endl;
        return -1;
    }
    //
    // dnn_superresオブジェクトを作成
    cv::dnn_superres::DnnSuperResImpl superRes;
    //出力
    cv::Mat outputImage;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //EDSR_x2
    std::cout << "EDSR_x2 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("EDSR_x2.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("edsr", 2); // "edsr"アルゴリズム、2倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("EDSR_x2.jpg", outputImage);
    std::cout << "EDSR_x2 : end :" << std::endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //EDSR_x3
    std::cout << "EDSR_x3 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("EDSR_x3.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("edsr", 3); // "edsr"アルゴリズム、3倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("EDSR_x3.jpg", outputImage);
    std::cout << "EDSR_x3 : end :" << std::endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //EDSR_x4
    std::cout << "EDSR_x4 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("EDSR_x4.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("edsr", 4); // "edsr"アルゴリズム、4倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("EDSR_x4.jpg", outputImage);
    std::cout << "EDSR_x4 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ESPCN_x2
    std::cout << "ESPCN_x2 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("ESPCN_x2.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("espcn", 2); // "espcn"アルゴリズム、2倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("ESPCN_x2.jpg", outputImage);
    std::cout << "ESPCN_x2 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ESPCN_x3
    std::cout << "ESPCN_x3 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("ESPCN_x3.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("espcn", 3); // "espcn"アルゴリズム、3倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("ESPCN_x3.jpg", outputImage);
    std::cout << "ESPCN_x3 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //ESPCN_x4
    std::cout << "ESPCN_x4 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("ESPCN_x4.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("espcn", 4); // "espcn"アルゴリズム、4倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("ESPCN_x4.jpg", outputImage);
    std::cout << "ESPCN_x4 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //FSRCNN_x2
    std::cout << "FSRCNN_x2 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("FSRCNN_x2.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("fsrcnn", 2); // "FSRCNN"アルゴリズム、2倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("FSRCNN_x2.jpg", outputImage);
    std::cout << "FSRCNN_x2 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //FSRCNN_x3
    std::cout << "FSRCNN_x3 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("FSRCNN_x3.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("fsrcnn", 3); // "FSRCNN"アルゴリズム、3倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("FSRCNN_x3.jpg", outputImage);
    std::cout << "FSRCNN_x3 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //FSRCNN_x4
    std::cout << "FSRCNN_x4 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("FSRCNN_x4.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("fsrcnn", 4); // "FSRCNN"アルゴリズム、4倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("FSRCNN_x4.jpg", outputImage);
    std::cout << "FSRCNN_x4 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //FSRCNN-small_x2
    std::cout << "FSRCNN-small_x2 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("FSRCNN-small_x2.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("fsrcnn", 2); // "FSRCNN-small"アルゴリズム、2倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("FSRCNN-small_x2.jpg", outputImage);
    std::cout << "FSRCNN-small_x2 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //FSRCNN-small_x3
    std::cout << "FSRCNN-small_x3 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("FSRCNN-small_x3.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("fsrcnn", 3); // "FSRCNN-small"アルゴリズム、3倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("FSRCNN-small_x3.jpg", outputImage);
    std::cout << "FSRCNN-small_x3 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //FSRCNN-small_x4
    std::cout << "FSRCNN-small_x4 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("FSRCNN-small_x4.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("fsrcnn", 4); // "FSRCNN-small"アルゴリズム、4倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("FSRCNN-small_x4.jpg", outputImage);
    std::cout << "FSRCNN-small_x4 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //LapSRN_x2
    std::cout << "LapSRN_x2 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("LapSRN_x2.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("lapsrn", 2); // "LapSRN"アルゴリズム、2倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("LapSRN_x2.jpg", outputImage);
    std::cout << "LapSRN_x2 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //LapSRN_x4
    std::cout << "LapSRN_x4 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("LapSRN_x4.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("lapsrn", 4); // "LapSRN"アルゴリズム、4倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("LapSRN_x4.jpg", outputImage);
    std::cout << "LapSRN_x4 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //LapSRN_x8
    std::cout << "LapSRN_x8 : start :" << std::endl;
    // モデルを読み込み
    superRes.readModel("LapSRN_x8.pb");
    // 使用するアルゴリズムを設定
    superRes.setModel("lapsrn", 8); // "LapSRN"アルゴリズム、8倍拡大
    // 高解像化処理
    superRes.upsample(inputImage, outputImage);
    cv::imwrite("LapSRN_x8.jpg", outputImage);
    std::cout << "LapSRN_x8 : end :" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "高解像化が完了しました！" << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cv::imshow("Input Image", inputImage);
    cv::waitKey(0);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
