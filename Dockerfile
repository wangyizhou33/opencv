FROM nvidia/opengl:base

ARG DEBIAN_FRONTEND=noninteractive

RUN apt -y update && apt -y install \
freeglut3-dev clang-format build-essential cmake \
xorg-dev libglu1-mesa-dev wget unzip \ 
libopencv-dev


# RUN \
#     wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip && \
#     unzip opencv.zip && \
# # Create build directory
#     mkdir -p build && cd build && \
# # Configure
#     cmake  ../opencv-4.x && \
# # Build
#     cmake --build . && \
#     make -j8 install

# Clean up APT when done.
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
