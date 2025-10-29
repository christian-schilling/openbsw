FROM ubuntu:jammy-20251001

RUN for i in 1 2 3; do \
        apt-get update && apt-get install -y \
            curl \
            python3-pip \
            python3.10 \
            tar \
        && rm -rf /var/lib/apt/lists/* \
        && break || { echo "Apt install failed, retrying ($i/3)..."; sleep 10; }; \
    done

RUN curl -L https://github.com/numtide/treefmt/releases/download/v2.1.0/treefmt_2.1.0_linux_amd64.tar.gz -o treefmt.tar.gz \
    && tar -xvzf treefmt.tar.gz \
    && install -m 755 treefmt /usr/bin/treefmt \
    && rm LICENSE README.md treefmt treefmt.tar.gz

RUN curl -L https://github.com/muttleyxd/clang-tools-static-binaries/releases/download/master-32d3ac78/clang-format-17_linux-amd64 -o usr/bin/clang-format-17 \
    && chmod +x  usr/bin/clang-format-17

RUN pip3 install cmakelang

ARG user_id=2001

RUN groupadd -g 4996 docker
RUN useradd --shell /bin/bash --uid ${user_id} -g docker -m jenkins

USER jenkins

WORKDIR /home/jenkins
