
#include <iostream>
#include <opencv2/opencv.hpp>
extern "C" {
#include <libavformat/avformat.h>
}

using namespace std;
using namespace cv;

int main() {
    void test_encoder();
//    // 打开摄像头
//    VideoCapture cap(0);
//    if (!cap.isOpened()) {
//        cerr << "无法打开摄像头" << endl;
//        return -1;
//    }
//
//    // 获取摄像头的宽高信息
//    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
//    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
//
//    // 初始化FFmpeg
//    avformat_network_init();
//
//    // 创建AVFormatContext
//    AVFormatContext* pFormatCtx = avformat_alloc_context();
//    if (!pFormatCtx) {
//        cerr << "无法创建AVFormatContext" << endl;
//        return -1;
//    }
//
//    // 设置输出视频格式为YUV420P
//    AVOutputFormat* outFmt = const_cast<AVOutputFormat*>(av_guess_format("rawvideo", NULL, NULL));
//    pFormatCtx->oformat = outFmt;
//
//    // 打开输出文件
//    if (avio_open(&pFormatCtx->pb, "output.yuv", AVIO_FLAG_WRITE) < 0) {
//        cerr << "无法创建输出文件" << endl;
//        return -1;
//    }
//
//    // 创建AVStream
//    AVStream* pStream = avformat_new_stream(pFormatCtx, NULL);
//    if (!pStream) {
//        cerr << "创建AVStream失败" << endl;
//        return -1;
//    }
//
//    // 设置帧率为30
//    int fps = 30;
//
//    // 设置AVStream的时间基准
//    AVRational time_base;
//    time_base.num = 1;
//    time_base.den = fps;
//
//    // 设置AVStream的时间基准
//    pStream->time_base = time_base;
//
//    // 创建AVCodecContext
//    AVCodecParameters* pCodecParams = pStream->codecpar;
//    pCodecParams->codec_id = AV_CODEC_ID_RAWVIDEO;
//    pCodecParams->codec_type = AVMEDIA_TYPE_VIDEO;
//    pCodecParams->format = AV_PIX_FMT_YUV420P;
//    pCodecParams->width = frame_width;
//    pCodecParams->height = frame_height;
//
//    // 写入流头信息
//    avformat_write_header(pFormatCtx, NULL);
//
//    // 录制视频并保存为YUV格式
//    chrono::steady_clock::time_point next_frame_time = chrono::steady_clock::now();
//
//    while (true) {
//        Mat frame;
//        cap >> frame; // 从摄像头读取一帧图像
//
//        if (frame.empty()) {
//            cerr << "摄像头数据流中断" << endl;
//            break;
//        }
//
//        // 将OpenCV的BGR图像转换为YUV420P格式
//        cvtColor(frame, frame, COLOR_BGR2YUV_I420);
//
//        // 将AVFrame写入输出文件
//        AVPacket pkt; 
//        av_new_packet(&pkt, frame.total() * frame.elemSize());
//        pkt.data = frame.data;
//        pkt.size = frame.total() * frame.elemSize();
//        pkt.stream_index = pStream->index;
//
//        // 让FFmpeg自动生成DTS和PTS
//        pkt.pts = av_rescale_q_rnd(pStream->nb_frames, time_base, pStream->time_base, (enum AVRounding)(AV_ROUND_NEAR_INF | AV_ROUND_PASS_MINMAX));
//        pkt.dts = pkt.pts;
//
//        // 更新nb_frames计数器
//        pStream->nb_frames++;
//
//        av_interleaved_write_frame(pFormatCtx, &pkt);
//
//        imshow("Camera", frame);
//
//        // 计算下一帧的时间戳
//        next_frame_time += chrono::milliseconds(1000 / fps);
//
//        // 按下ESC键退出录制
//        if (waitKey(1) == 27)
//            break;
//    }
//
//    // 写入文件尾
//    av_write_trailer(pFormatCtx);
//
//    // 释放资源
//    avio_close(pFormatCtx->pb);
//    avformat_free_context(pFormatCtx);
//    cap.release();
//    destroyAllWindows();
//
//    cout << "视频录制完成，已保存为output.yuv" << endl;
//    cout << frame_height << "高度" << endl;
//    cout << frame_width << "宽度" << endl;
    test_encoder();
    return 0;
}
