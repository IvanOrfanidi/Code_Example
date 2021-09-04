#include <iostream>
#include <limits>

#ifdef CUDA_ENABLE
#include <opencv2/cudaarithm.hpp>
#endif
#include <opencv2/opencv.hpp>

constexpr int WIDTH = 1000;
constexpr int HEIGHT = 1000;

int main()
{
#ifdef CUDA_ENABLE
    bool cudaEnable = false;
    if (cv::cuda::getCudaEnabledDeviceCount() != 0) {
        cv::cuda::DeviceInfo deviceInfo;
        if (deviceInfo.isCompatible()) {
            cudaEnable = true;
        }
    }
#endif

    cv::Mat MA(cv::Size(WIDTH, HEIGHT), CV_32F);
    cv::randu(MA, cv::Scalar::all(-10), cv::Scalar::all(10));
    cv::Mat MB(cv::Size(WIDTH, HEIGHT), CV_32F);
    cv::randu(MB, cv::Scalar::all(-10), cv::Scalar::all(10));

    auto start = cv::getTickCount();
    cv::Mat MC = MA * MB;
    auto end = cv::getTickCount();
    std::cout << "calculation time:            " << ((end - start) * (1000.0f / cv::getTickFrequency())) << " ms" << std::endl;

#ifdef CUDA_ENABLE
    if (cudaEnable) {
        cv::cuda::GpuMat gpuMA(MA);
        cv::cuda::GpuMat gpuMB(MB);
        cv::cuda::GpuMat gpuMD;
        start = cv::getTickCount();
        cv::cuda::gemm(gpuMA, gpuMB, 1.0, cv::cuda::GpuMat(), 0.0, gpuMD);
        end = cv::getTickCount();
        cv::Mat MD;
        gpuMD.download(MD);
        std::cout << "calculation time with CUDA:  " << ((end - start) * (1000.0f / cv::getTickFrequency())) << " ms" << std::endl;
    } else {
        std::cout << "CUDA is not supported" << std::endl;
    }
#else
    std::cout << "CUDA is not supported" << std::endl;
#endif

    return EXIT_SUCCESS;
}