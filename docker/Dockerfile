FROM ubuntu:24.10

RUN apt-get update && \
    apt-get install -y \
    git \
    time \
    python3 \
    python3-pip

RUN pip3 install online-judge-verify-helper==5.6.0 --break-system-packages

WORKDIR /CompetitiveProgrammingLibrary

ENTRYPOINT ["oj-verify", "run", "--tle", "5"]
