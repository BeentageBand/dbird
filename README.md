# Overview
DBIRD

# Build
## linux
Install dependencies:
```
sudo apt-get update && \
sudo apt-get install -y \
    automake \
    autoconf \
    g++ \
    gcc \
    libtool \
    libjsoncpp-dev \
    libgmock-dev \
    m4 \
    make \
    pkg-config
sudo apt-get clean

```

Build with autotools:
```
autoreconf -i
./configure
make
```

# Test

