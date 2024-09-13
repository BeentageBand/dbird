# First stage: Build the C++ application
FROM debian:latest AS builder

# Set environment variables to non-interactive mode
ENV DEBIAN_FRONTEND=noninteractive

# Set Build Arguments
ARG FLAVOR=master

# Install necessary build tools
RUN apt-get update && \
    apt-get install -y \
    automake \
    autoconf \
    g++ \
    gcc \
    libtool \
    libjsoncpp-dev \
    m4 \
    make \
    pkg-config \
    && apt-get clean

# Set the working directory inside the container
WORKDIR /usr/src/app

# Copy your source code into the container
COPY . .

# Build the application
RUN autoconf -i && configure && make

# Second stage: Create a lightweight runtime image
FROM debian:latest

# Set the working directory for runtime
WORKDIR /usr/src/app

# Copy only the built executable from the builder stage
COPY --from=builder /usr/src/app/out/${FLAVOR} /usr/src/app/

# Command to run the application
CMD ["./${FLAVOR}"]
