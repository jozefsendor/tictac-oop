# Używamy oficjalnego obrazu Ubuntu jako bazowego
FROM ubuntu:latest

# Instalujemy wymagane pakiety
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    cmake \
    && rm -rf /var/lib/apt/lists/*

# Ustawiamy katalog roboczy
WORKDIR /app

# Kopiujemy pliki projektu do kontenera
COPY . .

# Tworzymy katalog build i przechodzimy do niego
RUN mkdir -p build && cd build \
    # Konfigurujemy projekt przy użyciu CMake
    && cmake .. \
    # Kompilujemy projekt
    && make

# Ustawiamy domyślną komendę, która uruchomi się po starcie kontenera
CMD ["bash"]
