FROM ubuntu:focal

ENV TZ=Europe/London
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    software-properties-common apt-utils openssh-server build-essential gdb gdbserver rsync vim cmake
RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN apt-get update && apt-get install -y gcc-9 g++-9 gcc-10 g++-10 \
    libboost-dev libboost-all-dev manpages-dev stl-manual libloki-dev libspdlog-dev

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 9
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 10
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10

#RUN wget https://github.com/Kitware/CMake/releases/download/v3.19.0/cmake-3.19.0-Linux-x86_64.sh \
#     -q -O /tmp/cmake-install.sh \
#      && chmod u+x /tmp/cmake-install.sh \
#      && mkdir /usr/bin/cmake \
#      && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
#      && rm /tmp/cmake-install.sh

#ENV PATH="/usr/bin/cmake/bin:${PATH}"

ADD . /code
WORKDIR /code

RUN mkdir /var/run/sshd
RUN echo 'root:root' | chpasswd
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

# 22 for ssh server. 7777 for gdb server.
EXPOSE 22 7777

RUN useradd -ms /bin/bash debugger
RUN echo 'debugger:pwd' | chpasswd

CMD ["/usr/sbin/sshd", "-D"]
