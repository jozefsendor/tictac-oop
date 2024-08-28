# Użyj oficjalnego obrazu Dockera z GCC jako bazowy
FROM gcc:latest

# Ustaw katalog roboczy w kontenerze
WORKDIR /app

# Zainstaluj CMake i inne wymagane narzędzia
RUN apt-get update && apt-get install -y \
    cmake \
    make \
    g++ \
    && rm -rf /var/lib/apt/lists/*

# Skopiuj pliki projektu do katalogu roboczego
COPY . .

# Skonfiguruj i zbuduj aplikację
RUN mkdir build && cd build && cmake .. && make

# Wskazanie komendy uruchamianej po starcie kontenera
CMD ["./build/game"]
