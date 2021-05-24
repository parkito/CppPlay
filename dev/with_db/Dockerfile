FROM ubuntu:focal

ENV TZ=Europe/London
ENV NOTVISIBLE "in users profile"

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone \
    && apt-get update && apt-get upgrade -y && apt-get install -y \
    software-properties-common apt-utils git build-essential libpq-dev openssh-server gdb gdbserver rsync vim cmake valgrind fish ltrace strace \
    && add-apt-repository ppa:ubuntu-toolchain-r/test \
    && add-apt-repository universe \
    && apt update && apt-get install -y g++-11 gcc-11 libfmt-dev \
    libboost-dev libboost-all-dev manpages-dev stl-manual libloki-dev libspdlog-dev \
  && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 30 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 30 \
    && update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 30 \
    && update-alternatives --set cc /usr/bin/gcc \
    && update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 30 \
    && update-alternatives --set c++ /usr/bin/g++ \
    && mkdir /var/run/sshd \
    && echo 'root:root' | chpasswd \
    && sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config \
    # SSH login fix. Otherwise user is kicked off after login
    && sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd \
    && echo "export VISIBLE=now" >> /etc/profile \
    # 22 for ssh server. 7777 for gdb server.
    && useradd -ms /bin/bash debugger \
    && echo 'debugger:pwd' | chpasswd \
    #install soci
    && cd /tmp && git clone git://github.com/SOCI/soci.git \
    && cd /tmp/soci && mkdir build \
    && cd build && cmake -G "Unix Makefiles" -DWITH_BOOST=OFF -DWITH_POSTGRESQL=ON -DCMAKE_CXX_STANDARD=20 /tmp/soci/ \
    && cd /tmp/soci/build && make \
    && cd /tmp/soci/build && make install \
    && apt --purge remove -y gcc-9 g++-9 gcc-10-base gcc-9-base \
    && apt autoremove -y --purge \
    && cd / && rm -r /tmp/soci


ADD . /code
WORKDIR /code
EXPOSE 22 7777
CMD ["/usr/sbin/sshd", "-D"]
