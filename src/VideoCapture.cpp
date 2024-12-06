#include "VideoCapture.h"

void VideoCapture::pushImg(unsigned char* imgPtr, int size) {
    
    imgBufferMutex.lock();
    imgBuffer.push(std::make_pair(imgPtr, size));
    imgBufferMutex.unlock();
}

std::pair<unsigned char*, int> VideoCapture::popImg() {
    std::pair<unsigned char*, int> ret = imgBuffer.front();
    imgBufferMutex.lock();
    imgBuffer.pop();
    imgBufferMutex.unlock();
    return ret;
}